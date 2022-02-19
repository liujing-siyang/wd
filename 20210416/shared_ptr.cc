#include <iostream>
#include <memory>
#include <vector>

using std::cout;
using std::endl;
using std::shared_ptr;
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
    shared_ptr<int> sp(pInt);//sp托管pInt指向的堆空间的资源
    cout << "*sp = " << *sp << endl;
    cout << "sp.use_count() = " << sp.use_count() << endl;
    printf("pInt = %p\n", pInt);
    printf("sp = %p\n", sp.get());


    cout << endl << endl;
    shared_ptr<int> sp2(sp);
    cout << "*sp2 = " << *sp2 << endl;
    cout << "*sp = " << *sp << endl;
    cout << "sp2.use_count() = " << sp2.use_count() << endl;
    cout << "sp.use_count() = " << sp.use_count() << endl;
    printf("sp2 = %p\n", sp2.get());
    printf("sp = %p\n", sp.get());

    cout << endl << endl;
    shared_ptr<int> sp3(new int(100));
    cout << "*sp3 = " << *sp3 << endl;
    cout << "sp3.use_count() = " << sp3.use_count() << endl;
    printf("sp3 = %p\n", sp3.get());

    cout << endl;
    sp3 = sp;//赋值，浅拷贝
    cout << "*sp = " << *sp << endl;
    cout << "*sp2 = " << *sp2 << endl;
    cout << "*sp3 = " << *sp3 << endl;
    cout << "sp.use_count() = " << sp.use_count() << endl;
    cout << "sp2.use_count() = " << sp2.use_count() << endl;
    cout << "sp3.use_count() = " << sp3.use_count() << endl;
    printf("sp = %p\n", sp.get());
    printf("sp2 = %p\n", sp2.get());
    printf("sp3 = %p\n", sp3.get());

    cout << endl << endl;
    shared_ptr<Point> sp4(new Point(3, 7));
    vector<shared_ptr<Point>> vec;
    vec.push_back(sp4);//shared_ptr是共享的，有拷贝构造函数和赋值构造函数
    vec.push_back(shared_ptr<Point>(new Point(1, 2)));

}
int main(int argc, char **argv)
{
    test();
    return 0;
}

