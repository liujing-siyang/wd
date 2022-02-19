#include <iostream>

using std::cout;
using std::endl;

class Grandpa
{
public:
    Grandpa()
    {
        cout << "Grandpa()" << endl;
    }

    virtual
    void func1()
    {
        cout << "void Grandpa::func1()" << endl;

    }

    virtual
    void func2()
    {
        cout << "void Grandpa::func2()" << endl;

    }

    ~Grandpa()
    {
        cout << "~Grandpa()" << endl;

    }

};

class Father
: public Grandpa
{
public:
    Father()
    : Grandpa()
    {
        cout << "Father()" << endl;
        func1();//Son栈对象还没有创建成功
    }

    virtual
    void func1()
    {
        cout << "void Father::func1()" << endl;

    }

    virtual
    void func2()
    {
        cout << "void Father::func2()" << endl;

    }

    ~Father()
    {
        cout << "~Father()" << endl;
        func2();//son栈对象已经销毁
    }
};

class Son
: public Father
{
public:
    Son()
    : Father()
    {
        cout << "Son()" << endl;
    }

    virtual
    void func1()
    {
        cout << "void Son::func1()" << endl;
    }

    virtual
    void func2()
    {
        cout << "void Son::func2()" << endl;
    }

    ~Son()
    {
        cout << "~Son()" << endl;
    }

};

int main(int argc, char **argv)
{
    Son son;//栈对象
    return 0;
}
