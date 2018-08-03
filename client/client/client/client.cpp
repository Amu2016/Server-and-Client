#include<WinSock2.h>
#include<stdio.h>
#include<iostream>
#include<string>
#include<pthread.h>
using namespace std;
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "pthreadVC2.lib")

void* ThreadFunc(void* threadData) {
	SOCKET* sclient = (SOCKET*)threadData;
	while (true) {
		char recData[255];
		int ret = recv(*sclient, recData, 255, 0);
		if (ret > 0) {
			recData[ret] = 0x00;
			printf("Rec: %s\n", recData);
		}
	}

	return(void*)0;
}

int main() {
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA data;
	if (WSAStartup(sockVersion, &data) != 0) {
		return 0;
	}
	SOCKET sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sclient == INVALID_SOCKET) {
		printf("INVALID SOCKET!");
	}
	sockaddr_in serAddr;
	serAddr.sin_family = AF_INET;
	serAddr.sin_port = htons(8888);
	serAddr.sin_addr.S_un.S_addr = inet_addr("192.168.51.171");
	if (connect(sclient, (sockaddr*)&serAddr, sizeof(serAddr)) == SOCKET_ERROR) {
		printf("connect error!");
		closesocket(sclient);
	}

	pthread_t pthread_id;
	pthread_create(&pthread_id, NULL, ThreadFunc, (void*)&sclient);

	while (true) {

		string data;
		cin >> data;
		if (data == "close")
			break;
		const char* sendData;
		sendData = data.c_str();//string转const char* 
		//char * sendData = "你好，TCP服务端，我是客户端\n"
		send(sclient, sendData, strlen(sendData), 0);
		//send()用来将数据由指定的socket传给对方主机
		//int send(int s, const void * msg, int len, unsigned int flags)
		//s为已建立好连接的socket，msg指向数据内容，len则为数据长度，参数flags一般设0
		//成功则返回实际传送出去的字符数，失败返回-1，错误原因存于error 

		//char recData[255];
		//int ret = recv(sclient, recData, 255, 0);
		//if (ret > 0) {
		//	recData[ret] = 0x00;
		//	printf("%s\n", recData);
		//}
		
	}
	closesocket(sclient);
	WSACleanup();
	system("pause");
	return 0;
}