#include <iostream>

using std::cout;
using std::endl;

//重载了函数调用运算符的类创建的对象称为函数对象
class FunctionObject
{
public:
    FunctionObject()
    : _cnt(0)
    {

    }
    int operator()(int x, int y)
    {
        cout << "int operator()(int ,int)" << endl;
        ++_cnt;
        return x + y;
    }

    int operator()(int x, int y, int z)
    {
        cout << "int operator()(int, int, int)" << endl;
        ++_cnt;
        return x * y * z;
    }
private:
    int _cnt;//状态
};

int add(int x, int y)
{
    static int cnt = 0;
    ++cnt;
    return x + y;
}

typedef int (*pFunction)(int, int);
int main(int argc, char **argv)
{
    int a = 3;
    int b = 4;
    FunctionObject fo;
    cout << "fo(a, b) = " << fo(a, b) << endl;
    fo.operator()(a, b);
    cout << "add(a, b) = " << add(a, b) << endl;

    FunctionObject fo1;
    cout << "fo1(a, b) = " << fo1(a, b) << endl;

    pFunction pf = add;
    pf(a, b);
    return 0;
}

