// SQLiteImplentation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sqlite3.h>
using namespace std;
int main()
{

	sqlite3 *db;
	sqlite3_stmt * stmt = nullptr;
	string sqlstatement = "insert into sample_table (value1,value2) values (3,3);";
	if (sqlite3_open("Sample.db", &db) == SQLITE_OK)
	{
		sqlite3_prepare(db, sqlstatement.c_str(), -1, &stmt, NULL);//preparing the statement
		sqlite3_step(stmt);//executing the statement
	}
	else
	{
		cout << "Failed to open db\n";
	}
	sqlite3_finalize(stmt);
	sqlite3_close(db);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
