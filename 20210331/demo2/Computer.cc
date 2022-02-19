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
