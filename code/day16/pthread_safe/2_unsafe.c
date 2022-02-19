#include <head.h>

void * threadFunc(void* p)
{
    time_t now;
    time(&now);
    char *pTime = ctime(&now);
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
    char *pTime = ctime(&now);
    printf("main pTime = %s\n", pTime);
    pthread_join(thid, NULL);
    return 0;
}

