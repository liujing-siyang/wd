#include <func.h>
int main()
{
    int semArrid = semget(1000,2,IPC_CREAT|0600);
    ERROR_CHECK(semArrid,-1,"semget");
    return 0;
}

