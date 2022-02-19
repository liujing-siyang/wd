#include <func.h>
int main()
{
    int semArrid = semget(1001,2,IPC_CREAT|0600);
    ERROR_CHECK(semArrid,-1,"semget");
    unsigned short arr[2] = {0,6};
    int ret = semctl(semArrid,0,SETALL,arr);
    ERROR_CHECK(ret,-1,"semctl setall");
#if 0
    unsigned short res[2];
    ret = semctl(semArrid,0,GETALL,res);
    for(int i = 0; i < 2; ++i){
        printf("res[%d] = %d\n",i, res[i]);
    }
#endif
    pid_t pid = fork();
    if(pid == 0){
        //消费者
        struct sembuf consume[2];
        consume[0].sem_num = 0;//0是商品
        consume[0].sem_op = -1;//商品-1
        consume[0].sem_flg = 0;
        consume[1].sem_num = 1;//1是空格
        consume[1].sem_op = 1;//空格+1
        consume[1].sem_flg = 0;
        while(1){
            sleep(2);
            printf("I am consumer, before consume, goods = %d, space = %d\n",
                   semctl(semArrid,0,GETVAL),semctl(semArrid,1,GETVAL));
#if 1
            semop(semArrid,consume,2); //增加空格，减少商品
            printf("consume!\n");
#else
            semop(semArrid,&consume[0],1);//拿走商品
            printf("I buy a goods!\n");
            semop(semArrid,&consume[1],1);//增加空格
#endif
            printf("I am consumer, after consume, goods = %d, space = %d\n",
                   semctl(semArrid,0,GETVAL),semctl(semArrid,1,GETVAL));
        }
    }
    else{
        struct sembuf produce[2];
        produce[0].sem_num = 0;//0是商品
        produce[0].sem_op = 1;//商品+1
        produce[0].sem_flg = 0;
        produce[1].sem_num = 1;//1是空格
        produce[1].sem_op = -1;//空格-1
        produce[1].sem_flg = 0;
        while(1){
            sleep(1);
            printf("I am producer, before produce, goods = %d, space = %d\n",
                   semctl(semArrid,0,GETVAL), semctl(semArrid,1,GETVAL));
#if 1
            semop(semArrid,produce,2);
            printf("produce!\n");
#else
            semop(semArrid,&produce[1],1);
            printf("I use a space!\n");
            semop(semArrid,&produce[0],1);
#endif 
            printf("I am producer, after produce, goods = %d, space = %d\n",
                   semctl(semArrid,0,GETVAL), semctl(semArrid,1,GETVAL));
        }
    }
    return 0;
}

