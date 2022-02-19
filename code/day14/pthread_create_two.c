#include <head.h>

void *threadFunc(void *p)
{
    //此时传递的long，是值传递
    printf("iStack = %ld\n",(long)p);
    return NULL;
}

int main(int argc, char** argv)
{
    pthread_t thid, thid1;
    int ret = 0;
    /* int iStack = 2; */
    long val = 3;
    //创建子线程
    //64位操作系统中，long和指针都占8个字节
    ret = pthread_create(&thid, NULL, threadFunc, (void*)val);
    THREAD_ERROR_CHECK(ret, "pthread_create");
    /* iStack += 2; */
    val += 3;
    //创建第二个子线程
    //两个子线程公用一个线程处理函数
    ret = pthread_create(&thid1, NULL, threadFunc, (void*)val);
    THREAD_ERROR_CHECK(ret, "pthread_create");
    sleep(1);
    return 0;
}

/*顺序不可预知
iStack = 6
iStack = 3*/