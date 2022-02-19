#include <iostream>
#include <limits>

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
    //为何前置++比后置++效率高？
    Complex &operator++()
    {
        cout << "Complex &operator++()" << endl;
        ++_dreal;
        ++_dimag;

        return *this;
    }

    Complex operator++(int)//int只是起标记作用
    {
        cout << "Complex operator++(int)" << endl;
        Complex tmp(*this);//局部对象
        ++_dreal;
        ++_dimag;

        return tmp;
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
    //输出流运算符不能以成员函数的形式进行重载,
    //成员函数的第一个参数的位置存在一个this，这样就违反
    //运算符重载的规则
    /* std::ostream &operator<<(std::ostream &os);//error */
    friend std::ostream &operator<<(std::ostream &os, const Complex &rhs);
    friend std::istream &operator>>(std::istream &is, Complex &rhs);

private:
    double _dreal;
    double _dimag;
};
//3、运算符重载之友元函数的形式进行重载,推荐使用友元
Complex operator+(const Complex &lhs, const Complex &rhs)
{
    cout << "friend Complex operator+(const Complex &, const Complex &)" << endl;
    return Complex(lhs._dreal + rhs._dreal,
                   lhs._dimag + rhs._dimag);
}

//返回类型和参数中的引用符号不能去掉，对于流而言，拷贝构造函数是私有的（不提供）
std::ostream &operator<<(std::ostream &os, const Complex &rhs)
{
    cout << "std::ostream &operator<<(std::ostream &, const Complex &)" << endl;
    if(0 == rhs._dreal && 0 == rhs._dimag)
    {
        os << 0;
    }
    else if(0 == rhs._dreal)
    {
        os << rhs._dimag << "i" << endl;
    }
    else
    {
        os << rhs._dreal;
        if(rhs._dimag > 0)
        {
            os << " + " << rhs._dimag << "i" << endl;
        }
        else if(rhs._dimag < 0)//1 -1  1-i
        {
             os << " - " << (-1) *rhs._dimag << "i" << endl;
        }
        else
        {
            os << endl;
        }
    }

    return os;
}

void readDouble(std::istream &is, double &number)
{
    while(is >> number, !is.eof())
    {
        if(is.bad())
        {
            std::cerr << "The istream is boken" << endl;
            return;
        }
        else if(is.fail())
        {
            is.clear();//重置流的状态
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//清空缓冲区
            cout << "pls input double data" << endl;
        }
        else
        {
            cout << "number = " << number << endl;
            break;
        }
    }
}
std::istream &operator>>(std::istream &is, Complex &rhs)
{
    /* is >> rhs._dreal >> rhs._dimag; */
    readDouble(is, rhs._dreal);
    readDouble(is, rhs._dimag);

    return is;
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
    c1 += c2;//4 + 6i
    /* c1.operator+=(c2);//ok */
    cout << "c1 = ";
    c1.print();

    cout << endl << "执行前置++与后置++" << endl;
    cout << "(++c1) = ";
    (++c1).print();//5 + 7i
    cout << "c1 = ";
    c1.print();//5 + 7i

    /* &(++c1);//ok */
    /* &(c1++);//error */

    cout << endl;
    cout << "(c1++) = ";
    (c1++).print();//5 + 7i
    cout << "c1 = ";
    c1.print();//6 + 8i
}

void test2()
{
    Complex c1(1, 2);
    cout << "c1 = " << c1 << endl;//链式编程
    //一步步拆解cout << "c1 = " << c1 << endl;
    operator<<(cout, "c1 = ");//返回的还是一个流对象，这里拆解的是第一个<<,下同
    operator<<(operator<<(cout, "c1 = "), c1);
    operator<<(operator<<(cout, "c1 = "), c1).operator<<(endl);

    cout << endl;
    Complex c2(3, 4);
    cout << "c2 = " << c2 << endl;

    Complex c3;
    std::cin >> c3;
    cout << "c3 = " << c3 << endl;

}
int main(int argc, char **argv)
{
    test2();
    return 0;
}
/*执行结果
Complex(double = 0, double = 0)
c1 = std::ostream &operator<<(std::ostream &, const Complex &)
1 + 2i

c1 = c1 = std::ostream &operator<<(std::ostream &, const Complex &)
1 + 2i
c1 = std::ostream &operator<<(std::ostream &, const Complex &)
1 + 2i


Complex(double = 0, double = 0)
c2 = std::ostream &operator<<(std::ostream &, const Complex &)
3 + 4i

Complex(double = 0, double = 0)
123
number = 123            //输入
456
number = 456            //输入
c3 = std::ostream &operator<<(std::ostream &, const Complex &)
123 + 456i

~Complex()
~Complex()
~Complex()
*/