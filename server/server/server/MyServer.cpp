#include"MyServer.h"

#include<stdio.h>
#include<string>

#define SERVER_PORT 8888
#define THREADPOOL_SIZE 10

Server::Server() :threadpool(THREADPOOL_SIZE)
{
	printf("Init Server...\n");

	winsock_ver = MAKEWORD(2, 2);
	addr_len = sizeof(SOCKADDR_IN);
	addr_svr.sin_family = AF_INET;
	addr_svr.sin_port = htons(SERVER_PORT);
	addr_svr.sin_addr.S_un.S_addr = ADDR_ANY;

	memset(buf_ip, 0, IP_BUF_SIZE);

	ret_val = WSAStartup(winsock_ver, &wsa_data);
	if (ret_val != 0) {
		printf("WSA failed to start up : \n");
		exit(1);
	}
	printf("WSA started up...\n");

	sock_svr = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock_svr == INVALID_SOCKET) {
		printf("Faild to creat server socket : \n");
		exit(1);
	}
	printf("Server socket bind...\n");

	ret_val = bind(sock_svr, (SOCKADDR*)&addr_svr, addr_len);
	if (ret_val != 0) {
		printf("Server socket faild to bind : \n");
		exit(1);
	}

	ret_val = listen(sock_svr, SOMAXCONN);

	if (ret_val == SOCKET_ERROR) {
		printf("Server socket faild to listen : \n");
		exit(1);
	}
	printf("Server socket started to listen...\n");
	printf("Server Started...\n");
}

Server::~Server() {
	closesocket(sock_svr);
	closesocket(sock_clt);
	WSACleanup();
	printf("Socket Closed...\n");
}

//DWORD WINAPI CreateClinetThread(LPVOID lpParamenter);

void Server::WaitForClient() {
	while(true) {
		sock_clt = accept(sock_svr, (SOCKADDR*)&addr_clt, &addr_len);
		if (sock_clt == INVALID_SOCKET) {
			printf("Faild to accept client : \n");
			exit(1);
		}

		printf("Client connected...  IP: %s\n", inet_ntoa(addr_clt.sin_addr));
		//PlayerInfo info;
		//info.sock = sock_clt;
		//info.addr = addr_clt;

		ClientSocket clientSocket;
		clientSocket.recvClient = new RecvClient();
		clientSocket.sendClient = new SendClient();
		clientSocket.recvClient->InitSocket(sock_clt, addr_clt);
		clientSocket.sendClient->InitSocket(sock_clt, addr_clt);
		clientSocket.recvClient->SetSendClinet(clientSocket.sendClient);
		vec_client.push_back(clientSocket);
		
		threadpool.AddTask(clientSocket.recvClient); // 线程池中添加接受消息任务
		threadpool.AddTask(clientSocket.sendClient); // 线程池中添加发送消息任务

		char* sendData = new char[255];
		strcpy(sendData, "[LOGIN IN...]");
		clientSocket.sendClient->AddSendMsg(sendData);
		strcpy(sendData, "[test...]");
		clientSocket.sendClient->AddSendMsg(sendData);
		strcpy(sendData, "[test...]");
		clientSocket.sendClient->AddSendMsg(sendData);

		//h_thread = CreateThread(nullptr, 0, CreateClinetThread, (LPVOID)&info, 0, nullptr);
		//if (h_thread == NULL) {
		//	printf("Faild to create thread : \n");
		//	exit(1);
		//}
		//CloseHandle(h_thread);
	}
}

DWORD WINAPI CreateClinetThread(LPVOID lpParamenter) {
	PlayerInfo* info = (PlayerInfo*)lpParamenter;
	SOCKET sock_clt = info->sock;
	SOCKADDR_IN addr_clt = info->addr;
	char buf_msg[MSG_BUF_SIZE];
	int ret_val = 0;
	int snd_result = 0;
	do {
		memset(buf_msg, 0, MSG_BUF_SIZE);
		ret_val = recv(sock_clt, buf_msg, MSG_BUF_SIZE, 0);
		if (ret_val > 0) {
			if (strcmp(buf_msg, "close") == 0) {
				printf("Client requests to close the Connection...\n");
				break;
			}
			buf_msg[ret_val] = 0x00;
			printf("Ip: %s Message : %s\n", inet_ntoa(addr_clt.sin_addr), buf_msg);
			char* sendData = new char[255];
			sprintf(sendData, "收到 : %s", buf_msg);
			snd_result = send(sock_clt, sendData, strlen(sendData), 0);
			if (snd_result == SOCKET_ERROR) {
				printf("Failed to send message to client : \n");
				closesocket(sock_clt);
				return 1;
			}
		}
		else if (ret_val == 0) {
			printf("connection closed...\n");
		}
		else {
			printf("Faild to receive message from client : \n");
			closesocket(sock_clt);
			return 1;
		}
	} while (ret_val > 0);

	ret_val = shutdown(sock_clt, SD_SEND);
	if (ret_val == SOCKET_ERROR) {
		printf("Failed to shutdown client socket : %s\n");
		closesocket(sock_clt);
		return 1;
	}
	return 0;
}