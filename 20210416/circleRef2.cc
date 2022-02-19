#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::shared_ptr;
using std::weak_ptr;

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

    weak_ptr<Parent> _pChild;

};

void test()
{
    shared_ptr<Parent> ptrParent(new Parent());
    shared_ptr<Child> ptrChild(new Child());
    cout << "ptrParent.use_count() = " << ptrParent.use_count() << endl;
    cout << "ptrChild.use_count() = " << ptrChild.use_count() << endl;

    cout << endl;
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

