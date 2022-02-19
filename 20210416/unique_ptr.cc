#include <iostream>
#include <memory>
#include <vector>

using std::cout;
using std::endl;
using std::unique_ptr;
using std::vector;

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
    unique_ptr<int> up(pInt);//up托管pInt指向的堆空间的资源
    cout << "*up = " << *up << endl;
    printf("pInt = %p\n", pInt);
    printf("up = %p\n", up.get());

    cout << endl;
    Point *pt = new Point(1, 4);
    unique_ptr<Point> pt2(pt);
    printf("pt = %p\n", pt);
    printf("pt2 = %p\n", pt2.get());

    /* unique_ptr<int> up2(up);//error */

    /* unique_ptr<int> up3(new int(100)); */
    /* up3 = up;//error */

    unique_ptr<Point> up4(new Point(3, 7));
    vector<unique_ptr<Point>> vec;
    //vec.push_back(up4);会调用拷贝构造函数，但在unique_ptr拷贝构造函数已经delete了，报错
    vec.push_back(std::move(up4));//转成右值调用的是移动构造函数
    vec.push_back(unique_ptr<Point>(new Point(1, 2)));

}
int main(int argc, char **argv)
{
    test();
    return 0;
}

