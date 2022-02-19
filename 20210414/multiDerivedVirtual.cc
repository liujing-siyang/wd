#include <iostream>

using std::cout;
using std::endl;

class A
{
public:
    virtual
    void a()
    {
        cout << "void A::a()" << endl;
    }

    virtual
    void b()
    {
        cout << "void A::b()" << endl;
    }

    virtual
    void c()
    {
        cout << "void A::c()" << endl;
    }
};

class B
{
public:
    virtual
    void a()
    {
        cout << "void B::a()" << endl;
    }

    virtual
    void b()
    {
        cout << "void B::b()" << endl;
    }

    void c()
    {
        cout << "void B::c()" << endl;
    }

    void d()
    {
        cout << "void B::d()" << endl;
    }

};

class C
: public A
, public B
{
public:
    virtual
    void a()
    {
        cout << "void C::a()" << endl;
    }

    void c()
    {
        cout << "void C::c()" << endl;
    }

    void d()
    {
        cout << "void C::d()" << endl;
    }
};

void test()
{
    cout << "sizeof(A) = " << sizeof(A) << endl;
    cout << "sizeof(B) = " << sizeof(B) << endl;
    cout << "sizeof(C) = " << sizeof(C) << endl;
    cout << endl;
    C c;
    printf("&c : %p\n", &c);

    cout << endl;
    A *pa = &c;
    printf("pa : %p\n", pa);
    pa->a();//C::a()
    pa->b();//A::b()
    pa->c();//C::c()

    cout << endl;
    B *pb = &c;
    printf("pb : %p\n", pb);
    pb->a();//C::a()
    pb->b();//B::b();
    pb->c();//B::c()
    pb->d();//B::d()

    cout << endl;
    C *pc = &c;
    printf("pc : %p\n", pc);
    pc->a();//C::a()
    /* pc->b();//二义性 */
    pc->A::b();//二义性
    pc->B::b();//二义性
    pc->c();//C::c()
    pc->d();//隐藏c::d()
}
int main(int argc, char **argv)
{
    test();
    return 0;
}

