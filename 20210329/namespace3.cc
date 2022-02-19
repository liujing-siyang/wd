#include <iostream>

/* using namespace std;//1、using编译指令，一次可以将命名空间std中的实体全部引出来 */

namespace wd
{
//命令空间中可以定义变量、函数、结构体、类等，统称为实体
int number = 10;

void show()
{
    std::cout << "void show()" << std::endl;
}

}//end of namespace wd

//2、作用域限定符的形式
//优势：即使自定义的实体与命名空间中的实体冲突，也没有关系
//劣势：繁琐
int cout(int x, int y)
{
    std::cout << "x = " << x << ", y = " << y << std::endl;
    return x + y;
}
int main(int argc, char **argv)
{
    std::cout << "number = " << wd::number << std::endl;//作用域限定符
    wd::show();
    cout(2, 5);
    return 0;
}

