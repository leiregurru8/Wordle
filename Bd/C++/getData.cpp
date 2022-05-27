#include "getData.h"
#include "../sqlite/sqlite3.h"
#include "../createConnection.h"
#include <string.h>
#include "loginregistro.h"
#include <iostream>


using namespace std;

int numeroUsuarios (sqlite3 *db)
{
    sqlite3_stmt *stmt;
    char sql[] = "select * from CLIENTE";
    int result = sqlite3_prepare_v2(db,sql,strlen(sql)+1,&stmt,NULL);

    if(result!=SQLITE_OK){
        cout<<"Error preparando la consulta"<<endl;
        cout<<(sqlite3_errmsg(db))<<endl;
        return result;
    }
    int contador = 0;
    do{
        result = sqlite3_step(stmt);
        if(result == SQLITE_ROW){
            contador++;
        }
    } while(result == SQLITE_ROW);

    result = sqlite3_finalize(stmt);
    if(result != SQLITE_OK){
        cout<<"Error finalizando la consulta."<<endl;
        cout<<(sqlite3_errmsg(db))<<endl;
        return result;
    }
    return contador;
}


int numeroPartidas(sqlite3 *db)
{
    sqlite3_stmt *stmt;
    char sql[] = "select * from PARTIDA";
    int result = sqlite3_prepare_v2(db,sql,strlen(sql)+1,&stmt,NULL);

    if(result!=SQLITE_OK){
        cout<<"Error"<<endl;
        cout<<(sqlite3_errmsg(db))<<endl;
        return result;
    }
    int contador = 0;
    do{
        result = sqlite3_step(stmt);
        if(result == SQLITE_ROW){
            contador++;
        }
    } while(result == SQLITE_ROW);

    result = sqlite3_finalize(stmt);
    if(result != SQLITE_OK){
        cout<<"Error"<<endl;
        cout<<(sqlite3_errmsg(db))<<endl;
        return result;
    }
    return contador;
}


Usuario* listaUsuarios(sqlite3 *db, int tamanyo)
{
    sqlite3_stmt *stmt;
	char sql[] = "SELECT * FROM USUARIO";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error(SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}
	Usuario *usuarios=new Usuario[tamanyo];
	int cont=0;
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			usuarios[cont].setNombreUsu( (char *) sqlite3_column_text(stmt, 0));
			usuarios[cont].setContrasenya( (char *) sqlite3_column_text(stmt, 1)); 
            usuarios[cont].setEdad(sqlite3_column_int(stmt, 2));
			usuarios[cont].setCiudad((char *) sqlite3_column_text(stmt, 3));
            usuarios[cont].setSexo((char *) sqlite3_column_text(stmt, 4));
            usuarios[cont].setCodUsu(sqlite3_column_int(stmt, 5));
			cont++;
		}
	} while (result == SQLITE_ROW);

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		
	}

	return usuarios;
}

Partida* listaPartidas(sqlite3 *db, int tamanyo)
{
    sqlite3_stmt *stmt;
	char sql[] = "SELECT * FROM PARTIDA";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error(SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}
	Partida *partidas=new Partida[tamanyo];
	int cont=0;
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			partidas[cont].setcodPartida(sqlite3_column_int(stmt, 0));
			partidas[cont].setnumIntentos(sqlite3_column_int(stmt, 1));
            partidas[cont].setvictoria(sqlite3_column_int(stmt, 2));
            partidas[cont].setcodUsuario(sqlite3_column_int(stmt, 3));
			cont++;
		}
	} while (result == SQLITE_ROW);

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		
	}

	return partidas;
}
