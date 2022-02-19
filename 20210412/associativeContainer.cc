#include <iostream>
#include <set>
#include <map>
#include <string>

using std::cout;
using std::endl;
using std::set;
using std::map;
using std::string;

void test()
{
    //set的特征：
    //1、set的关键字唯一
    //2、默认情况下，按照关键字进行升序排列
    //3、底层实现用的是红黑树
    /* set<int> number = {1, 3, 5, 9, 4, 6, 2, 6, 2, 4};//初始化 */
    int arr[10] = {1, 3, 5, 9, 4, 6, 2, 6, 2, 4};
    set<int> number(arr, arr + 10);//左闭右开[0, 10)

    //遍历
    for(auto &elem : number)
    {
        cout << elem << "  ";
    }
    cout << endl;

    set<int>::iterator it;//迭代器可以看成是一种指针
    for(it = number.begin(); it != number.end(); ++it)
    {
        cout << *it << "  ";
    }
    cout << endl;

    //set的查找
    cout << endl;
    size_t cnt1 = number.count(10);
    size_t cnt2 = number.count(5);
    cout << "cnt1 = " << cnt1 << endl
         << "cnt2 = " << cnt2 << endl;

    it = number.find(6);
    if(it == number.end())
    {
        cout << "该元素不存在set容器中" << endl;
    }
    else
    {
        cout << *it << endl;
    }

    //set的插入
    cout << endl;
    /* std::pair<set<int>::iterator, bool> ret = number.insert(7); */
    auto ret = number.insert(7);
    if(ret.second)
    {
        cout << *ret.first << endl;
    }
    else
    {
        cout << "该元素已经存在，无法插入"  << endl;
    }
    for(auto &elem : number)
    {
        cout << elem << "  ";
    }
    cout << endl;

    //set的修改
    //set不支持下标访问
    /* cout << number[1] << endl;//error */

    //不支持修改操作（为了保护红黑树的结构）
    /* *it = 100;//error */
}

void test1()
{
    std::pair<int, string> number{123, "helloworld"};
    cout << number.first << "   " << number.second << endl;
}

void test2()
{
    //map的特征：
    //1、key值是唯一的
    //2、默认情况下，按照key进行排序
    map<string, string> number = {
        {"021", "wuhan"},
        {"027", "wuhan"},
        {"022", "shanghai"},
        std::pair<string, string>("0755", "shenzhen"),
        std::pair<string, string>("021", "xinjiang"),
        std::pair<string, string>("021", "nanjing"),
    };

    for(auto &elem : number)
    {
        cout << elem.first << "   " << elem.second << endl;
    }
    cout << endl;

    //map 的查找
    cout << endl;
    auto it = number.find("021");
    if(it == number.end())
    {
        cout << "该值不在map中" << endl;
    }
    else
    {
        cout << it->first << "  " << it->second << endl;
    }

    //map的插入
    cout << endl;
    std::pair<map<string, string>::iterator, bool> ret 
        = number.insert(std::pair<string, string>("0987", "taiwan"));
    if(ret.second)
    {
        cout << "元素插入成功" << ret.first->first << "  "
                               << ret.first->second << endl;
    }
    else
    {
        cout << "插入失败，该元素存在map中"  << endl;
    }
    for(auto &elem : number)
    {
        cout << elem.first << "   " << elem.second << endl;
    }
    cout << endl;

    //map的下标访问
    //当key值存在的时候，返回对应的value值；
    //当key值不存在的时候，返回的value为空，并且key和value插入到了map中
    cout << endl;
    cout << "number[\"027\"] = " << number["027"] << endl;
    cout << "number[\"0321\"] = " << number["0321"] << endl;
    for(auto &elem : number)
    {
        cout << elem.first << "   " << elem.second << endl;
    }
    cout << endl;

    number["0321"] = "xian";//修改操作
    number.operator[]("0321").operator=("xian");
    for(auto &elem : number)
    {
        cout << elem.first << "   " << elem.second << endl;
    }
    cout << endl;

}
int main(int argc, char **argv)
{
    test2();
    return 0;
}

