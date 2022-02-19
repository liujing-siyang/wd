#include <func.h>
int main(int argc, char *argv[])
{
    ARGS_CHECK(argc,2);
    int ret = mkdir(argv[1],0777);
    //实际的权限会受到umask的影响
    ERROR_CHECK(ret,-1,"mkdir");
    return 0;
}

