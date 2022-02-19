#include <iostream>
#include <list>

using std::cout;
using std::endl;
using std::list;

template <typename Container>
void display(const Container &c)
{
    for(auto &elem : c)
    {
        cout << elem << "  ";
    }
    cout << endl;
}

struct Com
{
    bool operator()(const int &lhs, const int &rhs) const
    {
        return lhs < rhs;
    }
};

void test()
{
    list<int> number = {1, 5, 9, 4, 6, 2, 7, 5};
    display(number);
    number.unique();
    display(number);

    cout << endl << "test sort...." << endl;
    number.sort();
    /* number.sort(std::less<int>()); */
    /* number.sort(std::greater<int>()); */
    /* number.sort(Com()); */
    display(number);

    cout << endl << "test reverse..." << endl;
    number.reverse();
    display(number);

    cout << endl << "test unique..." << endl;
    number.unique();//先要排序，不然重复元素去不掉
    display(number);

    cout << endl << "test merge..." << endl;
    list<int> number2{10, 8, 30};
    number.sort();
    number2.sort();
    /* number2.sort(std::greater<int>()); */
    number.merge(number2);
    display(number);
    display(number2);

    cout << endl << "test splice..." << endl;
    list<int> number3 = {3, 0, 12, 29};
    auto it = number.begin();
    ++it;
    ++it;
    /* number.splice(it, number3); */
    /* display(number); */
    /* display(number3); */

    cout << endl;
    auto it2 = number3.begin();
    number.splice(it, number3, it2);
    display(number);
    display(number3);

    cout << endl;
    it = number.begin();
    ++it;
    ++it;
    cout << "*it = " << *it << endl;
    auto it3 = number.end();
    --it3;
    --it3;
    cout << "*it3 = " << *it3 << endl;
    number.splice(it, number, it3);
    display(number);
}

int main(int argc, char **argv)
{
    test();
    return 0;
}

