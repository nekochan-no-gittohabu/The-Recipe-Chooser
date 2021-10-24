#include "Database_Manager.h"

const char* Database_Manager::dir = R"(CookBook.db)";

Database_Manager::Database_Manager() {
	this->createDB();
	this->createTable();
}

int Database_Manager::createDB()
{
	sqlite3* DB;

	int exit = 0;
	exit = sqlite3_open(Database_Manager::dir, &DB);

	sqlite3_close(DB);

	return 0;
}

int Database_Manager::createTable()
{
	sqlite3* DB;
	char* messageError;

	string sql = "CREATE TABLE IF NOT EXISTS RECIPES("
		"ID INTEGER PRIMARY KEY AUTOINCREMENT, "
		"NAME      TEXT NOT NULL, "
		"INGR      TEXT NOT NULL, "
		"AMOUNT    TEXT NOT NULL, "
		"RECIPE    TEXT NOT NULL );";

	try
	{
		int exit = 0;
		exit = sqlite3_open(Database_Manager::dir, &DB);
		/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
		exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
		if (exit != SQLITE_OK) {
			cerr << "Error in createTable function." << endl;
			sqlite3_free(messageError);
		}
		else
			cout << "Table created Successfully" << endl;
		sqlite3_close(DB);
	}
	catch (const exception& e)
	{
		cerr << e.what();
	}

	return 0;
}

int Database_Manager::insertData(const string& mystring)
{
	sqlite3* DB;
	char* messageError;

	string sql = "INSERT INTO RECIPES (NAME, INGR, AMOUNT, RECIPE) VALUES(" + mystring + ");";

	int exit = sqlite3_open(Database_Manager::dir, &DB);
	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK) {
		cerr << "Error in insertData function." << endl;
		sqlite3_free(messageError);
	}
	else
		cout << "Records inserted Successfully!" << endl;

	return 0;
}

int Database_Manager::updateData()
{
	sqlite3* DB;
	char* messageError;

	string sql("UPDATE RECIPE SET AMOUNT = '2 Teaspoons' WHERE INGR = 'Oil'");

	int exit = sqlite3_open(Database_Manager::dir, &DB);
	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK) {
		cerr << "Error in updateData function." << endl;
		sqlite3_free(messageError);
	}
	else
		cout << "Records updated Successfully!" << endl;

	return 0;
}

int Database_Manager::deleteData(std::string sdata)
{
	sqlite3* DB;
	char* messageError;

	string sql = "DELETE FROM RECIPES WHERE NAME IS '" + sdata + "';";

	int exit = sqlite3_open(Database_Manager::dir, &DB);
	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
	exit = sqlite3_exec(DB, sql.c_str(), Database_Manager::callback, NULL, &messageError);
	if (exit != SQLITE_OK) {
		cerr << "Error in deleteData function." << endl;
		sqlite3_free(messageError);
	}
	else
		cout << "Records deleted Successfully!" << endl;

	return 0;
}

int Database_Manager::selectData(int a, std::string sdata)
{
	sqlite3* DB;
	char* messageError;
	if (a == 0) {
		string sql = "SELECT * FROM RECIPES WHERE NAME LIKE '%" + sdata + "%' OR INGR LIKE '%" + sdata + "%';";
		int exit = sqlite3_open(Database_Manager::dir, &DB);
		/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here*/
		exit = sqlite3_exec(DB, sql.c_str(), Database_Manager::callback, NULL, &messageError);
	}
	else {
		string sql = "SELECT * FROM RECIPES WHERE NAME IS '" + sdata + "';";
		int exit = sqlite3_open(Database_Manager::dir, &DB);
		/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here*/
		exit = sqlite3_exec(DB, sql.c_str(), Database_Manager::callbackview, NULL, &messageError);
	}
	
	

	

	if (exit != SQLITE_OK) {
		cerr << "Error in selectData function." << endl;
		sqlite3_free(messageError);
	}
	else
		cout << "Records selected Successfully!" << endl;

	return 0;
}

// retrieve contents of database used by selectData()
/* argc: holds the number of results, argv: holds each value in array, azColName: holds each column returned in array, */
int Database_Manager::callback(void* NotUsed, int argc, char** argv, char** azColName
)
{
	QVector<QString> result{};
	for (int i = 0; i < argc; i++) {
		if (i==1)
			result.push_back(QString::fromStdString(argv[i]));
	}
	emit Database_Manager::Get().NameListLoaded(result);

	return 0;
}

int Database_Manager::callbackview(void* NotUsed, int argc, char** argv, char** azColName
)
{
	QVector<QString> result{};
	for (int i = 1; i < argc; i++) {
			result.push_back(QString::fromStdString(argv[i]));
	}
	emit Database_Manager::Get().RecipeLoaded(result);

	return 0;
}