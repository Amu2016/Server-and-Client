#include<stdio.h>
#include<WinSock2.h>
#include<string>
#include"ThreadPool.h"
#include"net/MessagePool.h"
#include"MyServer.h"
#include"sql/Q_login_data.h"
#pragma comment(lib,"ws2_32.lib")

int main(int argc, char*argv[]) {
	SqlMgr::getInstance();

	Q_login::getInstance()->Write("客户端一号", "201314", "461427494@qq.com");

	CThreadPool::getInstance()->setPoolSize(10);
	Server::getInstance();
	//server.WaitForClient();

	char* recv_msgName = new char[100];
	char* recv_msgBuffer = new char[SOCKET_READ_BUFFER_SIZE];
	char* msg;
	int32_t msgLen;
	int m_len, msgId, nameLenth;

	MsgTeam msgTeam;
	msgTeam.InitTeam();
	while (true)
	{
		MsgBuffer* msgBuffer =  msgTeam.GetMsg();
		msg = msgBuffer->msg;
		msgLen = msgBuffer->lenth;
		//printf("Handle Msg...  \n");
		//消息长度
		m_len = ((byte)msg[0] << 24) | ((byte)msg[1] << 16) | ((byte)msg[2] << 8) | ((byte)msg[3]);
		//消息id
		msgId = ((byte)msg[4] << 24) | ((byte)msg[5] << 16) | ((byte)msg[6] << 8) | ((byte)msg[7]);
		//消息名字长度
		nameLenth = ((byte)msg[8] << 24) | ((byte)msg[9] << 16) | ((byte)msg[10] << 8) | ((byte)msg[11]);

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
		meg_Obj->callmsg(msgBuffer->sock);
	}

	system("pause");
	return 0;
}