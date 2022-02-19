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

    void print()
    {
        cout << "(" << _ix 
             << ", " << _iy 
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
    /* int a; */
    Point pt(1, 2);//栈对象
    pt.~Point();//析构函数可以显示调用,一般不建议显示调用析构函数
    pt.print();
}

void test2()
{
    Point pt1(1, 2);//栈对象
    cout << "pt1 = ";
    pt1.print();

    cout << endl;
    Point pt2 = pt1;//构造函数的调用，拷贝（复制）构造函数
    cout << "pt2 = ";
    pt2.print();

}
int main(int argc, char **argv)
{
    test2();

    return 0;
}

