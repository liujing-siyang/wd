#include <head.h>

int main(int argc, char** argv)
{
    //创建sfd，用于与客户端建立连接
    int sfd = socket(AF_INET, SOCK_STREAM, 0);
    ERROR_CHECK(sfd, -1, "socket");
    struct sockaddr_in serAddr;
    memset(&serAddr, 0, sizeof(serAddr));

    serAddr.sin_family = AF_INET;
    serAddr.sin_addr.s_addr = inet_addr(argv[1]);
    serAddr.sin_port = htons(atoi(argv[2]));
    //允许端口和ip可重用
    int reuse = 1; // 设置选项生效
    setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));

    //把sfd， 与本地的端口号和ip进行绑定
    int ret = bind(sfd, (struct sockaddr*)&serAddr, sizeof(serAddr));
    ERROR_CHECK(ret, -1, "bind");

    //监听sfd， 并且最大监听的连接数为10
    ret = listen(sfd, 10);
    ERROR_CHECK(ret, -1, "listen");

    //accept函数接收对端的连接请求，并且返回一个新的文件描述符，
    //新的文件描述符用于与对端进行数据的交互
    int newFd = 0;
    fd_set rdset;
    //创建一个新的集合存储需要监听的文件描述符
    fd_set needMointorSet;
    FD_ZERO(&needMointorSet);
    FD_ZERO(&rdset);
    FD_SET(STDIN_FILENO, &needMointorSet);
    FD_SET(sfd, &needMointorSet);
    int readyNum = 0;
    char buf[128] = {0};
    while(1){
        memcpy(&rdset, &needMointorSet, sizeof(fd_set));
        //把需要监听的文件描述符加入到集合当中
        readyNum = select(10, &rdset, NULL, NULL, NULL);
        for(int i = 0; i < readyNum; ++i){
            if(FD_ISSET(STDIN_FILENO, &rdset)){
                memset(buf, 0, sizeof(buf));
                read(STDIN_FILENO, buf, sizeof(buf));
                send(newFd, buf, strlen(buf)-1, 0);
            }
            if(FD_ISSET(newFd, &rdset)){
                memset(buf, 0, sizeof(buf));
                ret = recv(newFd, buf, sizeof(buf), 0);
                //如果recv的返回值是0，就代表对端断开连接
                if(0 == ret){
                    printf("bye,bye\n");
                    close(newFd);
                    FD_CLR(newFd, &needMointorSet);
                    continue;
                }
                printf("buf = %s\n", buf);
            }
            else if (FD_ISSET(sfd, &rdset)){
                accept(sfd, NULL, NULL);
                ERROR_CHECK(newFd, -1, "accept");
                FD_SET(newFd, &needMointorSet);
            }
        }
    }

    //关闭文件描述符
    close(sfd);
    close(newFd);
    return 0;
}

