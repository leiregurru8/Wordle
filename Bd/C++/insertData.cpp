#include "insertData.h"
#include "../sqlite/sqlite3.h"
#include "../createConnection.h"
#include <string.h>
#include "loginregistro.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int insertarUsuario(sqlite3 * db, char* nombreUsu, char* contrasenya,  int edad, char* ciudad, char* sexo, int codUsu)
{
	sqlite3_stmt *stmt;
	char sql[] = "INSERT INTO Usuario (nombreUsu, contrasenya,edad,ciudad,sexo,codUsu) values (?,?,?,?,?,?)";

	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);		
	if (result != SQLITE_OK)
	{
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (INSERT)\n");
	result = sqlite3_bind_text(stmt, 1, nombreUsu, strlen(nombreUsu), SQLITE_STATIC);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters2\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 2, contrasenya, strlen(contrasenya), SQLITE_STATIC);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters2\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_int(stmt, 3, edad);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters2\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 4, ciudad, strlen(ciudad), SQLITE_STATIC);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters2\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 5, sexo, strlen(sexo), SQLITE_STATIC);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters2\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
    result = sqlite3_bind_int(stmt, 6, codUsu);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters3\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE)
	{
		printf("Error\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK)
	{
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (INSERT)\n");
	return SQLITE_OK;
}
int insertarPartida(sqlite3 * db, int codPartida, int numIntentos,  int victoria, int codUsuario)
{
	sqlite3_stmt *stmt;
	char sql[] = "INSERT INTO Partida (codPartida, numIntentos,victoria,codUsuario) values (?,?,?,?,?)";

	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);		
	if (result != SQLITE_OK)
	{
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

    result = sqlite3_bind_int(stmt, 1, codPartida);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters2\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_int(stmt, 2, numIntentos);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters2\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
     result = sqlite3_bind_int(stmt, 3, victoria);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters2\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

    result = sqlite3_bind_int(stmt, 4, codUsuario);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters2\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}


	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE)
	{
		printf("Error\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK)
	{
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (INSERT)\n");
	return SQLITE_OK;
}