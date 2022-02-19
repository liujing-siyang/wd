#include <func.h>
int DFSprint(char *path,int width);
int main(int argc, char *argv[])
{
    ARGS_CHECK(argc,2);
    DFSprint(argv[1],0);
    return 0;
}
int DFSprint(char *path,int width){
    char newPath[1024] = {0};
    DIR *pdir = opendir(path);
    ERROR_CHECK(pdir,NULL,"opendir");
    struct dirent *pdirent;
    while((pdirent = readdir(pdir))){
        if(strcmp(pdirent->d_name,".") == 0 ||
           strcmp(pdirent->d_name,"..") == 0){
            continue;
        }
        printf("%*s%s\n",width,"",pdirent->d_name);
        if(pdirent->d_type == DT_DIR){
            sprintf(newPath,"%s%s%s",path,"/",pdirent->d_name);
            DFSprint(newPath,width+4);
        }
    }
    return 0;
}
