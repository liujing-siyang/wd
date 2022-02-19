#include <func.h>
int main()
{
    int semArrid = semget(1000,1,IPC_CREAT|0600);
    ERROR_CHECK(semArrid,-1,"semget");
    int ret = semctl(semArrid,0,SETVAL,1);
    ERROR_CHECK(ret,-1,"semctl setval");
    struct sembuf P;
    P.sem_num = 0;
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
    
    p[0] = 0;//p[0]表示商品的数量
    p[1] = 6;//p[1]表示仓库空格的数量

    pid_t pid = fork();
    if(pid == 0){
        //子进程是消费者
        while(1){
            sleep(2);
            printf("I am consumer, before consume, goods = %d, space = %d\n",p[0],p[1]);
            semop(semArrid, &P, 1);
            if(p[0] > 0){
                --p[0];
                printf("Buy a goods!\n");
                ++p[1];
            }
            semop(semArrid, &V, 1);
            printf("I am consumer, after consume, goods = %d, space = %d\n",p[0],p[1]);
        }
    }
    else{
        //父进程是生产者
        while(1){
            sleep(1);
            printf("I am producer, before produce, goods = %d, space = %d\n",p[0],p[1]);
            semop(semArrid,&P,1);
            if(p[1] > 0){
                --p[1];
                printf("Produce a goods!\n");
                ++p[0];
            }
            semop(semArrid,&V,1);
            printf("I am producer, after produce, goods = %d, space = %d\n",p[0],p[1]);
        }
    }

    return 0;
}

