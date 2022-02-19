#ifndef __COMPUTER_H__
#define __COMPUTER_H__

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

#endif
