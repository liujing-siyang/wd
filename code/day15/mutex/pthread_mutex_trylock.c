#include <head.h>

int main(int argc, char** argv)
{
    pthread_mutex_t mutex;
    int ret = 0;
    //互斥锁的初始化
    ret = pthread_mutex_init(&mutex, NULL);
    THREAD_ERROR_CHECK(ret, "init");

    /* pthread_mutex_lock(&mutex); */
    //测试加锁
    ret = pthread_mutex_trylock(&mutex);
    THREAD_ERROR_CHECK(ret, "trylock");

    pthread_mutex_unlock(&mutex);

    //互斥锁的销毁
    ret = pthread_mutex_destroy(&mutex);
    THREAD_ERROR_CHECK(ret, "destroy");
    return 0;
}

