#pragma once
#include<WinSock2.h>
#include"TaskBase.h"
#include<vector>
#include"ThreadPool.h"
#include"stdafx.h"
#include<net/msgteam.h>
using namespace std;

#pragma comment(lib,"ws2_32.lib")

#define MSG_BUF_SIZE 1000
class SendClient;

class RecvClient : public CTask { // 接受任务
public:
	RecvClient()
		:buffer(malloc(SOCKET_READ_BUFFER_SIZE - 4)),
		c_msg(new char[SOCKET_READ_BUFFER_SIZE]),
		recv_msgName(new char[100]),
		recv_msgBuffer(new char[SOCKET_READ_BUFFER_SIZE])
	{}

	void InitSocket(SOCKET sock, SOCKADDR_IN addr) {
		sock_clt = sock;
		addr_clt = addr;
		online = true;
		pthread_mutex_init(&m_pthreadMutex, nullptr);
		pthread_cond_init(&m_pthreadCond, nullptr);
	}

	void SetSendClinet(SendClient* sendclient) {
		send_clt = sendclient;
	}

	virtual int Run();
private:
	pthread_mutex_t m_pthreadMutex;    /** 线程同步锁 */
	pthread_cond_t m_pthreadCond;      /** 线程同步的条件变量 */
	SOCKET sock_clt;
	SOCKADDR_IN addr_clt;
	SendClient* send_clt;

	vector<char*> vec_recvMsg;
	bool online;

	char* recv_msgName;
	char* recv_msgBuffer;

	MsgTeam msgteam;

	void *buffer;
	char* c_len;
	char* c_msg;
};

class SendClient : public CTask { //发送任务
public:
	SendClient() {}

	void InitSocket(SOCKET sock, SOCKADDR_IN addr)
	{
		sock_clt = sock;
		addr_clt = addr;
		online = true;
		pthread_mutex_init(&m_pthreadMutex, nullptr);
		pthread_cond_init(&m_pthreadCond, nullptr);
	}

	void AddSendMsg(MsgBuffer* msg);

	virtual int Run();
private:
	pthread_mutex_t m_pthreadMutex;    /** 线程同步锁 */
	pthread_cond_t m_pthreadCond;      /** 线程同步的条件变量 */

	SOCKET sock_clt;
	SOCKADDR_IN addr_clt;
	vector<MsgBuffer*> vec_sendMsg;

	bool online;
};
