#include <func.h>
struct mymsg{
    long mtype;
    char mtext[64];
};
int main()
{
    int msgid = msgget(1000,IPC_CREAT|0600);
    ERROR_CHECK(msgid,-1,"msgget");
    struct mymsg buf;
    memset(&buf,0,sizeof(buf));
    int ret = msgrcv(msgid, &buf, sizeof(buf.mtext),2,0);
    ERROR_CHECK(ret,-1,"msgrcv");
    printf("type = %ld, msg = %s\n", buf.mtype, buf.mtext);
    return 0;
}

