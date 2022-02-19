 ///
 /// @file    InetAddress.hpp
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-02-05 15:12:35
 ///
 
#ifndef __WD_INETADDRESS_H__
#define __WD_INETADDRESS_H__

#include <netinet/in.h>

#include <string>

using std::string;

namespace wd
{

class InetAddress
{
public:
	InetAddress(const string & ip, unsigned short port);
	InetAddress(const struct sockaddr_in & addr);

	//如果操作的成员函数不会对数据成员进行修改，都要设计成const成员函数
	string ip() const;
	unsigned short port() const;

	const struct sockaddr_in * getInetAddressPtr() const;

private:
	struct sockaddr_in _addr;
};


}//end of namespace wd


#endif
