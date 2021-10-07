/// db by liqon, 02.10 v1

#include <iostream>
#include "calendary.h"

void Calendary::createCalendary()
{
    sqlite3_open("Calendary.db", &db);
    int rc = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS cal(date date, time time, mode varchar(100), text varchar(32760));", NULL, NULL, &err);
    if (rc != SQLITE_OK)
        exit(*err);
}

void Calendary::insertRow(memoNoteInputInfo info)
{
    string query = "insert into cal VALUES (date("+(info.date)+"), time("+(info.time)+"), "+(info.mode)+", "+(info.text)+");";
    cout << query << endl;
    int rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &err);
    if (rc != SQLITE_OK)
        exit(*err);
}

void Calendary::select()
{
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, "select date, time, mode, text from cal", -1, &stmt, NULL);

    memoNoteOutputInfo info;

    while (sqlite3_step(stmt) != SQLITE_DONE)
    {
        info = {sqlite3_column_text(stmt, 0), sqlite3_column_text(stmt, 1), sqlite3_column_text(stmt, 2), sqlite3_column_text(stmt, 3)};
        cout << "date = " << info.date << " time = " << info.time << " mode = " << info.mode << " text = " << info.text << endl;
    }
}

void Calendary::selectSearch(string modifier)
{
    sqlite3_stmt* stmt;
    string modi = "select date, time, mode, text from cal " + modifier;
    sqlite3_prepare_v2(db, modi.c_str() , -1, &stmt, NULL);

    memoNoteOutputInfo info;

    while (sqlite3_step(stmt) != SQLITE_DONE)
    {
        info = {sqlite3_column_text(stmt, 0), sqlite3_column_text(stmt, 1), sqlite3_column_text(stmt, 2), sqlite3_column_text(stmt, 3)};
        cout << "date = " << info.date << " time = " << info.time << " mode = " << info.mode << " text = " << info.text << endl;
    }
}

void Calendary::deleteTable()
{
    string del_query = "delete from cal";
    int rc = sqlite3_exec(db, del_query.c_str(), NULL, NULL, &err);
    if (rc != SQLITE_OK)
        exit(*err);
}

void Calendary::deleteChosen(string modifier)
{
    string del_query = "delete from cal " + modifier;
    int rc = sqlite3_exec(db, del_query.c_str(), NULL, NULL, &err);
    if (rc != SQLITE_OK)
        exit(*err);
}

void Calendary::close()
{
    sqlite3_close(db);
}

int main()
{
    char* err;

    Calendary calendary;
    calendary.createCalendary();

    memoNoteInputInfo info = {"'now'", "'now'", "'NONE'", "'my first note'"};

//        calendary.insertRow(info);


    //    string search_modifier = "where text LIKE '%note%'";
    //    string search_modifier = "where time = '12:48:39'";

    //    calendary.selectSearch(search_modifier);

    calendary.deleteChosen("where time = '13:45:13'");

    //    calendary.deleteTable();

    calendary.select();

    calendary.close();

    return 0;
}
