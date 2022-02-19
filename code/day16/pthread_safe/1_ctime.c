#include <head.h>

int main(int argc, char** argv)
{
    time_t now;
    time(&now);
    char *pTime = ctime(&now);
    printf("pTime = %s\n", pTime);
    sleep(2);
    printf("pTime = %s\n", pTime);
    return 0;
}

