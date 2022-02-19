#include <func.h>
int main()
{
    int semArrid = semget(1000,1,IPC_CREAT|0600);
    ERROR_CHECK(semArrid,-1,"semget");
    int ret = semctl(semArrid,0,SETVAL,1);
    ERROR_CHECK(ret,-1,"semctl");
    struct sembuf P;
    P.sem_num = 0; //下标是0
    P.sem_op = -1;
    P.sem_flg = SEM_UNDO;
    struct sembuf V;
    V.sem_num = 0;
    V.sem_op = 1;
    V.sem_flg = SEM_UNDO;
    int shmid = shmget(1000,4096,IPC_CREAT|0600);
    ERROR_CHECK(shmid,-1,"shmget");
    int *p = (int *)shmat(shmid,NULL,0);
    ERROR_CHECK(p,(int *)-1,"shmat");
    p[0] = 0;
    pid_t pid = fork();
    if(pid == 0){
        for(int i = 0; i < 1000000; ++i){
            semop(semArrid,&P,1);
            ++p[0];
            semop(semArrid,&V,1);
        }
    }
    else{
        for(int i = 0; i < 1000000; ++i){
            semop(semArrid,&P,1);
            ++p[0];
            semop(semArrid,&V,1);
        }
        wait(NULL);
        printf("p[0] = %d\n",p[0]);
    }
    return 0;
}

