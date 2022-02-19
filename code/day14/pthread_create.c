#include <head.h>

void* threadFunc(void *p)
{
    printf("hello main\n");
    return NULL;
}
int main(int argc, char** argv)
{
    pthread_t thid;
    int ret = 0;
    //创建子线程
    ret = pthread_create(&thid, NULL, threadFunc, NULL);
    THREAD_ERROR_CHECK(ret, "pthread_create");
    printf("hello child\n");
    //usleep1微秒，时间太短了。可能会出现，子线程的
    //printf函数正在执行的\n的时候，主线程从usleep醒来准备
    //退出的时候后发现缓冲区还有内容，那么就刷新了缓冲区，此时缓冲区就被
    //刷新了两次，所以会看到两次打印的结果
    usleep(1);
    
    return 0;
}

