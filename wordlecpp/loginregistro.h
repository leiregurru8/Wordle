#ifndef LOGINREGISTRO_H_
#define LOGINREGISTRO_H_

class Usuario{
		private:
			char* nombreUsu;
			char* contrasenya;
			int edad;
			char* ciudad;
			char* sexo;
			int codUsu;
			//array de partidas
			//estadisticas (opcional)

		public:
		Usuario();
		~Usuario();
		Usuario(char* nombreUsu, char* contrasenya);
		Usuario(char* nombreUsu, char* contrasenya, int edad, char* ciudad, char* sexo);
		Usuario(char* nombreUsu, char* contrasenya, int edad, char* ciudad, char* sexo, int codUsu);
		Usuario(const Usuario &u);
		char* getNombreUsu();
		char* getContrasenya();
		int getEdad();
		char* getCiudad();
		char* getSexo();
		int getCodUsu();
		void setNombreUsu(char* nombreUsu);
		void setContrasenya(char* contrasenya);
		void setEdad(int edad);
		void setCiudad(char* ciudad);
		void setSexo(char* sexo);
		void setCodUsu(int codUsu);
		Usuario registro();
		Usuario login();

		char* obtenerDatos();
	};
	class Partida
	{
		private:
			int codPartida;
			char* fecha;
			int numIntentos;
			int victoria;
			int codUsuario;

		public:
			Partida();
			~Partida();
			Partida(int codPartida,char* fecha,int numIntentos,int victoria,int codUsuario);
			Partida(int codPartida,int numIntentos,int victoria,int codUsuario);
			Partida(const Partida &p);
			int getcodPartida();
			char* getFecha();
			int getnumIntentos();
			int getvictoria();
			int getcodUsuario();
			void setcodPartida(int codPartida);
			void setFecha(char* fecha);
			void setnumIntentos(int numIntentos);
			void setvictoria(int victoria);
			void setcodUsuario(int codUsuario);
	};


#endif