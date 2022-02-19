#ifndef __WORKQUE_H__
#define __WORKQUE_H__
#include "head.h"

//队列存储的节点数据结构
typedef struct node{
    int clientFd;
    struct node *pNext;
}Node_t, *pNode_t;

//队列自己的数据结构
typedef struct{
    char exitFlag;
    pNode_t pHead, pTail;
    int size;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
}Que_t, *pQue_t;

int queInit(pQue_t pQue);
int queInsert(pQue_t pQue, pNode_t pNew);
int queGet(pQue_t pQue, pNode_t *pGet);
#endif
