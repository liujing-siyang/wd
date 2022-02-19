#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;


void test()
{
    int a = 10;
    int b = 20;
    int *pflag = &a;
    vector<int> vec;
    string s1 = "hello";
    string s2 = "world";


    //非const左值引用只能绑定到左值
    //const左值引用可以绑定到左值与右值,叫做万能引用
    const int &ref = a;
    const int &ref2 = 10;
    &pflag;
    &(*pflag);
    &vec;
    &s1;
    &s2;

    /* &(a + b);//error */
    /* &(s1 + s2);//error */
    /* &(a++);//error */
    &(++a);//ok

    int &&rref = 10;//右值引用可以绑定到右值
    /* int &&rref2 = a;//右值引用不能绑定到左值 */

    &rref;



}

//右值引用不一定是左值
int &&func()
{
    return 10;
}

void test2()
{
    int number1 = 10;
    int number2 = 10;
    number2 = std::move(number1);//std::move对于内置类型不起作用
    &number1;
    cout << "number1 = " << number1 << endl;
    cout << "number2 = " << number2 << endl;

}
int main(int argc, char **argv)
{
    test2();
    return 0;
}

