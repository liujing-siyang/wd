#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;
using std::istream_iterator;
using std::ostream_iterator;
using std::vector;
using std::copy;

void test()
{
    vector<int> number;
    istream_iterator<int> isi(cin);
    cout << "111" << endl;
    /* copy(isi, istream_iterator<int>(), number.end()); */
    copy(isi, istream_iterator<int>(), back_inserter(number));
    cout << "222" << endl;

    /* ostream_iterator<int> osi(cout, "\n"); */
    copy(number.begin(), number.end(), ostream_iterator<int>(cout, " "));
    cout << "333" << endl;
}

int main(int argc, char **argv)
{
    test();
    return 0;
}

