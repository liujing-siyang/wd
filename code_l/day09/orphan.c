#include <func.h>
int main()
{
    pid_t pid = fork();
    if(pid == 0){
        sleep(1);
        printf("I am child, pid = %d, ppid = %d\n",getpid(),getppid());
    }
    else{
        printf("I am parent, pid = %d, ppid = %d\n",getpid(),getppid());
    }
    return 0;
}

