#include <string>
#include "../createConnection.h"
#include "../../wordlecpp/loginregistro.h"

using namespace std;

#ifndef GETDATA_H_
#define GETDATA_H_


Usuario *getUsuario (char* nombreUsu, char* contrasenya);
Usuario* listaUsuarios(sqlite3 *db, int tamanyo);
Partida* listaPartidas(sqlite3 *db, int tamanyo);
#endif