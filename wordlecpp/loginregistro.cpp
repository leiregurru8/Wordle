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


	//constructor copia 
	Usuario:: Usuario(const Usuario &u)
	{
	this->nombreUsu=new char[strlen(u.nombreUsu)];
	for(int i=0;i<strlen(u.nombreUsu);i++)
	{
		this->nombreUsu[i]=u.nombreUsu[i];
	}

	this->contrasenya=new char[strlen(u.contrasenya)];
	for(int i=0;i<strlen(u.contrasenya);i++)
	{
		this->contrasenya[i]=u.contrasenya[i];
	}
	this->edad=u.edad;

	this->nombreUsu=new char[strlen(u.ciudad)];
	for(int i=0;i<strlen(u.ciudad);i++)
	{
		this->ciudad[i]=u.ciudad[i];
	}

	this->sexo=new char[strlen(u.sexo)];
	for(int i=0;i<strlen(u.sexo);i++)
	{
		this->sexo[i]=u.sexo[i];
	}

	this->codUsu=u.codUsu;

}

	Usuario Usuario::registro()
	{
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
		cout<< "Introduce tu sexo (Mujer o Hombre):" <<endl;
		cin>> sexo;
		//LE ENVIO LOS DATOS AL SERVER PARA QUE HAGA LA INSERT
		
		Usuario u(nombreUsu,contrasenya,edad,ciudad,sexo);

		return u;
	}

		Usuario Usuario::login()
		{
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

	
	char *Usuario::getNombreUsu()
	{
		return this->nombreUsu;
	} 

	char* Usuario::getContrasenya()
	{
		return this->contrasenya;
	}
	int Usuario:: getEdad()
	{
		return this->edad;
	}
	char* Usuario:: getCiudad()
	{
		return this->ciudad;
	}
	char* Usuario:: getSexo()
	{
		return this->sexo;
	}
	int Usuario::getCodUsu()
	{
		return this->codUsu;
	}

	void Usuario::setNombreUsu(char* nombreUsu)
	{
		this->nombreUsu=nombreUsu;
	}
	void Usuario::setContrasenya(char* contrasenya)
	{
		this->contrasenya=contrasenya;
	}
	void Usuario::setEdad(int edad)
	{
		this->edad=edad;
	}
	void Usuario::setCiudad(char* ciudad)
	{
		this->ciudad=ciudad;
	}
	void Usuario::setSexo(char* sexo)
	{
		this->sexo=sexo;
	}
	void Usuario::setCodUsu(int codUsu)
	{
		this->codUsu=codUsu;
	}
	char* Usuario::obtenerDatos(){

		char*mensaje= new char[200];
		strcpy(mensaje, this->nombreUsu);
		strcat(mensaje, ";");
		strcat(mensaje, this->contrasenya);
		strcat(mensaje, ";");
		char* edad = new char[3];
		itoa(this->edad, edad, 0);
		strcat(mensaje,edad );
		strcat(mensaje, ";");
		strcat(mensaje, this->ciudad);
		strcat(mensaje, ";");
		strcat(mensaje, this->sexo);
		strcat(mensaje, ";");
		char* codUsu = new char[3];
		itoa(this->codUsu, codUsu, 0);
		strcat(mensaje,codUsu);

	}


	Partida::Partida(int codPartida,int numIntentos,int victoria,int codUsuario)
	{
		this-> codPartida=codPartida;

		this->numIntentos=numIntentos;

		this->victoria=victoria;

		this->codUsuario=codUsuario;

	}

	int Partida::getcodPartida()
	{
		return this->codPartida;
	}
	char* Partida::getFecha()
	{
		return this->fecha;
	}
	int Partida::getnumIntentos()
	{
		return this->numIntentos;
	}
	int Partida::getvictoria()
	{
		return this->victoria;
	}
	int Partida::getcodUsuario()
	{
		return this->codUsuario;
	}
	void Partida::setcodPartida(int codPartida)
	{
		this->codPartida=codPartida;
	}
	void Partida::setFecha(char* fecha)
	{
		this->fecha=fecha;
	}
	void Partida::setnumIntentos(int numIntentos)
	{
		this->numIntentos=numIntentos;
	}
	void Partida::setvictoria(int victoria)
	{
		this->victoria=victoria;
	}
	void Partida::setcodUsuario(int codUsuario)
	{
		this->codUsuario=codUsuario;
	}

} //Separar por cliente y servidor. Servidor tiene el socket server y lo de la BD.
	//Cliente todo lo demás

	//El socket server tendrá un swithc, en función de lo que le llegue llama a 1 metodo de BD u otro
	//Por facilitar, metemos todas las clases en los dos lados y a las clases les añadimos el metodo toStr

