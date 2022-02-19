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
    int newFd = accept(sfd, NULL, NULL);
    ERROR_CHECK(newFd, -1, "accept");
    char buf[128] = {0};

    //从客户端接收数据到buf中
    recv(newFd, buf, sizeof(buf), 0);
    printf("buf = %s\n", buf);

    //发送数据给客户端
    send(newFd, "helloclient", 11, 0);

    //通信完成关闭文件描述符
    close(sfd);
    close(newFd);
    return 0;
}

