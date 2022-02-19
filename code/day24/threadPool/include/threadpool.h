#ifndef __THREADPOOL_H__
#define __THREADPOOL_H__
#include "workque.h"

typedef  struct{
    int threadNum;
    pthread_t *pthid;
    Que_t Que;
}threadPool_t, *pThreadPool_t;

typedef struct{
    int dataLen;
    char buf[1000];
}train_t;

int threadPoolInit(pThreadPool_t pPool, int threadNum);
int threadPoolStart(pThreadPool_t pPool);

int tcpInit(int *socketFd, char *ip, char *port);
int epollAddFd(int epfd, int fd);
int transFile(int clientFd);

#endif

