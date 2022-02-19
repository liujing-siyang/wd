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
        //*(int *)(_pstr - 4) = 1;
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

    //s2 = s2 = s1;
    //s3[0] = 'H';
    //cout << s1[0] << endl;
    char &operator[](size_t idx)
    {
        if(idx < size())
        {
            //s3[0] = 'H';这里默认了下标访问运算符是用来写
            if(getRefcount() > 1)//引用计数大于1
            {
                char *pTmp = new char[size() + 5]() + 4;//申请新的堆空间
                strcpy(pTmp, _pstr);//拷贝到新空间上
                decreaseRefcount();//对原来的计数减1
                _pstr = pTmp;//指向这块空间
                initRefcount();//引用计数初始化为1
            }

            return _pstr[idx];

        }
        else
        {
            static char nullchar = '\0';
            return nullchar;
        }
    }

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
    s3[0] = 'H';
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
    cout << "s1[0] = " << s1[0] << endl;
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

