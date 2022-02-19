#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void printVectorCapacity(const vector<int> &vc)
{
    cout << "vc.size() = " << vc.size() << endl
         << "vc.capacity() = " << vc.capacity() << endl;
}
void test()
{
    //vector的底层扩容原理：当size()== capacity()之后，如果还要继续
    //插入元素，就会按照2 * capacity()进行扩容，接着将老的空间中的元素
    //拷贝到新的空间来，再将新的元素插入到新的空间的后面，然后将老的
    //空间进行释放
    vector<int> vec;
    vec.reserve(9);
    printVectorCapacity(vec);

    cout << endl;
    vec.push_back(1);
    printVectorCapacity(vec);

    cout << endl;
    vec.push_back(2);
    printVectorCapacity(vec);

    cout << endl;
    vec.push_back(3);
    printVectorCapacity(vec);

    cout << endl;
    vec.push_back(4);
    printVectorCapacity(vec);

    cout << endl;
    vec.push_back(5);
    printVectorCapacity(vec);

    cout << endl;
    vec.push_back(5);
    printVectorCapacity(vec);

    cout << endl;
    vec.push_back(5);
    printVectorCapacity(vec);

    cout << endl;
    vec.push_back(5);
    printVectorCapacity(vec);

    cout << endl;
    vec.push_back(5);
    printVectorCapacity(vec);

    cout << endl;
    vec.push_back(5);
    printVectorCapacity(vec);
}

int main(int argc, char **argv)
{
    test();
    return 0;
}

