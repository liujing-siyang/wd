#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::auto_ptr;

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
    //裸指针
    int *pInt  = new int(10);
    auto_ptr<int> ap(pInt);//ap托管pInt指向的堆空间的资源
    cout << "*ap = " << *ap << endl;
    printf("pInt = %p\n", pInt);//地址一致
    printf("ap = %p\n", ap.get());

    cout << endl;
    Point *pt = new Point(1, 4);
    auto_ptr<Point> pt2(pt);
    printf("pt = %p\n", pt);//地址一致
    printf("pt2 = %p\n", pt2.get());

    auto_ptr<int> ap2(ap);//表面上执行拷贝构造函数，但是底层已经发生了
                      //发生了所有权的转移，按照移动语义应该将拷贝构造函数和赋值构造函数delete掉，这里就会直接报错
    cout << "*ap2 = " << *ap2 << endl;
    cout << " *ap = " << *ap << endl;//移动语义已经将资源转移，导致错误
}
int main(int argc, char **argv)
{
    test();
    return 0;
}

