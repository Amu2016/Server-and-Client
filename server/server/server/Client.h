#pragma once
#include<WinSock2.h>
#include"TaskBase.h"
#include<vector>
#include"ThreadPool.h"
using namespace std;

#pragma comment(lib,"ws2_32.lib")

#define MSG_BUF_SIZE 1000
class SendClient;

class RecvClient : public CTask { // 接受任务
public:
	RecvClient(){}

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

	void AddSendMsg(char* msg);

	virtual int Run();
private:
	pthread_mutex_t m_pthreadMutex;    /** 线程同步锁 */
	pthread_cond_t m_pthreadCond;      /** 线程同步的条件变量 */

	SOCKET sock_clt;
	SOCKADDR_IN addr_clt;
	vector<char*> vec_sendMsg;

	bool online;
};
