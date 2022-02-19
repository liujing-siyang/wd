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
    train.dataLen = strlen(FILE);//文件名长度
    strcpy(train.buf, FILE);//拷贝文件名

    int fd = open(FILE, O_RDWR);
    ERROR_CHECK(fd, -1, "open");

    send(clientFd, &train, 4 + train.dataLen, 0);//发送文件名信息

    //该结构体内存储文件的相关信息
    struct stat fileInfo;
    bzero(&fileInfo, sizeof(fileInfo));

    //使用fstat函数获取文件的相关信息
    fstat(fd, &fileInfo);
    train.dataLen = sizeof(fileInfo.st_size);//文件长度所占字节数
    memcpy(train.buf, &fileInfo.st_size, train.dataLen);//拷贝文件长度的数值

    //传输文件长度到客户端
    send(clientFd, &train, 4 + train.dataLen, 0);
    printf("filesize = %ld\n", fileInfo.st_size);

    int sum = 0;
    while(1){
        //循环读取数据到train.buf中
        train.dataLen = read(fd, train.buf, sizeof(train.buf));
        //循环发送数据到发送缓冲区，如果对端断开，send先返回-1， 再次send，会收到
        //系统发送的SIGPIPE信号
        int ret = send(clientFd, &train, 4 + train.dataLen, 0);
        sum += (train.dataLen);
        if(-1 == ret){
            break;//对端断开连接，就不再发送数据
        }
    
        //如果发送的数据字节数为0，那么就退出
        if(0 == train.dataLen){
            printf("sum = %d\n", sum);
            break;
        }
    }
    close(fd);
    close(clientFd);
    return 0;
}
