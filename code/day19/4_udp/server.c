#include <head.h>

int main(int argc, char** argv)
{
    //创建sfd，用于与客户端建立连接
    int sfd = socket(AF_INET, SOCK_DGRAM, 0);
    ERROR_CHECK(sfd, -1, "socket");
    struct sockaddr_in serAddr;
    memset(&serAddr, 0, sizeof(serAddr));

    serAddr.sin_family = AF_INET;
    serAddr.sin_addr.s_addr = inet_addr(argv[1]);
    serAddr.sin_port = htons(atoi(argv[2]));

    //把sfd， 与本地的端口号和ip进行绑定
    int ret = bind(sfd, (struct sockaddr*)&serAddr, sizeof(serAddr));
    ERROR_CHECK(ret, -1, "bind");
    char buf[128] = {0};

    //用于存储对端的ip和端口号
    struct sockaddr_in cliAddr;
    memset(&cliAddr, 0, sizeof(cliAddr));
    socklen_t len = sizeof(cliAddr);
    fd_set rdset;
    FD_ZERO(&rdset);
    int readyNum = 0;
    while(1){
        FD_SET(STDIN_FILENO, &rdset);
        FD_SET(sfd, &rdset);
        //select的第二个参数是传入传出参数，每次都会修改位图里面的数据
        readyNum = select(10, &rdset, NULL, NULL, NULL);
        for(int i = 0; i < readyNum; ++i){
            if(FD_ISSET(STDIN_FILENO, &rdset)){
                memset(buf, 0, sizeof(buf));
                read(STDIN_FILENO, buf, sizeof(buf));
                sendto(sfd, buf, strlen(buf)-1, 0, (struct sockaddr*)&cliAddr, len);
            }
            if(FD_ISSET(sfd, &rdset)){
                memset(buf, 0, sizeof(buf));
                ret = recvfrom(sfd, buf, sizeof(buf), 0, (struct sockaddr*)&cliAddr, &len);
                printf("buf = %s\n", buf);
                //如果recv的返回值是0，就代表对端断开连接
                /* if(0 == ret){ */
                /*     printf("bye,bye\n"); */
                /*     close(newFd); */
                /*     //把文件描述符从needMonitorSet集合中删除 */
                /*     FD_CLR(newFd, &needMointorSet); */
                /*     continue; */
                /* } */
                /* printf("buf = %s\n", buf); */
            }
        }
    }

    close(sfd);
    return 0;
}

