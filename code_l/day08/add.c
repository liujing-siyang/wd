#include <func.h>
int main(int argc, char *argv[])
{
    // ./add 1 2
    ARGS_CHECK(argc,3);
    int i1 = atoi(argv[1]);
    int i2 = atoi(argv[2]);
    printf("%d + %d = %d\n", i1,i2,i1+i2);
    return 0;
}

