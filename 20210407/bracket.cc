#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

//int arr[10]
//arr[0] arr.operator[](idx)

class CharArray
{
public:
    CharArray(size_t sz = 10)
    : _size(sz)
    , _data(new char[_size]())
    {
        cout << "CharArray(size_t = 10)" << endl;
    }

    //重载下标访问运算符相对来说比较安全（就是对idx范围作了判断）
    //下标访问运算符中的函数参数可以是任意类型(map就是一个例子)
    //
    //什么时候返回类型要用引用？
    //1、对于函数返回类型是类类型的时候，建议先写引用符号，除非
    //return返回的是临时对象或局部对象
    //
    //2、针对流对象而言（cout << "hello" << "122" << 123 << endl << endl;)，连续输出，要求对象生命周期大于下标访问运算符
    char &operator[](size_t idx) //size_t就是大于等于0的，加引用是为了能返回一个左值，同时对象不会因为下标访问运算符生命周期结束而结束
    {
        if(idx < _size)
        {
            return _data[idx];
        }
        else
        {
            static char nullchar = '\0';//返回类型用了引用，那么就返回对象的生命周期就应该大于函数的生命周期，所以用static
            return nullchar;
        }
    }

    size_t size() const
    {
        return _size;
    }

    ~CharArray()
    {
        cout << "~CharArray()" << endl;
        if(_data)
        {
            delete [] _data;
            _data = nullptr;
        }
    }
private:
    size_t _size;
    char *_data;
};
int main(int argc, char **argv)
{
    const char *pstr = "helloworld";
    CharArray ca(strlen(pstr) + 1);

    for(size_t idx = 0; idx != ca.size(); ++idx)
    {
        ca.operator[](idx) = pstr[idx];
        /* ca[idx] = pstr[idx]; */
    }

    for(size_t idx = 0; idx != ca.size(); ++idx)
    {
        cout << ca[idx] << "  ";
        cout << ca.operator[](idx) << "  ";
    }
    cout << endl;
    return 0;
}

