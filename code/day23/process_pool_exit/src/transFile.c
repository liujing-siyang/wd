#include "process_pool.h"

#define FILE "file"

void sigFunc(int sigNum)
{
    printf("%d is comming\n", sigNum);
}
int transFile(int clientFd)
{
    signal(SIGPIPE, sigFunc);
    //私有协议，把发送的数据进行分隔
    train_t train;
    memset(&train, 0, sizeof(train));
    train.dataLen = strlen(FILE);
    strcpy(train.buf, FILE);

    int fd = open(FILE, O_RDWR);
    ERROR_CHECK(fd, -1, "open");

    send(clientFd, &train, 4 + train.dataLen, 0);

    //该结构体内存储文件的相关信息
    struct stat fileInfo;
    bzero(&fileInfo, sizeof(fileInfo));

    //使用fstat函数获取文件的相关信息
    fstat(fd, &fileInfo);
    train.dataLen = sizeof(fileInfo.st_size);
    memcpy(train.buf, &fileInfo.st_size, train.dataLen);

    //传输文件长度到客户端
    send(clientFd, &train, 4 + train.dataLen, 0);
    printf("filesize = %ld\n", fileInfo.st_size);

    /* int sum = 0; */
    /* while(1){ */
    /*     //循环读取数据到train.buf中 */
    /*     train.dataLen = read(fd, train.buf, sizeof(train.buf)); */
    /*     //循环发送数据到发送缓冲区，如果对端断开，send先返回-1， 再次send，会收到 */
    /*     //系统发送的SIGPIPE信号 */
    /*     int ret = send(clientFd, &train, 4 + train.dataLen, 0); */
    /*     sum += (train.dataLen); */
    /*     if(-1 == ret){ */
    /*         break; */
    /*     } */
    
    /*     //如果发送的数据字节数为0，那么就退出 */
    /*     if(0 == train.dataLen){ */
    /*         printf("sum = %d\n", sum); */
    /*         break; */
    /*     } */
    /* } */

    //mmap零拷贝方式传输数据
    /* char *pMap = (char *)mmap(NULL, fileInfo.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0); */
    /* ERROR_CHECK(pMap, (char *)-1, "mmap"); */
    /* send(clientFd, pMap, fileInfo.st_size, 0); */

    /* munmap(pMap, fileInfo.st_size); */

    //sendfile零拷贝传输文件
    sendfile(clientFd, fd, 0, fileInfo.st_size);  
    close(fd);
    close(clientFd);
    return 0;
}
