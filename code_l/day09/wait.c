#include <func.h>
int main()
{
    pid_t pid = fork();
    if(pid == 0){
        printf("I am child, pid = %d, ppid = %d\n",getpid(),getppid());
        while(1);
    }
    else{
        printf("I am parent, pid = %d, ppid = %d\n",getpid(),getppid());
        int status;
        //pid_t cpid = wait(&status);
        pid_t cpid = waitpid(pid,&status,WNOHANG);
        printf("I am parent, cpid = %d\n", cpid);
        if(WIFEXITED(status)){
            printf("child exit code = %d\n", WEXITSTATUS(status));
        }
        else if(WIFSIGNALED(status)){
            printf("child is killed by signal %d\n",WTERMSIG(status));
        }
    }
    return 0;
}

