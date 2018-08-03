#pragma once
#include<vector>
#include<string>
using namespace std;

/**
* ִ��������࣬�����������ݲ�ִ��
*/
class CTask
{
protected:
	string m_strTaskName;  /** ��������� */
	void* m_ptrData;       /** Ҫִ�е�����ľ������� */

public:
	CTask() {}
	CTask(const string& taskName)
	{
		m_strTaskName = taskName;
		m_ptrData = NULL;
	}
	virtual ~CTask() {}

	virtual int Run() = 0;

	void SetData(void* data);    /** ������������ */
};