#include <iostream>

using std::cout;
using std::endl;

//引用和指针的异同点？
void test()
{
    int number = 20;
    int &ref = number;//引用是变量的别名,引用的提出就是为了减少指针的使用
    cout << "number = " << number << endl;
    cout << "ref = " << ref << endl;
    printf("number's address : %p\n", &number);
    printf("ref's address : %p\n", &ref);

    cout << endl;
    int number2 = 100;
    ref = number2;//操作引用与操作变量本身是一样的
    cout << "number2 = " << number2 << endl;
    cout << "number = " << number << endl;
    cout << "ref = " << ref << endl;
    printf("number2's address : %p\n", &number2);
    printf("number's address : %p\n", &number);
    printf("ref's address : %p\n", &ref);

    //引用的实质就是一个指针,指针常量
    /* int &ref2;//引用不能单独存在，在定义的时候必须要进行初始化，引用一经绑定就不能 */
             //改变引用的指向
}

//1、引用作为函数参数
#if 0
//参数在传递的时候，进行值拷贝
void swap(int x, int y)//int x = a, int y = b
{
    int tmp = x;
    x = y;
    y = tmp;
}
#endif
#if 0
//值传递==>地址值
void swap(int *px, int *py)//int *px = &a, int *py = &b;
{
    int tmp = *px;
    *px = *py;
    *py = tmp;
}
#endif


void swap(int &x, int &y)//int &x = a, int &y = b;
{
    int tmp = x;
    x = y;
    y = tmp;
}

void test2()
{
    int a = 3, b = 4;
    cout << "交换之前a = " << a << ", b = " << b << endl;
    swap(a, b);
    cout << "交换之后a = " << a << ", b = " << b << endl;
}

int func()
{
    int number = 10;
    return number;//在执行return时候有拷贝操作
}
//2、引用作为函数的返回类型
//前提：实体的生命周期一定要大于函数的生命周期
int arr[10] = {1, 3, 5, 7, 9, 12};
int &getIndex(int idx)
{
    return arr[idx];//先不考虑越界的问题
}

void test3()
{
    cout << "getIndex(1) = " << getIndex(1) << endl;
    getIndex(1) = 100;
    cout << "getIndex(1) = " << getIndex(1) << endl;
    cout << "arr[1] = " << arr[1] << endl;
}

//不能返回局部变量的引用
int &func2()
{
    int number = 10;
    return number;
}

//可以返回堆空间的引用，不建议这么做，除非有自动内存回收的机制
int &getHeapData()
{
    int *pInt = new int(200);

    return *pInt;
}

void test4()
{
    int a = 3, b = 4;
    int c = a + getHeapData() + b;//内存泄漏
    cout << "c = " << c << endl;

    int &ref = getHeapData();
    delete &ref;
}
int main(int argc, char **argv)
{
    test4();
    return 0;
}

