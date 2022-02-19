#include "../include/threadpool.h"

int main(int argc, char** argv)
{
    int threadNum = atoi(argv[3]);

    //线程池的初始化
    threadPool_t threadPool;
    threadPoolInit(&threadPool, threadNum);

    //线程池的启动
    threadPoolStart(&threadPool);
    //初始化tcp监听套接字
    int sfd;
    tcpInit(&sfd, argv[1], argv[2]);

    int epfd = epoll_create(1);

    epollAddFd(epfd, sfd);

    int readyNum = 0;
    int newFd = 0;
    struct epoll_event evs[2]; 
    memset(evs, 0, sizeof(evs));
    while(1){
        readyNum = epoll_wait(epfd, evs, 2, -1);
        for(int i = 0; i < readyNum; ++i){
            if(evs[i].data.fd == sfd){
                newFd = accept(sfd, NULL, NULL);
                pNode_t pNode = (pNode_t)calloc(1, sizeof(Node_t));
                pNode->clientFd = newFd;
                pthread_mutex_lock(&threadPool.Que.mutex);
                queInsert(&threadPool.Que, pNode);
                pthread_cond_signal(&threadPool.Que.cond);
                pthread_mutex_unlock(&threadPool.Que.mutex);
            }
        }
    }
    
    return 0;
}

