#include <head.h>

void* threadFunc(void* p)
{
    //子线程执行解锁操作，但是不建议这样写，防止子线程忘记释放锁资源
    printf("i am child thread\n");
    pthread_mutex_t *pMutex = (pthread_mutex_t*)p;
    pthread_mutex_unlock(pMutex);
    pthread_exit(NULL);
}
int main(int argc, char** argv)
{
    pthread_mutex_t mutex;
    int ret = 0;
    //互斥锁的初始化
    ret = pthread_mutex_init(&mutex, NULL);
    THREAD_ERROR_CHECK(ret, "init");
    //加锁
    ret = pthread_mutex_lock(&mutex);
    THREAD_ERROR_CHECK(ret, "lock");
    printf("lock\n");
    pthread_t thid;
    ret = pthread_create(&thid, NULL, threadFunc, &mutex);
    //解锁
    /* ret = pthread_mutex_unlock(&mutex); */
    /* THREAD_ERROR_CHECK(ret, "unlock"); */
   /* printf("unlock\n"); */
    //互斥锁的销毁
    pthread_join(thid, NULL);
    ret = pthread_mutex_destroy(&mutex);
    THREAD_ERROR_CHECK(ret, "destroy");
    return 0;
}

