///// db by liqon, 02.10 v1

#include <iostream>
#include "database.h"

DataBase::DataBase()
{

}

//void DataBase::createCalendary()
//{
//    sqlite3_open("Calendary.db", &db);
//    int rc = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS cal(date date, time time, mode varchar(100), text varchar(32760));", NULL, NULL, &err);
//    if (rc != SQLITE_OK)
//        exit(*err);
//}

//void DataBase::insertRow(memoNoteInputInfo info)
//{
//    string query = "insert into cal VALUES (date("+(info.date)+"), time("+(info.time)+"), "+(info.mode)+", "+(info.text)+");";
//    cout << query << endl;
//    int rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &err);
//    if (rc != SQLITE_OK)
//        exit(*err);
//}

//void DataBase::select()
//{
//    sqlite3_stmt* stmt;
//    sqlite3_prepare_v2(db, "select date, time, mode, text from cal", -1, &stmt, NULL);

//    memoNoteOutputInfo info;

//    while (sqlite3_step(stmt) != SQLITE_DONE)
//    {
//        info = {sqlite3_column_text(stmt, 0), sqlite3_column_text(stmt, 1), sqlite3_column_text(stmt, 2), sqlite3_column_text(stmt, 3)};
//        cout << "date = " << info.date << " time = " << info.time << " mode = " << info.mode << " text = " << info.text << endl;
//    }
//}

//void DataBase::selectSearch(string modifier)
//{
//    sqlite3_stmt* stmt;
//    string modi = "select date, time, mode, text from cal " + modifier;
//    sqlite3_prepare_v2(db, modi.c_str() , -1, &stmt, NULL);

//    memoNoteOutputInfo info;

//    while (sqlite3_step(stmt) != SQLITE_DONE)
//    {
//        info = {sqlite3_column_text(stmt, 0), sqlite3_column_text(stmt, 1), sqlite3_column_text(stmt, 2), sqlite3_column_text(stmt, 3)};
//        cout << "date = " << info.date << " time = " << info.time << " mode = " << info.mode << " text = " << info.text << endl;
//    }
//}

//void DataBase::deleteTable()
//{
//    string del_query = "delete from cal";
//    int rc = sqlite3_exec(db, del_query.c_str(), NULL, NULL, &err);
//    if (rc != SQLITE_OK)
//        exit(*err);
//}

//void DataBase::deleteChosen(string modifier)
//{
//    string del_query = "delete from cal " + modifier;
//    int rc = sqlite3_exec(db, del_query.c_str(), NULL, NULL, &err);
//    if (rc != SQLITE_OK)
//        exit(*err);
//}

//void DataBase::close()
//{
//    sqlite3_close(db);
//}
