#pragma once
#include"SqlMgr.h"

class Q_login {
public:
	struct data
	{
		int userId;
		string name;
		string password;
		string email;
	};

	static Q_login* getInstance() {
		static Q_login* login = new Q_login();
		return login;
	}

	bool Get(const int id) {
		SqlMgr::getInstance()->SelectById(table_name, id_name, id);
	}

	void Write(const char *name, const char *passsword, const char *email)
	{
		sprintf(info, "(NULL, '%s', '%s','%s')",name, passsword, email);
		SqlMgr::getInstance()->InsertData(table_name, info);
	}

private:
	Q_login() 
		:table_name("login_info")
	{}


private:
	vector<data> v_login;

	const char table_name[20];

	struct
	{
		const char id_name[10] = "userid";
	};

	char info[100];

	int userid;
	string name;
	string password;
	string email;
};