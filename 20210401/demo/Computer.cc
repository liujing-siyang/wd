#include "Computer.h"
#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

Computer::Computer(const char *brand, float price)
: _brand(new char[strlen(brand) + 1]())
/* : _brand(brand) */
, _price(price)
{
    cout << "Computer(const char *, float)" << endl;
    /* int a = 10; */
    /* int b(10); */
    /* _brand = new char[strlen(brand) + 1](); */
    strcpy(_brand, brand);
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

void Computer::print()
{
    if(_brand)
    {
        cout << "brand : " << _brand << endl
             << "price : " << _price << endl;
    }
}


Computer::~Computer()
{
    cout << "~Computer()" << endl;
    if(_brand)
    {
        delete [] _brand;
        _brand = nullptr;
    }
}
