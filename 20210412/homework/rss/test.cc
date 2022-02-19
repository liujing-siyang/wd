#include "tinyxml2.h"
#include <iostream>
#include <string>
#include <regex>
using std::cout;
using std::endl;
using std::string;

using namespace tinyxml2;
 
int main(void)
{
	XMLDocument doc;
	doc.LoadFile("coolshell.xml");
	if(doc.ErrorID()) {
		cout << " XMLDocument LoadFile error!" << endl;
		return -1;
	}

	XMLElement * itemNode = doc.FirstChildElement("rss")->FirstChildElement("channel")->FirstChildElement("item");
	/* while(itemNode) { */
	if(itemNode) {
		XMLElement * titleNode = itemNode->FirstChildElement("title");
		XMLElement * linkNode = itemNode->FirstChildElement("link");
		XMLElement * descriptionNode = itemNode->FirstChildElement("description");
		XMLElement * contentNode = itemNode->FirstChildElement("content:encoded");

		string title(titleNode->GetText());
		string link(linkNode->GetText());
		string description(descriptionNode->GetText());
		string content(contentNode->GetText());
#if 0
		cout << "title: " << title << endl
			 << "link: " << link << endl
			 << "decripiton:" << description << endl
			 << endl << endl << endl
			 << "content: " << content << endl;
#endif
        std::regex re("<[^>]+>|");

		/* cout << "title: " << title << endl */
		/* 	 << "link: " << link << endl */
		/*      << "description :" << std::regex_replace(description, re, string("")) << endl */
		/*      << "content :" << std::regex_replace(content, re, string("")) << endl; */
        description = std::regex_replace(description, re, string(""));
        content = std::regex_replace(content, re, string(""));
		cout << "title: " << title << endl
			 << "link: " << link << endl
			 << "decripiton:" << description << endl
			 << endl << endl << endl
			 << "content: " << content << endl;
        
        itemNode = itemNode->NextSiblingElement("item");
	}

	return 0;
}
