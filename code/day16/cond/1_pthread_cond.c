#include <head.h>

typedef struct{
    int num;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
}Data_t;

void *threadFunc(void* p)
{
    Data_t *pData = (Data_t*)p;
    pthread_mutex_lock(&pData->mutex);
    if(0 == pData->num){
        printf("before wait\n");
        //阻塞性函数
        //上半部：等待、解锁、睡觉
        //下半部：醒过来、加锁（如果锁被使用了，阻塞、如果没有被使用、就直接加锁）、从pthread_cond_wait返回
        pthread_cond_wait(&pData->cond, &pData->mutex);
        printf("after wait\n");
    }
    pthread_mutex_unlock(&pData->mutex);
    printf("买到了酒\n");
    pthread_exit(NULL);
}
int main(int argc, char** argv)
{
    Data_t data;
    data.num = 0;
    pthread_mutex_init(&data.mutex, NULL);
    pthread_cond_init(&data.cond, NULL);
    pthread_t thid;
    int ret = 0;
    ret = pthread_create(&thid, NULL, threadFunc, &data);

    sleep(6);
    //sleep(1)为了充分让子线程执行，否则主线程执行过快，子线程
    //还没有执行到pthread_cond_wait。
    pthread_mutex_lock(&data.mutex);
    pthread_cond_signal(&data.cond);
    //sleep（5）发送信号给子线程，子线程此时已经收到了这个信号，
    //但是5秒钟内并没有解锁，所以pthread_cond_wait加锁不成功造成阻塞
    printf("有酒了\n");
    pthread_mutex_unlock(&data.mutex);

    pthread_join(thid, NULL);
    pthread_mutex_destroy(&data.mutex);
    pthread_cond_destroy(&data.cond);
    return 0;
}

