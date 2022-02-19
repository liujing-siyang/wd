#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::mem_fn;

class Number
{
public:
    Number(size_t data = 0)
    : _data(data)
    {
    }

    void print() const
    {
        cout << _data << "  ";
    }

    bool isEven() const
    {
        return (0 == _data % 2);
    }

    bool isPrime() const
    {
        if(1 == _data)
        {
            return false;
        }

        //质数/素数
        for(size_t idx = 2; idx <= _data/2; ++idx)
        {
            if(0 == _data % idx)
            {
                return false;
            }
        }

        return true;
    }

private:
    size_t _data;
};

void test()
{
    vector<Number> numbers;
    for(size_t idx = 1; idx != 30; ++idx)
    {
        numbers.push_back(Number(idx));
    }

    std::for_each(numbers.begin(), numbers.end(), mem_fn(&Number::print));
    /* std::for_each(numbers.begin(), numbers.end(), &Number::print); */
    cout << endl;

    //erase函数参数之前说过，两个参数，
    numbers.erase(remove_if(numbers.begin(), numbers.end(), mem_fn(&Number::isEven)), numbers.end());
    std::for_each(numbers.begin(), numbers.end(), mem_fn(&Number::print));
    cout << endl;

    numbers.erase(remove_if(numbers.begin(), numbers.end(), mem_fn(&Number::isPrime)), numbers.end());
    std::for_each(numbers.begin(), numbers.end(), mem_fn(&Number::print));
    cout << endl;
}

int main(int argc, char **argv)
{
    test();
    return 0;
}
