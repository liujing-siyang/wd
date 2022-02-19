#include <iostream>

using std::cout;
using std::endl;

//动态多态的原理：当基类定义了虚函数，就会在基类创建的对象的
//存储布局之中产生一个虚函数指针，虚函数指针指向一张虚表（
//虚函数表），虚函数表存放的是虚函数的入口地址，当派生类继承
//基类的时候，就会吸收基类的虚函数，然后在派生类的对象的存储
//布局之中产生派生类自己的虚函数指针，然后指向派生类自己的
//虚表（虚函数表），派生类自己的虚表存放是自己的虚函数的入口
//地址，如果派生类自己重定义了该虚函数，就会用该虚函数去取代
//从基类继承过来的虚函数的入口地址，进而体现动态多态
//
//
//动态多态被激活的五个条件
//1、基类定义虚函数
//2、派生类重定义（重写、覆盖）该虚函数
//3、创建派生类对象
//4、基类的指针指向派生类对象
//5、基类的指针调用虚函数
//
class Base
{
public:
    Base(double base = 0)
    : _base(base)
    {
        cout << "Base(double = 0)" << endl;
    }

    virtual
    void print()
    {
        cout << "Base::base = " << _base << endl;
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
    Derived(double base = 0, double derived = 0)
    : Base(base)
    , _derived(derived)
    {
        cout << "Derived(double = 0)" << endl;
    }

    /* void print(); */
    //重定义的函数的返回类型必须一致
    void print()
    {
        cout << "Derived::derived = " << _derived << endl;
    }

    ~Derived()
    {
        cout << "~Derived()" << endl;
    }
private:
    double _derived;
};

void func(Base &ref)
{
    ref.print();
}

//虚函数指针（只要定义了虚函数，就会在类创建的对象的存储布局之中
//产生虚函数指针）
int main(int argc, char **argv)
{
    cout << "sizeof(Base) = " << sizeof(Base) << endl;
    cout << "sizeof(Derived) = " << sizeof(Derived) << endl;

    cout << endl;
    Base base(10);
    Derived derived(20, 30);

    cout << endl << endl;
    base.print();//不能体现动态动态
    derived.print();//不能体现动态多态，编译时已经确定

    return 0;
}

