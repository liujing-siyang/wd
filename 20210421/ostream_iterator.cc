#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::vector;
using std::copy;

int main(int argc, char **argv)
{
    vector<int> number = {1, 4, 7, 9, 5, 3};
    ostream_iterator<int> osi(cout, "\n");
    copy(number.begin(), number.end(), osi);

    /* cout << 1 << "  " << 4 << "  " << 7 << "  " << 9 << endl; */
    return 0;
}

