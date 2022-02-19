#include <stdlib.h>
#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

//内存溢出？野指针？内存踩踏？
//
//malloc/free与new/delete异同点？
//相同点
//1、都是用来申请堆空间的
//2、必须成对出现，否则可能出现内存泄漏
//不同点：
//1、malloc/free是C语言的库函数，new/delete是C++的表达式
//2、malloc申请的空间是原始的，未初始化的，new申请的堆空间是初始化
void test()
{
    int *pInt = (int *)malloc(sizeof(int));//1、申请堆空间
    memset(pInt, 0, sizeof(int));//2、清零（初始化）
    *pInt = 10;//3、赋值
    printf("pInt本身：%p\n", &pInt);
    printf("pInt所指空间：%p\n", pInt);

    free(pInt);//4、回收堆空间
    pInt = nullptr;

    int *pArray = (int *)malloc(sizeof(int) * 10);//1、申请堆空间
    memset(pInt, 0, sizeof(int) * 10);//2、清零（初始化）
    pArray[0] = 10;

    free(pArray);
}

void test2()
{
    int *pInt = new int(10);//1、申请空间，并初始化，还可以赋值

    delete pInt;//2、释放堆空间
    pInt = nullptr;

    int *pArray= new int[20]();//1、申请空间，并初始化

    delete [] pArray;//2、释放堆空间
    pArray = nullptr;
}
int main(int argc, char **argv)
{
    test();
    return 0;
}

