#include <func.h>
int main()
{
    int semArrid = semget(1000,2,IPC_CREAT|0600);
    ERROR_CHECK(semArrid,-1,"semget");
    struct semid_ds stat;
    semctl(semArrid,0,IPC_STAT,&stat);
    printf("uid = %d\n",stat.sem_perm.uid);
    printf("perm = %o\n",stat.sem_perm.mode);
    printf("nsems = %ld\n",stat.sem_nsems);
    return 0;
}

