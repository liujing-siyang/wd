#include <iostream>

using std::cout;
using std::endl;

//声明了纯虚函数的类称为抽象类，抽象类不能创建对象
class Base
{
public:
    virtual  
    void display() const = 0;

    virtual  
    void print() const = 0;
};

//抽象类的派生类如果有纯虚函数没有实现，那么该派生类也是一个
//抽象类，抽象类不能创建对象
class Derived
: public Base
{
public:
    virtual 
    void display() const override
    {
        cout << "void Derived::display() const" << endl;
    }
};

class Derived2
: public Derived
{
public:
    void print() const override
    {
        cout << "void Derived::print() const" << endl;
    }
};
int main(int argc, char **argv)
{
    /* Base base;//error */
    /* Derived derived;//error */
    /* Derived d();// int func();//实际上是函数声明 */
    /* derived.display(); */

    Derived2 derived2;
    derived2.display();
    derived2.print();

    Base *pbase = &derived2;
    Derived *pderived = &derived2;
    return 0;
}

