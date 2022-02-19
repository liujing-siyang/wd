#include <iostream>

using namespace std;

namespace wd
{
//命令空间中可以定义变量、函数、结构体、类等，统称为实体
int number = 10;

void show()
{
    cout << "void show()" << endl;
}

}//end of namespace wd

int main(int argc, char **argv)
{
    cout << "number = " << wd::number << endl;//作用域限定符
    wd::show();
    return 0;
}

