#include <iostream>
#include "../sqlite/sqlite3.h"
#include <string>
using namespace std;

int main()
{
    char* err;
    sqlite3* db;
    sqlite3_stmt* stmt;
    sqlite3_open("myDb.db", &db);
    int rc = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS liq(x1 date, x2 date, name varchar(100));", NULL, NULL, &err);
    if (rc != SQLITE_OK)
    {
        cout << "error: " << err;
    }
    int day = -3;
    string query = "insert into liq VALUES (date('now'), date('now', '"+to_string(day)+" day'), 'test2');";
    cout << query << endl;
    rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &err);
    if (rc != SQLITE_OK)
    {
        cout << "Insert error: " << err;
    }
    sqlite3_prepare_v2(db, "select x1, x2, name from liq", -1, &stmt, NULL);
    const unsigned char* a1;
    const unsigned char* a2;
    const unsigned char* my_name;
    while (sqlite3_step(stmt) != SQLITE_DONE)
    {
        a1 = sqlite3_column_text(stmt, 0);
        a2 = sqlite3_column_text(stmt, 1);
        my_name = sqlite3_column_text(stmt, 2);
        cout << "a1 = " << a1 << " a2 = " << a2 << " name = " << my_name << endl;
    }
    sqlite3_close(db);
}
