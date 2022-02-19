 ///
 /// @file    main.cpp
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-03-31 09:04:53
 ///
 
#include "zinx.h"
#include <iostream>
#include <memory>
using std::cout;
using std::endl;

Ichannel * pStdInChannel = nullptr;
Ichannel * pStdOutChannel = nullptr;
AZinxHandler * pEchoHandler = nullptr;
AZinxHandler * pExitHandler = nullptr;
AZinxHandler * pCmdHandler = nullptr;
AZinxHandler * pDateHandler = nullptr;

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

class EchoHandler : public AZinxHandler
{
    /*信息处理函数，开发者重写该函数实现信息的处理，当有需要一个环节继续处理时，应该创建新的信息对象（堆对象）并返回指针*/
	virtual IZinxMsg *InternelHandle(IZinxMsg &_oInput)
	{
		GET_REF2DATA(BytesMsg, oBytes, _oInput);
		auto pChannel = ZinxKernel::Zinx_GetChannel_ByInfo("stdout");
		if(pChannel) {
			ZinxKernel::Zinx_SendOut(oBytes.szData, *pChannel);
		}

		return nullptr;
	}

	/*获取下一个处理环节函数，开发者重写该函数，可以指定当前处理环节结束后下一个环节是什么，通过参数信息对象，可以针对不同情况进行分别处理*/
	virtual AZinxHandler *GetNextHandler(IZinxMsg &_oNextMsg)
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
		return pCmdHandler;
	}
    /*获取通道信息函数，开发者可以在该函数中返回跟通道相关的一些特征字符串，方便后续查找和过滤*/
	virtual std::string GetChannelInfo()
	{
		return std::string("stdin");
	}
};

class ExitHandler : public AZinxHandler
{
    /*信息处理函数，开发者重写该函数实现信息的处理，当有需要一个环节继续处理时，应该创建新的信息对象（堆对象）并返回指针*/
	virtual IZinxMsg *InternelHandle(IZinxMsg &_oInput)
	{
		/* GET_REF2DATA(BytesMsg, obytes, _oInput); */
		/* if(obytes.szData == "exit") { */
		ZinxKernel::Zinx_Exit();
		return nullptr;
		/* } else { */
		/* 	return new BytesMsg(obytes); */
		/* } */
	}

	/*获取下一个处理环节函数，开发者重写该函数，可以指定当前处理环节结束后下一个环节是什么，通过参数信息对象，可以针对不同情况进行分别处理*/
	virtual AZinxHandler *GetNextHandler(IZinxMsg &_oNextMsg)
	{
		return nullptr;
	}
};

class DateHandler : public AZinxHandler
{
    /*信息处理函数，开发者重写该函数实现信息的处理，当有需要一个环节继续处理时，应该创建新的信息对象（堆对象）并返回指针*/
	virtual IZinxMsg *InternelHandle(IZinxMsg &_oInput)
	{
		GET_REF2DATA(BytesMsg, obytes, _oInput);
		time_t tm = time(NULL);
		std::string dateStr = ctime(&tm);
		dateStr.append(" >> ").append(obytes.szData);
		obytes.szData = dateStr;
		return new BytesMsg(obytes);
	}

	/*获取下一个处理环节函数，开发者重写该函数，可以指定当前处理环节结束后下一个环节是什么，通过参数信息对象，可以针对不同情况进行分别处理*/
	virtual AZinxHandler *GetNextHandler(IZinxMsg &_oNextMsg)
	{
		return pEchoHandler;
	}
};

class CmdHandler : public AZinxHandler
{
    /*信息处理函数，开发者重写该函数实现信息的处理，当有需要一个环节继续处理时，应该创建新的信息对象（堆对象）并返回指针*/
	virtual IZinxMsg *InternelHandle(IZinxMsg &_oInput)
	{
		GET_REF2DATA(BytesMsg, obytes, _oInput);
		if(obytes.szData == "open") {
			ZinxKernel::Zinx_Add_Channel(*pStdOutChannel);
			cout << "channel:" << pStdOutChannel->GetFd() << " open " << endl;
			return nullptr;
		} else if(obytes.szData == "close") {
			ZinxKernel::Zinx_Del_Channel(*pStdOutChannel);
			cout << "channel:" << pStdOutChannel->GetFd() << " closed!" << endl;
			return nullptr;
		} else if(obytes.szData == "date") {
			_isAddDatePrefix = true;
			return nullptr;
		} else if(obytes.szData == "cleardate") {
			_isAddDatePrefix = false;
			return nullptr;
		} else
			return new BytesMsg(obytes);
	}

	/*获取下一个处理环节函数，开发者重写该函数，可以指定当前处理环节结束后下一个环节是什么，通过参数信息对象，可以针对不同情况进行分别处理*/
	virtual AZinxHandler *GetNextHandler(IZinxMsg &_oNextMsg)
	{
		GET_REF2DATA(BytesMsg, obytes, _oNextMsg);
		if(obytes.szData == "exit") {
			return pExitHandler;
		} else if(_isAddDatePrefix) {
			return pDateHandler;
		} else
			return pEchoHandler;
	}

private:
	bool _isAddDatePrefix = false;
};


void test0() 
{
	ZinxKernel::ZinxKernelInit();

	pStdInChannel = new StdinChannel();
	pStdOutChannel = new StdoutChannel();
	pEchoHandler = new EchoHandler();
	pExitHandler = new ExitHandler();
	pCmdHandler = new CmdHandler();
	pDateHandler= new DateHandler();

	std::unique_ptr<AZinxHandler> p1(pEchoHandler);
	std::unique_ptr<AZinxHandler> p2(pExitHandler);
	std::unique_ptr<AZinxHandler> p3(pCmdHandler);
	std::unique_ptr<AZinxHandler> p4(pDateHandler);

	ZinxKernel::Zinx_Add_Channel(*pStdOutChannel);
	ZinxKernel::Zinx_Add_Channel(*pStdInChannel);

	ZinxKernel::Zinx_Run();

	ZinxKernel::ZinxKernelFini();
} 
 
int main(void)
{
	test0();
	return 0;
}
