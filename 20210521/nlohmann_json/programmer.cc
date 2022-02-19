 ///
 /// @file    programmer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-05-19 17:16:57
 ///
 
#include <iostream>
#include <string>
#include <vector>

#include <nlohmann/json.hpp>

using namespace std;

struct Programmer
{
	string name;
	int age;
	string phone;
	string address;
	vector<string> languages;
	vector<string> books;
};
 
void test0() 
{
	Programmer programmer {
		"Bjarne Stroustrup",
		71,
		"19888405103",
		"Morgan Stanley in New York City",
		{"C", "C++"},
		{
			"A tour of C++", 
			"C++语言的设计和演化",
			"The C++ Programming Language"
		}
	};
	cout << "sizeof(programmer):" << sizeof(programmer) << endl;

	int cnt = 100000;
	clock_t start = clock();
	while(cnt-- > 0) {
		nlohmann::json j;
		j["name"] = programmer.name;
		j["age"] = programmer.age;
		j["phone"] = programmer.phone;
		j["address"] = programmer.address;
		j["languages"] = programmer.languages;
		j["books"] = programmer.books;

		if(cnt == 1) {
			string jstr = j.dump();
			cout << "json's size:\n" << jstr.size() << endl;
			cout << jstr << endl;
		}
	}
	clock_t end = clock();
	cout << "time:" << (end - start) / 1000 << endl;
} 
 
int main(void)
{
	test0();
	return 0;
}
