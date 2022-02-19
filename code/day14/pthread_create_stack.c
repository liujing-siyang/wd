#include <head.h>

void *threadFunc(void *p)
{
    printf("iStack = %d\n", *(int*)p);
    return NULL;
}
int main(int argc, char** argv)
{
    pthread_t thid;
    int ret = 0;
    int iStack = 2;

    printf("iStack = %d\n", iStack);
    //传递栈空间给子线程
    ret = pthread_create(&thid, NULL, threadFunc, &iStack);
    THREAD_ERROR_CHECK(ret, "pthread_create");
    //sleep1秒钟等待子线程完全执行
    sleep(1);
    return 0;
}

