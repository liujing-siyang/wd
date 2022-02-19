#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

class String
{
public:
    String()
    : _pstr(nullptr)//new char[1]()
    {
        cout << "String()" << endl;
    }

    String(const char *pstr)
    : _pstr(new char[strlen(pstr) + 1]())
    {
        cout << "String(const char *)" << endl;
        strcpy(_pstr, pstr);
    }

    //拷贝构造函数
    //将拷贝构造函数和赋值运算符函数，称为具有复制（拷贝）控制语义的函数
    String(const String &rhs)
    : _pstr(new char[strlen(rhs._pstr) + 1]())
    {
        cout << "String(const String &)" << endl;
        strcpy(_pstr, rhs._pstr);
    }

    //String s3 = String("world");
    //移动构造函数
    //将移动构造函数和移动赋值运算符函数称为具有移动语义的函数
    String(String &&rhs)
    : _pstr(rhs._pstr)//浅拷贝
    {
        cout << "String(String &&)" << endl;
        rhs._pstr = nullptr;//防止析构函数释放已经转移的资源
    }

    //赋值运算符函数
    //s2 = s1
    String &operator=(const String &rhs)
    {
        cout << "String &operator=(const String &)" << endl;

        if(this != &rhs)//自复制
        {
            delete [] _pstr;
            _pstr = nullptr;

            _pstr = new char[strlen(rhs._pstr) + 1]();
            strcpy(_pstr, rhs._pstr);
        }
        return *this;
    }

    //s3 = String("world");
    //移动赋值运算符函数
    String &operator=(String &&rhs)
    {
        cout << "String &operator=(String &&)" << endl;

        if(this != &rhs)//自移动，s3 = std::move(s3),delete完s3的空间就被回收了，浅拷贝指向的就是已经被回收的空间
        {
            delete [] _pstr;
            _pstr = nullptr;

            _pstr = rhs._pstr;//浅拷贝
            rhs._pstr = nullptr;
        }
        return *this;
    }


    ~String()
    {
        cout << "~String()" << endl;

        if(_pstr)
        {
            delete [] _pstr;
            _pstr = nullptr;
        }
    }
    
    //流对象的拷贝构造函数是不提供的，返回类型和参数用引用是防止拷贝构造函数的调用
    friend std::ostream &operator<<(std::ostream &os, const String &rhs);

private:
    char *_pstr;
};

std::ostream &operator<<(std::ostream &os, const String &rhs)
{
    if(rhs._pstr)
    {
        os << rhs._pstr;
    }
    return os;
}

void test0()
{
    const char *pstr = "hello";

    char str[] = {'w', 'o', 'r', 'l', 'd'};
}
void test()
{
    //int func(const char *);
    String s1("hello");
    cout << "s1 = " << s1 << endl; 

    cout << endl;
    String s2(s1);//拷贝构造函数
    cout << "s2 = " << s2 << endl;

    cout << endl;

    //"world"在文字常量区，有内存存储它，可以取地址，为左值
    //String("world")为一个临时对象，是右值
    String s3 = "world";//String("world")，调用移动构造函数
    cout << "s3 = " << s3 << endl;
    &"world";

    cout << endl << endl;
    s3 = String("wuhan");//调用移动赋值运算符函数
    cout << "s3 = " << s3 << endl;

    cout << endl << endl;
    String("world") = String("world");//调用移动赋值运算符函数

    cout << endl << endl;
    s1 = std::move(s1);//std::move可以将一个左值转换为一个右值
    //底层实际上就是做了一个强制转换static_cast<T &&>(value)，这里体现防止自移动
    cout << "s1 = " << s1 << endl;

    cout << endl;
    s3 = std::move(s1);//表明s1就不想使用，s1的空间已经在移动赋值运算符函数中回收了
    cout << "s3  = " << s3 << endl;
    cout << "s1  = " << s1 << endl;
    cout << "1111" << endl;

    cout << endl;
    s1 = s2;//赋值运算符函数
    cout << "s1  = " << s1 << endl;
}

int main(int argc, char **argv)
{
    test();
    return 0;
}
