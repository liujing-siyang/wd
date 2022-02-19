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

    char buf[128] = {0};

    socklen_t len = sizeof(serAddr);
    sendto(sfd, "helloserver", 11, 0, (struct sockaddr*)&serAddr, len);

    recvfrom(sfd, buf, sizeof(buf), 0, (struct sockaddr*)&serAddr, &len);
    printf("buf = %s\n", buf);

    close(sfd);
    return 0;
}

