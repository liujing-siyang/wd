#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::shared_ptr;

class Child;

class Parent
{
public:
    Parent()
    {
        cout << "Parent()" << endl;
    }

    ~Parent()
    {
        cout << "~Parent()" << endl;
    }

    shared_ptr<Child> _pParent;
};

class Child
{
public:
    Child()
    {
        cout << "Child()" << endl;
    }

    ~Child()
    {
        cout << "~Child()" << endl;
    }

    shared_ptr<Parent> _pChild;

};

void test()
{
    shared_ptr<Parent> ptrParent(new Parent());
    shared_ptr<Child> ptrChild(new Child());
    cout << "ptrParent.use_count() = " << ptrParent.use_count() << endl;
    cout << "ptrChild.use_count() = " << ptrChild.use_count() << endl;

    cout << endl;
    //栈对象ptrParent和ptrChild销毁了，引用计数由2变为1，但堆对象Parent和Child
    //之间的循环引用导致它们的析构函数没有调用，因为引用计数不为0。
    ptrParent->_pParent = ptrChild;
    ptrChild->_pChild = ptrParent; 
    cout << "ptrParent.use_count() = " << ptrParent.use_count() << endl;
    cout << "ptrChild.use_count() = " << ptrChild.use_count() << endl;
}
int main(int argc, char **argv)
{
    test();
    return 0;
}

