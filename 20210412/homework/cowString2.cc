#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

class String
{
public:
    String()
    : _pstr(new char[5]() + 4)
    {
        cout << "String()" << endl;
        initRefcount();
    }

    String(const char *pstr)
    : _pstr(new char[strlen(pstr) + 5]() + 4)
    {
        cout << "String(const char *)" << endl;
        strcpy(_pstr, pstr);
        initRefcount();
    }

    //String s2 = s1;
    String(const String &rhs)
    : _pstr(rhs._pstr)
    {
        cout << "String(const String &)" << endl;
        increaseRefcount();
    }

    //s3 = s1;
    String &operator=(const String &rhs)
    {
        cout << "String &operator=(const String &)" << endl;
        if(this != &rhs)//1、自复制
        {
            release();//2、释放左操作数
            _pstr = rhs._pstr;//3、浅拷贝
            increaseRefcount();
        }
        
        return *this;//4、返回*this
    }

private:
    class CharProxy
    {
    public:
        CharProxy(String &self, size_t idx)
        : _self(self)
        , _idx(idx)
        {

        }

        char &operator=(const char &ch);
        /* friend std::ostream &operator<<(std::ostream &os, const CharProxy &rhs); */
        operator char()//CharProxy ===> char, 类型转换函数
        {
            return _self._pstr[_idx];
        }
    private:
        String &_self;
        size_t _idx;
    };
    //s2 = s2 = s1;
    //s3[0] = 'H';
    //cout << s1[0] << endl;
public:
    //s3[0] = 'H';//s3.operator[](0)===>CharProxy
    //cout << s1[0] << endl;//s1.operator[](0)==>CharProxy
    //代理模式
    CharProxy operator[](size_t idx)//是String的成员函数
    {
        return CharProxy(*this, idx);
    }
#if 0
    char &operator[](size_t idx)
    {
        if(idx < size())
        {

            if(getRefcount() > 1)
            {
                char *pTmp = new char[size() + 5]() + 4;
                strcpy(pTmp, _pstr);
                decreaseRefcount();
                _pstr = pTmp;
                initRefcount();
            }

            return _pstr[idx];

        }
        else
        {
            static char nullchar = '\0';
            return nullchar;
        }
    }

#endif
    ~String()
    {
        cout << "~String()" << endl;
        release();
    }
private:
    void release()
    {
        decreaseRefcount();
        if(0 == *(int *)(_pstr - 4))
        {
            delete [] (_pstr - 4);
        }
    }

    void initRefcount() 
    {
        *(int *)(_pstr - 4) = 1;
    }

    void increaseRefcount() 
    {
        ++*(int *)(_pstr - 4);
    }

    void decreaseRefcount() 
    {
        --*(int *)(_pstr - 4);
    }

    size_t size() const
    {
        return strlen(_pstr);
    }
public:
    int getRefcount() const
    {
        return *(int *)(_pstr - 4);
    }

    const char *c_str() const
    {
        return _pstr;
    }

    friend std::ostream &operator<<(std::ostream &os, const String &rhs);
    /* friend std::ostream &operator<<(std::ostream &os, const String::CharProxy &rhs); */
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

char &String::CharProxy::operator=(const char &ch)
{
    if(_idx < _self.size())
    {

        if(_self.getRefcount() > 1)
        {
            char *pTmp = new char[_self.size() + 5]() + 4;
            strcpy(pTmp, _self._pstr);
            _self.decreaseRefcount();
            _self._pstr = pTmp;
            _self.initRefcount();
        }

        _self._pstr[_idx] = ch;//真正的写操作

        return _self._pstr[_idx];

    }
    else
    {
        static char nullchar = '\0';
        return nullchar;
    }

}
#if 0
/* cout << s1[0] << endl; //s1.operator[](0)*/
std::ostream &operator<<(std::ostream &os, const String::CharProxy &rhs)
{
    /* os << rhs._self.c_str()[rhs._idx]; */
    os << rhs._self._pstr[rhs._idx];
    return os;
}
#endif
void test()
{
    String s1 = "hello";
    cout << "s1 = " << s1 << endl;
    cout << "s1.getRefcount() = " << s1.getRefcount() << endl;
    printf("s1'address : %p\n", s1.c_str());

    cout << endl;
    String s2 = s1;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s1.getRefcount() = " << s1.getRefcount() << endl;
    cout << "s2.getRefcount() = " << s2.getRefcount() << endl;
    printf("s1'address : %p\n", s1.c_str());
    printf("s2'address : %p\n", s2.c_str());

    cout << endl;
    String s3("world");
    cout << "s3 = " << s3 << endl;
    cout << "s3.getRefcount() = " << s3.getRefcount() << endl;
    printf("s3'address : %p\n", s3.c_str());

    cout << endl << "执行赋值操作s3 = s1" << endl;
    s3 = s1;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    cout << "s1.getRefcount() = " << s1.getRefcount() << endl;
    cout << "s2.getRefcount() = " << s2.getRefcount() << endl;
    cout << "s3.getRefcount() = " << s3.getRefcount() << endl;
    printf("s1'address : %p\n", s1.c_str());
    printf("s2'address : %p\n", s2.c_str());
    printf("s3'address : %p\n", s3.c_str());


    cout << endl << "对s3[0]执行写操作"  << endl;
    s3[0] = 'H';//char = char//CharProxy = char
    s3.operator[](0).operator=('H');
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    cout << "s1.getRefcount() = " << s1.getRefcount() << endl;
    cout << "s2.getRefcount() = " << s2.getRefcount() << endl;
    cout << "s3.getRefcount() = " << s3.getRefcount() << endl;
    printf("s1'address : %p\n", s1.c_str());
    printf("s2'address : %p\n", s2.c_str());
    printf("s3'address : %p\n", s3.c_str());

    cout << endl << "对s1[0]执行读操作" << endl;
    //CharProxy===>char
    cout << "s1[0] = " << s1[0] << endl;//os << char//os << CharProxy
    operator<<(cout, s1.operator[](0));
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    cout << "s1.getRefcount() = " << s1.getRefcount() << endl;
    cout << "s2.getRefcount() = " << s2.getRefcount() << endl;
    cout << "s3.getRefcount() = " << s3.getRefcount() << endl;
    printf("s1'address : %p\n", s1.c_str());
    printf("s2'address : %p\n", s2.c_str());
    printf("s3'address : %p\n", s3.c_str());
}

int main(int argc, char **argv)
{
    test();
    return 0;
}

