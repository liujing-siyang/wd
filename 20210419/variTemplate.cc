#include <iostream>

using std::cout;
using std::endl;
#if 0
template <typename T1, typename T2>
void print(T1 t1, T2 t2)
{

}

template <typename T1, typename T2, typename T3, typename T4>
void print(T1 t1, T2 t2, T3 t3, T4 t4)
{

}
#endif

template <typename... Args>//template <typename T1, typename T2, ....>,Args模板参数包
void print(Args... args)//T1 t1, T2 t2,....//args,函数参数包
{
    /* cout << "sizeof(Args) = " << sizeof(Args) << endl; */
    cout << "sizeof...(Args) = " << sizeof...(Args) << endl;
    cout << "sizeof...(args) = " << sizeof...(args) << endl;

    /* cout << args... << endl; */
    /* cout << ...args << endl; */
}

void display();

template <typename T, typename... Args>
void display(T t1, Args... args)
{
    cout << t1 << " ";
    display(args...);//解包
}

void display()
{
    cout << endl;
}

void test2()
{
    display();
    display(1, 2);
    //cout << 1 << " ";
    //display(2);
    //   cout << 2 << " ";
    //   display();
    //     cout << endl;
    display(1, 'a', true);
    //cout << 1 << " ";
    //display('a', true);
    // cout << 'a' << " ";
    //  display(true);
    //    cout << 1 << " ";
    //    display();
    //       cout << endl;
    display(1, 'a', true, "helloworld");
}

void test()
{
    print();
    print(1, 'a');
    print(1, 'a', 3.3, true);
}

int sum()
{
    return 0;
}

template <typename T, typename... Args>
T sum(T t1, Args... args)
{
    return t1 + sum(args...);
}

void test3()
{
    cout << "sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) = "
         << sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << endl;
}
int main(int argc, char **argv)
{
    test3();
    return 0;
}

