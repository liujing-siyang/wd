#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
    Point()
    : _ix(0)//真正初始化数据成员的位置，称为初始化表达式（初始化列表）
    , _iy(0)
    {
        cout << "Point()" << endl;
    }
    
    Point(int ix, int iy)
    : _ix(ix)
    , _iy(iy)
    {
        cout << "Point(int, int)" << endl;
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
int main(int argc, char **argv)
{
    cout << "before test..." << endl;
    test();
    cout << "after test..." << endl;

    return 0;
}

