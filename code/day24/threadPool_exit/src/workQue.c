#include "../include/workque.h"

int queInit(pQue_t pQue)
{
    pQue->pHead = NULL;
    pQue->pTail = NULL;
    pQue->size = 0;
    pQue->exitFlag = 0;
    pthread_mutex_init(&pQue->mutex, NULL);
    pthread_cond_init(&pQue->cond, NULL);
    return 0;
}

int queInsert(pQue_t pQue, pNode_t pNew)
{
    //当队列为空时
    if(0 == pQue->size){
        pQue->pHead = pNew;
        pQue->pTail = pNew;
    }
    //队列不为空的时候
    else{
        pQue->pTail->pNext = pNew;
        pQue->pTail = pNew;
    }

    pQue->size++;
    return 0;
}

int queGet(pQue_t pQue, pNode_t* pGet)
{
    if(0  == pQue->size){
        return -1;
    }

    //获取节点
    *pGet = pQue->pHead;
    //并且头指针向后移动一个
    pQue->pHead = pQue->pHead->pNext;

    if(pQue->pHead == NULL){
        pQue->pTail = NULL;
    }

    pQue->size--;
    return 0;
}

