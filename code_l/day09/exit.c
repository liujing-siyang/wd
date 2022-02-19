#include <func.h>
void f(){
    printf("f\n");
}
int func(){
    printf("I am func");
    _exit(123);
    //return 123;
}
int main()
{
    pid_t pid = fork();
    if(pid == 0){
        atexit(f);
        printf("I am child");
        func();
        printf("can you see me?\n");
    }
    else{
        printf("I am parent\n");
        int status;
        wait(&status);
        if(WIFEXITED(status)){
            printf("child is exit, exit code = %d\n",WEXITSTATUS(status));
        }
    }
    return 0;
}

