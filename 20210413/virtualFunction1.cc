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
//4、基类的指针指向(引用绑定)派生类对象
//5、基类的指针(引用)调用虚函数
//
class Line
{
public:
    virtual
    float distance();
};
class Base
{
    friend float Line::distance();
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

    void testprint()                                                                                                                                                    
    {
        cout << "Base void testprint()" << _base << endl;
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

    void testprint()
    {
        cout << "Derived void testprint()" << _derived << endl;
    }
    ~Derived()
    {
        cout << "~Derived()" << endl;
    }
private:
    double _derived;
};

void func(Base *pbase)//通过指针调用
{
    pbase->print();
}
void testfunc(Base *pbase)
{
    pbase->testprint();
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
//使用指针访问非虚函数时，编译器根据指针本身的类型决定要调用哪个函数，而不是根据指针指向的对 象类型；
//使用指针访问虚函数时，编译器根据指针所指对象的类型决定要调用哪个函数(动态联编)，而与指针本身 的类型无关。
    cout << endl << endl;
    func(&base);//Base *pbase = &base;           10
    func(&derived);//Base *pbase = &derived;     30
    cout << endl << endl;
    testfunc(&base);                           //10
    testfunc(&derived);                        //20
    return 0;
}

