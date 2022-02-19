#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;

void func()
{
    cout << "void func()" << endl;
}
int main(int argc, char **argv)
{
    cout << "begin ..." << endl;
    atexit(func);//atexit注册函数func，当进程结束后执行注册的func函数
    atexit(func);
    atexit(func);
    atexit(func);
    atexit(func);
    cout << "end ..." << endl;

    return 0;
}

