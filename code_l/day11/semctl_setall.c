#include <func.h>
int main()
{
    int semArrid = semget(1000,2,IPC_CREAT|0600);
    ERROR_CHECK(semArrid,-1,"semget");
    unsigned short arr[2] = {3,5};
    int ret = semctl(semArrid,0,SETALL,arr);
    ERROR_CHECK(ret,-1,"semctl setall");
    unsigned short res[2];
    ret = semctl(semArrid,0,GETALL,res);
    ERROR_CHECK(ret,-1,"semctl getall before");
    printf("-------------\n");
    for(int i = 0; i < 2; ++i){
        printf("res[%d] = %d\n", i, res[i]);
    }
    printf("-------------\n");
    struct sembuf op[2];
    op[0].sem_num = 0;
    op[0].sem_op = 2;
    op[0].sem_flg = SEM_UNDO;
    op[1].sem_num = 1;
    op[1].sem_op = -2;
    op[1].sem_flg = SEM_UNDO;
    semop(semArrid,op,2);
    ret = semctl(semArrid,0,GETALL,res);
    ERROR_CHECK(ret,-1,"semctl getall after");
    for(int i = 0; i < 2; ++i){
        printf("res[%d] = %d\n", i, res[i]);
    }
    return 0;
}

