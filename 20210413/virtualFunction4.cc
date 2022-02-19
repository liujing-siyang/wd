#include <iostream>

using std::cout;
using std::endl;

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

    void func1()
    {
        //Base *pbase2 = &derived;
        //Base * const this = 
        this->print();//体现动态多态，使用动态联编
    }

    void func2()
    {
        Base::print();//没有体现动态多态，使用静态联编
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

int main(int argc, char **argv)
{
    cout << "sizeof(Base) = " << sizeof(Base) << endl;
    cout << "sizeof(Derived) = " << sizeof(Derived) << endl;

    cout << endl;
    Base base(10);
    Derived derived(20, 30);

    cout << endl << endl;
    Base *pbase = &base;
    pbase->func1();
    pbase->func2();

    cout << endl;
    Base *pbase2 = &derived;//基类的指针指向派生类对象
    pbase2->func1();//30,基类的指针调用虚函数
    pbase2->func2();//20


    return 0;
}

