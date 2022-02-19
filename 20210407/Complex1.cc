#include <iostream>

using std::cout;
using std::endl;

//复数 i^2 = -1;
class Complex
{
public:
    Complex(double dreal = 0, double dimag = 0)
    : _dreal(dreal)
    , _dimag(dimag)
    {
        cout << "Complex(double = 0, double = 0)" << endl;
    }

    double getReal() const
    {
        return _dreal;
    }

    double getImag() const
    {
        return _dimag;
    }

    void print() const
    {
        cout << _dreal << " + " << _dimag << "i" << endl;
    }

    ~Complex()
    {
        cout << "~Complex()" << endl;
    }

private:
    double _dreal;
    double _dimag;
};
#if 0
int operator+(int x, int y)
{

}

Z = X + Y;

/* if(a&& b) */
if(a || b)
{

}
else
{

}
#endif

//1、运算符重载之普通函数的形式
Complex operator+(const Complex &lhs, const Complex &rhs)
{
    cout << "Complex operator+(const Complex &, const Complex &)" << endl;
    return Complex(lhs.getReal() + rhs.getReal(),
                   lhs.getImag() + rhs.getImag());
}
void test()
{
    Complex c1(1, 2);
    cout << "c1 = ";
    c1.print();

    cout << endl;
    Complex c2(3, 4);
    cout << "c2 = ";
    c2.print();

    cout << endl;
    Complex c3 = c1 + c2;//不会调用赋值构造函数而直接是构造函数
    cout << "c3 = ";
    c3.print();
}
int main(int argc, char **argv)
{
    test();
    return 0;
}
/*执行结果
Complex(double = 0, double = 0)
c1 = 1 + 2i

Complex(double = 0, double = 0)
c2 = 3 + 4i

Complex operator+(const Complex &, const Complex &)
Complex(double = 0, double = 0)
c3 = 4 + 6i
~Complex()
~Complex()
~Complex()
*/