#include <head.h>

void * threadFunc(void* p)
{
    time_t now;
    time(&now);
    char buf[64] = {0};
    char *pTime = ctime_r(&now, buf);
    printf("child pTime = %s\n", pTime);
    sleep(2);
    printf("child pTime = %s\n", pTime);
    pthread_exit(NULL);

}
int main(int argc, char** argv)
{
    pthread_t thid;
    pthread_create(&thid,NULL, threadFunc,NULL);
    sleep(1);
    time_t now;
    time(&now);
    char buf[64] = {0};
    //ctime_r 安全的原因是因为，把返回来的数据存储在自己定义的buf中
    char *pTime = ctime_r(&now, buf);
    printf("main pTime = %s\n", pTime);
    pthread_join(thid, NULL);
    return 0;
}

