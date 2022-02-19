#include <iostream>

using std::cout;
using std::endl;

class Base
{
public:
    Base(long base = 0)
    : _base(base)
    {
        cout << "Base(long = 0)" << endl;
    }

    virtual 
    void f()
    {
        cout << "void Base::f()" << endl;
    }

    virtual 
    void g()
    {
        cout << "void Base::g()" << endl;
    }

    virtual 
    void h()
    {
        cout << "void Base::h()" << endl;
    }

    ~Base()
    {
        cout << "~Base()" << endl;
    }
private:
    long _base;
};

class Derived
: public Base
{
public:
    Derived(long base = 0, long derived = 0)
    : Base(base)
     , _derived(derived)
    {
        cout << "Derived(long = 0, long = 0 )" << endl;
    }

    virtual 
    void f()
    {
        cout << "void Derived::f()" << endl;
    }

    virtual 
    void g()
    {
        cout << "void Derived::g()" << endl;
    }

    virtual 
    void h()
    {
        cout << "void Derived::h()" << endl;
    }

    ~Derived()
    {
        cout << "~Derived()" << endl;
    }
private:
    long _derived;
};

void test()
{
    //虚表只有一张，位于只读段
    Derived derived1(10, 20);
    printf("derived1对象的地址: %p\n", &derived1);
    printf("derived1对象的地址: %p\n", (long *)&derived1);
    printf("虚表的地址: %p\n", (long *)*(long *)&derived1);
    printf("虚函数的地址: %p\n", (long *) * (long *)*(long *)&derived1);


    cout << endl;
    typedef void (*pFunction)(void);//函数的类型
    pFunction tmp  = (pFunction)*((long *)*(long *)&derived1);
    tmp();
    printf("虚函数的地址： %p\n", tmp);

    tmp  = (pFunction)*((long *)*(long *)&derived1 + 1);
    tmp();
    printf("第二个虚函数的地址： %p\n", tmp);

    tmp  = (pFunction)*((long *)*(long *)&derived1 + 2);
    tmp();
    printf("第三个虚函数的地址： %p\n", tmp);


    cout << endl << endl;
    Derived derived2(10, 20);
    printf("derived2对象的地址: %p\n", &derived2);
    printf("derived2对象的地址: %p\n", (long *)&derived2);
    printf("虚表的地址: %p\n", (long *)*(long *)&derived2);
    printf("虚函数的地址: %p\n", (long *) * (long *)*(long *)&derived2);

    cout << endl;
    cout << "_base = " << *((long *)&derived1 + 1) << endl;
    cout << "_derived = " << *((long *)&derived1 + 2) << endl;
}
int main(int argc, char **argv)
{
    test();
    return 0;
}

