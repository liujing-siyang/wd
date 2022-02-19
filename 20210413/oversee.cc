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

    ~Base()
    {
        cout << "~Base()" << endl;
    }
/* private: */
protected:
    double _base;
};

class Derived
: public Base
{
public:
    Derived(double base = 0,double number = 0)
    : Base(base)
    , _base(number)
    {
        cout << "Derived(double = 0)" << endl;
    }

    /* void print() */
    /* { */

    /* } */
    virtual
    void print(int x)
    {
        cout << "Base::_base = " << Base::_base << endl;
        cout << "Derived::_base = " << _base<< endl;
    }

    ~Derived()
    {
        cout << "~Derived()" << endl;
    }
private:
    double _base;
};
int main(int argc, char **argv)
{
    Derived derived(10, 20);
    /* derived.print();//error */
    derived.print(1);
    /* derived.Base::print(); */
    return 0;
}

