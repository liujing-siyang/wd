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
    recv(sfd, &dataLen, 4, 0);//接收文件名的字节长度
    recv(sfd, buf, dataLen, 0);//接收文件名
    int fd = open(buf, O_RDWR|O_CREAT, 0666);
    ERROR_CHECK(fd, -1, "open");

    //fileLen用于接收传递过来的文件长度
    off_t fileLen = 0;
    recv(sfd, &dataLen, 4, 0);//文件长度数值所占的字节
    recv(sfd, &fileLen, dataLen, 0);//文件长度
    printf("fileLen = %ld\n", fileLen);

    //recvLen函数用于接收此时已经接收到的所有数据
    off_t recvLen = 0;

    while(1){
        //循环接收数据，先接数据长度，在接收数据
        recv(sfd, &dataLen, 4, 0);
        //以太网帧每次都要满1460个字节才发送吗？
        //当发送端发送的比较慢而接收方接收的比较快，而以太网帧每次发送的数据长度最大为1460个字节
        //对方第一次发送1000个字节，加上int一共1004个字节，第二次为456个字节，第三次从第二次没有接受完的位置就是457位置开始，就会将本来是数据的地方当成datalen
        //MSG_WAITALL接收完datalen字节个数据才返回，也就是第二次只接收456个字节并不会返回，而是等待第二个以太网帧的数据，凑齐1004个字节才返回
        /* ret = recv(sfd, buf, dataLen, MSG_WAITALL); */
        ret = recvCycle(sfd, buf, dataLen);
        recvLen += ret;

        float rate = (float)recvLen / fileLen * 100;

        //打印下载进度
        printf("rate = %5.2f %%\r", rate);
        //刷新缓冲区
        fflush(stdout);

        if(0 == dataLen){
            break;
        }
        write(fd, buf, ret);
    }
    printf("\n");
    close(fd);
    close(sfd);
    return 0;
}

