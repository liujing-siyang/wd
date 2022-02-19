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
    //int arr[5] = {1, 3, 4};
    Point pt[5] = {Point(1, 2), Point(3, 4), Point(5, 6)};
    pt[0].print();
    pt[1].print();

    cout << endl;
    //逗号表达式
    Point pt2[5] = {{1, 2}, {3, 4}, {5, 6}};
    pt2[0].print();
    pt2[1].print();
}

void test2()
{
    Point *pt = new Point(1, 2);
    pt->print();

    delete pt;
    pt = nullptr;

    cout << endl;
    Point *pArray = new Point[5]();
    pArray[0] = Point(1, 3);
    pArray[1] = {4, 8};


    /* delete [] pArray; */
    free(pArray);
}
int main(int argc, char **argv)
{
    test2();

    return 0;
}

