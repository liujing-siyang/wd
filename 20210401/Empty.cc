#include <iostream>

using std::cout;
using std::endl;

class Empty
{
//默认有四个函数：
//无参构造函数、
//拷贝构造函数、
//赋值运算符函数
//析构函数
};
int main(int argc, char **argv)
{
    //空类占一个字节大小空间，一个字节是为了区分不同对象的
    cout << "sizeof(Empty) = " << sizeof(Empty) << endl;

    Empty ex;
    Empty ey;
    printf("ex : %p\n", &ex);
    printf("ey : %p\n", &ey);

    return 0;
}

