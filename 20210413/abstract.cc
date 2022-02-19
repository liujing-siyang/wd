#include <iostream>

using std::cout;
using std::endl;


//将构造函数用protected进行修饰之后，该类不能不能创建对象
//该类是一个抽象
class Base
{
public:
private:
protected:
    Base()
    {
        cout << "Base()" << endl;
    }
};

class Derived
: public Base
{
public:
    Derived()
    : Base()
    {

    }
};
int main(int argc, char **argv)
{
    /* Base base;//error */
    Derived deived;
    return 0;
}

