#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <set>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::set;
using std::ostream_iterator;
using std::back_inserter;
using std::back_insert_iterator;
using std::front_inserter;
using std::front_insert_iterator;
using std::inserter;
using std::insert_iterator;
using std::copy;


void test()
{
    vector<int> numberVec = {1, 5, 9, 5, 2};
    list<int> numberList = {3, 7, 4, 9, 2};

    //将list中的数据拷贝到vector
    copy(numberList.begin(), numberList.end(), back_insert_iterator<vector<int>>(numberVec));
    //底层实际上调用了push_back
    copy(numberVec.begin(), numberVec.end(), ostream_iterator<int>(cout, "  "));
    cout << endl;
    
    //将vector中的数据拷贝到list的前面
    copy(numberVec.begin(), numberVec.end(), front_insert_iterator<list<int>>(numberList));
    //底层实际上调用了push_front
    copy(numberList.begin(), numberList.end(), ostream_iterator<int>(cout, "  "));
    cout << endl;

    set<int> numberSet = {3, 5, 8, 9, 12, 4, 6};
    //将vector中的数据拷贝到set的中间
    auto it = numberSet.begin();
    ++it;
    copy(numberVec.begin(), numberVec.end(), insert_iterator<set<int>>(numberSet, it));
    //底层实际上调用了insert
    copy(numberSet.begin(), numberSet.end(), ostream_iterator<int>(cout, "  "));
    cout << endl;
}

int main(int argc, char **argv)
{
    test();
    return 0;
}

