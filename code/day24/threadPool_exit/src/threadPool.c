#include "../include/threadpool.h"

void cleanFunc(void *pArg)
{
    printf("cleanFunc\n");
    pQue_t pQue = (pQue_t)pArg;
    pthread_mutex_unlock(&pQue->mutex);
    return ;
}

void *threadFunc(void* p)
{
    pQue_t pQue = (pQue_t)p;
    pthread_cleanup_push(cleanFunc, pQue);
    pNode_t pCur = NULL;
    int getSucess = 1;
    while(1){
        pthread_mutex_lock(&pQue->mutex);
        if(0 == pQue->size){
            //如果队列里没有数据，等待
            //等到主线程接收到客户端的连接请求后，
            //把返回来得newFd会加入到队列里，并通知子线程
            pthread_cond_wait(&pQue->cond, &pQue->mutex);
        }

        //获取队列的头结点
        getSucess = queGet(pQue, &pCur);
        pthread_mutex_unlock(&pQue->mutex);
        //如果获取成功，就开始传输文件
        if(0 == getSucess){
            transFile(pCur->clientFd);
            free(pCur);
            pCur = NULL;
        }
        if(1 == pQue->exitFlag){
            printf("child thread exit\n");
            pthread_exit(NULL);
        }
    }
    pthread_cleanup_pop(1);

    pthread_exit(NULL);
}

int threadPoolInit(pThreadPool_t pPool, int threadNum)
{
    pPool->threadNum = threadNum;

    pPool->pthid  =  (pthread_t*)calloc(threadNum, sizeof(pthread_t));
    queInit(&pPool->Que);
    return 0;
}

int threadPoolStart(pThreadPool_t pPool)
{
    //线程池启动后循环创子线程
    for(int i = 0; i < pPool->threadNum; ++i){
        pthread_create(pPool->pthid+i, NULL, threadFunc, &pPool->Que);
    }
    return 0;
}
