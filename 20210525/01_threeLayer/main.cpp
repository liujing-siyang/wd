 ///
 /// @file    main.cpp
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-03-31 09:04:53
 ///
 
#include "zinx.h"
#include <iostream>
#include <memory>
#include <string>
using std::cout;
using std::endl;
using std::string;

Ichannel * pStdInChannel = nullptr;
Ichannel * pStdOutChannel = nullptr;
Irole * pEchoRole = nullptr;

class CmdData 
: public UserData {
public:
	/* 表示要回显的数据 */
	std::string szUserData;
	
	virtual ~CmdData(){}
};

class CmdCheck : public Iprotocol
{
public:
	static CmdCheck * getInstance()
	{
		if(nullptr == _pInstance) {
			_pInstance = new CmdCheck;
		}
		return _pInstance;
	}

	static void destroy()
	{
		if(_pInstance) {
			delete _pInstance;
			_pInstance = nullptr;
		}
	}

	/*原始数据和业务数据相互函数，开发者重写该函数，实现协议*/
	virtual UserData *raw2request(std::string _szInput)
	{	
		//若输入为exit命令,则退出程序
		if(_szInput == "exit") {
			ZinxKernel::Zinx_Exit();
			return nullptr;
		}
		//在这里，业务数据就是CmdData为代表的，需要向其进行转化，
		//所以必须要new一个堆空间的对象出来
		auto pret = new CmdData();
		pret->szUserData = _szInput;
		return pret;
	}
	
	/*原始数据和业务数据相互函数，开发者重写该函数，实现协议*/
	virtual std::string *response2raw(UserData &_oUserData)
	{
		GET_REF2DATA(CmdData, output, _oUserData);
		return new string(output.szUserData);
	}

private:
    /*获取处理角色对象函数，开发者应该重写该函数，用来指定当前产生的用户数据消息应该传递给哪个角色处理*/
	virtual Irole *GetMsgProcessor(UserDataMsg &_oUserDataMsg)
	{
		auto roleList = ZinxKernel::Zinx_GetAllRole();
		return roleList.front();//获取第一个role进行处理
	}

	/*获取发送通道函数，开发者应该重写该函数，用来指定当前字节流应该由哪个通道对象发出*/
	virtual Ichannel *GetMsgSender(BytesMsg &_oBytes)
	{
		return ZinxKernel::Zinx_GetChannel_ByInfo("stdout");
	}

private:
	CmdCheck(){}
	virtual ~CmdCheck() {}
private:
	static CmdCheck * _pInstance;
};

CmdCheck * CmdCheck::_pInstance = getInstance();


class EchoRole : public Irole
{
	/*初始化函数，开发者可以重写该方法实现对象相关的初始化，该函数会在role对象添加到zinxkernel时调用*/
	virtual bool Init() {	return true;	}

	/*处理信息函数，重写该方法可以对业务数据进行处理，若还需要后续处理流程，则应返回相关数据信息（堆对象）*/
	virtual UserData *ProcMsg(UserData &_poUserData) 
	{
		GET_REF2DATA(CmdData, output, _poUserData);
		auto pret = new CmdData(output);//切记要进行复制
		ZinxKernel::Zinx_SendOut(*pret, *CmdCheck::getInstance());
		return nullptr;
	}

	/*去初始化函数，类似初始化函数，该函数会在role对象摘除出zinxkernel时调用*/
	virtual void Fini() {}
};

class StdoutChannel: public Ichannel
{
public:
	/* 通道初始化函数，一般地，开发者应该重写这个函数
	 * 实现打开文件和一定的参数配置
	 * 该函数会在通道对象添加到zinxkernel时被调用*/
	virtual bool Init() {	return true;	}

	/* 读取数据， 开发者应该根据目标文件不同，重写这个函数，
	 * 以实现将fd中的数据读取到参数_string中
	 * 该函数会在数据源所对应的文件有数据到达时被调用*/
	virtual bool ReadFd(std::string &_input) {	return false;	}

