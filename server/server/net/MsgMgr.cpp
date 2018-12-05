#include"MsgMgr.h"

#include"MessagePool.h"

void MsgMgr::connect(const char* ip, unsigned short port, ConnectCallBack fun) {

	//Socket->Connect(ip, port, fun);

	//callback = fun;
}

void MsgMgr::onConnected()
{
	//if (callback)
	//	callback();

	//const char* sendData;
	//sendData = "你好，TCP服务端，我是客户端\n";
	//MsgMgr::getInstance()->Send(sendData);
}

void MsgMgr::OnMessage(const char * msg, int msgLen)
{
	//消息长度
	auto m_len = ((unsigned char)msg[0] << 24) | ((unsigned char)msg[1] << 16) | ((unsigned char)msg[2] << 8) | ((unsigned char)msg[3]);
	//消息id
	auto msgId = ((unsigned char)msg[4] << 24) | ((unsigned char)msg[5] << 16) | ((unsigned char)msg[6] << 8) | ((unsigned char)msg[7]);
	//消息名字长度
	auto nameLenth = ((unsigned char)msg[8] << 24) | ((unsigned char)msg[9] << 16) | ((unsigned char)msg[10] << 8) | ((unsigned char)msg[11]);

	//消息名字
	memset(recv_msgName, 0, nameLenth);
	strncpy(recv_msgName, msg + 12, (12 + nameLenth));
	recv_msgName[nameLenth] = 0x00;

	//消息主体
	memset(recv_msgBuffer, 0, msgLen - 12 - nameLenth);
	strncpy(recv_msgBuffer, msg + 12 + nameLenth, msgLen - 12 - nameLenth);

	//从消息池中取出消息对象  读取收到的消息并执行
	auto meg_Obj = MessagePool::getInstance()->GetMsg(msgId);
	meg_Obj->reading(recv_msgBuffer, msgLen - 12 - nameLenth);
	//meg_Obj->callmsg();
}

void MsgMgr::Send(const char * msg)
{
}
