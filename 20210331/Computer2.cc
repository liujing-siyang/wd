#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

class Computer
{
public:
    void setBrand(const char *brand);
    void setPrice(float price);
    void print();

private://封装
    char _brand[20];//m_brand brand_
    float _price;
};//不要忘了分号

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
    cout << "brand : " << _brand << endl
         << "price : " << _price << endl;
}

int main(int argc, char **argv)
{
    Computer com;
    com.setBrand("lenovo");
    com.setPrice(6000);
    com.print();

    /* com._price = 100;//私有的 */
    return 0;
}

