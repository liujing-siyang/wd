#include <head.h>

void *threadFunc(void *p1)
{
    printf("p = %s\n", (char*)p1);
    //子线程对堆空间进行修改
    strcpy((char*)p1, "nihao");
    return NULL;
}
int main(int argc, char** argv)
{
    pthread_t thid;
    int ret = 0;
    //创建20个字节的堆空间
    char *p = (char*)malloc(20);
    strcpy(p, "hello");
    //向子线程传入堆空间内容
    ret = pthread_create(&thid, NULL, threadFunc, p);
    //睡眠一秒钟，等待子线程执行完成
    sleep(1);
    printf("p = %s\n", p);
    return 0;
}

