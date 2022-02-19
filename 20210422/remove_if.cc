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

bool func(int number)
{
    return number > 4;
}
void test()
{
    vector<int> numberVec = {1, 3, 7, 8, 1, 2, 5, 7, 9, 4, 6, 7};
    copy(numberVec.begin(), numberVec.end(), ostream_iterator<int>(cout, "  "));
    cout << endl;

    cout << endl;
    auto it = remove_if(numberVec.begin(), numberVec.end(), func);
    numberVec.erase(it, numberVec.end());
    copy(numberVec.begin(), numberVec.end(), ostream_iterator<int>(cout, "  "));
    cout << endl;

}

void test2()
{
    vector<int> numberVec = {1, 3, 7, 8, 1, 2, 5, 7, 9, 4, 6, 7};
    copy(numberVec.begin(), numberVec.end(), ostream_iterator<int>(cout, "  "));
    cout << endl;

    cout << endl;
    auto it = remove_if(numberVec.begin(), numberVec.end(), 
                        bind2nd(std::greater<int>(), 4));
    /* auto it = remove_if(numberVec.begin(), numberVec.end(), */ 
    /*                     bind1st(std::less<int>(), 4)); */
    /* auto it = remove_if(numberVec.begin(), numberVec.end(), [](int number) */
    /*                     -> bool { */
    /*                     return number > 4; */
    /*                     }); */
    numberVec.erase(it, numberVec.end());
    copy(numberVec.begin(), numberVec.end(), ostream_iterator<int>(cout, "  "));
    cout << endl;

}

void test3()
{
    vector<int> number;
    number.push_back(1);

    bool flag = true;
    auto it = number.begin();
    for(; it != number.end(); ++it)
    {
        cout << *it << "  ";
        if(flag)
        {
            number.push_back(2);//底层已经发生了扩容
            flag = false;
            it = number.begin();
        }
    }
}
int main(int argc, char **argv)
{
    test3();
    return 0;
}

