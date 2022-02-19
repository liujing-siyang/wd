#include "Computer.h"
#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

//静态数据成员不能在初始化列表中进行，只能在全局静态的位置，特别的：
//对于头文件与实现文件的形式，必须放在实现文件中，否则就有可能出现
//重复定义
float Computer::_totalPrice = 0.0;

Computer::Computer(const char *brand, float price)
: _brand(new char[strlen(brand) + 1]())
, _price(price)
/* , _totalPrice(0) */
{
    cout << "Computer(const char *, float)" << endl;
    strcpy(_brand, brand);
    _totalPrice += _price;
}
#if 0
Computer::Computer(const Computer &rhs)
: _brand(rhs._brand)//浅拷贝
, _price(rhs._price)
{
    cout << "Computer(const Computer &)" << endl;
}
#endif
#if 1
//1、拷贝构造函数的参数const可以去掉吗？
//
//2、拷贝构造函数参数里面的引用符号可以去掉吗?
Computer::Computer(const Computer &rhs)
: _brand(new char[strlen(rhs._brand) + 1]())//深拷贝
, _price(rhs._price)
{
    cout << "Computer(const Computer &)" << endl;
    strcpy(_brand, rhs._brand);
}

#endif

#if 0
Computer &Computer::operator=(const Computer &rhs)
{
    cout << "Computer &operator=(const Computer &)" << endl;
    _brand = rhs._brand;
    _price = rhs._price;

    return *this;
}
#endif
#if 1
//赋值运算符这样写还有什么问题没有？
Computer &Computer::operator=(const Computer &rhs)
{
    cout << "Computer &operator=(const Computer &)" << endl;
    if(this != &rhs)//1、自复制
    {
        delete [] _brand;//2、释放左操作数
        _brand = nullptr;
        _brand = new char[strlen(rhs._brand) + 1]();//3、深拷贝
        strcpy(_brand, rhs._brand);
        _price = rhs._price;
    }

    return *this;//4、返回*this
}
#endif
void Computer::setBrand(const char *brand)
{
    strcpy(_brand, brand);
}

void Computer::setPrice(float price)
{
    _price = price;
}

void func(const Computer &rhs)
{
    rhs.print();
}

void Computer::print(/* Computer * const this      */)
{
    cout << "void print()" << endl;
    /* this->_price = 100; */
    if(_brand)
    {
        cout << "brand : " << _brand << endl
             << "price : " << _price << endl;
    }
}

void Computer::print(/*const Computer * const this   */) const
{
    /* this = nullptr;//error */
    /* this->_price = 100; */
    cout << "void print() const" << endl;
    if(_brand)
    {
        cout << "brand : " << _brand << endl
             << "price : " << _price << endl;
    }
}

//静态的成员函数的第一个参数位置没有this指针
//静态的成员函数不能访问非静态的数据成员和非静态的成员函数
//非静态的成员函数能访问静态的数据成员和静态的成员函数
//
//如果非要在静态成员函数中调用非静态数据成员与非静态成员函数，可以传参
//
//void func(Computer com);
void Computer::printTotalPrice()
{
    /* this->_price = 100;//error */
    /* print();//error */
    /* printf("this : %p\n", this);//error */
    cout << "totalPrice = " << _totalPrice << endl;
}
Computer::~Computer()
{
    cout << "~Computer()" << endl;
    _totalPrice -= _price;
    if(_brand)
    {
        delete [] _brand;
        _brand = nullptr;
    }
}
