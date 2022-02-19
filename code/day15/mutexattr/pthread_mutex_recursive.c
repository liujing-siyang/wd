#include <head.h>

int main(int argc, char** argv)
{
    pthread_mutexattr_t mutexattr;
    pthread_mutexattr_init(&mutexattr);
    //设置锁的属性为嵌套锁
    pthread_mutexattr_settype(&mutexattr, PTHREAD_MUTEX_RECURSIVE);

    pthread_mutex_t mutex;
    //此时创建的这把锁就是一个嵌套锁
    pthread_mutex_init(&mutex, &mutexattr);

    printf("first lock\n");
    pthread_mutex_lock(&mutex);
    printf("second lock\n");
    //嵌套锁可以对一把锁加锁两次
    pthread_mutex_lock(&mutex);

    pthread_mutex_unlock(&mutex);
    pthread_mutex_unlock(&mutex);

    int ret = pthread_mutex_destroy(&mutex);
    THREAD_ERROR_CHECK(ret, "destroy");
    return 0;
}

