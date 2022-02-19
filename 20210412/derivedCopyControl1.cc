#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

class Base
{
public:
    Base(const char *pbase)
    : _pbase(new char[strlen(pbase) + 1]())//strlen不能换成sizeof
    {
        cout << "Base(const char *) " << endl;
        strcpy(_pbase, pbase);
    }

    Base(const Base &rhs)
    : _pbase(new char[strlen(rhs._pbase) + 1]())
    {
        cout << "Base(const Base &) " << endl;
        strcpy(_pbase, rhs._pbase);

    }

    Base &operator=(const Base &rhs)
    {
        cout << "Base &operator=(const Base &)" << endl;
        if(this != &rhs)
        {
            delete [] _pbase;
            _pbase = nullptr;

            _pbase = new char[strlen(rhs._pbase) + 1]();
            strcpy(_pbase, rhs._pbase);
        }

        return *this;
    }

    ~Base()
    {
        cout << "~Base()" << endl;
        if(_pbase)
        {
            delete [] _pbase;
            _pbase = nullptr;
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const Base &rhs);
private:
    char *_pbase;
};
std::ostream &operator<<(std::ostream &os, const Base &rhs)
{
    if(rhs._pbase)
    {
        os << rhs._pbase;
    }

    return os;
}

class Derived
: public Base
{
public:
    Derived(const char *pbase)
    : Base(pbase)
    {
        cout << "Derived(const char *)" << endl;
    }

    ~Derived()
    {
        cout << "~Derived()" << endl;
    }

    friend std::ostream &operator<<(std::ostream &os, const Derived &rhs);
};
std::ostream &operator<<(std::ostream &os, const Derived &rhs)
{
    const Base &ref = rhs;
    os << ref;
    return os;
}


void test()
{
    Derived derived("hello");
    cout << "derived = " << derived << endl;

    cout << endl;
    Derived d2 = derived;
    cout << "derived = " << derived << endl;
    cout << "d2 = " << d2 << endl;

    cout << endl;
    Derived d3("world");
    cout << "d3 = " << d3 << endl;
    d3 = derived;
    cout << "derived = " << derived << endl;
    cout << "d3 = " << d3 << endl;
}
int main(int argc, char **argv)
{
    test();
    return 0;
}

结果
Base(const char *) 
Derived(const char *)
derived = hello

Base(const Base &) 
derived = hello
d2 = hello

Base(const char *) 
Derived(const char *)
d3 = world
Base &operator=(const Base &)
derived = hello
d3 = hello
~Derived()
~Base()
~Derived()
~Base()
~Derived()
~Base()