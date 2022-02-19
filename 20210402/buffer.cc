#include <unistd.h>
#include <iostream>

using std::cout;
using std::endl;
using std::flush;
using std::ends;

void test()
{
    for(size_t idx = 0;idx < 1024; ++idx)
    {
        cout << 'a';
    }
    /* cout << "123" << endl;//刷新缓冲区,可以换行 */
    /* cout << "123" << flush;//刷新缓冲区，不可以换行 */
    cout << "123" << ends;//不能刷新缓冲区，不可以换行

    sleep(5);
}
int main(int argc, char **argv)
{
    test();
    return 0;
}

