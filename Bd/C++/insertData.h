#include <string>
#include "../createConnection.h"
#include "../../wordlecpp/loginregistro.h"

using namespace std;

#ifndef INSERTDATA_H_
#define INSERTDATA_H_

int insertarUsuario(sqlite3 * db, char* nombreUsu, char* contrasenya,  int edad, char* ciudad, char* sexo, int codUsu);
int insertarPartida(sqlite3 * db, int codPartida, int numIntentos,  int victoria, int codUsuario);

#endif