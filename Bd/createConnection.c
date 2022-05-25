#include "createConnection.h"
#include "sqlite/sqlite3.h"
#include  <stdio.h>

sqlite3 *db;

int startConn()
{
    int rc = sqlite3_open("./Bd/db.db", &db);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Cannot open database: %s\n",
                sqlite3_errmsg(db));
        sqlite3_close(db);

        return 0;
    }

    return 1;
}
int main(void)
{
    int conn = startConn();

    if(conn==1)
    {
        printf("todo ok");
    }
}