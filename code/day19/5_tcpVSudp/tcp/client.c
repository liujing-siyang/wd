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

    //连接服务器，把sfd与服务端的ip与端口号建立连接
    int ret = connect(sfd, (struct sockaddr*)&serAddr, sizeof(serAddr));
    ERROR_CHECK(ret, -1, "connect");

    char buf[128] = {0};
    
    //发送数据到服务端
    send(sfd, "helloserver", 11, 0);
    /* send(sfd, "nihao", 5, 0); */

    //接收数据到buf中
    recv(sfd, buf, sizeof(buf), 0);
    printf("buf = %s\n", buf);

    close(sfd);
    return 0;
}

