#include <stdio.h>
#include <iostream>

using std::cout;//3、using声明机制，一次只引出一个实体
using std::endl;//推荐使用

int number = 1;

namespace wd
{
int number = 10;

void show(int number)
{
    cout << "形参number = " << number << endl;
    cout << "wd的空间的number = " << wd::number << endl;
    cout << "全局变量number = " << ::number << endl;//匿名命名空间
    printf("hello world\n");
    ::printf("hello world\n");
}

namespace hb
{
int number = 30;

void print()
{
    cout << "void wd::hb::print()" << endl;
}
}//end of namespace hb

}//end of namespace wd


int main(int argc, char **argv)
{
    cout << "number = " << wd::number << endl;//作用域限定符
    wd::show(12);
    wd::hb::print();

    return 0;
}

