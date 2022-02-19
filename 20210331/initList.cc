#include <iostream>

using std::cout;
using std::endl;

class Test
{
public:
    Test(int value)
    : _iy(value)//数据成员被初始化的顺序只与其被声明的顺序有关
    , _ix(_iy)//与其在初始化列表中的顺序没有关系
    {
        cout << "Test(int)" << endl;
    }

    void print()
    {
        cout << "(" << _ix
             << ", " << _iy
             << ")" << endl;
    }
private:
    int _iy;
    int _ix;
};
int main(int argc, char **argv)
{
    Test tst(10);
    tst.print();
    return 0;
}

