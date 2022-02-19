#ifndef __COMPUTER_H__
#define __COMPUTER_H__

class Computer
{
public:
    Computer(const char *brand, float price);
    Computer(const Computer &rhs);
    Computer &operator=(const Computer &rhs);
    void setBrand(const char *brand);
    void setPrice(float price);

    //const版本的成员函数与非const版本的成员函数可以重载
    //一般先写const版本的
    void print();
    void print() const;
    static void printTotalPrice();
    ~Computer();

private://封装
    char *_brand;//8
    float _price;//4, 内存对齐
    static float _totalPrice;//全局共享的，不占类的大小
};//不要忘了分号


#endif
