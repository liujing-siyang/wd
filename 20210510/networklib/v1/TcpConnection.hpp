 /// 
using std::string;

namespace wd
{
	
class TcpConnnection : Noncopyable
{
public:
	TcpConnnection(int fd);

	string receive();
	void send(const string & msg);

	string toString() const;
private:
	InetAddress getLocalAddr();
	InetAddress getPeerAddr();
private:
	Socket _sock;
	SocketIO _sockIO;
	InetAddress _localAddr;
	InetAddress _peerAddr;
	bool _isShutdownWrite;
};



}//end of namespace wd

#endif
