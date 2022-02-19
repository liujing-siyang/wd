#include <iostream>
#include <vector>
#include <deque>
#include <list>

using std::cout;
using std::endl;
using std::vector;
using std::deque;
using std::list;


void test()
{
    /* vector<int> number;//1、空对象 */
    /* vector<int> number(10, 1);//2、count个数据 */
    /* int arr[10] = {1, 3, 5, 7, 9, 2, 4, 6}; */
    /* vector<int> number(arr, arr + 10);//3、迭代器范围,左闭右开 */
    vector<int> number = {1, 3, 5, 7, 9, 2, 4, 6};//4、大括号形式

    //遍历1:下标
    for(size_t idx = 0; idx != number.size(); ++idx)
    {
        cout << number[idx] << "  ";
    }
    cout << endl;

    //遍历2：迭代器
    vector<int>::iterator it;
    for(it = number.begin(); it != number.end(); ++it)
    {
        cout << *it << "  ";
    }
    cout << endl;

    //遍历3：auto + 迭代器
    auto it2 = number.begin();
    for(; it2 != number.end(); ++it2)
    {
        cout << *it2 << "  ";
    }
    cout << endl;

    //遍历4：for + auto
    for(auto &elem : number)
    {
        cout << elem << "  ";
    }
    cout << endl;
}

void test2()
{
    /* deque<int> number;//1、空对象 */
    /* deque<int> number(10, 1);//2、count个数据 */
    /* int arr[10] = {1, 3, 5, 7, 9, 2, 4, 6}; */
    /* deque<int> number(arr, arr + 10);//3、迭代器范围,左闭右开 */
    deque<int> number = {1, 3, 5, 7, 9, 2, 4, 6};//4、大括号形式

    //遍历1:下标
    for(size_t idx = 0; idx != number.size(); ++idx)
    {
        cout << number[idx] << "  ";
    }
    cout << endl;

    //遍历2：迭代器
    deque<int>::iterator it;
    for(it = number.begin(); it != number.end(); ++it)
    {
        cout << *it << "  ";
    }
    cout << endl;

    //遍历3：auto + 迭代器
    auto it2 = number.begin();
    for(; it2 != number.end(); ++it2)
    {
        cout << *it2 << "  ";
    }
    cout << endl;

    //遍历4：for + auto
    for(auto &elem : number)
    {
        cout << elem << "  ";
    }
    cout << endl;
}

void test3()
{
    /* list<int> number;//1、空对象 */
    /* list<int> number(10, 1);//2、count个数据 */
    /* int arr[10] = {1, 3, 5, 7, 9, 2, 4, 6}; */
    /* list<int> number(arr, arr + 10);//3、迭代器范围,左闭右开 */
    list<int> number = {1, 3, 5, 7, 9, 2, 4, 6};//4、大括号形式

    //遍历1:list不支持下标访问//error
    /* for(size_t idx = 0; idx != number.size(); ++idx) */
    /* { */
    /*     cout << number[idx] << "  "; */
    /* } */
    /* cout << endl; */

    //遍历2：迭代器
    list<int>::iterator it;
    for(it = number.begin(); it != number.end(); ++it)
    {
        cout << *it << "  ";
    }
    cout << endl;

    //遍历3：auto + 迭代器
    auto it2 = number.begin();
    for(; it2 != number.end(); ++it2)
    {
        cout << *it2 << "  ";
    }
    cout << endl;

    //遍历4：for + auto
    for(auto &elem : number)
    {
        cout << elem << "  ";
    }
    cout << endl;
}
int main(int argc, char **argv)
{
    test3();
    return 0;
}

