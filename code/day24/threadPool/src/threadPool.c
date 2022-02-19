#include "../include/threadpool.h"

void *threadFunc(void* p)
{
    pQue_t pQue = (pQue_t)p;
    pNode_t pCur = NULL;
    int getSucess = 1;
    while(1){
        pthread_mutex_lock(&pQue->mutex);
        if(0 == pQue->size){
            pthread_cond_wait(&pQue->cond, &pQue->mutex);
        }

        getSucess = queGet(pQue, &pCur);
        pthread_mutex_unlock(&pQue->mutex);
        if(0 == getSucess){
            transFile(pCur->clientFd);
        }
    }
    return 0;
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
    for(int i = 0; i < pPool->threadNum; ++i){
        pthread_create(pPool->pthid+i, NULL, threadFunc, &pPool->Que);
    }
    return 0;
}
