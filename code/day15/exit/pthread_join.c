#include <head.h>

void* threadFunc(void* p)
{
    /* char *p1 = (char*)malloc(10); */
    /* strcpy(p1, "hello"); */
    //传出指向10个自己堆空间指针
    while(1);
    long val = 3;
    pthread_exit((void*)val);
}
int main(int argc, char** argv)
{
    pthread_t thid;
    int ret = 0;
    ret = pthread_create(&thid, NULL, threadFunc, NULL);
    printf("thid  = %ld\n", thid);
    //用于接收子线程的退出值
    /* char *retVal = NULL; */
    long retVal = 0;
    //pthread_join等待子线程的退出，并且可以接收子线程的退出码
    //它是一个阻塞性函数，会一直等待子线程的退出
    pthread_join(thid, (void**)&retVal);
    printf("retVal = %ld\n", retVal);
    return 0;
}

