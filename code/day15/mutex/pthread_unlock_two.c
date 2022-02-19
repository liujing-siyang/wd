#include <head.h>

int main(int argc, char** argv)
{
    pthread_mutex_t mutex;
    int ret = 0;
    //互斥锁的初始化
    ret = pthread_mutex_init(&mutex, NULL);
    THREAD_ERROR_CHECK(ret, "init");
    printf("first lock\n");
    ret = pthread_mutex_lock(&mutex);
    THREAD_ERROR_CHECK(ret, "lock");

    ret = pthread_mutex_unlock(&mutex);
    THREAD_ERROR_CHECK(ret, "unlock");
    //对只加一次锁的锁解两次锁会造成销毁失败
    ret = pthread_mutex_unlock(&mutex);
    THREAD_ERROR_CHECK(ret, "unlock");
    //互斥锁的销毁
    ret = pthread_mutex_destroy(&mutex);
    THREAD_ERROR_CHECK(ret, "destroy");
    return 0;
}

/*first lock
destroy : Device or resource busy*/