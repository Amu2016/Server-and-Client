#pragma once
#include<vector>
#include<string>
using namespace std;

/**
* 执行任务的类，设置任务数据并执行
*/
class CTask
{
protected:
	string m_strTaskName;  /** 任务的名称 */
	void* m_ptrData;       /** 要执行的任务的具体数据 */

public:
	CTask() {}
	CTask(const string& taskName)
	{
		m_strTaskName = taskName;
		m_ptrData = NULL;
	}
	virtual ~CTask() {}

	virtual int Run() = 0;

	void SetData(void* data);    /** 设置任务数据 */
};