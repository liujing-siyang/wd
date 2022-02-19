#include <iostream>

using std::cout;
using std::endl;

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

    //2、运算符重载之成员函数的形式
    Complex operator+(const Complex &rhs)
    {
        cout << "Complex operator+(const Complex &)" << endl;
        return Complex(_dreal + rhs._dreal,
                       _dimag + rhs._dimag);
    }

    ~Complex()
    {
        cout << "~Complex()" << endl;
    }

private:
    double _dreal;
    double _dimag;
};

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
    Complex c3 = c1 + c2;
    cout << "c3 = ";
    c3.print();
}
int main(int argc, char **argv)
{
    test();
    return 0;
}
