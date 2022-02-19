#include <head.h>

int main(int argc, char** argv)
{
    pthread_mutexattr_t mutexattr;
    pthread_mutexattr_init(&mutexattr);
    //设置锁的属性为检错锁
    pthread_mutexattr_settype(&mutexattr, PTHREAD_MUTEX_ERRORCHECK);

    pthread_mutex_t mutex;
    //此时创建的这把锁就是一个检错锁
    pthread_mutex_init(&mutex, &mutexattr);
    
    int ret = 0;
    printf("first lock\n");
    ret = pthread_mutex_lock(&mutex);
    THREAD_ERROR_CHECK(ret, "lock1");
    printf("second lock\n");
    //检错锁可以不可以对一把锁加锁两次
    //对于检错锁如果一个锁已经被使用，同一个线程再次请求这 把锁，则返回 EDEADLK，避免死锁
    ret = pthread_mutex_lock(&mutex);
    THREAD_ERROR_CHECK(ret, "lock2");

    pthread_mutex_unlock(&mutex);

    ret = pthread_mutex_destroy(&mutex);
    THREAD_ERROR_CHECK(ret, "destroy");
    return 0;
}

/*first lock
second lock
lock2 : Resource deadlock avoided*/