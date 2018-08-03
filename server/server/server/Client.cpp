#include"Client.h"

int RecvClient::Run() {
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
			send_clt->AddSendMsg(sendData);
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
		printf("Failed to shutdown client socket :\n");
		closesocket(sock_clt);
		return 1;
	}

	return 0;
}



//pthread_mutex_t SendClient::m_pthreadMutex = PTHREAD_MUTEX_INITIALIZER;
//pthread_cond_t SendClient::m_pthreadCond = PTHREAD_COND_INITIALIZER;

void SendClient::AddSendMsg(char* msg) {
	pthread_mutex_lock(&m_pthreadMutex);
	vec_sendMsg.push_back(msg);
	pthread_mutex_unlock(&m_pthreadMutex);
	pthread_cond_signal(&m_pthreadCond);
}

int SendClient::Run() {
	while (1)
	{
		pthread_mutex_lock(&m_pthreadMutex);
		while (vec_sendMsg.size() == 0 && online)
		{
			pthread_cond_wait(&m_pthreadCond, &m_pthreadMutex);
		}

		if (!online) {
			pthread_mutex_unlock(&m_pthreadMutex);
			return 1;
		}

		vector<char*>::iterator iter = vec_sendMsg.begin();

		char* buffer = *iter;
		if (iter != vec_sendMsg.end()) {
			buffer = *iter;
			vec_sendMsg.erase(iter);
		}
		pthread_mutex_unlock(&m_pthreadMutex);

		//char* sendData = new char[255];
		//sprintf(sendData, "收到 :");
		int snd_result = send(sock_clt, buffer, strlen(buffer), 0);
		if (snd_result == SOCKET_ERROR) {
			printf("Failed to send message to client : \n");
			closesocket(sock_clt);
			return 1;
		}
	}

	return 0;
}