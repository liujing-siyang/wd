#include <func.h>
int main()
{
    char buf[40] = {0};
    char * ret = getcwd(buf,40);
    ERROR_CHECK(ret,NULL,"getcwd");
    printf("buf = %s\n", buf);
    printf("pwd = %s\n",getcwd(NULL,0));
    return 0;
}

