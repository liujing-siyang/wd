#include <iostream>

using std::cout;
using std::endl;

//标准命名空间可以进行拓展，一般不建议大家这么做
namespace  std
{
struct MyStruct
{
    int a;
};
}//end of namespace std

#if 0
//结构不能进行拓展
struct A
{
    int a;
};

struct A
{
    int b;
};
#endif

//带命名空间中的函数声明
namespace wd
{
int var = 20;
void show();

}

namespace wh
{
void print()
{
    cout << "void wh::print() " << endl;
}

void display()
{
    cout << "void wh::display() " << endl;
    wd::show();
}
}//end of namespace wh

namespace wd
{
int number = 10;

void show()
{
    cout << "void show()" << endl;
    wh::print();
}

}//end of namespace wd
int main(int argc, char **argv)
{
    cout << "wd::var = " << wd::var << endl;
    cout << "wd::number = " << wd::number << endl;
    wh::display();
    return 0;
}

