#include <head.h>

int main(int argc, char** argv)
{
    //gethostbyname函数会根据网站的域名转换成相应信息存储到hostent结构体中
    struct hostent* pHost = gethostbyname(argv[1]);
    if(NULL == pHost){
        return -1;
    }

    //打印主机正式名
    printf("hostname = %s\n", pHost->h_name);
    //循环打印主机的别名
    for(int i = 0; pHost->h_aliases[i] != NULL; ++i){
        printf("aliases = %s\n", pHost->h_aliases[i]);
    }

    //打印主机ip地址类型
    printf("addrtype = %d\n", pHost->h_addrtype);
    //打印ip地址长度
    printf("len = %d\n", pHost->h_length);

    //循环的打印主机ip地址
    char buf[128] = {0};
    for(int i = 0; pHost->h_addr_list[i] != NULL; ++i){
        memset(buf, 0, sizeof(buf));
        printf("addr = %s\n", inet_ntop(pHost->h_addrtype, pHost->h_addr_list[i], buf, sizeof(buf)));
    }
    return 0;
}

