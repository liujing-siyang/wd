#include <func.h>
int main(int argc, char *argv[])
{
    ARGS_CHECK(argc,2);
    DIR *pdir = opendir(argv[1]);
    ERROR_CHECK(pdir,NULL,"opendir");
    chdir(argv[1]);//一定要记住改变当前工作目录
    struct dirent *pdirent;
    while((pdirent = readdir(pdir))){
        struct stat statbuf;
        int ret = stat(pdirent->d_name,&statbuf);
        ERROR_CHECK(ret,-1,"stat");
        printf("%6o %ld %s %s %10ld %12s %s",
               statbuf.st_mode,
               statbuf.st_nlink,
               getpwuid(statbuf.st_uid)->pw_name,
               getgrgid(statbuf.st_gid)->gr_name,
               statbuf.st_size,
               pdirent->d_name,
               ctime(&statbuf.st_mtime));
    }
    closedir(pdir);
    return 0;
}

