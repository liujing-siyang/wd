#include <iostream>
#include <memory>
#include <string>

using std::cout;
using std::endl;
using std::unique_ptr;
using std::shared_ptr;
using std::string;
//定制删除器，就是重写函数对象，处理不是new出来的空间
struct FILEFclose
{
    void operator()(FILE *fp) const
    {
        cout << "void operator()(FILE *) const" << endl;
        fclose(fp);
    }
};

void test()
{
    string msg = "hello,world";
    unique_ptr<FILE, FILEFclose> up(fopen("wuhan.txt", "a+"));//FILEFclose放在参数位置，是一个类
    fwrite(msg.c_str(), 1, msg.size(), up.get());
    //写了fclose会导致double free,不写程序异常结束导致写入文件失败
    /* fclose(up.get()); */
}

void test2()
{
    string msg = "hello,world";
    FILEFclose ff;
    shared_ptr<FILE> sp(fopen("wd.txt", "a+"), FILEFclose());//FILEFclose()放在构造函数第二个位置，是一个对象
    /* shared_ptr<FILE> sp(fopen("wd.txt", "a+"), ff); */
    fwrite(msg.c_str(), 1, msg.size(), sp.get());

}
int main(int argc, char **argv)
{
    test2();
    return 0;
}

