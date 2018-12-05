#include"Client.h"
#include"bean/test.pb.h"
#include<string>
using namespace std;

//#pragma execution_character_set("utf-8")

int RecvClient::Run() {
	printf("RecvClient Run  \n");
	char buf_msg[MSG_BUF_SIZE];
	int ret_val = 0;
	int snd_result = 0;

	do {
		memset(buf_msg, 0, MSG_BUF_SIZE);
		ret_val = recv(sock_clt, buf_msg, MSG_BUF_SIZE, 0);
		if (ret_val > 0) {
			//if (strcmp(buf_msg, "close") == 0) {
			//	printf("Client requests to close the Connection...\n");
			//	break;
			//}
			//buf_msg[ret_val] = 0x00;
			//printf("Ip: %s Message : %s\n", inet_ntoa(addr_clt.sin_addr), buf_msg);

			//auto m_len = ((byte)buf_msg[0] << 24) | ((byte)buf_msg[1] << 16) | ((byte)buf_msg[2] << 8) | ((byte)buf_msg[3]);
			//INT32 len = ((buf_msg[0] - 1) << 21) | ((buf_msg[1] - 1) << 14) | ((buf_msg[2] - 1) << 7) | (buf_msg[3] - 1);

			char* buff = new char[ret_val];
			memset(buff, 0, ret_val);
			memcpy(buff, buf_msg, ret_val);
			MsgBuffer* msgbuf = new MsgBuffer(buff, ret_val, sock_clt);
			msgteam.PutMsg(msgbuf);


			////消息长度
			//auto m_len = ((byte)buf_msg[0] << 24) | ((byte)buf_msg[1] << 16) | ((byte)buf_msg[2] << 8) | ((byte)buf_msg[3]);
			////消息id
			//auto msgId = ((byte)buf_msg[4] << 24) | ((byte)buf_msg[5] << 16) | ((byte)buf_msg[6] << 8) | ((byte)buf_msg[7]);
			////消息名字长度
			//auto nameLenth = ((byte)buf_msg[8] << 24) | ((byte)buf_msg[9] << 16) | ((byte)buf_msg[10] << 8) | ((byte)buf_msg[11]);

			////消息名字
			//memset(recv_msgName, 0, nameLenth);
			//strncpy(recv_msgName, buf_msg + 12, (12 + nameLenth));
			//recv_msgName[nameLenth] = 0x00;

			////消息主体
			//memset(recv_msgBuffer, 0, ret_val - 12 - nameLenth);
			//strncpy(recv_msgBuffer, buf_msg + 12 + nameLenth, ret_val - 12 - nameLenth);

			////strncpy(buf_msg, buf_msg + 4, ret_val);


			//Test::ReqPersonInfo personMsg;
			//personMsg.ParseFromArray(recv_msgBuffer, ret_val);
			////buf_msg[ret_val] = 0x00;
			//auto msgId3 = personMsg.msgid();
			////auto name = personMsg.name();
			////auto id = personMsg.id();
			////auto email = personMsg.email();
			////printf("name Message : %s\n", personMsg.name());
			////printf("id Message : %d\n", personMsg.id());
			////printf("email Message : %s\n", personMsg.email());




			////===========================
			//Test::ResPersonInfo personMsg1;
			//personMsg1.set_msgid(200001);
			//personMsg1.set_name("客户端一号");
			//personMsg1.set_id(7);
			//personMsg1.set_email("461427494@qq.com");

			//int size = personMsg1.ByteSize();
			//void *buffer = malloc(size);
			//personMsg1.SerializeToArray(buffer, size);

			//const char* msgName = "ResPersonInfo";

			////  -1 char[] 尾部包含 "\0"
			//int32_t name_len = strlen(msgName);

			//int32_t msgId2 = 200001;

			//// msgId(int32_t)字节数  name_len(int32_t)字节数  name(char[])字节数
			//int32_t msg_len = 4 + 4 + name_len + size;

			//char* c_msg = new char[12 + name_len + size];

			//c_msg[0] = (char)(0xff & (msg_len >> 24));
			//c_msg[1] = (char)(0xff & (msg_len >> 16));
			//c_msg[2] = (char)(0xff & (msg_len >> 8));
			//c_msg[3] = (char)(0xff & (msg_len));

			//c_msg[4] = (char)(0xff & (msgId2 >> 24));
			//c_msg[5] = (char)(0xff & (msgId2 >> 16));
			//c_msg[6] = (char)(0xff & (msgId2 >> 8));
			//c_msg[7] = (char)(0xff & (msgId2));

			//c_msg[8] = (char)(0xff & (name_len >> 24));
			//c_msg[9] = (char)(0xff & (name_len >> 16));
			//c_msg[10] = (char)(0xff & (name_len >> 8));
			//c_msg[11] = (char)(0xff & (name_len));

			//sprintf(c_msg + 12, msgName);
			//sprintf(c_msg + 12 + name_len, (char*)buffer);

			//auto lenss = 12 + name_len + size;

			//MsgBuffer* msgbuf1 = new MsgBuffer(c_msg, lenss, sock_clt);

			//send_clt->AddSendMsg(msgbuf1);
		}
		else if (ret_val == 0) {
			printf("connection closed...\n");
		}
		else {
			printf("Faild to receive message from client : %s\n" + WSAGetLastError());
			closesocket(sock_clt);
			break;
		}
	} while (ret_val > 0);

	ret_val = shutdown(sock_clt, SD_SEND);
	if (ret_val == SOCKET_ERROR) {
		printf("Failed to shutdown client socket :\n");
		closesocket(sock_clt);
	}

	printf("RecvClient  close !!!! \n");

	return 0;
}



//pthread_mutex_t SendClient::m_pthreadMutex = PTHREAD_MUTEX_INITIALIZER;
//pthread_cond_t SendClient::m_pthreadCond = PTHREAD_COND_INITIALIZER;

void SendClient::AddSendMsg(MsgBuffer* msg) {
	pthread_mutex_lock(&m_pthreadMutex);
	vec_sendMsg.push_back(msg);
	pthread_mutex_unlock(&m_pthreadMutex);
	pthread_cond_signal(&m_pthreadCond);
}

int SendClient::Run() {
	printf("SendClient Run  \n");
	while (1)
	{
		pthread_mutex_lock(&m_pthreadMutex);
		while (vec_sendMsg.size() == 0 && online)
		{
			pthread_cond_wait(&m_pthreadCond, &m_pthreadMutex);
		}

		if (!online) {
			pthread_mutex_unlock(&m_pthreadMutex);
			break;
		}

		vector<MsgBuffer*>::iterator iter = vec_sendMsg.begin();

		MsgBuffer* buffer = *iter;
		if (iter != vec_sendMsg.end()) {
			buffer = *iter;
			vec_sendMsg.erase(iter);
		}
		pthread_mutex_unlock(&m_pthreadMutex);

		//char* sendData = new char[255];
		//sprintf(sendData, "收到 :");
		auto lenss = buffer->lenth;
		int snd_result = send(sock_clt, buffer->msg, buffer->lenth, 0);
		if (snd_result == SOCKET_ERROR) {
			printf("Failed to send message to client : \n");
			closesocket(sock_clt);
			break;
		}
	}

	printf("SendClient close !!!! \n");

	return 0;
}