#include <func.h>
int global = 0;
int main()
{
    int stack = 1;
    int *p = (int *)malloc(sizeof(int));
    *p = 3;
    pid_t pid = fork();
    if(pid == 0){
        printf("I am child, PID = %d, PPID = %d\n", getpid(), getppid());
        printf("stack = %d\n",stack);
        printf("global = %d\n",global);
        printf("heap = %d\n",*p);
    }
    else{
        printf("I am parent, PID = %d, PPID = %d\n", getpid(), getppid());
        printf("stack = %d\n",stack);
        printf("global = %d\n",global);
        printf("heap = %d\n",*p);
        sleep(1);
    }
    return 0;
}

