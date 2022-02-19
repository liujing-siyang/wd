#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
    //默认情况下，编译器会自动生成一个默认（无参）构造函数
    //
    //当有自定义构造函数的时候，编译器就不会再自动生成默认构造函数
    //如果还想调用默认构造函数的时候，必须显示定义
    //
    //构造函数是可以进行重载的
    //
    Point()
    : _ix(0)//真正初始化数据成员的位置，称为初始化表达式（初始化列表）
    , _iy(0)
    {
        cout << "Point()" << endl;
        /* _ix = 0;//赋值 */
        /* _iy = 0; */
    }
    
    //构造函数特点：与类名相同，没有返回类型，void都没有
    //作用：完成数据成员的初始化
    Point(int ix, int iy)
    : _ix(ix)
    , _iy(iy)
    {
        cout << "Point(int, int)" << endl;
        /* _ix = ix;//赋值 */
        /* _iy = iy; */
    }

    void print()
    {
        cout << "(" << _ix 
             << ", " << _iy 
             << ")" << endl;
    }
private:
    int _ix;
    int _iy;
};
int main(int argc, char **argv)
{
    Point pt1;
    pt1.print();
    Point pt(1, 2);//对象创建的时候，会自动调用构造函数
    /* pt.Point(2, 3);//error,构造函数不能用调用 */
    pt.print();
    Point(2, 3).print();//构造函数的调用会创建对象
    return 0;
}

