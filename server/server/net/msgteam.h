#pragma once
#include<WinSock2.h>
#include"stdafx.h"
#include<queue>
#include<pthread.h>

struct MsgBuffer {
	MsgBuffer(char* msg, int32_t lenth, SOCKET sock)
		:msg(msg),
		lenth(lenth),
		sock(sock)
	{
	}
	SOCKET sock;
	char* msg;
	int32_t lenth;
};

class MsgTeam {
public:
	MsgTeam() {}
	~MsgTeam() {}

	//只能执行一次
	static void InitTeam()
	{
		if (init)
			return;
		pthread_mutex_init(&m_pthreadMutex, nullptr);
		pthread_cond_init(&m_pthreadCond, nullptr);
		init = false;
	}

	void PutMsg(MsgBuffer* msg)
	{
		//printf("PutMsg Msg...  \n");
		pthread_mutex_lock(&m_pthreadMutex);
		teamIn->push(msg);
		pthread_mutex_unlock(&m_pthreadMutex);
		pthread_cond_signal(&m_pthreadCond);
	}

	MsgBuffer* GetMsg()
	{
		if (teamOut->size() <= 0)
			changeTeam();
		auto msg = teamOut->back();
		teamOut->pop();
		return msg;
	}

private:
	void changeTeam()
	{
		pthread_mutex_lock(&m_pthreadMutex);
		if(teamOut->size() <= 0 && teamIn->size() <= 0)
		{
			printf("Wait Msg...  \n");
			pthread_cond_wait(&m_pthreadCond, &m_pthreadMutex);
		}
		if (teamIn == &teamA) 
		{
			teamIn = &teamB;
			teamOut = &teamA;
		}
		else 
		{
			teamIn = &teamA;
			teamOut = &teamB;
		}
		pthread_mutex_unlock(&m_pthreadMutex);
	}

	static bool init;
	static pthread_mutex_t m_pthreadMutex;    /** 线程同步锁 */
	static pthread_cond_t m_pthreadCond;      /** 线程同步的条件变量 */
	static queue<MsgBuffer*>* teamIn;
	static queue<MsgBuffer*>* teamOut;

	static queue<MsgBuffer*> teamA;
	static queue<MsgBuffer*> teamB;
};