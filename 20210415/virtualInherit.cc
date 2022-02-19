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

    A(int ia)
    : _ia(ia)
    { 
        cout << "A(int)" << endl;
    }

    ~A()
    { 
        cout << "~A()" << endl; 
    }

protected:
    int _ia;
};

class B
: virtual public A
{
public:
    B()
    {
        cout << "B()" << endl; 
    }

    B(int ia, int ib)
    : A(ia)
    , _ib(ib)
    {
        cout << "B(int, int)" << endl; 
    }

    ~B()
    {
        cout << "~B()" << endl; 
    }

protected:
    int _ib;
};

class C
: public B 
{
public:
    C()
    { 
        cout << "C()" << endl; 
    }

    C(int ia, int ib, int ic)
    : B(ia, ib)
    , A(ia)
    , _ic(ic)
    {
        cout << "C(int, int, int)" << endl;
    }

    void show() const 
    {
        cout << "_ia =  " << _ia << endl
            << "_ib =  " << _ib << endl
            << "_ic =  " << _ic << endl;
    }

    ~C()
    { 
        cout << "~C()" << endl; 
    }

private:
    int _ic;
};

int main(int agrc, char **argv)
{
    C c(10, 20, 30);
    c.show();

    return 0;
}
