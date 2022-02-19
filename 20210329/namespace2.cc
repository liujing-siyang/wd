#include <iostream>

using namespace std;//1、using编译指令，一次可以将命名空间std中的实体全部引出来

namespace wd
{
//命令空间中可以定义变量、函数、结构体、类等，统称为实体
int number = 10;

void show()
{
    cout << "void show()" << endl;
}

}//end of namespace wd

int cout()
{
    return 10;
}
int main(int argc, char **argv)
{
    cout << "number = " << wd::number << endl;//作用域限定符
    wd::show();
    cout();
    return 0;
}

