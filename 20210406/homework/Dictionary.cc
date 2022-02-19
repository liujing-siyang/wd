#include <time.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::sort;

void test()
{
    vector<int> vec;
    vec[0] = 100;//error core dump
}
struct Record
{
    Record(const string &word, int frequency)
    : _word(word)
    , _frequency(frequency)
    {

    }

    string _word;
    int _frequency;
};

bool operator<(const Record &lhs, const Record &rhs)
{
    return lhs._word < rhs._word;
}

class Dictionary
{
public:
    Dictionary(int capa)
    {
        _dict.reserve(capa);
    }
    void read(const string &filename)
    {
        ifstream ifs(filename);
        if(!ifs)
        {
            std::cerr << "ifstream is broken" << endl;
            return ;
        }

        string line;
        while(getline(ifs, line))
        {
            istringstream iss(line);
            string word;
            while(iss >> word)
            {
                string newWord = dealWord(word);//处理每个不合法的单词
                insert(newWord);
            }
        }

        sort(_dict.begin(), _dict.end());
        ifs.close();
    }

    string dealWord(const string &word)
    {
        for(size_t idx = 0; idx != word.size(); ++idx)
        {
            if(!isalpha(word[idx]))//判断每个字符是不是一个字母
            {
                return string();
            }
        }

        return word;
    }

    void insert(const string &word)
    {
        if(word == string())
        {
            return;
        }

        size_t idx = 0;
        for(idx = 0; idx != _dict.size(); ++idx)
        {
            if(word == _dict[idx]._word)
            {
                ++_dict[idx]._frequency;
                break;
            }
        }

        if(idx == _dict.size())
        {
            _dict.push_back(Record(word, 1));
        }
    }

    void store(const string &filename)
    {
        ofstream ofs(filename);
        if(!ofs)
        {
            std::cerr << "ofstream is broken" << endl;
            return;
        }

        for(size_t idx = 0; idx != _dict.size(); ++ idx)
        {
            ofs << _dict[idx]._word << "         " << _dict[idx]._frequency << endl;
        }


        ofs.close();
    }
private:
    vector<Record> _dict;
};
int main(int argc, char **argv)
{
    Dictionary dictionary(13000);
    cout << "begin reading...." << endl;
    time_t beg = time(NULL);
    dictionary.read("The_Holy_Bible.txt");
    time_t end = time(NULL);
    cout << "time: " << (end - beg) << "s" << endl;
    cout << "end reading...." << endl;
    dictionary.store("dict.dat");
    return 0;
}

