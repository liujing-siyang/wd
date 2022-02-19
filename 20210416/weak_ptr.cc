#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::shared_ptr;
using std::weak_ptr;

class Point
{
public:
    Point(int ix = 0, int iy = 0)
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
    /* weak_ptr<Point> wp(new Point(10));//error */
    weak_ptr<Point> wp;//只能传一个weak_ptr 或share_ptr类型的指针

    {
        shared_ptr<Point> sp(new Point(10, 100));
        /* wp.operator=(sp); */
        wp = sp;
        cout << "sp.use_count() = " << sp.use_count() << endl;
        cout << "wp.use_count() = " << wp.use_count() << endl;
        //bool expired()，use_count()为0返回true；
        //这里use_count为1，返回false，所以打印的是0；
        cout << "wp.expired() = " << wp.expired() << endl;
        
        shared_ptr<Point> sp2 = wp.lock();//lock将weak_ptr提升为shared_ptr，判断共享的资源是否已经销毁的方式就是从 wp提升为sp
        if(sp2)//源代码定义了share_ptr 和 nullptr的比较运算符
        {
            cout << "提升成功" << endl;
            cout << "sp2 = ";
            sp2->print();
        }
        else
        {
            cout << "提升失败" << endl;
        }
    }//栈对象sp被销毁

    cout << endl;
    cout << "wp.expired() = " << wp.expired() << endl;//use_count()为0返回true，打印1
    shared_ptr<Point> sp2 = wp.lock();//wp为空，提升失败
    if(sp2)
    {
        cout << "提升成功" << endl;
        cout << "sp2 = ";
        sp2->print();
    }
    else
    {
        cout << "提升失败" << endl;
    }
}
int main(int argc, char **argv)
{
    test();
    return 0;
}

