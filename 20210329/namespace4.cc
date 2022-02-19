#include <iostream>

using std::cout;//3、using声明机制，一次只引出一个实体
using std::endl;//推荐使用

namespace wd
{
//命令空间中可以定义变量、函数、结构体、类等，统称为实体
int number = 10;

void show()
{
    cout << "void show()" << endl;
}

}//end of namespace wd

#if 0
//2、作用域限定符的形式
//优势：即使自定义的实体与命名空间中的实体冲突，也没有关系
//劣势：繁琐
int cout(int x, int y)
{
    cout << "x = " << x << ", y = " << y << endl;
    return x + y;
}
#endif

int main(int argc, char **argv)
{
    cout << "number = " << wd::number << endl;//作用域限定符
    wd::show();
    cout(2, 5);
    return 0;
}

