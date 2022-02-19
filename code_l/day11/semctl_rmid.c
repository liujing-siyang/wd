#include <func.h>
int main()
{
    int semArrid = semget(1001,2,IPC_CREAT|0600);
    ERROR_CHECK(semArrid,-1,"semget");
    semctl(semArrid,0,IPC_RMID);
    return 0;
}

