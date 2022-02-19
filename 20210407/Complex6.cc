#include <iostream>
#include <limits>

using std::cout;
using std::endl;

class Point;

class Complex
{
    friend class Point;
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

//Point是自定义类型
class Point
{
public:
    Point(int ix = 0, int iy = 0)
    : _ix(ix)
    , _iy(iy)
    {
        cout << "Point(int = 0, int = 0)" << endl;
    }

    Point(const Complex &rhs)
    : _ix(rhs._dreal)
    , _iy(rhs._dimag)
    {
        cout << "Point(const Complex &)" << endl;
    }

    //类型转换函数
    //是一个成员函数
    //函数没有返回类型
    //函数没有参数
    //函数以return去返回目标类型的变量
    //违反常规思维
    operator int()
    {
        cout << "operator int()" << endl;
        return _ix + _iy;
    }

    operator double()
    {
        cout << "operator double()" << endl;
        if(0 == _iy)
        {
            return _iy;
        }
        else
        {
            return static_cast<double>(_ix)/_iy;
        }
    }

    operator Complex()
    {
        cout << "operator Complex()" << endl;
        return Complex(_ix, _iy);
    }

    void print() const
    {
        cout << "(" << _ix
             <<"," << _iy
             << ")";
    }

    ~Point()
    {
        cout << "~Point()" << endl;
    }
private:
    int _ix;
    int _iy;
};
void test()
{
    //从其他类型向自定义类型Point进行的转换
    Point pt1(1, 2);

    Point pt2 = 5;//隐式转换

    Complex c1(1, 8);
    Point pt3 = c1;//Point(const Complex &rhs)
    pt3.print();
    /* cout << "pt3 = " << pt3 << endl; */

    //从自定义类型Point向其他类型进行转化
    cout << endl << endl;
    int ix = pt1;
    cout << "ix = " << ix << endl;

    double dy = pt1;
    cout << "dy = " << dy << endl;

    Complex c2 = pt1;
    cout << "c2 = " << c2 << endl;
    
}
int main(int argc, char **argv)
{
    test();
    return 0;
}
/*执行结果
Point(int = 0, int = 0)
Point(int = 0, int = 0)
Complex(double = 0, double = 0)
Point(const Complex &)
(1,8)

operator int()
ix = 3
operator double()
dy = 0.5
operator Complex()
Complex(double = 0, double = 0)
c2 = std::ostream &operator<<(std::ostream &, const Complex &)
1 + 2i

~Complex()
~Point()
~Complex()
~Point()
~Point()
*/