#include <iostream>

using std::cout;
using std::endl;

#if 0
int add(int x,int y)
{
    return x + y;
}
#endif
//默认参数必须从右往左连续赋初值
int add(int x = 0, int y = 0, int z = 0)
{
    return x + y + z;
}

int main(int argc, char **argv)
{
    int a = 3, b = 4, c= 5;
    /* cout << "add() = " << add() << endl; */
    cout << "add(a) = " << add(a) << endl;
    cout << "add(a, b) = " << add(a, b) << endl;
    cout << "add(a, b, c) = " << add(a, b, c) << endl;
    return 0;
}

