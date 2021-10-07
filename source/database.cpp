#include "database.h"
#include <iostream>
#include "../sqlite/sqlite3.h"
#include <string>

database::database()
{

}

/// db by liqon, 02.10 v1


using namespace std;


/// \brief memoNoteOutputInfo serves to structurize info got from the table
/// data type caused by output format from table
struct memoNoteOutputInfo
{
    const unsigned char* date;
    const unsigned char* time;
    const unsigned char* mode;
    const unsigned char* text;
};


/// \brief memoNoteInputInfo serves to structurize info needed to put into the table
struct memoNoteInputInfo
{
    string date;
    string time;
    string mode;
    string text;
};


/// \brief Database class
/// here we contain notes with memeNote...Info atributes
class Calendary
{
public:
    Calendary()
    {}


    /// \brief create Calendary if not exists yet(open it else)
    void createCalendary()
    {
        sqlite3_open("Calendary.db", &db);
        int rc = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS cal(date date, time time, mode varchar(100), text varchar(32760));", NULL, NULL, &err);
        if (rc != SQLITE_OK)
            exit(*err);
    }

    /// \brief insert row with data into the bd
    /// \param info - input info
    void insertRow(memoNoteInputInfo info)
    {
        string query = "insert into cal VALUES (date("+(info.date)+"), time("+(info.time)+"), "+(info.mode)+", "+(info.text)+");";
        cout << query << endl;
        int rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &err);
        if (rc != SQLITE_OK)
            exit(*err);
    }

    /// \brief select all from the table(cout now)
    void select()
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

    ///
    /// \brief search in the table by any attribute
    /// \param modifier - the basis of the search
    void selectSearch(string modifier)
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

    /// \brief delete all table
    void deleteTable()
    {
        string del_query = "delete from cal";
        int rc = sqlite3_exec(db, del_query.c_str(), NULL, NULL, &err);
        if (rc != SQLITE_OK)
            exit(*err);
    }

    /// \brief delete chosen raws(notes)
    /// \param modifier the basis of the selection what to delete
    void deleteChosen(string modifier)
    {
        string del_query = "delete from cal " + modifier;
        int rc = sqlite3_exec(db, del_query.c_str(), NULL, NULL, &err);
        if (rc != SQLITE_OK)
            exit(*err);
    }

    void close()
    {
        sqlite3_close(db);
    }

private:
    sqlite3* db;
    char* err;
};

//int main()
//{
//    char* err;

//    Calendary calendary;
//    calendary.createCalendary();

//    memoNoteInputInfo info = {"'now'", "'now'", "'NONE'", "'my first note'"};

////    calendary.insertRow(info);


////    string search_modifier = "where text LIKE '%note%'";
////    string search_modifier = "where time = '12:48:39'";

////    calendary.selectSearch(search_modifier);

//    calendary.deleteChosen("where time = '13:45:13'");

////    calendary.deleteTable();

//    calendary.select();

//    calendary.close();

//    return 0;
//}
