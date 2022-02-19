#include <iostream>
#include <map>
#include <string>
#include <utility>

using std::cout;
using std::endl;
using std::map;
using std::string;
using std::make_pair;

template <typename Container>
void display(const Container &c)
{
    for(auto &elem : c)
    {
        cout << elem.first << "  "
             << elem.second << endl;
    }
}

void test()
{
    map<int, string> number = {
        {1, "wuhan"},
        {2, "nanjing"},
        std::pair<int, string>(4, "shanghai"),
        std::pair<int, string>(8, "nanjing"),
        std::pair<int, string>(8, "nanjing"),
        make_pair(5, "xinjiang"),
        make_pair(6, "nanjing"),
    };
    display(number);

    cout << endl << "map的插入" << endl;
    number.insert({10, "wuhan"});
    /* number.insert(std::pair<int, string>(10, "wuhan"));//ok */
    /* number.insert(make_pair(10, "wuhan"));//ok */

    cout << endl << "map的下标访问" << endl;
    cout << "number[1] = " << number[1] << endl;
    cout << "number[0] = " << number[0] << endl;
    display(number);

    cout << endl;
    number[0] = "henan";
    display(number);
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

    /* float getDistance() const */
    /* { */
    /*     return hypot(_ix, _iy); */
    /* } */

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

    friend bool operator<(const Point &lhs, const Point &rhs);
    friend bool operator>(const Point &lhs, const Point &rhs);
    friend std::ostream &operator<<(std::ostream &os, const Point &rhs);
    friend struct Comapation;
    /* friend Comapation; */
private:
    int _ix;
    int _iy;
};

std::ostream &operator<<(std::ostream &os, const Point &rhs)
{
    os << "(" << rhs._ix 
       << ", " << rhs._iy 
       << ")";

    return os;
}

void test2()
{
    map<string, Point> number = {
        {"111", Point(1, 2)},
        {"333", Point(-1, 2)},
        std::pair<string, Point>("444", Point(4, 5)),
        std::pair<string, Point>("888", Point(4, 5)),
        make_pair("777", Point(1, 4)),
    };
    display(number);

    cout << endl << "map的插入" << endl;
    number.insert(make_pair("555", Point(19, 2)));
    display(number);

    cout << endl << "map的下标访问" << endl;
    cout << "number[111] = " << number["111"] << endl;
    cout << "number[666] = " << number["666"] << endl;
    cout << "222222" << endl;
    number["666"] = Point(7, 8);//临时对象（匿名对象），右值
    cout << "11111111" << endl;
}
int main(int argc, char **argv)
{
    test2();
    return 0;
}

