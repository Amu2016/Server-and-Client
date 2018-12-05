#include"msgteam.h"

pthread_mutex_t MsgTeam::m_pthreadMutex;
pthread_cond_t MsgTeam::m_pthreadCond;

queue<MsgBuffer*> MsgTeam::teamA;
queue<MsgBuffer*> MsgTeam::teamB;

queue<MsgBuffer*>* MsgTeam::teamIn = &MsgTeam::teamA;
queue<MsgBuffer*>* MsgTeam::teamOut = &MsgTeam::teamB;

bool MsgTeam::init = false;