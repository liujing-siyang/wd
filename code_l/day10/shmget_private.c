#include <func.h>
int main()
{
    int shmid = shmget(IPC_PRIVATE,4096,IPC_CREAT|0600);
    ERROR_CHECK(shmid,-1,"shmget");
    char * p = (char *)shmat(shmid,NULL,0);
    pid_t pid = fork();
    if(pid == 0){
        strcpy(p,"Iamchild");
    }
    else{
        wait(NULL);
        puts(p);
        shmctl(shmid,IPC_RMID,NULL);
    }
    return 0;
}

