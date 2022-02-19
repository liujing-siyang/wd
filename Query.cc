#include "Query.h"


std::set<line_no>::iterator QueryResult::begin()
{
	return lines->begin();
}
 
std::set<line_no>::iterator QueryResult::end()
{
	return lines->end();
}
 
std::shared_ptr<std::vector<std::string>> QueryResult::get_file()
{
	return file;
}
//读取文件
TextQuery::TextQuery(ifstream &is): file(new vector<string>)
{
    string text;
    while (getline(is, text)) {       //获取文件的每一行
		file->push_back(text);        //保存每一行到file容器
		int n = file->size() - 1;     //当前行号
		istringstream line(text);     //字符串输入流将行文本分解成单词
		string word;
		while (line >> word) {        //对于一行的每个单词
            auto &lines = wm[word]; //lines是一个智能指针，循环内相同的word还会创建指针吗？
            if (!lines){//单词第一次出现
                lines.reset(new set<line_no>); //分配一个新set
            }
            lines->insert(n);      //将此行号插入set中
		}
	}
}

QueryResult TextQuery::query(const string &sought) const
{
    static shared_ptr<set<line_no>> nodata(new set<line_no>);    //指向行号集的指针
    auto loc = wm.find(word);
    if (loc == wm.end())
    {
        return QueryResult(sought,nodata,file);
    }
    else
    {
        return QueryResult(sought,loc->second,file);
    }
}
 
std::ostream &operator<<(ostream &os, const Query &query)
{
    return os << query.rep();
}

QueryResult OrQuery::eval(const TextQuery& text)const{
    auto right = rhs.eval(text);
    auto left = lhs.eval(text);
    auto ret_lines = make_shared<set<line_no>>(left.begin(),left.end());
    ret_lines->insert(right.begin(),right.end());
    return QueryResult(rep(),ret_lines,left.get_file());
}

QueryResult AndQuery::eval(const TextQuery& text)const{
    auto right = rhs.eval(text);
    auto left = lhs.eval(text);
    auto ret_lines = make_shared<set<line_no>>();
    set_intersection(left.begin(),left.end(),
                     right.begin(),right.end(),
                     inserter(*ret_lines,ret_lines->begin()));
    return QueryResult(rep(),ret_lines,left.get_file());
}

QueryResult NotQuery::eval(const TextQuery &text)const{
    auto result = query.eval(text);
    auto ret_lines = make_shared<set<line_no>>();
    auto beg = result.begin();
    auto end = result.end();
    auto sz =result.get_file()->size();
    for(size_t n = 0; n != sz;++n){
        if(beg ==end || *beg != n){
            ret_lines->insert(n);
        }
        else if(beg != end){
            ++beg;
        }
    }
    return QueryResult(rep(),ret_lines,result.get_file());
}
int main(int argc, char *argv[])
{
	ifstream is(argv[1]);
	TextQuery t1(is);
	string word;
	Query q = Query("fiery") & Query("bird") | Query("wind");
	cout << q << endl;
	cout << q.eval(t1) << endl;
	cin.get();
	return 0;
}
