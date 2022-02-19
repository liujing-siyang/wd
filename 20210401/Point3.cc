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
    //
    //1、拷贝构造函数参数中的引用符号能不能去掉？
    //不能，因为在调用拷贝构造函数的时候，会满足调用时机1，
    //就会形成假递归，无线循环下去，函数的参数存在栈上，
    //最终导致栈溢出
    //
    //2、拷贝构造函数的const可以去掉吗？
    //不能，如果去掉const，就存在非const左值绑定到了右值，而
    //非const左值引用不能绑定到右值，所以当传递右值(临时对象
    //、匿名对象、字面值常量)时候就报错
    Point(const Point &rhs)
    /* Point(Point &rhs) */
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
    //1、拷贝构造函数的调用时机1：当用一个已经存在的对象去初始化一个
    //刚刚创建的对象的时候，会调用拷贝构造函数
    //Point(const Point rhs)
    //const Point rhs = pt1
    //const Point rhs = pt1
    //const Point rhs = pt1
    Point pt2 = pt1;//构造函数的调用，拷贝（复制）构造函数
    cout << "pt2 = ";
    pt2.print();

}


//void func2(int a)
//2、拷贝构造函数的调用时机2：当形参与实参结合的时候，会调用拷贝
//构造函数
void func2(Point pt)//Point pt = pt1;
{
    cout << "pt = ";
    pt.print();
}

void test3()
{
    //int b(10);
    Point pt1(3, 5);
    cout << "pt1 = ";
    pt1.print();

    cout << endl;
    func2(pt1);
}

int func0()
{
    int a(10);
    return a;
}

//3、拷贝构造函数的调用时机3：当函数的返回类型是类类型的时候
//在执行return语句的时候，会调用拷贝构造函数
//（优化开关:-fno-elide-constructors）
Point func3()
{
    Point pt3(3, 5);
    cout << "pt3 = ";
    pt3.print();

    return pt3;
}

void test4()
{

    int a = 10;
    int b = a;

    int number = 100;
    int &ref = number;
    &number;
    const int &ref2 = 100;
    const int &ref3 = number;
    /* &100;//error */


    //Point(Point &rhs)
    /* &func3();//error */
    const Point &rhs = func3();
    Point pt4 = func3();//func3()返回的对象是临时对象/匿名对象,
                        //它的生命周期只在本行
    cout << "pt4 = ";
    pt4.print();
}
int main(int argc, char **argv)
{
    test4();

    return 0;
}

