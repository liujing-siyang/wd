#include "tinyxml2.h"
#include <iostream>
#include <string>
#include <regex>

using std::cout;
using std::endl;
using std::string;
using std::regex;
using std::regex_replace;

using namespace tinyxml2;

int test()
{
    XMLDocument doc;
    doc.LoadFile("coolshell.xml");
    if(doc.ErrorID())
    {
        cout << "doc open file error!" << endl;
        return doc.ErrorID();
    }

    XMLElement *itemNode = doc.FirstChildElement("rss")->FirstChildElement("channel")->FirstChildElement("item");
    /* if(itemNode) */
    while(itemNode)
    {
        XMLElement *titleNode = itemNode->FirstChildElement("title");
        XMLElement *linkNode = itemNode->FirstChildElement("link");
        XMLElement *descriptionNode = itemNode->FirstChildElement("description");
        XMLElement *contentNode = itemNode->FirstChildElement("content:encoded");

        string title(titleNode->GetText());
        string link(linkNode->GetText());
        string description(descriptionNode->GetText());
        string content(contentNode->GetText());

        
        regex reg("<[^>]+>|");
        description = regex_replace(description, reg, "");
        content = regex_replace(content, reg, "");

        cout << "title : " << title << endl
             << "link : " << link << endl
             << "description : " << description << endl
             << "content : " << content << endl;

        itemNode = itemNode->NextSiblingElement("item"); 
    }

    return 0;
}

int main(int argc, char **argv)
{
    test();
    return 0;
}

