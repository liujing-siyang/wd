#include <func.h>
int main()
{
    int shmid = shmget(1000,4096,IPC_CREAT|0600);
    ERROR_CHECK(shmid,-1,"shmget");
    char *p = (char *)shmat(shmid,NULL,0);
    ERROR_CHECK(p,(char *)-1,"shmat");
    int ret = shmdt(p);
    ERROR_CHECK(ret,-1,"shmdt");
    while(1);
    return 0;
}
