#include <iostream>
#include <functional>

using std::cout;
using std::endl;
using std::bind;

int add(int x , int y)
{
    cout << "int add(int, int)" << endl;
    return x + y;
}

class Test
{
public:
    int add(int x , int y)
    {
        cout << "int Test::add(int, int)" << endl;
        return x + y;
    }

    int data = 135;//C++11新的方式初始化数据

};

#if 1
int func(int x, int y, int z)
{
    cout << "int add(int, int, int )" << endl;
    return x + y + z;
}
#endif

void test()
{
    /* vector<int> number; */
    //add   int(int, int) = int()
    //f的类型int(),函数也是有类型，通过函数的返回类型和参数列表进行控制
    /* auto f = std::bind(add, 1, 2); */
    //std::function是函数的容器
    std::function<int()> f = std::bind(add, 1, 2);
    cout << "f() = " << f() << endl;

    Test tst;
    /* auto f2 = bind(&Test::add, &tst, 3, 4); */
    std::function<int()> f2 = bind(&Test::add, &tst, 3, 4);
    cout << "f2() = " << f2() << endl;

    /* auto f3 = bind(func, 1, 2, 3); */
    std::function<int()> f3 = bind(func, 1, 2, 3);
    cout <<"f3() = " << f3() << endl;

    //占位符
    //add int(int, int)
    //int(int)
    /* auto f4 = bind(add, 1, std::placeholders::_1);//占位符 */
    std::function<int(int)> f4 = bind(add, 1, std::placeholders::_1);//占位符
    cout << "f4(5) = " << f4(5) << endl;

    std::function<int()> f5 = bind(&Test::data, &tst);//bind绑定到数据成员
    cout << "f5() = " << f5() << endl;
}

typedef int (*pFunc)();//函数指针

int func1()
{
    return 5;
}

int func2()
{
    return 10;
}

int func3(int x)
{
    return x;
}
void test2()
{
    pFunc f = func1; //用f注册回调函数
    cout << "f() = " << f() << endl;//执行回调函数

    f = func2;
    cout << "f() = " << f() << endl;

    /* f = func3; */
}

void func4(int x1, int x2, int x3, const int &x4, int x5)
{
    cout << "x1 = " << x1 
         << ", x2 = " << x2 
         << ", x3 = " << x3 
         << ", x4 = " << x4 
         << ", x5 = " << x5 << endl;
}

void test4()
{
    //占位符本身表示形参的位置
    //占位符中的下划线的数字表示实参的位置
    //引用包装器cref = c = const  ref = reference 
    //ref
    int number = 100;
    auto f = bind(func4, 1, std::placeholders::_9
                  , std::placeholders::_3, std::cref(number), number);
    number = 12345;
    
    f(16, 27, 19, 200, 300, 500, 100, 200, 300);
}
int main(int argc, char **argv)
{
    test();
    return 0;
}

