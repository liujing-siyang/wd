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
    ret = pthread_mutex_unlock(&mutex);
    THREAD_ERROR_CHECK(ret, "unlock");
    //互斥锁的销毁
    ret = pthread_mutex_destroy(&mutex);
    //可以对一把锁解锁两次，引用计数从1变成-1，不报错但不建议这么做：
    //destroy无法对引用计数为非0的锁进行销毁
    THREAD_ERROR_CHECK(ret, "destroy");
    //再次加锁
    ret = pthread_mutex_lock(&mutex);
    THREAD_ERROR_CHECK(ret, "lock");
    //再次摧毁一把锁
    ret = pthread_mutex_destroy(&mutex);
    THREAD_ERROR_CHECK(ret, "destroy2");
    return 0;
}

/*first lock
destroy : Device or resource busy*/