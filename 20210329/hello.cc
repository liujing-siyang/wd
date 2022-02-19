#include <iostream>//C++头文件为何没有.h？因为C++的头文件都是用模板写的，模板有个特点
                   //必须要知道所有实现之后才能进行编译
using namespace std;//命名空间


//函数声明可以有多次
//函数定义只能有一次
void test();
void test();
void test();
void test();

void test()
{

}

int main(int argc, char **argv)
{
    //cout,标准输出
    //<<,输出流运算符
    //"Hello world",字符串常量
    //endl,end of line
    //operator<<运算符重载
    cout << "Hello world" << endl;
    operator<<(cout, "hello world").operator<<(endl);
    operator<<(cout, "hello world");
    cout.operator<<(endl);

    //cin,标准输入
    //>>,输入流运算符
    int number = 10;
    cin >> number;
    cout << "number = " << number << endl;
    return 0;
}

