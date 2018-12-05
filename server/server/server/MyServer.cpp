#include"MyServer.h"

#include<stdio.h>
#include<string>

#define SERVER_PORT 8888
#define THREADPOOL_SIZE 10
vector<ClientSocket> Server::vec_client;
SOCKET Server::sock_svr;
pthread_mutex_t Server::m_pthreadMutex;    /** 线程同步锁 */
pthread_cond_t Server::m_pthreadCond;      /** 线程同步的条件变量 */

Server::Server() 
	: buffer(malloc(SOCKET_READ_BUFFER_SIZE - 4)),
	c_msg(new char[SOCKET_READ_BUFFER_SIZE])
{
	initServer();

	pthread_mutex_init(&m_pthreadMutex, nullptr);
	pthread_cond_init(&m_pthreadCond, nullptr);

	pthread_listen = (pthread_t*)malloc(sizeof(pthread_t));
	pthread_create(pthread_listen, NULL, WaitForClient, NULL);
}

void Server::initServer() {
	printf("Init Server...\n");

	winsock_ver = MAKEWORD(2, 2);
	int addr_len = sizeof(SOCKADDR_IN);
	addr_svr.sin_family = AF_INET;
	addr_svr.sin_port = htons(SERVER_PORT);
	addr_svr.sin_addr.S_un.S_addr = ADDR_ANY;

	memset(buf_ip, 0, IP_BUF_SIZE);

	ret_val = WSAStartup(winsock_ver, &wsa_data);
	if (ret_val != 0) {
		printf("WSA failed to start up : \n");
		//exit(1);
	}
	printf("WSA started up...\n");

	sock_svr = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock_svr == INVALID_SOCKET) {
		printf("Faild to creat server socket : \n");
		//exit(1);
	}
	printf("Server socket bind...\n");

	ret_val = bind(sock_svr, (SOCKADDR*)&addr_svr, addr_len);
	
	if (ret_val != 0) {
		printf("Server socket faild to bind : \n");
		//exit(1);
	}

	ret_val = listen(sock_svr, SOMAXCONN);

	if (ret_val == SOCKET_ERROR) {
		printf("Server socket faild to listen : \n");
		//exit(1);
	}
	printf("Server socket started to listen...\n");
	printf("Server Started...\n");
}

Server::~Server() {
	closesocket(sock_svr);
	//closesocket(sock_clt);
	free(pthread_listen);
	WSACleanup();
	printf("Socket Closed...\n");
}

void Server::Send(SOCKET sock, base_reqmessage* msg) {
	auto msgInfo = msg->writing();

	auto size = msgInfo.lenth;
	buffer = msgInfo.msg;

	const char* msgName = "ResPersonInfo";
	int32_t name_len = strlen(msgName);
	int32_t msgId = msg->getId();

	// msgId(int32_t)字节数  name_len(int32_t)字节数  name(char[])字节数
	int32_t msg_len = 4 + 4 + name_len + size;

	c_msg[0] = (char)(0xff & (msg_len >> 24));
	c_msg[1] = (char)(0xff & (msg_len >> 16));
	c_msg[2] = (char)(0xff & (msg_len >> 8));
	c_msg[3] = (char)(0xff & (msg_len));

	c_msg[4] = (char)(0xff & (msgId >> 24));
	c_msg[5] = (char)(0xff & (msgId >> 16));
	c_msg[6] = (char)(0xff & (msgId >> 8));
	c_msg[7] = (char)(0xff & (msgId));

	c_msg[8] = (char)(0xff & (name_len >> 24));
	c_msg[9] = (char)(0xff & (name_len >> 16));
	c_msg[10] = (char)(0xff & (name_len >> 8));
	c_msg[11] = (char)(0xff & (name_len));

	sprintf(c_msg + 12, msgName);
	sprintf(c_msg + 12 + name_len, (char*)buffer);
	int32_t len = 12 + name_len + size;

	int snd_result = send(sock, c_msg, len, 0);
	if (snd_result == SOCKET_ERROR) {
		printf("Failed to send message to client : \n");
		//closesocket(sock);
	}
	//delete buffer;
}

void* Server::WaitForClient(void * threadData) {
	SOCKADDR_IN addr_clt;
	int addr_len = sizeof(SOCKADDR_IN);
	while(true) {
		SOCKET sock_clt = accept(sock_svr, (SOCKADDR*)&addr_clt, &addr_len);
		if (sock_clt == INVALID_SOCKET) {
			printf("Faild to accept client : \n");
			exit(1);
		}

		printf("Client connected...  IP: %s\n", inet_ntoa(addr_clt.sin_addr));

		ClientSocket clientSocket;
		clientSocket.recvClient = new RecvClient();
		//clientSocket.sendClient = new SendClient();
		clientSocket.recvClient->InitSocket(sock_clt, addr_clt);
		//clientSocket.sendClient->InitSocket(sock_clt, addr_clt);
		//clientSocket.recvClient->SetSendClinet(clientSocket.sendClient);

		pthread_mutex_lock(&m_pthreadMutex);
		vec_client.push_back(clientSocket);
		pthread_mutex_unlock(&m_pthreadMutex);
		pthread_cond_signal(&m_pthreadCond);
		
		CThreadPool::getInstance()->AddTask(clientSocket.recvClient); // 线程池中添加接受消息任务
		//CThreadPool::getInstance()->AddTask(clientSocket.sendClient); // 线程池中添加发送消息任务
	}
	return (void*)0;
}