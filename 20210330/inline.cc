#include <iostream>

using std::cout;
using std::endl;

#define multiply(x, y) ((x) * (y))

//普通函数的调用是有开销的

//在函数调用的时候，直接用函数体去替代函数的调用
inline
int add(int x, int y)
{
    return x + y;
}

int main(int argc, char **argv)
{
    int a = 3, b = 4;
    cout << "multiply(a, b) = " << multiply(a, b) << endl;
    cout << "add(a, b) = " << add(a, b) << endl;
    return 0;
}

