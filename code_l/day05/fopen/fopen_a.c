#include <func.h>
int main(int argc, char *argv[])
{
    ARGS_CHECK(argc,2);
    FILE *fp = fopen(argv[1],"a+");
    ERROR_CHECK(fp,NULL,"fopen");
    char buf[20] = {0};
    printf("pos = %ld\n",ftell(fp));
    fread(buf,1,19,fp);
    printf("pos = %ld\n",ftell(fp));
    puts(buf);
    fwrite("You are welcome",1,15,fp);
    printf("pos = %ld\n",ftell(fp));
    fseek(fp,0,SEEK_SET);
    memset(buf,0,sizeof(buf));
    fread(buf,1,19,fp);
    puts(buf);
    fwrite("You are welcome",1,15,fp);
    fclose(fp);
    return 0;
}

