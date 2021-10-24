#pragma once

#include <sqlite3.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <QObject>
#include <QVector>
#include <QString>
using namespace std;

class Database_Manager : public QObject {
	Q_OBJECT
public:
	static Database_Manager& Get() {
		static Database_Manager database;
		return database;
	}

	static const char* dir;
	static int createDB();
	static int createTable();
	static int deleteData(std::string sdata);
	static int insertData(const std::string& mystring);
	static int updateData();
	static int selectData(int a, std::string sdata);
	static int callback(void* NotUsed, int argc, char** argv, char** azColName);
	static int callbackview(void* NotUsed, int argc, char** argv, char** azColName);

signals:
	void NameListLoaded(QVector<QString> Values);
	void RecipeLoaded(QVector<QString> Values);

private:
	Database_Manager();
};
	