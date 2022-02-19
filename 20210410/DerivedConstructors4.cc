#include <iostream>

using std::cout;
using std::endl;

class Test
{
public:
    Test()
    {
        cout << "Test()" << endl;
    }

    ~Test()
    {
        cout << "~Test()" << endl;
    }
};
class Base
{
public:
#if 0
    Base()
    : _base(0)
    {
        cout << "Base()" << endl;
    }
#endif

    Base(double base)
    : _base(base)
    {
        cout << "Base(double)" << endl;
    }

    ~Base()
    {
        cout << "~Base()" << endl;
    }
private:
    double _base;
};

class Derived
: public Base
{
public:
    Derived()
    : Base(0)
    , _derived(0)
    {
        cout << "Derived()" << endl;
    }
    
    Derived(double derived)
    : Base(derived)
    , _tst()
    , _derived(derived)
    {
        cout << "Derived(double)" << endl;
    }

    ~Derived()
    {
        cout << "~Derived()" << endl;
    }
private:
    double _derived;
    Test _tst;
};
int main(int argc, char **argv)
{
    //error,"在创建派生类对象的时候，先调用基类构造函数，在调用派生类构造函数"
    //ok，创建派生类对象的时候，会调用派生类的构造函数，为了完成从基类吸收数据成员
    //的初始化，所以会调用基类构造函数，然后再调用派生类构造函数的函数体
    Derived d1(10);
    return 0;
}

