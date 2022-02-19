#include <head.h>

void* threadFunc(void* p)
{
    printf("child\n");
    pthread_exit(NULL);
}
int main(int argc, char** argv)
{
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    //设置线程属性为分离状态，分离状态的子线程是不可以被join的
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    pthread_t thid;
    pthread_create(&thid, &attr, threadFunc, NULL);
    printf("main\n");
    int ret = 0;
    //join发现它等待的线程是不可以被join的，所以直接返回，这样子线程
    //是没有的到执行的
    ret = pthread_join(thid, NULL);
    THREAD_ERROR_CHECK(ret, "join");
    return 0;
}

