#include <func.h>
int main()
{
    pid_t pid = fork();
    if(pid == 0){
        printf("I am child. I quit\n");
        return 0;
    }
    else{
        printf("I am parent. I am busy\n");
        while(1);
    }
    return 0;
}

