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

    void show() const
    {
        cout << "void A::show() const" << endl;
    }

    ~A()
    {
        cout << "~A()" << endl;
    }
};

class B
{
public:
    B()
    {
        cout << "B()" << endl;
    }

    void show() const
    {
        cout << "void B::show() const" << endl;
    }

    ~B()
    {
        cout << "~B()" << endl;
    }
};

class C
{
public:
    C()
    {
        cout << "C()" << endl;
    }

    void show() const
    {
        cout << "void C::show() const" << endl;
    }

    ~C()
    {
        cout << "~C()" << endl;
    }
};

//对于多基继承，对于每一个基类一定要在继承的时候，写上继承方式，
//否则就是私有的
//
//基类构造函数的执行顺序，与其在派生类初始化列表中的顺序没有关系
//只与基类被继承的时候的顺序有关
class D
: public B
, public C
, public A
{
public:
    D()
    : A()
    , C()
    , B()
    {
        cout << "D()" << endl;
    }

    ~D()
    {
        cout << "~D()" << endl;
    }

};

int main(int argc, char **argv)
{
    //多基继承问题1：成员函数访问冲突
    //解决方案：在成员函数前面加上类名和作用符限定符
    D d;
    d.A::show();
    d.B::show();
    d.C::show();
    return 0;
}

