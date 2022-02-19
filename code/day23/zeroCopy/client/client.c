#define _GNU_SOURCE
#include <head.h>

int recvCycle(int clientFd, void *buf, int totalLen);

int main(int argc, char** argv)
{
    //创建sfd描述符，用于与对端建立连接时使用
    int sfd = socket(AF_INET, SOCK_STREAM, 0);
    ERROR_CHECK(sfd, -1, "socket");
    
    struct sockaddr_in serAddr;
    memset(&serAddr, 0, sizeof(serAddr));

    serAddr.sin_family = AF_INET;
    serAddr.sin_addr.s_addr = inet_addr(argv[1]);
    serAddr.sin_port = htons(atoi(argv[2]));

    //连接服务器，把sfd与服务端的ip与端口号建立连接
    int ret = connect(sfd, (struct sockaddr*)&serAddr, sizeof(serAddr));
    ERROR_CHECK(ret, -1, "connect");

    char buf[1000] = {0};
    
    
    int dataLen = 0;
    //接收数据到buf中
    recv(sfd, &dataLen, 4, 0);
    recv(sfd, buf, dataLen, 0);
    int fd = open(buf, O_RDWR|O_CREAT, 0666);
    ERROR_CHECK(fd, -1, "open");

    struct timeval start, end;
    gettimeofday(&start, NULL);
    //fileLen用于接收传递过来的文件长度
    off_t fileLen = 0;
    recv(sfd, &dataLen, 4, 0);
    recv(sfd, &fileLen, dataLen, 0);
    printf("fileLen = %ld\n", fileLen);

    //recvLen函数用于接收此时已经接收到的所有数据
    /* off_t recvLen = 0; */

    /* while(1){ */
    /*     //循环接收数据，先接数据长度，在接收数据 */
    /*     recv(sfd, &dataLen, 4, 0); */
    /*     /1* ret = recv(sfd, buf, dataLen, MSG_WAITALL); *1/ */
    /*     ret = recvCycle(sfd, buf, dataLen); */
    /*     recvLen += ret; */

    /*     float rate = (float)recvLen / fileLen * 100; */

    /*     //打印下载进度 */
    /*     /1* printf("rate = %5.2f %%\r", rate); *1/ */
    /*     /1* //刷新缓冲区 *1/ */
    /*     /1* fflush(stdout); *1/ */

    /*     if(0 == dataLen){ */
    /*         break; */
    /*     } */
    /*     write(fd, buf, ret); */
    /* } */
    //使用mmap方式接受数据

    /* ERROR_CHECK(pMap, (char *)-1, "mmap"); */
    /* recvCycle(sfd, pMap, fileLen); */
    /* munmap(pMap, fileLen); */

    int recvLen = 0;
    int fds[2];
    pipe(fds);
    //使用splice接收数据
    while(recvLen < fileLen){
        int ret = splice(sfd, NULL, fds[1], NULL, 1024, 0);
        /* printf("ret = %d\n", ret); */
        ret = splice(fds[0], NULL, fd, NULL, ret, 0);
        recvLen += ret;
    }

    gettimeofday(&end, NULL);

    printf("cost time = %ld\n", (end.tv_sec - start.tv_sec)*1000000 + (end.tv_usec - start.tv_usec));

    printf("\n");
    close(fd);
    close(sfd);
    return 0;
}

