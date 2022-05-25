#include "loginregistro.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

namespace inicio{
	Usuario::Usuario(){//no sabemos si lo necesitamos
	}

	Usuario::~Usuario(){}//no sabemos si lo necesitamos

	Usuario:: Usuario(char* nombreUsu, char* contrasenya){
		this->nombreUsu = new char[strlen(nombreUsu)+1];
		strcpy(this->nombreUsu,nombreUsu);

		this->contrasenya = new char[strlen(contrasenya)+1];
		strcpy(this->contrasenya, contrasenya);
	}

	Usuario::Usuario(char* nombreUsu, char* contrasenya, int edad, char* ciudad, char* sexo, int codUsu){
		this->nombreUsu = new char[strlen(nombreUsu)+1];
		strcpy(this->nombreUsu,nombreUsu);

		this->contrasenya = new char[strlen(contrasenya)+1];
		strcpy(this->contrasenya, contrasenya);

		this->edad=edad;

		this->ciudad = new char[strlen(ciudad)+1];
		strcpy(this->ciudad, ciudad);

		this->sexo=sexo;

		this-> codUsu=codUsu;
	}

	Usuario Usuario::registro(){
		char* nombreUsu;
		char* contrasenya;
		char* ciudad;
		char* sexo;
		int edad;
		int codUsu;
	
		cout<< "Bienvenido a Wordle! para poder registrarte deberas rellenar unos datos" <<endl;

		cout<< "Introduce tu nombre de usuario:" <<endl;
		cin>> nombreUsu;
		cout<< "Introduce tu contrasenya:" <<endl;
		cin>> contrasenya;
		cout<< "Introduce tu edad:" <<endl;
		cin>> edad;
		cout<< "Introduce tu ciudad:" <<endl;
		cin>> ciudad;
		cout<< "Introduce tu sexo (M o H):" <<endl;
		cin>> sexo;
		//LE ENVIO LOS DATOS AL SERVER PARA QUE HAGA LA INSERT
		
		Usuario u(nombreUsu,contrasenya,edad,ciudad,sexo);

		return u;
	}

		Usuario Usuario::login(){
			char* nombreUsu;
			char* contrasenya;

			cout<< "Introduce tu nombre de usuario:" <<endl;
			cin>> nombreUsu;
			cout<< "Introduce tu contrasenya:" <<endl;
			cin>> contrasenya;
			//SELECT CON LOS DATOS
			//A TRAVÉS DEL SOCKET MANDO NOMBREUSU Y CONTRASENYA
			//SI LA COMPROBACIÓN SALE BIEN, EL SOCKET ME DEVUELVE TODOS LOS DATOS DEL USUARIO SEPARADOS POR ;
			//SI LA COMPROBACIÓN SALE MAL, ME DEVUELVE NULL
			Usuario u(nombreUsu, contrasenya);
			return u;
		}
	
} //Separar por cliente y servidor. Servidor tiene el socket server y lo de la BD.
	//Cliente todo lo demás

	//El socket server tendrá un swithc, en función de lo que le llegue llama a 1 metodo de BD u otro
	//Por facilitar, metemos todas las clases en los dos lados y a las clases les añadimos el metodo toStr

