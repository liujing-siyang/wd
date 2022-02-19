#include <func.h>
int main(int argc, char *argv[])
{
    ARGS_CHECK(argc,2);
    FILE *fp = fopen(argv[1],"r+");
    ERROR_CHECK(fp,NULL,"fopen");
    //int fd = fp->_fileno;
    int fd = fileno(fp);
    write(fd,"howareyou",9);
    fclose(fp);
    return 0;
}

