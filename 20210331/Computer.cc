#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

//C++里面对struct的功能做了一个提升：与class基本相同，唯一的
//区别就是struct的默认访问权限是public，class的默认访问权限是
//private
class Computer
{
//类的内部：大括号范围以内
public:
    inline
    void setBrand(const char *brand)
    {
        strcpy(_brand, brand);
    }

    inline
    void setPrice(float price)
    {
        _price = price;
    }

    inline
    void print()
    {
        cout << "brand : " << _brand << endl
             << "price : " << _price << endl;
    }
private://封装
    char _brand[20];//m_brand brand_
    float _price;
};//不要忘了分号

int main(int argc, char **argv)
{
    Computer com;
    com.setBrand("lenovo");
    com.setPrice(6000);
    com.print();

    /* com._price = 100;//私有的 */
    return 0;
}

