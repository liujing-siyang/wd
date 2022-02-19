#include <head.h>

int main(int argc, char** argv)
{
    short port = 0x1234;
    //把端口号从主机字节序转换成网络字节序
    short nport = htons(port);
    printf("nport = %x\n", nport);
    //把端口号从网络字节序转换成主机字节序
    printf("port = %x", ntohs(nport));
    return 0;
}

