#include <func.h>
int main()
{
    int shmid = shmget(1000,4096,0600|IPC_CREAT);
    ERROR_CHECK(shmid,-1,"shmget");
    struct shmid_ds stat;
    int ret = shmctl(shmid,IPC_STAT,&stat);
    ERROR_CHECK(ret,-1,"shmctl");
    printf("cuid = %d\n",stat.shm_perm.cuid);
    printf("perm = %o\n",stat.shm_perm.mode);
    printf("size = %ld\n",stat.shm_segsz);
    printf("nattach = %ld\n",stat.shm_nattch);
    return 0;
}

