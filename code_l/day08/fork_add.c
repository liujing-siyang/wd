#include <func.h>
int main()
{
    pid_t pid = fork();
    if(pid == 0){
        printf("I am child!\n");
        //execl("./add","./add","1","2",NULL);
        char *const argv[] = {"./add","3","4", NULL};
        execvp("add",argv);
        printf("You can't see me!\n");
    }
    else{
        printf("I am parent!\n");
        printf("You can see me!\n");
        sleep(1);
    }
    return 0;
}

