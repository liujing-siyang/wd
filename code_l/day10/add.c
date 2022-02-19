#include <func.h>
int main()
{
    int shmid = shmget(1000,4096,IPC_CREAT|0600);
    ERROR_CHECK(shmid,-1,"shmget");
    int *p = (int *)shmat(shmid,NULL,0);
    ERROR_CHECK(p,(int *)-1,"shmat");
    p[0] = 0;
    pid_t pid = fork();
    if(pid == 0){
        for(int i = 0; i < 1000000; ++i){
            ++p[0];
        }
    }
    else{
        for(int i = 0; i < 1000000; ++i){
            ++p[0];
        }
        wait(NULL);
        printf("p[0] = %d\n",p[0]);
    }
    return 0;
}

