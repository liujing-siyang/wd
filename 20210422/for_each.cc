#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using std::cout;
using std::endl;
using std::for_each;
using std::vector;
using std::ostream_iterator;
using std::copy;

void print(int &number)
{
    ++number;
    cout << number << "  ";
}
void test()
{
    vector<int> numberVec = {1, 3, 5, 7, 9, 4, 6, 7};
    copy(numberVec.begin(), numberVec.end(), ostream_iterator<int>(cout, "  "));
    cout << endl;

    for_each(numberVec.begin(), numberVec.end(), print);
    cout << endl;
    copy(numberVec.begin(), numberVec.end(), ostream_iterator<int>(cout, "  "));
    cout << endl;

    //匿名函数
    for_each(numberVec.begin(), numberVec.end(),[] (int &number)
             {
             ++number;
             cout << number << "  ";

             });
    cout << endl;
    
}

void test2()
{
    vector<int> numberVec = {1, 3, 5, 7, 9, 4, 6, 7};
    copy(numberVec.begin(), numberVec.end(), ostream_iterator<int>(cout, "  "));
    cout << endl;

    size_t cnt1 = count(numberVec.begin(), numberVec.end(), 7);
    cout << "cnt1 = " << cnt1 << endl;

    auto it = find(numberVec.begin(), numberVec.end(), 3);
    if(it == numberVec.end())
    {
        cout << "该元素不存在vector中" << endl;
    }
    else
    {
        cout << "该元素存在vector中" << *it << endl;
    }
}
int main(int argc, char **argv)
{
    test2();
    return 0;
}

