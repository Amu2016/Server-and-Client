#pragma once
#include"login.pb.h"
#include"stdafx.h"
#include"base/base_message.h"
#include"server/MyServer.h"

class loginSuccess_ReqMessage : public base_reqmessage {
public:
	loginSuccess_ReqMessage(string name, int32_t id, string email)
		:buffer(malloc(SOCKET_READ_BUFFER_SIZE - 4)),
		msgId(110001)
	{
		loginSuccess.set_msgid(110001);

		loginSuccess.set_name(name);
		loginSuccess.set_id(id);
		loginSuccess.set_email(email);
	}

	virtual void reading(const void* data, int size)
	{
		//personMsg = msg;
	}

	virtual MsgInfo writing()
	{
		int size = loginSuccess.ByteSize();
		memset(buffer, 0, size);
		loginSuccess.SerializeToArray(buffer, size);

		MsgInfo msgInfo;
		msgInfo.msg = buffer;
		msgInfo.lenth = size;

		return msgInfo;
	}

	virtual int32_t getId()
	{
		return msgId;
	}

private:
	Login::LoginSuccess loginSuccess;
	int32_t msgId;

	void* buffer;

	string name;
	int32_t id;
	string email;
};

class login_ResMessage : public base_message {
public:
	login_ResMessage(){}

	virtual void reading(const void* data, int size)
	{
		loginInfo.ParseFromArray(data, size);
		msgId = loginInfo.msgid();
		name = loginInfo.name();
		password = loginInfo.password();
	}

	//virtual MsgInfo writing()
	//{
	//	msgId = personMsg->msgid();
	//	MsgInfo msg;
	//	return msg;
	//}

	virtual int32_t getId()
	{
		return msgId;
	}

	virtual void callmsg(SOCKET sock)
	{
		//printf("========callmsg======= %d\n", msgId);

		//auto msg = test_ReqMessage("客户端一号", 7, "461427494@qq.com");
		//Server::getInstance()->Send(sock, &msg);
	}

private:
	Login::Login loginInfo;
	int32_t msgId;

	string name;
	int32_t password;
};
