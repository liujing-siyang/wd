#include <iostream>

using std::cout;
using std::endl;

int number = 1;

namespace wd
{
int number = 20;

class Test
{
public:
    Test(int var)
    : number(var)
    {

    }

    void print(int number) 
    {
        cout << "形参number = " << number << endl;
        cout << "成员变量number = " << this->number << endl;
        cout << "成员变量number = " << Test::number << endl;
        cout << "命名空间中的number = " << wd::number << endl;
        cout << "全局的number = " << ::number << endl;//匿名命名空间
    }
private:
    int number;
};
}//end of namespace wd
int main(int argc, char **argv)
{
    int value = 100;
    wd::Test tst(300);
    tst.print(value);
    return 0;
}

