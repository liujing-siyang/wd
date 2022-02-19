#include <head.h>

int main(int argc, char** argv)
{
    //定义结构体用于存储转换后的网络二进制值
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    //把点分十进制的ip地址转换成网络二进制值
    inet_aton(argv[1], &addr.sin_addr);
    printf("addr = %x\n", addr.sin_addr.s_addr);
    //把结构体里的二进制值，转换成点分十进制
    printf("addr = %s\n", inet_ntoa(addr.sin_addr));
    return 0;
}

