 ///
 /// @file    substitution.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-05-04 15:59:51
 ///
 
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class User
{
public:
	User(const string & name)
	: _name(name)
	, _score(0)
	{}

	//未进行折扣时的消费
	void consume(float delta)
	{
		cout << "User::consume()" << endl;
		_score += delta;
		cout << ">> " << _name 
			 << " consume " << delta << endl;
	}

protected:
	string _name;
	float _score;
};

class VipUser
: public User
{
public:
	VipUser(const string & name)
	: User(name)
	, _discount(1)
	{}

	//进行折扣时的消费
	void consume2(float delta) {
		cout << "VipUser::consume()" << endl;
		float tmp = delta * _discount;
		_score += tmp;
		if(_score > 1000 && _score < 5000) {
			_discount = 0.9;
		}
		cout << ">> " << _name 
			 << " consume " << tmp << endl;
	}

private:
	float _discount;
};
//里氏替换原则的核心思想: 派生类可以扩展基类的功能，
//但不能改变基类原有的功能
 
void test0() 
{
	User user("哩哩老师");
	user.consume(1000);
	user.consume(1000);

	VipUser vipuser("泥鳅老师");
	vipuser.consume2(2700);// 有隐藏 oversee
	vipuser.consume2(100);//有折扣
	vipuser.consume(1000);//不差钱

} 
 
int main(void)
{
	test0();
	return 0;
}
