#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

class Base
{
public:
    Base()
    : _pbase(nullptr)
    {
        cout << "Base()" << endl;
    }

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
    Derived(const char *pbase, const char *pderived)
    : Base(pbase)
    , _pderived(new char[strlen(pderived) + 1]())
    {
        cout << "Derived(const char *, const char *)" << endl;
        strcpy(_pderived, pderived);
    }

    Derived(const Derived &rhs)
    : Base(rhs)//显示初始化
    , _pderived(new char[strlen(rhs._pderived) + 1]())
    {
        cout << "Derived(const Derived &)" << endl;
        strcpy(_pderived, rhs._pderived);
    }

    Derived &operator=(const Derived &rhs)
    {
        cout << "Derived &operator=(const Derived &)" << endl;
        if(this != &rhs)
        {
            Base::operator=(rhs);//显示调用基类的赋值运算符函数
            delete [] _pderived;
            _pderived = nullptr;

            _pderived = new char[strlen(rhs._pderived) + 1]();
           strcpy(_pderived, rhs._pderived);

        }

        return  *this;
    }

    ~Derived()
    {
        cout << "~Derived()" << endl;
        if(_pderived)
        {
            delete [] _pderived;
            _pderived = nullptr;
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const Derived &rhs);
private:
    char *_pderived;
};
std::ostream &operator<<(std::ostream &os, const Derived &rhs)
{
    const Base &ref = rhs;
    os << ref << ", " << rhs._pderived;
    return os;
}

void test()
{
    Derived derived("hello", "world");
    cout << "derived = " << derived << endl;

    cout << endl;
    Derived d2 = derived;
    cout << "derived = " << derived << endl;
    cout << "d2 = " << d2 << endl;

    cout << endl;
    Derived d3("wuhan", "hubei");
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
Derived(const char *, const char *)
derived = hello, world

Base(const Base &) 
Derived(const Derived &)
derived = hello, world
d2 = hello, world

Base(const char *) 
Derived(const char *, const char *)
d3 = wuhan, hubei
Derived &operator=(const Derived &)
Base &operator=(const Base &)
derived = hello, world
d3 = hello, world
~Derived()
~Base()
~Derived()
~Base()
~Derived()
~Base()