#include <head.h>

int recvCycle(int clientFd, void *buf, int totalLen)
{
    int ret = 0;
    int recvLen = 0;
    while(recvLen < totalLen){
        ret = recv(clientFd, (char*)buf + recvLen, totalLen - recvLen, 0);
        recvLen += ret;
        if(0 == ret){
            printf("bye\n");
            return -1;
        }
    }
    return recvLen;
}
