#include <iostream>

using std::cout;
using std::endl;

//宏定义发生的时机在预处理阶段，只是进行简单的字符串替换
//如果出现bug，知道运行时候才会发现
#define multiply(x, y) x * y
#define MAX 10

void test()
{
    //发生的时机在编译阶段，如果发生错误，就会在编译时候报出来
    //内置类型：char/short/int/float/double/long/bool/void *
    const int number = 10;//const修饰的变量称为常量,定义的时候必须进行初始化
    /* number = 20;//error,不能进行赋值 */
    int const number2 = 10;
}

//函数指针      指针函数
//int (*pf)()   int * func()
//数组指针       指针数组
//int (*pArray)[]  int* pArray[]
void test2()
{
    int value1 = 10;
    int *p = &value1;
    *p = 20;
    p = nullptr;//NULL;

    cout << endl;
    int value2 = 20;
    const int *p2 = &value2;//当const位于*左边的时候，称为常量指针（pointer to const）
    /* *p2 = 222;//error,不能修改指针所指变量的值 */
    p2 = &value1;//ok,可以修改指针的指向（本身）

    cout << endl;
    int value3 = 30;
    int const *p3 = &value3;
    /* *p3 = 333;//error,不能修改指针所指变量的值 */
    p3 = &value1;//ok,可以修改指针的指向（本身）

    cout << endl;
    int value4 = 40;
    int * const p4 = &value4;//当const位于*右边的时候，称为指针常量（const pointer）
    *p4 = 444;//ok,可以修改指针所指变量的值
    /* p4 = &value1;//error,不可以修改指针的指向（本身） */

    cout << endl;
    int value5 = 50;
    const int * const p5 = &value5;//
    /* *p5 = 555;//error,不可以修改指针所指变量的值 */
    /* p5 = &value1;//error,不可以修改指针的指向（本身） */
}
int main(int argc, char **argv)
{
    test2();
    return 0;
}

