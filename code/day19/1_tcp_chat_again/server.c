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
    //新创建一个集合， 把需要监听的文件描述符都放到集合中
    fd_set needMointorSet;
    FD_ZERO(&needMointorSet);
    FD_ZERO(&rdset);

    //把需要监听的文件描述符加入到集合当中
    FD_SET(STDIN_FILENO, &needMointorSet);
    FD_SET(sfd, &needMointorSet);
    int readyNum = 0;
    char buf[128] = {0};
    while(1){
        memcpy(&rdset, &needMointorSet, sizeof(fd_set));
        //select的第二个参数是传入传出参数，每次都会修改位图里面的数据
        //所以需要建立一个新的集合防止数据被改变
        //每次把新的集合数据拷贝给rdset
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
                    //把文件描述符从needMonitorSet集合中删除
                    FD_CLR(newFd, &needMointorSet);
                    continue;
                }
                printf("buf = %s\n", buf);
            }
            //如果sfd就绪就说明对端有连接请求，使用accept函数把
            //全连接队列里的第一个连接拿出来建立连接
            else if (FD_ISSET(sfd, &rdset)){
                newFd = accept(sfd, NULL, NULL);
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

