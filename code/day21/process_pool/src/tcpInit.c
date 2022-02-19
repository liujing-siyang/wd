#include <head.h>

int tcpInit(int *socketFd, char *ip, char *port)
{
    //创建sfd，用于与客户端建立连接
    int sfd = socket(AF_INET, SOCK_STREAM, 0);
    ERROR_CHECK(sfd, -1, "socket");
    struct sockaddr_in serAddr;
    memset(&serAddr, 0, sizeof(serAddr));

    serAddr.sin_family = AF_INET;
    serAddr.sin_addr.s_addr = inet_addr(ip);
    serAddr.sin_port = htons(atoi(port));

    //把sfd， 与本地的端口号和ip进行绑定
    int ret = bind(sfd, (struct sockaddr*)&serAddr, sizeof(serAddr));
    ERROR_CHECK(ret, -1, "bind");

    //监听sfd， 并且最大监听的连接数为10
    ret = listen(sfd, 10);
    ERROR_CHECK(ret, -1, "listen");
    *socketFd = sfd;

    return 0;
}
