#include <head.h>

void* threadFunc(void *p)
{
    char *p1 = (char*)malloc(10);
    strcpy(p1, "hello");
    //printf是一个取消点, 子线程收到cancel信号后，执行至取消点退出
    printf("i am child thread\n");
    printf("hello\n");
    free(p1);
    p1 = NULL;
    pthread_exit(NULL);
}
int main(int argc, char** argv)
{
    pthread_t thid;
    int ret  = 0;
    ret = pthread_create(&thid, NULL, threadFunc, NULL);

    printf("i am main thread\n");
    //向子线程发送cancel信号
    pthread_cancel(thid);

    pthread_join(thid, NULL);
    return 0;
}

/*i am main thread
i am child thread
hello //可能会执行
*/