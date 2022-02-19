#include <func.h>
int main()
{
    pid_t pid = fork();
    if(pid == 0){
        printf("child, pid = %d, ppid = %d, pgid = %d\n",
               getpid(),getppid(),getpgrp());
        setpgid(0,0);
    }
    else{
        printf("parent, pid = %d, ppid = %d, pgid = %d\n",
               getpid(),getppid(),getpgid(0));
        pid_t ret = setsid();
        ERROR_CHECK(ret,-1,"setsid");
        wait(NULL); 
    }
    return 0;
}

