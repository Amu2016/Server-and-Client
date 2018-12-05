#pragma once
#include"MessagePool.h"
#include <google/protobuf/message.h>
#include"stdafx.h"

class MsgMgr {
protected:
	typedef std::function<void()> ConnectCallBack;
public:
	static MsgMgr* getInstance() {
		static MsgMgr* msgmgr = new MsgMgr();
		return msgmgr;
	}

	void connect(const char* ip, unsigned short port, ConnectCallBack fun);

	void onConnected();

	void OnMessage(const char* msg, int msgLen);

	void Send(const char* msg);

protected:
	inline google::protobuf::Message* CreatMessage(const string& msg) 
	{
		google::protobuf::Message* message = nullptr;
		const google::protobuf::Descriptor* descriptor = google::protobuf::DescriptorPool::generated_pool()->FindMessageTypeByName(msg);
		if (descriptor) 
		{
			const google::protobuf::Message* prototype = google::protobuf::MessageFactory::generated_factory()->GetPrototype(descriptor);
			if (prototype)
			{
				message = prototype->New();
			}
		}
		return message;
	}

	inline void ReleaseMessage(google::protobuf::Message* pMsg)
	{
		if (pMsg != nullptr)
		{
			pMsg->Clear();
			delete pMsg;
		}
	}

private:
	MsgMgr()
		:c_len(new char[4]),
		buffer(malloc(SOCKET_READ_BUFFER_SIZE - 4)),
		c_msg(new char[SOCKET_READ_BUFFER_SIZE]),
		recv_msgName(new char[100]),
		recv_msgBuffer(new char[SOCKET_READ_BUFFER_SIZE])
	{
	}
	~MsgMgr() {
		free(buffer);
		delete c_len;
		delete c_msg;
	}

	ConnectCallBack callback;

	//------recv--------
	char* recv_msgName;
	char* recv_msgBuffer;
	//-------------

	//-----send-------
	void *buffer;
	char* c_len;
	char* c_msg;
	//--------------
};