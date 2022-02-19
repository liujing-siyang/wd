#include <iostream>
#include <unordered_map>
#include <string>

using std::cout;
using std::endl;
using std::unordered_map;
using std::string;

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
    //key值唯一
    //key值没有顺序
    unordered_map<string, string> number = {
        {"111", "wuhan"},
        {"222", "hainan"},
        std::pair<string, string>("666", "xinjiang"),
        std::pair<string, string>("555", "xinjiang"),
        std::make_pair("888", "beijing"),
        std::make_pair("777", "beijing"),
        std::pair<string, string>("555", "xinjiang1"),
    };

    display(number);
}

class Point
{
public:
    Point(int ix = 0, int iy = 0)
    : _ix(ix)
    , _iy(iy)
    {
        /* cout << "Point(int, int)" << endl; */
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
        /* cout << "~Point()" << endl; */
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
    unordered_map<string, Point> number = {
        {"111", Point(1, 2)},
        {"333", Point(-1, 2)},
        std::pair<string, Point>("444", Point(4, 5)),
        std::pair<string, Point>("888", Point(4, 5)),
        std::make_pair("777", Point(1, 4)),
        std::make_pair("777", Point(3, 4)),
        {"333", Point(-1, 2)},
    };
    display(number);

    cout << endl << "map的插入" << endl;
    number.insert(std::make_pair("555", Point(19, 2)));
    display(number);

    cout << endl << "map的下标访问" << endl;
    cout << "number[111] = " << number["111"] << endl;
    cout << "number[666] = " << number["666"] << endl;
    cout << "222222" << endl;
    number["666"] = Point(7, 8);//临时对象（匿名对象），右值
    display(number);

}
int main(int argc, char **argv)
{
    test2();
    return 0;
}

