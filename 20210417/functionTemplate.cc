#include <string.h>//C头文件
#include <iostream>
#include <string>//C++头文件

using std::cout;
using std::endl;
//            参数推导
//函数模板===================模板函数
//         实例化（从抽象到具体）
//
//隐式实例化
//显示实例化
//函数模板
/* template <class T> */
template <typename T>//模板参数
T add(T t1, T t2)
{
    cout << "T add(T, T)" << endl;
    return t1 + t2;
}

template <typename T>//模板参数
T add(T t1, T t2, T t3)
{
    cout << "T add(T, T, T)" << endl;
    return t1 + t2 + t3;
}

//普通函数比函数模板优先执行
//
//函数模板与普通函数可以进行重载
//
//函数模板可以与函数模板进行重载
//
//模板函数
int add(int t1, int t2)
{
    cout << "int add(int, int)" << endl;
    return t1 + t2;
}


#if 0
float add(float t1, float t2)
{
    cout << "float add(float, float)" << endl;
    return t1 + t2;
}
#endif

//模板的特化
//模板的全特化，
//模板的偏特化(部分特化)
template <>
const char *add(const char *p1, const char *p2)
{
    cout << "const char *add(const char *, const char *)" << endl;
    char *ptmp =  new char[strlen(p1) + strlen(p2) + 1]() ;
    strcpy(ptmp, p1);
    strcat(ptmp, p2);

    return ptmp;
}
void test()
{
    int ia = 3, ib = 4, ic = 5;
    float fa = 3.3, fb = 4.4;
    char ca = 'a', cb = 1;

    const char *pstr1 = "hello";
    const char *pstr2 = "world";


    cout << "add(ia, ib) = " << add(ia, ib) << endl;//隐式实例化
    cout << "add(fa, fb) = " << add<float>(fa, fb) << endl;//显示实例化
    cout << "add(ca, cb) = " << add(ca, cb) << endl;

    cout << "add(ia, fb) = " << add(ia, fb) << endl;//仅仅只有模板的时候，类型必须一样

    cout << "add(ia, ib, ic) = " << add(ia, ib, ic) << endl;//隐式实例化
    cout << "add(pstr1, pstr2) = " << add(pstr1, pstr2) << endl;
}
int main(int argc, char **argv)
{
    test();
    return 0;
}

