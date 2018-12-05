#pragma once
#include"stdafx.h"
#include"bean/base/base_message.h"

class MessagePool {
public:
	static MessagePool* getInstance() {
		static MessagePool* msgmgr = new MessagePool();
		return msgmgr;
	}

	base_message* GetMsg(int msgId) 
	{
		auto iter = m_msgPool.find(msgId);
		if (iter == m_msgPool.end())
			printf("Error   ===== ID:  &d  msg is not defined", msgId);
		return  iter->second;
	}

private:
	MessagePool();

	void Add(int msgId, base_message* p_msg)
	{
		m_msgPool.insert(pair<int, base_message*>(msgId, p_msg));
	}

private:
	map<int, base_message*> m_msgPool;
};