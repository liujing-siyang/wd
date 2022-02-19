#include <iostream>                                                                                                                                                                                    
#include <string>
#include <sstream>
#include <ostream>
#include <vector> 
#include <fstream>
#include <memory>
#include <map>
#include <set>

using std::shared_ptr;
using std::map;
using std::set;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::ifstream;
using std::istringstream;
using std::make_shared;

using line_no = vector<string>::size_type;
class QueryResult;	//查询结果类
class TextQuery;	//文本查询类

//查询结果类
class QueryResult{
    friend class TextQuery;
    friend ostream &operator<<(ostream& , const  QueryResult &);
public:
    QueryResult(string s,shared_ptr<set<line_no>>p,shared_ptr<vector<string>>f)
        :sought(s),lines(p),file(f){

            }
    set<line_no>::iterator begin();
    set<line_no>::iterator end();
    shared_ptr<vector<string>> get_file();
//读取文件
private:
    string sought;//要查询的单词
    shared_ptr<set<line_no>>lines;//出现的行号
    shared_ptr<vector<string>>file;//输入文件
};

//文本查询类
class TextQuery{
    friend class QueryResult;
public:
    //构造函数
    TextQuery(ifstream&);

    QueryResult query(const string&)const;
  private:
     shared_ptr<vector<string>>file;//file为一个智能指针,指向一个元素为string的容器
     map<string,shared_ptr<set<line_no>>>wm;//关联容器，将单词和出现的行号的set容器关联
  };

//Query_base抽象基类，制定一个标准
class Query_base{
    friend class Query;
protected:
//    using line_no = TextQuery::line_no;
    virtual ~Query_base() = default;
private:
    virtual QueryResult eval(const TextQuery&)const = 0;
    virtual string rep() const = 0;
};

//接口类，基类包括派生类都可以通过Query来使用，隐藏实现
//Query包装了Query_base
class Query{
    friend Query operator~(const Query &);
    friend Query operator|(const Query &,const Query &);
    friend Query operator&(const Query &,const Query &);
public:
    //构造函数
    Query(const string &);

    QueryResult eval(const TextQuery &t)const{
        return q->eval(t);//执行WordQuery对象的eval函数
    }
    string rep()const{
        return q->rep();
    }
private:
    //构造函数定义为private,不希望一般用户随便定义Query_base对象。 
    //注意：友元类可以访问protected和private成员。
    Query (shared_ptr<Query_base>query):q(query){//为什么还要有这个构造函数，传进来应该是个字符串

    }
    //通过智能指针实现动态绑定
    shared_ptr<Query_base> q;//托管WordQuery的一个对象
};
//用来查找一个给定的单词，是在给定TextQuery对象上实际执行查询的唯一一个操作
class WordQuery:public Query_base{
    friend class Query;
    //构造函数
    WordQuery(const string &s):query_word(s){}

    //查询单词
    QueryResult eval(const TextQuery &t)const{
        return t.query(query_word);//执行TextQuery的query成员函数
    }
    //查询的一个string
    string rep()const {return query_word;}
    string query_word;//要查找的单词
};

//无论哪种查询都是建立在WordQuery的根本上，
//因此 Query的构造函数用一个WordQuery来初始化  
inline Query::Query(const string &query_word) : 
				q(new WordQuery(query_word)) {}
//非查询类
class NotQuery:public Query_base{
    friend Query operator~(const Query &);
    //构造函数
    NotQuery (const Query &q):query(q){}
    string rep()const{
        return "~(" + query.rep() + ")";
    }
    QueryResult eval(const TextQuery&) const;//重写Query_base的eval函数
    Query query;
};
//传入Query对象，返回一个NotQuery对象
inline Query operator~(const Query &operand)
{
	return shared_ptr<Query_base>(new NotQuery(operand));
}
//两个运算符的抽象基类
class BinaryQuery{
protected:
    //构造函数
    BinaryQuery(const Query &l,const Query &r,string s):lhs(l),rhs(r),opSym(s){}
    string rep() const {
        return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
    }
    Query lhs,rhs;//左右侧的运算对象
    string opSym;//运算符的名字
};
//与操作类
class AndQuery :public BinaryQuery{
    friend Query operator&(const Query&,const Query&);
    AndQuery(const Query &left,const Query &right):BinaryQuery(left,right,"&"){}
    QueryResult eval(const TextQuery&)const;
};

inline
Query operator&(const Query &lhs,const Query &rhs){
    return shared_ptr<Query_base>(new AndQuery(lhs,rhs));
}
//或操作类
class OrQuery :public BinaryQuery{
    friend Query operator|(const Query&,const Query&);
    OrQuery(const Query &left,const Query &right):BinaryQuery(left,right,"|"){}
    QueryResult eval(const TextQuery&)const;
};

inline Query operator|(const Query &lhs,const Query &rhs){
    /* return shared_ptr<Query_base>(new OrQuery(lhs,rhs)); */
    return shared_ptr<Query_base>(new OrQuery(lhs,rhs));
}
