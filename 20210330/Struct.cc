#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

struct Computer
{
//类的内部：大括号范围以内
public:
    void setBrand(const char *brand)
    {
        strcpy(_brand, brand);
    }

    void setPrice(float price)
    {
        _price = price;
    }

    void print()
    {
        cout << "brand : " << _brand << endl
             << "price : " << _price << endl;
    }
private://封装
    char _brand[20];
    float _price;
};//不要忘了分号
int main(int argc, char **argv)
{
    Computer com;
    com.setBrand("lenovo");
    com.setPrice(6000);
    com.print();

    com._price = 100;//私有的
    return 0;
}

