#include <func.h>
int main()
{
    FILE *fp = popen("./child", "r");
    ERROR_CHECK(fp,NULL,"popen");
    char buf[128] = {0};
    fread(buf,1,sizeof(buf)-1, fp);
    printf("read from pipe = %s\n",buf);
    pclose(fp);
    return 0;
}

