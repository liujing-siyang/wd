#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

class Base
{
public:
    Base(const char *pbase)
    : _pbase(new char[strlen(pbase) + 1]())
    {
        cout << "Base(const char *)" << endl;
        strcpy(_pbase, pbase);
    }

    virtual 
    void print() const
    {
        cout << "Base::_pbase = " << _pbase << endl;
    }

    //如果基类的析构函数被设计为虚函数之后，派生类的析构函数
    //就自动的称为虚函数
    //
    //基类的析构函数定义为虚函数之后，派生类重定义了自己的析构函数
    //，这个时候对于编译器而言也是一种重写（重定义，覆盖），之所以
    //编译器可以这么做，是因为析构函数对于每一个类而言，具有唯一性
    //
    virtual
    ~Base()//destructor()
    {
        cout << "~Base()" << endl;
        if(_pbase)
        {
            delete [] _pbase;
            _pbase = nullptr;
        }
    }
private:
    char *_pbase;

};

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

    void print() const 
    {
        cout << "Derived::_pderived = " << _pderived << endl;

    }

    ~Derived()//destructor()
    {
        cout << "~Derived()" << endl;
        if(_pderived)
        {
            delete [] _pderived;
            _pderived = nullptr;
        }

    }
private:
    char *_pderived;
};


int main(int argc, char **argv)
{
    Base *pbase = new Derived("hello", "world");
    pbase->print();

    //pbase->~Base();//pbase->~destructor();
    delete pbase;//1、执行析构函数 2、operator delete
    /* delete dynamic_cast<Derived *>(pbase); */
    return 0;

}
