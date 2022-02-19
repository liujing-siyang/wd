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

    void show() const
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
        cout << "Derived(double = 0, double  = 0)" << endl;
    }

    void print() const
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

void test()
{
    cout << "sizeof(Base) = " << sizeof(Base) << endl;
    cout << "sizeof(Derived) = " << sizeof(Derived) << endl;

    Base base(11.11);
    base.show();
    Derived derived(22.22, 33.33);
    derived.print();

    cout << endl << "派生类对象向基类进行转化" << endl;
    base = derived;//1、可以将派生类对象赋值给基类对象
    base.operator=(derived);//Base &operator=(const Base &rhs)==>const Base &rhs = derived;
    base.show();

    cout << endl;
    Base &ref = derived;//2、基类的引用可以绑定到派生类对象上
    ref.show();

    Base *pbase1 = &derived;
    pbase1->show();//3、基类的指针可以指向派生类对象(向上转型)
#if 0
    cout << endl << "基类对象向派生对象进行转化"  << endl;
    Base base2(11.11);
    Derived derived2(22.22, 33.33);
    derived2 = base2;//error,1、不能把基类对象赋值给派生对象
    derived2.operator=(base2);//Derived &operator=(const Derived &rhs) ==> const  Derived &rhs = base2;

    Derived &ref2 = base2;//2、error，不能将派生类的引用绑定到基类的对象上来

    Derived2 *p1 = &base2;//error, 3、不能将派生类的指针指向基类对象
#endif
    /* Derived *pderived2 = &base; */
    Derived *pderived2 = static_cast<Derived *>(&base);//向下转型（不安全）

    Base *pbase3 = &derived;
    Derived *pderived3 = static_cast<Derived *>(pbase3);//向下转型（安全的）
}
int main(int argc, char **argv)
{
    test();
    return 0;
}

