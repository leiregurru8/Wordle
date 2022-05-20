#include "loginregistro.h"
#include <iostream>

namespace inicio{
	Usuario::Usuario(){//no sabemos si lo necesitamos
	}

	Usuario::~Usuario();//no sabemos si lo necesitamos

	Usuario:: Usuario(char* nombreUsu, char* contrasenya){
		this->nombreUsu = new char[strlen(nombreUsu)+1];
		strcpy(this->nombreUsu,nombreUsu);

		this->contrasenya = new char[strlen(contrasenya)+1];
		strcpy(this->contrasenya, contrasenya);
	}

	Usuario::Usuario(char* nombreUsu, char* contrasenya, int edad, char* ciudad, char sexo){
		this->nombreUsu = new char[strlen(nombreUsu)+1];
		strcpy(this->nombreUsu,nombreUsu);

		this->contrasenya = new char[strlen(contrasenya)+1];
		strcpy(this->contrasenya, contrasenya);

		this->edad=edad;

		this->ciudad = new char[strlen(ciudad)+1];
		strcpy(this->ciudad, ciudad);

		this->sexo=sexo;
	}

	Usuario Usuario::registro(){
		char* nombreUsu, contrasenya, ciudad;
		int edad;
		char sexo;
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
		
		Usuario(nombreUsu, contrasenya, edad, ciudad, sexo);

		return Usuario;
	}

		Usuario Usuario::login(){
			char* nombreUsu, contrasenya;

			cout<< "Introduce tu nombre de usuario:" <<endl;
			cin>> nombreUsu;
			cout<< "Introduce tu contrasenya:" <<endl;
			cin>> contrasenya;
			//SELECT CON LOS DATOS
			//A TRAVÉS DEL SOCKET MANDO NOMBREUSU Y CONTRASENYA
			//SI LA COMPROBACIÓN SALE BIEN, EL SOCKET ME DEVUELVE TODOS LOS DATOS DEL USUARIO SEPARADOS POR ;
			//SI LA COMPROBACIÓN SALE MAL, ME DEVUELVE NULL
			Usuario(nombreUsu, contrasenya);
			return Usuario;
		}
	
}

