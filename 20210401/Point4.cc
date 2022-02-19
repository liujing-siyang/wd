#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
    Point(int ix = 0, int iy = 0)
    : _ix(ix)
    , _iy(iy)
    {
        cout << "Point(int = 0, int = 0)" << endl;
    }

    //默认情况下，编译器会自动生成拷贝构造函数
    Point(const Point &rhs)
    : _ix(rhs._ix)
    , _iy(rhs._iy)
    {
        cout << "Point(const Point &)" << endl;
    }

    //赋值运算符函数的返回类型的引用可以去掉吗？
    //不能，如果去掉，就会在执行return语句的时候，符合拷贝构造
    //函数的调用时机3，执行拷贝构造函数，调用开销变大
    //
    //赋值运算符函数的返回类型可以是void？
    //不行，考虑连等
    Point &operator=(const Point &rhs)
    /* void operator=(const Point &rhs) */
    {
        cout << "Point &operator=(const Point &)" << endl;
        _ix = rhs._ix;//赋值
        _iy = rhs._iy;
        /* return *this; */
    }

    //实质：this指针指向对象本身
    //存在；存在每一个非静态成员函数的第一个参数的位置
    //是一个指针常量
    void print(/* Point * const this*/)
    {
        /* printf("this : %p\n", this); */
        /* cout << "this1 " << this << endl; */
        /* this = nullptr; */
        /* this->_ix = 100; */
        cout << "(" << this->_ix 
             << ", " << this->_iy 
             << ")" << endl;
    }

    //析构函数：与类名相同，前面加~，没有返回类型，没有参数
    //析构函数具有唯一性，不能重载
    //作用：完成数据成员的清理工作
    //
    //默认情况下，编译器会自动生成析构函数
    ~Point()
    {
        cout << "~Point()" << endl;
    }
private:
    int _ix;
    int _iy;
};


void test()
{
    //int a(10);
    //int b = 20;
    //int c = 30;
    //c = b = a;
    Point pt1(1, 2);//栈对象
    cout << "pt1 = ";
    pt1.print();

    cout << endl;
    Point pt2(3, 4);//栈对象
    cout << "pt2 = ";
    pt2.print();

    cout << endl;
    Point pt3(5, 6);//栈对象
    cout << "pt3 = ";
    pt3.print();

    cout << endl << "使用pt2 = pt1" << endl;
    //Point &operator=(const Point rhs)
    //const Point rhs = pt1;
    //Point(const Point &rhs)
    pt3 = pt2 = pt1;
    pt2.operator=(pt1);//赋值运算符函数
    cout << "pt1 = ";
    pt1.print();
    cout << "pt2 = ";
    pt2.print();
}

int main(int argc, char **argv)
{
    test();
    return 0;
}

