#include <iostream>
#include <vector>
#include <iterator>

using std::cout;
using std::endl;
using std::vector;
using std::reverse_iterator;

int main(int argc, char **argv)
{
    vector<int> number = {1, 3, 5, 7, 9};

    vector<int>::reverse_iterator it = number.rbegin();
    for(; it != number.rend(); ++it)
    {
        cout << *it  << " ";
    }
    cout << endl;
    return 0;
}

