#pragma once
#include"test.pb.h"
#include"stdafx.h"
#include"base/base_message.h"
#include"server/MyServer.h"

class test_ReqMessage : public base_reqmessage {
public:
	test_ReqMessage(string name, int32_t id, string email)
		:buffer(malloc(SOCKET_READ_BUFFER_SIZE - 4)),
		msgId(100001)
	{
		personMsg.set_msgid(100001);

		personMsg.set_name(name);
		personMsg.set_id(id);
		personMsg.set_email(email);
	}

	virtual void reading(const void* data, int size)
	{
		//personMsg = msg;
	}

	virtual MsgInfo writing()
	{
		int size = personMsg.ByteSize();
		memset(buffer, 0, size);
		personMsg.SerializeToArray(buffer, size);

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
	Test::ResPersonInfo personMsg;
	int32_t msgId;

	void* buffer;

	string name;
	int32_t id;
	string email;
};

class test_ResMessage : public base_message {
public:
	test_ResMessage()
	{}

	virtual void reading(const void* data, int size)
	{
		personMsg.ParseFromArray(data, size);
		msgId = personMsg.msgid();
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
		printf("========callmsg======= %d\n", msgId);

		auto msg = test_ReqMessage("客户端一号", 7, "461427494@qq.com");
		Server::getInstance()->Send(sock, &msg);
	}

private:
	Test::ReqPersonInfo personMsg;
	int32_t msgId;
};