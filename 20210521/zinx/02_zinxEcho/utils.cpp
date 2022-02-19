#include "zinx.h"

using namespace std;

void AZinxHandler::Handle(IZinxMsg & _oInput)
{
	IZinxMsg *poNextMsg = NULL;
	AZinxHandler *poNextHandler = NULL;

	poNextMsg = InternelHandle(_oInput);//多态，调用的为AZinxHandler的派生类Ichannel的InternelHandle方法
	if (NULL != poNextMsg)//消息对象不为空
	{
		poNextHandler = GetNextHandler(*poNextMsg);//获取下一个处理者
		if (NULL != poNextHandler)
		{
			poNextHandler->Handle(*poNextMsg);//接着递归调用Handle
		}

		delete poNextMsg;//析构对象
	}

	return;
}
//进行消息处理
IZinxMsg *Ichannel::InternelHandle(IZinxMsg & _oInput)
{
	IZinxMsg *poRet = NULL;
	GET_REF2DATA(SysIOReadyMsg, oIoStat, _oInput);//将_oInput向下转型成SysIOReadyMsg，用oIoStat的引用去接
	if (oIoStat.m_emIoDic == SysIOReadyMsg::IN)
	{
		BytesMsg *poBytes = new BytesMsg(oIoStat);
		if (true == ReadFd(poBytes->szData))//调用Ichannel的ReadFd输入数据初始化poBytes的szData数据成员，这是真正输入的消息
		{
			poBytes->szInfo = GetChannelInfo();//获取"stdin"填充通道信息
			poRet = poBytes;
		}
		else
		{
			delete poBytes;
		}
	}
	else if (oIoStat.m_emIoDic == SysIOReadyMsg::OUT)
	{
		GET_REF2DATA(BytesMsg, oBytes, _oInput);
		if (false == HasOutput())//如果没有要输出的数据
		{
			ZinxKernel::Zinx_SetChannelOut(*this);//注册写事件
		}
		//加入发送缓冲区
		m_WriteBuffer.push_back(oBytes.szData);
	}

	return poRet;//返回BytesMsg对象指针
}

void Ichannel::FlushOut()
{
	while (false == m_WriteBuffer.empty())
	{
		if (true == WriteFd(m_WriteBuffer.front()))
		{
			m_WriteBuffer.pop_front();
		}
		else
		{
			break;
		}
	}
}

AZinxHandler* Iprotocol::GetNextHandler(IZinxMsg & _oNextMsg)
{
	AZinxHandler *poRet = NULL;

	GET_REF2DATA(SysIOReadyMsg, oIoStat, _oNextMsg);
	if (oIoStat.m_emIoDic == SysIOReadyMsg::IN)
	{
		GET_REF2DATA(UserDataMsg, oUserDataMsg, _oNextMsg);
		poRet = GetMsgProcessor(oUserDataMsg);
	}
	else if (oIoStat.m_emIoDic == SysIOReadyMsg::OUT)
	{
		GET_REF2DATA(BytesMsg, obytes, _oNextMsg);
		poRet = GetMsgSender(obytes);
	}

	return poRet;
}

AZinxHandler *Ichannel::GetNextHandler(IZinxMsg & _oNextMsg)//这里穿不传参好像不重要？
{
	AZinxHandler *poRet = NULL;
	GET_REF2DATA(SysIOReadyMsg, oIoStat, _oNextMsg);
	if (oIoStat.m_emIoDic == SysIOReadyMsg::IN)
	{
		GET_REF2DATA(BytesMsg, oBytes, _oNextMsg);
		poRet = GetInputNextStage(oBytes);
	}

	return poRet;
}

IZinxMsg *Iprotocol::InternelHandle(IZinxMsg & _oInput)
{
	IZinxMsg *poRet = NULL;
	GET_REF2DATA(SysIOReadyMsg, oIoStat, _oInput);
	if (oIoStat.m_emIoDic == SysIOReadyMsg::IN)
	{
		GET_REF2DATA(BytesMsg, oBytes, _oInput);
		UserData *poUserData = raw2request(oBytes.szData);
		if (NULL != poUserData)
		{
			UserDataMsg *poUserDataMsg = new UserDataMsg(oBytes);
			poUserDataMsg->poUserData = poUserData;
			poRet = poUserDataMsg;
		}
	}
	else if (oIoStat.m_emIoDic == SysIOReadyMsg::OUT)
	{
		GET_REF2DATA(UserDataMsg, oUserDataMsg, _oInput);
		string *pszData = response2raw(*(oUserDataMsg.poUserData));
		if (NULL != pszData)
		{
			BytesMsg *poBytes = new BytesMsg(oIoStat);
			poBytes->szData = *pszData;
			delete pszData;
			poRet = poBytes;
		}
	}

	return poRet;
}

IZinxMsg *Irole::InternelHandle(IZinxMsg & _oInput)
{
	IZinxMsg *poRet = NULL;
	GET_REF2DATA(SysIOReadyMsg, oIoStat, _oInput);
	if (oIoStat.m_emIoDic == SysIOReadyMsg::IN)
	{
		GET_REF2DATA(UserDataMsg, oUserDataMsg, _oInput);
		UserData *poUserData = ProcMsg(*(oUserDataMsg.poUserData));
		if (NULL != poUserData)
		{
			UserDataMsg *poUserDataMsg = new UserDataMsg(oUserDataMsg);
			poUserDataMsg->poUserData = poUserData;
			poRet = poUserDataMsg;
		}
	}

	return poRet;
}

AZinxHandler *Irole::GetNextHandler(IZinxMsg & _oNextMsg)
{
	GET_REF2DATA(UserDataMsg, oUserDataMsg, _oNextMsg);
	return poNextProcessor;
}

std::string Ichannel::Convert2Printable(std::string &_szData)
{
	char *pcTemp = (char *)calloc(1UL, _szData.size() * 3 + 1);
	int iCurPos = 0;

	if (NULL != pcTemp)
	{
		for (int i = 0; i < _szData.size(); ++i)
		{
			iCurPos += sprintf(pcTemp + iCurPos, "%02X ", (unsigned char)_szData[i]);
		}
		pcTemp[iCurPos] = 0;
	}

	std::string szRet = std::string(pcTemp);
	free(pcTemp);

	return szRet;
}
