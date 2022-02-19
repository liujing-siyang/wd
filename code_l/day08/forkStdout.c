#include <func.h>
int main()
{
    printf("hello\n");
    pid_t pid = fork();
    if(pid == 0){
        printf("world\n");
    }
    else
    {
        printf("world\n");
    }
    return 0;
}

