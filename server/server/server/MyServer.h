#pragma once
#include<WinSock2.h>
#include"ThreadPool.h"''
#include"Client.h"
#include"bean/base/base_message.h"

#pragma comment(lib,"ws2_32.lib")

#define IP_BUF_SIZE 129

struct PlayerInfo {
	SOCKET sock;
	SOCKADDR_IN addr;
};

struct RecvEvent {

};

struct ClientSocket {
	//RecvEvent recvEvent;
	RecvClient* recvClient;
	//SendClient* sendClient;
};

class Server {
public:
	static Server* getInstance() {
		static Server* server = new Server();
		return server;
	}

	void Send(SOCKET sock, base_reqmessage* msg);

	~Server();

protected:
	void initServer();
private:
	Server();
	static void* WaitForClient(void * threadData);
	Server(const Server&) = delete;
	Server& operator=(const Server&) = delete;

	pthread_t * pthread_listen;

	WORD winsock_ver;
	WSADATA wsa_data;
	HANDLE h_thread;
	SOCKADDR_IN addr_svr;
	int ret_val;
	char buf_ip[IP_BUF_SIZE];


	static SOCKET sock_svr;
	static vector<ClientSocket> vec_client;

	static pthread_mutex_t m_pthreadMutex;    /** 线程同步锁 */
	static pthread_cond_t m_pthreadCond;      /** 线程同步的条件变量 */
	//SOCKET sock_clt;
	//int addr_len;
	//SOCKADDR_IN addr_clt;

	//-----send-------
	void *buffer;
	//char* c_len;
	char* c_msg;
	//--------------
};