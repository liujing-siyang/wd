#include <head.h>

void cleanFunc(void* p)
{
    printf("cleanFunc\n");
    free(p);
    p = NULL;
}
void* threadFunc(void *p)
{
    char *p1 = (char*)malloc(20);
    strcpy(p1, "hello");
    pthread_cleanup_push(cleanFunc, p1);
    printf("hello main\n");
    free(p1);
    p1 = NULL;
    /* pthread_exit(NULL); */
    pthread_cleanup_pop(0);
    //return是C语言阵营的函数，使用return不会触发弹栈
    return NULL;
}
int main(int argc, char** argv)
{
    pthread_t thid;
    int ret = 0;
    //创建子线程
    ret = pthread_create(&thid, NULL, threadFunc, NULL);
    THREAD_ERROR_CHECK(ret, "pthread_create");
    /* pthread_cancel(thid); */

    pthread_join(thid, NULL);
    return 0;
}