	/* 写出数据， 开发者应该将数据写出的操作通过重写该函数实现
	 * 该函数会在调用zinxkernel::sendout函数后被调用
	 * （通常不是直接调用而是通过多路复用的反压机制调用）*/
	virtual bool WriteFd(std::string &_output) 
	{
		cout << _output << endl;
		return true;
	}

	/* 通道去初始化，开发者应该在该函数回收相关资源
	 * 该函数会在通道对象从zinxkernel中摘除时调用*/
	virtual void Fini(){}

	/* 获取文件描述符函数， 开发者应该在该函数返回当前关心的文件，
	 * 一般地，开发者应该在派生类中定义属性用来记录数据
	 * 来记录当前IO所用的文件，在此函数中只是返回该属性*/
	virtual int GetFd() {	return 1;	}

    /*获取通道信息函数，开发者可以在该函数中返回跟通道相关的一些特征字符串，方便后续查找和过滤*/
	virtual std::string GetChannelInfo()
	{
		return std::string("stdout");
	}

	virtual AZinxHandler *GetInputNextStage(BytesMsg &_oInput)
	{
		return nullptr;
	}
};
 
class StdinChannel: public Ichannel
{
public:
	/*通道初始化函数，一般地，开发者应该重写这个函数
	 * 实现打开文件和一定的参数配置
	 * 该函数会在通道对象添加到zinxkernel时被调用*/
	virtual bool Init() 
	{
		return true;
	}

	/*读取数据， 开发者应该根据目标文件不同，重写这个函数，
	 * 以实现将fd中的数据读取到参数_string中
	 * 该函数会在数据源所对应的文件有数据到达时被调用*/
	virtual bool ReadFd(std::string &_input)
	{
		std::cin >> _input;
		return true;
	}

	/*写出数据， 开发者应该将数据写出的操作通过重写该函数实现
	 * 该函数会在调用zinxkernel::sendout函数后被调用
	 * （通常不是直接调用而是通过多路复用的反压机制调用）*/
	virtual bool WriteFd(std::string &_output)
	{
		return false;
	}

	/*通道去初始化，开发者应该在该函数回收相关资源
	 * 该函数会在通道对象从zinxkernel中摘除时调用*/
	virtual void Fini(){}

	/* 获取文件描述符函数， 开发者应该在该函数返回当前关心的文件，
	 * 一般地，开发者应该在派生类中定义属性用来记录数据
	 * 来记录当前IO所用的文件，在此函数中只是返回该属性*/
	virtual int GetFd(){	return 0;	}

	/*获取下一个处理环节，开发者应该重写该函数，指定下一个处理环节
	一般地，开发者应该在该函数返回一个协议对象，用来处理读取到的字节流*/
	virtual AZinxHandler *GetInputNextStage(BytesMsg &_oInput)
	{
		return CmdCheck::getInstance();
	}

    /*获取通道信息函数，开发者可以在该函数中返回跟通道相关的一些特征字符串，方便后续查找和过滤*/
	virtual std::string GetChannelInfo()
	{
		return std::string("stdin");
	}
};

void test0() 
{
	ZinxKernel::ZinxKernelInit();

	pStdInChannel = new StdinChannel();
	pStdOutChannel = new StdoutChannel();
	pEchoRole = new EchoRole();

	std::unique_ptr<Irole> p1(pEchoRole);

	ZinxKernel::Zinx_Add_Channel(*pStdOutChannel);
	ZinxKernel::Zinx_Add_Channel(*pStdInChannel);
	ZinxKernel::Zinx_Add_Role(*pEchoRole);

	ZinxKernel::Zinx_Run();

	ZinxKernel::ZinxKernelFini();
	
	CmdCheck::destroy();
} 
 
int main(void)
{
	test0();
	return 0;
}
