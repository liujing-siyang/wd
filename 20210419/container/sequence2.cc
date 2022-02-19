#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::deque;
using std::list;
using std::string;

template <typename Container>
void display(const Container &c)
{
    for(auto &elem : c)
    {
        cout << elem << "  ";
    }
    cout << endl;
}

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

void test00()
{
    vector<Point> vec;
    vec.push_back(Point(1, 2));
    vec.emplace_back(1, 2);//Point(1, 2)
}
void test()
{
    cout << "sizeof(vector<int>) = " << sizeof(vector<int>) << endl;
    cout << "sizeof(vector<string>) = " << sizeof(vector<string>) << endl;
    cout << endl;

    vector<int> number{1, 3, 5, 7, 9, 2, 4, 5, 3, 2};
    display(number);
    cout << "number.size() = " << number.size() << endl;
    cout << "number.capacity() = " << number.capacity() << endl;

    cout << endl << "在vector的尾部进行插入与删除" << endl;
    number.push_back(11);
    number.push_back(19);
    display(number);
    cout << "number.size() = " << number.size() << endl;
    cout << "number.capacity() = " << number.capacity() << endl;
    number.pop_back();
    display(number);
    number.shrink_to_fit();//缩减空间
    cout << "number.size() = " << number.size() << endl;
    cout << "number.capacity() = " << number.capacity() << endl;

    //为什么vector不支持在头部进行插入与删除?
    //取出第一个元素？
    /* int arr[10]; */
    &number;//error,不是第一个元素的地址
    &number[0];//取出第一个元素的地址
    &*number.begin();//ok
    int *pData = number.data();

    cout << endl << "在vector的中间进行插入" << endl;
    auto it3 = number.begin();
    ++it3;
    ++it3;
    cout << "*it3 = " << *it3 << endl;
    cout << "number.size() = " << number.size() << endl;
    cout << "number.capacity() = " << number.capacity() << endl;
    number.insert(it3, 100);
    display(number);
    cout << "*it3 = " << *it3 << endl;
    cout << "number.size() = " << number.size() << endl;
    cout << "number.capacity() = " << number.capacity() << endl;

    cout << endl;
    it3 = number.begin();
    ++it3;
    ++it3;
    cout << "*it3 = " << *it3 << endl;
    number.insert(it3, 30, 20);
    display(number);
    cout << "*it3 = " << *it3 << endl;
    cout << "number.size() = " << number.size() << endl;
    cout << "number.capacity() = " << number.capacity() << endl;

    cout << endl;
    int arr[] = {10, 30, 50};
    it3 = number.begin();
    ++it3;
    ++it3;
    cout << "*it3 = " << *it3 << endl;
    number.insert(it3, arr, arr + 3);
    display(number);
    cout << "*it3 = " << *it3 << endl;
    cout << "number.size() = " << number.size() << endl;
    cout << "number.capacity() = " << number.capacity() << endl;

    cout << endl << "vector清空元素" << endl;
    number.clear();
    number.shrink_to_fit();//缩减空间
    cout << "number.size() = " << number.size() << endl;
    cout << "number.capacity() = " << number.capacity() << endl;
    
}

void test2()
{
    deque<int> number{1, 3, 5, 7, 9, 2, 4, 5, 3, 2};
    display(number);

    cout << endl << "在deque的尾部进行插入与删除" << endl;
    number.push_back(11);
    number.push_back(19);
    display(number);
    number.pop_back();
    display(number);

    cout << endl << "在deque的头部进行插入与删除" << endl;
    number.push_front(0);
    number.push_front(123);
    display(number);
    number.pop_front();
    display(number);

    cout << endl << "在deque的中间进行插入" << endl;
    auto it3 = number.begin();
    ++it3;
    ++it3;
    cout << "*it3 = " << *it3 << endl;
    number.insert(it3, 100);
    display(number);
    cout << "*it3 = " << *it3 << endl;

    cout << endl;
    number.insert(it3, 30, 20);
    display(number);
    cout << "*it3 = " << *it3 << endl;

    cout << endl;
    int arr[] = {10, 30, 50};
    number.insert(it3, arr, arr + 3);
    display(number);
    cout << "*it3 = " << *it3 << endl;

    cout << endl << "deque清空元素" << endl;
    number.clear();
    number.shrink_to_fit();//缩减空间
    cout << "number.size() = " << number.size() << endl;
}

void test3()
{
    list<int> number{1, 3, 5, 7, 9, 2, 4, 5, 3, 2};
    display(number);

    cout << endl << "在list的尾部进行插入与删除" << endl;
    number.push_back(11);
    number.push_back(19);
    display(number);
    number.pop_back();
    display(number);

    cout << endl << "在list的头部进行插入与删除" << endl;
    number.push_front(0);
    number.push_front(123);
    display(number);
    number.pop_front();
    display(number);

    cout << endl << "在list的中间进行插入" << endl;
    auto it3 = number.begin();
    ++it3;
    ++it3;
    cout << "*it3 = " << *it3 << endl;
    number.insert(it3, 100);
    display(number);
    cout << "*it3 = " << *it3 << endl;

    cout << endl;
    number.insert(it3, 3, 20);
    display(number);
    cout << "*it3 = " << *it3 << endl;

    cout << endl;
    int arr[] = {10, 30, 50};
    number.insert(it3, arr, arr + 3);
    display(number);
    cout << "*it3 = " << *it3 << endl;

    cout << endl << "list清空元素" << endl;
    number.clear();
    /* number.shrink_to_fit();//缩减空间 */
    cout << "number.size() = " << number.size() << endl;
    /* number.capacity();//error */
}

int main(int argc, char **argv)
{
    cout << endl << "test vector ..." << endl;
    test2();
#if 0
    cout << endl << "test deque ..." << endl;
    test2();
    cout << endl << "test list ..." << endl;
    test3();
#endif
    return 0;
}

