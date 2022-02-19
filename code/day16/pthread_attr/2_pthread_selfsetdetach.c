#include <head.h>


void* threadFunc(void* p)
{
    pthread_detach(pthread_self());
    printf("child\n");
    pthread_exit(NULL);
}
int main(int argc, char** argv)
{

    pthread_t thid;
    pthread_create(&thid, NULL, threadFunc, NULL);
    printf("main\n");

    int ret = 0;
    //此时主线程执行速度太快了，创建子线程初始时是可以被join的
    //所以子线程在运行时把自己设置为分离属性，已经晚了
    ret = pthread_join(thid, NULL);
    THREAD_ERROR_CHECK(ret, "join");

    return 0;
}

