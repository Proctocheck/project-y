#ifndef CALENDARY_H
#define CALENDARY_H

#include "sqlite3.h"
#include "sqlite3ext.h"
#include <string>
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

class DataBase
{
public:
    DataBase();

    /// \brief create Calendary if not exists yet(open it else)
    void createCalendary();

    /// \brief insert row with data into the bd
    /// \param info - input info
    void insertRow(memoNoteInputInfo info);

    /// \brief select all from the table(cout now)
    void select();

    /// \brief search in the table by any attribute
    /// \param modifier - the basis of the search
    void selectSearch(string modifier);

    /// \brief delete all table
    void deleteTable();

    /// \brief delete chosen raws(notes)
    /// \param modifier the basis of the selection what to delete
    void deleteChosen(string modifier);


    void close();

private:
    sqlite3* db;
    char* err;
};

#endif // CALENDARY_H
