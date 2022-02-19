#include <func.h>
int main()
{
    pid_t pid = fork();
    if(pid == 0){
        printf("child, pid = %d, ppid = %d, pgid = %d\n",
               getpid(),getppid(),getpgrp());
        setpgid(0,0);
        while(1);
    }
    else{
        printf("parent, pid = %d, ppid = %d, pgid = %d\n",
               getpid(),getppid(),getpgid(0));
        while(1);
        wait(NULL); 
    }
    return 0;
}

