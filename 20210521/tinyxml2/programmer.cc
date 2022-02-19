///
/// @file    programmer.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2021-05-19 17:16:57
///

#include <iostream>
#include <string>
#include <vector>

#include <tinyxml2.h>

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
	cout << "sizeof(programmer): " << sizeof(programmer) << endl;

	using namespace tinyxml2;

	int count = 100000;
	clock_t start = clock();
	while(count-- > 0) {
		XMLDocument doc;
		XMLElement * nameElem = doc.NewElement("name");
		nameElem->SetText(programmer.name.c_str());
		XMLElement * ageElem = doc.NewElement("age");
		ageElem->SetText(programmer.age);

		XMLElement * phoneElem = doc.NewElement("phone");
		phoneElem->SetText(programmer.phone.c_str());

		XMLElement * addressElem = doc.NewElement("address");
		addressElem->SetText(programmer.address.c_str());

		XMLElement * langElem1 = doc.NewElement("language");
		XMLElement * langElem2 = doc.NewElement("language");
		langElem1->SetText(programmer.languages[0].c_str());
		langElem2->SetText(programmer.languages[1].c_str());
		XMLElement * languagesElem = doc.NewElement("languages");
		languagesElem->InsertFirstChild(langElem1);
		languagesElem->InsertAfterChild(langElem1, langElem2);

		XMLElement * bookElem1 = doc.NewElement("book");
		XMLElement * bookElem2 = doc.NewElement("book");
		XMLElement * bookElem3 = doc.NewElement("book");
		bookElem1->SetText(programmer.books[0].c_str());
		bookElem2->SetText(programmer.books[1].c_str());
		bookElem3->SetText(programmer.books[2].c_str());
		XMLElement * booksElem = doc.NewElement("books");
		booksElem->InsertFirstChild(bookElem1);
		booksElem->InsertAfterChild(bookElem1, bookElem2);
		booksElem->InsertAfterChild(bookElem2, bookElem3);

		XMLElement * programmerElem = doc.NewElement("programmer");
		doc.InsertFirstChild(programmerElem);
		programmerElem->InsertFirstChild(nameElem);
		programmerElem->InsertAfterChild(nameElem, ageElem);
		programmerElem->InsertAfterChild(ageElem, phoneElem);
		programmerElem->InsertAfterChild(phoneElem, addressElem);
		programmerElem->InsertAfterChild(addressElem, languagesElem);
		programmerElem->InsertAfterChild(languagesElem, booksElem);

		/* doc.Print(); */
		/* doc.SaveFile("programmer.xml"); */
		if(count == 1) {
			XMLPrinter streamer;
			doc.Print(&streamer);
			cout << "siz:" << streamer.CStrSize() << endl;
			cout << streamer.CStr() << endl;
		}
	}//end of while
	clock_t end = clock();
	cout << "time:" << (end - start) / 1000 << endl;
} 

int main(void)
{
	test0();
	return 0;
}
