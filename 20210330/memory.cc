#include <iostream>

using std::cout;
using std::endl;

int a;//全局变量,默认初值为0
char *p1;//全局变量
const int kMax = 10;

int main(int argc, char **argv)
{
    const int kMin = 1;
    int b;//栈,默认值为随机值
    char *p2;//栈
    char str1[] = "hello";
    static int cx = 10;//静态变量，位于全局静态区
    const char *pstr = "helloworld";//pstr本身位于栈区，指向的字符串常量位于文字常量区

    int *pInt = new int(10);//pInt本身位于栈区，指向的空间位于堆区

    printf("\n打印变量的地址\n");
    printf("&a = %p\n", &a);
    printf("&p1 = %p\n", &p1);
    printf("p1 = %p\n", p1);
    printf("&b = %p\n", &b);
    printf("&p2 = %p\n", &p2);
    printf("p2 = %p\n", p2);
    printf("&str1 = %p\n", &str1);
    printf("str1 = %p\n", str1);
    printf("&cx = %p\n", &cx);
    printf("&pstr = %p\n", &pstr);
    printf("pstr = %p\n", pstr);
    printf("helloworld = %p\n", &"helloworld");
    printf("&pInt = %p\n", &pInt);
    printf("pInt = %p\n", pInt);
    printf("&main = %p\n", &main);//程序代码区
    printf("main = %p\n", main);
    printf("&kMax = %p\n", &kMax);
    printf("&kMin = %p\n", &kMin);

    printf("\n打印变量的值\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    return 0;
}

