#pragma once
#include"stdafx.h"
#include<WinSock2.h>
#include"mysql.h"
#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"libmysql.lib")

class SqlMgr {
public:
	static SqlMgr* getInstance() {
		static SqlMgr* sql = new SqlMgr();
		return sql;
	}



public:
	bool QueryDatabase1()
	{
		sprintf(query, "select * from lonin_info"); //执行查询语句，这里是查询所有，user是表名，不用加引号，用strcpy也可以
		mysql_query(&mysql, "set names utf-8"); //设置编码格式（SET NAMES GBK也行），否则cmd下中文乱码
											  //返回0 查询成功，返回1查询失败
		if (mysql_query(&mysql, query))        //执行SQL语句
		{
			printf("Query failed (%s)\n", mysql_error(&mysql));
			return false;
		}
		else
		{
			printf("query success\n");
		}
		//获取结果集
		if (!(res = mysql_store_result(&mysql)))    //获得sql语句结束后返回的结果集
		{
			printf("Couldn't get result from %s\n", mysql_error(&mysql));
			return false;
		}

		//打印数据行数
		printf("number of dataline returned: %d\n", mysql_affected_rows(&mysql));

		//获取字段的信息
		char *str_field[32];  //定义一个字符串数组存储字段信息
		for (int i = 0; i<4; i++)   //在已知字段数量的情况下获取字段名
		{
			str_field[i] = mysql_fetch_field(res)->name;
		}
		for (int i = 0; i<4; i++)   //打印字段
			printf("%10s\t", str_field[i]);
		printf("\n");
		//打印获取的数据
		while (column = mysql_fetch_row(res))   //在已知字段数量情况下，获取并打印下一行
		{
			printf("%10s\t%10s\t%10s\t%10s\n", column[0], column[1], column[2], column[3]);  //column是列数组
		}
		return true;
	}

	/***************************数据库操作***********************************/
	//其实所有的数据库操作都是先写个sql语句，然后用mysql_query(&mysql,query)来完成，包括创建数据库或表，增删改查

	//查询数据 根据id
	bool SelectById(const char *tablename, const char *id_name, const int id) {
		bool result;
		Open();
		mysql_query(&mysql, "set names \'GBK\'"); //设置编码格式（SET NAMES GBK也行），否则cmd下中文乱码

		sprintf(query, "select * from %s WHERE %s = %d", tablename, id_name, id);

		Close();
		return result;
	}

	//插入数据
	bool InsertData(const char *tablename, const char *values)
	{
		bool result;
		Open();
		mysql_query(&mysql, "set names \'GBK\'");

		sprintf(query, "insert into %s values %s;", tablename, values);
		if (mysql_query(&mysql, query))        //执行SQL语句
		{
			printf("Query failed (%s)\n", mysql_error(&mysql));
			result = false;
		}
		else
		{
			printf("Insert success\n");
			result = true;
		}
		Close();
		return result;
	}
	//修改数据
	bool ModifyData()
	{
		sprintf(query, "update lonin_info set email='lilei325@163.com' where name='Lilei'");
		if (mysql_query(&mysql, query))        //执行SQL语句
		{
			printf("Query failed (%s)\n", mysql_error(&mysql));
			return false;
		}
		else
		{
			printf("Insert success\n");
			return true;
		}
	}
	//删除数据
	bool DeleteData()
	{
		/*sprintf(query, "delete from user where id=6");*/
		//char query[100];
		//printf("please input the sql:\n");
		//gets(query);  //这里手动输入sql语句
		//if (mysql_query(&mysql, query))        //执行SQL语句
		//{
		//	printf("Query failed (%s)\n", mysql_error(&mysql));
		//	return false;
		//}
		//else
		//{
		//	printf("Insert success\n");
		//	return true;
		//}
	}

private:
		SqlMgr()
			:res(nullptr)
		{
			mysql_init(&mysql);  //连接mysql，数据库


			printf("=====================\n");
			//中间分别是主机，用户名，密码，数据库名，端口号（可以写默认0或者3306等），可以先写成参数再传进去
			if (!(mysql_real_connect(&mysql, "localhost", "db_admin", "201314", "game_data", 8000, NULL, 0)))
			{
				printf("Error connecting MySQL to database:%s\n", mysql_error(&mysql));
			}
			else
			{
				printf("Connected MySQL...\n");
			}
			printf("=====================\n");
			mysql_close(&mysql);
		}

		//释放资源
		void FreeConnect()
		{
			//释放资源
			mysql_free_result(res);
			mysql_close(&mysql);
		}

		bool Open() {
			mysql_init(&mysql);  //连接mysql，数据库
			if (!(mysql_real_connect(&mysql, "localhost", "db_admin", "201314", "game_data", 8000, NULL, 0)))
			{
				printf("Error connecting MySQL to database:%s\n", mysql_error(&mysql));
				return false;
			}
			else
			{
				printf("Connected MySQL...\n");
				return true;
			}
		}

		void Close() {
			if (res != nullptr) {
				mysql_free_result(res);
				res = nullptr;
			}
			mysql_close(&mysql);
		}

private:

	MYSQL mysql; //mysql连接
	MYSQL_FIELD *fd;  //字段列数组
	MYSQL_RES *res; //这个结构代表返回行的一个查询结果集
	MYSQL_ROW column; //一个行数据的类型安全(type-safe)的表示，表示数据行的列

	char field[32][32];  //存字段名二维数组
	char query[150]; //查询语句
};