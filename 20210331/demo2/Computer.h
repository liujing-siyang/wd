#ifndef __COMPUTER_H__
#define __COMPUTER_H__

class Computer
{
public:
    Computer(const char *brand, float price);
    void setBrand(const char *brand);
    void setPrice(float price);
    void print();
    ~Computer();

private://封装
    char *_brand;//m_brand brand_
    float _price;
};//不要忘了分号

#endif
