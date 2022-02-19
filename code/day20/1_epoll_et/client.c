#include <head.h>

int main(int argc, char** argv)
{
    //创建sfd描述符，用于与对端建立连接时使用
    int sfd = socket(AF_INET, SOCK_STREAM, 0);
    ERROR_CHECK(sfd, -1, "socket");
    
    struct sockaddr_in serAddr;
    memset(&serAddr, 0, sizeof(serAddr));

    serAddr.sin_family = AF_INET;
    serAddr.sin_addr.s_addr = inet_addr(argv[1]);
    serAddr.sin_port = htons(atoi(argv[2]));

    //连接服务器，把sfd与服务端的if与端口号建立连接
    int ret = connect(sfd, (struct sockaddr*)&serAddr, sizeof(serAddr));
    ERROR_CHECK(ret, -1, "connect");

    send(sfd, "hellocserver", 11, 0);

    char buf[128] = {0};
    //创建集合用于存储文件描述符
    fd_set rdset;
    FD_ZERO(&rdset);
    int readyNum = 0;
    //循环聊天
    while(1){
        //把需要监听的文件描述符加入到集合当中
        FD_SET(STDIN_FILENO, &rdset);
        FD_SET(sfd, &rdset);
        readyNum = select(sfd+1, &rdset, NULL, NULL, NULL);
        for(int i = 0; i < readyNum; ++i){
            //如果是标准输入就绪就发送数据
            if(FD_ISSET(STDIN_FILENO, &rdset)){
                memset(buf, 0, sizeof(buf));
                read(STDIN_FILENO, buf, sizeof(buf));
                send(sfd, buf, strlen(buf)-1, 0);
            }
            //如果是newFd就绪，说明对端有数据发送过来，就接收数据
            if(FD_ISSET(sfd, &rdset)){
                memset(buf, 0, sizeof(buf));
                recv(sfd, buf, sizeof(buf), 0);
                printf("buf = %s\n", buf);
            }
        }
    }

    close(sfd);
    return 0;
}

