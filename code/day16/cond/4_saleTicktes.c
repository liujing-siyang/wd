#include <head.h>

typedef  struct {
    int num;
    pthread_cond_t cond;
    pthread_mutex_t mutex;
}Data_t;

void* saleWin1(void* p)
{
    Data_t *pData = (Data_t *)p;
    while(1){
        pthread_mutex_lock(&pData->mutex);
        //如果票数不为零， 卖票
        if(0 != pData->num){
            pData->num--;
            printf("win1 sale a ticket\n");
            //如果自己卖光了票，就通知放票线程放票；
            if(0 == pData->num){
                pthread_cond_signal(&pData->cond);
            }
        }
        //如果是别的窗口卖光的，也通知放票线程放票
        else{
            pthread_cond_signal(&pData->cond);
        }
        pthread_mutex_unlock(&pData->mutex);
        /* usleep(10); */
    }
    pthread_exit(NULL);
}
void* saleWin2(void* p)
{
    Data_t *pData = (Data_t *)p;
    while(1){
        pthread_mutex_lock(&pData->mutex);
        //如果票数不为零， 卖票
        if(0 != pData->num){
            pData->num--;
            printf("win2 sale a ticket\n");
            //如果自己卖光了票，就通知放票线程放票；
            if(0 == pData->num){
                pthread_cond_signal(&pData->cond);
            }
        }
        //如果是别的窗口卖光的，也通知放票线程放票
        else{
            pthread_cond_signal(&pData->cond);
        }
        pthread_mutex_unlock(&pData->mutex);
        /* usleep(10); */
    }
    pthread_exit(NULL);
}

void* setTicket(void* p)
{
    Data_t *pData = (Data_t *)p;
    pthread_mutex_lock(&pData->mutex);
    if(0 != pData->num){
        pthread_cond_wait(&pData->cond, &pData->mutex);
    }
    pData->num = 10;
    printf("set tickets\n");
    pthread_mutex_unlock(&pData->mutex);
    pthread_exit(NULL);

}
int main(int argc, char** argv)
{
    Data_t data;
    data.num = 0;
    pthread_cond_init(&data.cond, NULL);
    pthread_mutex_init(&data.mutex, NULL);
    pthread_t thid1, thid2, thid3;
    pthread_create(&thid1, NULL, saleWin1, &data);
    pthread_create(&thid2, NULL, saleWin2, &data);
    pthread_create(&thid3, NULL, setTicket, &data);

    pthread_join(thid1, NULL);
    pthread_join(thid2, NULL);
    pthread_join(thid3, NULL);

    pthread_mutex_destroy(&data.mutex);
    pthread_cond_destroy(&data.cond);
    return 0;
}

