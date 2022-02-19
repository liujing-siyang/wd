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
    buf.mtype = 1;//chat
    strcpy(buf.mtext, "hello");
    int ret = msgsnd(msgid, &buf,5,0);
    ERROR_CHECK(ret,-1,"msgsnd");
    buf.mtype = 2;
    time_t now;
    time(&now);
    strcpy(buf.mtext,ctime(&now));
    msgsnd(msgid,&buf,strlen(buf.mtext),0);
    return 0;
}

