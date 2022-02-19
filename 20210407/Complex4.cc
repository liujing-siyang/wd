#include <iostream>

using std::cout;
using std::endl;

class Complex
{
    friend Complex operator+(const Complex &lhs, const Complex &rhs);
public:
    Complex(double dreal = 0, double dimag = 0)
    : _dreal(dreal)
    , _dimag(dimag)
    {
        cout << "Complex(double = 0, double = 0)" << endl;
    }

    //复合赋值运算符
    //对于对象本身发生变化的这种运算符，建议以成员函数的形式
    Complex &operator+=(const Complex &rhs)
    {
        cout << "Complex &operator+=(const Complex &)" << endl;
        _dreal += rhs._dreal;
        _dimag += rhs._dimag;

        return *this;
    }

    //++c1;
    Complex &operator++()
    {
        cout << "Complex &operator++()" << endl;
        ++_dreal;
        ++_dimag;

        return *this;
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
        /* cout << _dreal << " + " << _dimag << "i" << endl; */
        if(0 == _dreal && 0 == _dimag)
        {
            cout << 0;
        }
        else if(0 == _dreal)
        {
            cout << _dimag << "i" << endl;
        }
        else
        {
            cout << _dreal;
            if(_dimag > 0)
            {
                cout << " + " << _dimag << "i" << endl;
            }
            else if(_dimag < 0)//1 -1  1-i
            {
                cout << " - " << (-1) *_dimag << "i" << endl;
            }
            else
            {
                cout << endl;
            }
        }
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
//
//3、运算符重载之友元函数的形式进行重载,推荐使用友元
Complex operator+(const Complex &lhs, const Complex &rhs)
{
    cout << "friend Complex operator+(const Complex &, const Complex &)" << endl;
    return Complex(lhs._dreal + rhs._dreal,
                   lhs._dimag + rhs._dimag);
}
void test()
{
    int a = 3;
    int b = 4;
    a += b;//a = 7 b = 4

    cout << "(++a) = " << (++a) << ", a = " << a << endl;//a = 8, 表达式8
    cout << "(a++) = " << (a++) << ", a = " << a << endl;//a = 9, 表达式8



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

    cout << endl << "执行c1+=c2" << endl;
    c1 += c2;
    /* c1.operator+=(c2);//ok */
    cout << "c1 = ";
    c1.print();

    cout << endl << "执行前置++与后置++" << endl;
    cout << "(++c1) = ";
    (++c1).print();
    cout << "c1 = ";
    c1.print();
    
}

void test2()
{
    Complex c1(1, 2);
    cout << "c1 = ";
    c1.print();

    cout << endl;
    Complex c2(1, 0);
    cout << "c2 = ";
    c2.print();

    cout << endl;
    Complex c3(1, -2);
    cout << "c3 = ";
    c3.print();

    cout << endl;
    Complex c4(0, 2);
    cout << "c4 = ";
    c4.print();

    cout << endl;
    Complex c5(0, 0);
    cout << "c5 = ";
    c5.print();

    cout << endl;
    Complex c6(0, -2);
    cout << "c6 = ";
    c6.print();

    cout <<endl;
    Complex c7(-1, 2);
    cout << "c7 = ";
    c7.print();

    cout << endl;
    Complex c8(-1, 0);
    cout << "c8 = ";
    c8.print();

    cout << endl;
    Complex c9(-1, -2);
    cout << "c9 = ";
    c9.print();
}
int main(int argc, char **argv)
{
    test();
    return 0;
}
/*执行结果
(++a) = 8, a = 8
(a++) = 8, a = 9
Complex(double = 0, double = 0)
c1 = 1 + 2i

Complex(double = 0, double = 0)
c2 = 3 + 4i

friend Complex operator+(const Complex &, const Complex &)
Complex(double = 0, double = 0)
c3 = 4 + 6i

执行c1+=c2
Complex &operator+=(const Complex &)
c1 = 4 + 6i

执行前置++与后置++
(++c1) = Complex &operator++()
5 + 7i
c1 = 5 + 7i
~Complex()
~Complex()
~Complex()
*/