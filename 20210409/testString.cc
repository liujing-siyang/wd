#include <iostream>

using std::cout;
using std::endl;

//1、引用计数放在栈上不行，拷贝构造函数中const导致不能更改
//2、放在全局静态位置不行，每个对象都不一样
//3、只能放在堆上面
class String
{
public:
    //s2 = s1
    String(const String &rhs)
    : _pstr(rhs._pstr)
    /* , _cnt(rhs._cnt) */
    {
        /* ++rhs._cnt; */
    }
private:
    char *_pstr;
    static int _cnt;

};

String func()
{
    String s;
    return s;
}
int main(int argc, char **argv)
{
    String s1;
    String s2;
    //
    String s3 = func();
    int &ref = 10;
    String &rhs = func();

    String s1 = "hello";
    String s2 = "world";
    return 0;
}

