#include <func.h>
int main(int argc, char *argv[])
{
    ARGS_CHECK(argc,2);
    DIR *pdir = opendir(argv[1]);
    ERROR_CHECK(pdir,NULL,"opendir");
    struct dirent *pdirent;
    long pos;
    while((pdirent = readdir(pdir))){
        printf("ino = %ld, reclen = %d,"
               "type = %d, name = %s\n",
               pdirent->d_ino,
               pdirent->d_reclen,
               pdirent->d_type,
               pdirent->d_name
              );
        if(strcmp(pdirent->d_name,"dir1") == 0){
            pos = telldir(pdir);
            printf("pos = %ld\n", pos);
        }
    }
    seekdir(pdir,pos);
    printf("-----------------------------\n");
    pdirent = readdir(pdir);
    printf("ino = %ld, reclen = %d,"
           "type = %d, name = %s\n",
           pdirent->d_ino,
           pdirent->d_reclen,
           pdirent->d_type,
           pdirent->d_name
          );
    closedir(pdir);
    return 0;
}

