#include <string.h>
#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;

//C++支持函数重载
//原理：做了名字改编
//步骤：当函数名字相同时候，根据参数列表不一样，对函数名字进行改编
//改编的时候，根据参数个数、参数顺序、参数类型进行改编
//C和C++的混合编程
#ifdef __cplusplus
extern "C"
{
#endif
int add(int x, int y)
{
    return x + y;
}
#ifdef __cplusplus
}
#endif

int add(int x, int y, int z)
{
    return x + y + z;
}

float add(float x, float y, float z)
{
    return x + y + z;
}

float add(float x, float y)
{
    return x + y;
}

float add(float x, int y, float z)
{
    return x + y + z;
}

int main(int argc, char **argv)
{
    int *pInt = static_cast<int *>(malloc(sizeof(int)));
    memset(pInt, 0, sizeof(int));
    free(pInt);
    return 0;
}

