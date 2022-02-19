#include <head.h>

int main(int argc, char** argv)
{
    //创建sfd，用于与客户端建立连接
    int sfd = socket(AF_INET, SOCK_DGRAM, 0);
    ERROR_CHECK(sfd, -1, "socket");
    struct sockaddr_in serAddr;
    memset(&serAddr, 0, sizeof(serAddr));

    serAddr.sin_family = AF_INET;
    serAddr.sin_addr.s_addr = inet_addr(argv[1]);
    serAddr.sin_port = htons(atoi(argv[2]));

    //把sfd， 与本地的端口号和ip进行绑定
    int ret = bind(sfd, (struct sockaddr*)&serAddr, sizeof(serAddr));
    ERROR_CHECK(ret, -1, "bind");
    char buf[8] = {0};

    //用于存储对端的ip和端口号
    struct sockaddr_in cliAddr;
    memset(&cliAddr, 0, sizeof(cliAddr));
    socklen_t len = sizeof(cliAddr);
    sleep(1);
    recvfrom(sfd, buf, sizeof(buf), 0, (struct sockaddr*)&cliAddr, &len);
    printf("buf = %s\n", buf);
    recvfrom(sfd, buf, sizeof(buf), 0, (struct sockaddr*)&cliAddr, &len);
    printf("buf = %s\n", buf);
    sendto(sfd, "helloclient", 11, 0, (struct sockaddr*)&cliAddr, len);

    close(sfd);
    return 0;
}

