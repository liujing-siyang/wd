 ///
 /// @file    programmer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-05-19 17:16:57
 ///

#include "programmer.pb.h"
#include <google/protobuf/text_format.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
/* using namespace google::protobuf; */

#if 1
struct Programmer0
{
	string name;
	int age;
	string phone;
	string address;
	vector<string> languages;
	vector<string> books;
};
#endif
 
void test0() 
{
	int count = 100000;
	Programmer0 programmer0 {
		"Bjarne Stroustrup",
		71,
		"19888405103",
		"Morgan Stanley in New York City",
		{"C", "C++"},
		{"A tour of C++", 
		 "C++语言的设计和演化",
		 "The C++ Programming Language"
		}
	};
	clock_t start = clock();
	while(count-- > 0) {

		using namespace google::protobuf;
		Programmer programmer;
		programmer.set_name(programmer0.name);
		programmer.set_age(programmer0.age);
		programmer.set_phone(programmer0.phone);
		programmer.set_address(programmer0.address);
		
		programmer.add_lang(programmer0.languages[0]);
		programmer.add_lang(programmer0.languages[1]);
		programmer.set_lang(0, "Java");

		programmer.add_book(programmer0.books[0]);
		programmer.add_book(programmer0.books[1]);
		programmer.add_book(programmer0.books[2]);

		if(count == 1) {
			//序列化
			string bytes;
			programmer.SerializeToString(&bytes);
			cout << bytes.size() << endl;
			cout << bytes << endl << endl;

			std::ofstream ofs0("./program.txt", std::ios::out | std::ios::binary);
			if(ofs0) {
				ofs0.write(bytes.c_str(), bytes.size());
			}
			ofs0.close();

			Programmer prog;
			prog.ParseFromString(bytes);//反序列化
			cout << "prog's message:" << endl
				 << prog.name() << endl
				 << prog.age() << endl
				 << prog.address() << endl
				 << prog.phone() << endl
				 << "book's size: " << prog.book_size() << endl
				 << prog.book(0) << endl
				 << prog.book(1) << endl
				 << prog.book(2) << endl
				 << "language's size:" << prog.lang_size() << endl
				 << prog.lang(0) << endl
				 << prog.lang(1) << endl;

			//将文本信息保存到字符串中
			/* string bytes2; */
			/* google::protobuf::TextFormat::PrintToString(programmer, &bytes2); */
			/* cout << bytes2.size() << endl */
			/* 	 << "bytes2:" << endl << bytes2 << endl; */
		}
	}//end of while
	clock_t end = clock();
	cout << "time:" << (end - start) / 1000 << endl;

	/* TextFormat::PrintToString(programmer, & bytes); */
	/* cout << bytes.size() << endl */
	/* 	 << bytes << endl << endl; */
	
#if 0
	//输出到文件中
	if(ofs) {
		auto output = new google::protobuf::io::OstreamOutputStream(&ofs);
		google::protobuf::TextFormat::Print(programmer, output);
		delete output;
	}
	ofs.close();
#endif


	/* char buff[1024] = {0}; */
	/* programmer.SerializeToArray(buff, 1024); */
	/* cout << strlen(buff) << endl; */
	/* cout << buff << endl; */
} 
 
int main(void)
{
	test0();
	return 0;
}
