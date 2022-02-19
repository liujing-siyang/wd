#include <iostream>

using std::cout;
using std::endl;

class A
{
public:
    A()
    {
        cout << "A()" << endl;
    }

    void setX(double dx)
    {
        _dx = dx;
    }

    void show() const
    {
        cout << "void A::dx = " << _dx  << endl;
    }

    ~A()
    {
        cout << "~A()" << endl;
    }

private:
    double _dx;
};

//虚基指针
class B
: virtual public A
{
public:
    B()
    {
        cout << "B()" << endl;
    }
};

class C
: virtual public A
{
public:
    C()
    {
        cout << "C()" << endl;
    }

};

class D
: public B
, public C
{
public:
    D()
    {
        cout << "D()" << endl;
    }

    ~D()
    {
        cout << "~D()" << endl;
    }
    /* double _dx;//B */
    /* double _dx;//C */

};
int main(int argc, char **argv)
{
    cout << "sizeof(A) = " << sizeof(A) << endl;
    cout << "sizeof(B) = " << sizeof(B) << endl;
    cout << "sizeof(C) = " << sizeof(C) << endl;
    cout << "sizeof(D) = " << sizeof(D) << endl;

    //多基继承的问题2：存储二义性
    //解决方案：在B与C继承A的时候，继承方式改为虚拟继承（virtual）
    D d;
    d.A::setX(1);
    d.A::show();

    d.B::setX(10);
    d.B::show();

    d.C::setX(20);
    d.C::show();

    d.show();
    return 0;
}

