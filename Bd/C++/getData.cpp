#include "getData.h"
#include "../sqlite/sqlite3.h"
#include "../createConnection.h"
#include <string.h>
#include "loginregistro.h"


using namespace std;
using namespace inicio;

inicio :: Usuario *getUsuario (char* nombreUsu, char* contrasenya)
{
    int rc;
    char *err_msg = 0;
    sqlite3_stmt *res;

    int codUsu;
    char *nombreUsu = new char[strlen(nombreUsu)+1];
    char *contrasenya = new char[strlen(contrasenya)+1];
    int edad;
    char sexo;
    
    Usuario *usu = new Usuario();
    char *sql = "SELECT * FROM USUARIO WHERE NOMBREUSU = ? AND CONTRASENYA = ?";

    rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

    if (rc == SQLITE_OK)
    {
        sqlite3_bind_text(res, 1, nombreUsu, -1, SQLITE_STATIC); // Le pasamos el (strlen(id)-1) para que ignore el /0 del id, si no no funciona
    }
    else
    {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
    }

    

    int step = sqlite3_step(res);

    if (step == SQLITE_ROW)
    {

        usu = new Usuario((char *)sqlite3_column_text(res, 0),(char *)sqlite3_column_text(res, 1), sqlite3_column_int(res, 3),(char *)sqlite3_column_text(res, 2),  (char *)sqlite3_column_text(res, 4));

        // guardamos la información
    }
    else
    {
        printf("No results found");
    }

    return usu;
}