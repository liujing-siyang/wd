#include <head.h>

void cleanFunc(void* p)
{
    printf("cleanFunc\n");
    free(p);
    p = NULL;
}
void cleanFunc2(void* p)
{
    printf("cleanFunc2\n");
    free(p);
    p = NULL;
}
void* threadFunc(void *p)
{
    char *p1 = (char*)malloc(20);
    strcpy(p1, "hello");
    char *p2 = (char*)malloc(20);
    strcpy(p2, "hello");
    pthread_cleanup_push(cleanFunc, p1);
    pthread_cleanup_push(cleanFunc2, p2);
    pthread_cleanup_pop(1);
    pthread_cleanup_pop(1);
    /* return NULL; */
    pthread_exit(NULL);
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

