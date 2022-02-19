#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

template <typename Container>
void display(const Container &c)
{
    for(auto &elem : c)
    {
        cout << elem << "  ";
    }
    cout << endl;
}

void test()
{
    vector<int> number{1, 3, 5, 7, 9, 2, 4, 5, 3, 2};
    display(number);
    cout << "number.size() = " << number.size() << endl;
    cout << "number.capacity() = " << number.capacity() << endl;

    auto it3 = number.begin();
    ++it3;
    ++it3;
    cout << "*it3 = " << *it3 << endl;
    number.insert(it3, 100);
    display(number);
    cout << "*it3 = " << *it3 << endl;
    cout << "number.size() = " << number.size() << endl;
    cout << "number.capacity() = " << number.capacity() << endl;

    //insert扩容原理
    //capacity() = n, size() = m, 待插入元素的个数t,
    //1、t < n - m;此时不会扩容
    //2 n - m < t < m;此时按照2 * m（2 * size()）
    //3、m < t < n,此时就是t + m;
    //4、t > n,此时按照  t + m
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
int main(int argc, char **argv)
{
    test();
    return 0;
}

