#include <iostream>

using std::cout;
using std::endl;

//模板参数的分类
//1、类型参数  T
//2、非类型参数， 整型,常量表达式：short/char/int/long/szie_t ,非整型float/double
template <typename T = int, short kMin = 10>
T multiply(T t1, T t2)
{
    return t1 * t2 *kMin;
}

int main(int argc, char **argv)
{
    int ia = 3, ib = 4;
    double da = 3.3, db = 4.4;
    cout << "multiply(ia, ib) = " << multiply(ia, ib) << endl;
    cout << "multiply(ia, ib) = " << multiply<int, 20>(ia, ib) << endl;
    return 0;
}

