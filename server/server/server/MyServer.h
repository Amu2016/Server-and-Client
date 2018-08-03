#pragma once
#include<WinSock2.h>
#include"ThreadPool.h"''
#include"Client.h"

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
	SendClient* sendClient;
};

class Server {
public:
	Server();
	~Server();
	Server(const Server&) = delete;
	Server& operator=(const Server&) = delete;
	void WaitForClient();
private:
	WORD winsock_ver;
	WSADATA wsa_data;
	SOCKET sock_svr;
	SOCKET sock_clt;
	HANDLE h_thread;
	SOCKADDR_IN addr_svr;
	SOCKADDR_IN addr_clt;
	CThreadPool threadpool;
	vector<ClientSocket> vec_client;
	int ret_val;
	int addr_len;
	char buf_ip[IP_BUF_SIZE];
};