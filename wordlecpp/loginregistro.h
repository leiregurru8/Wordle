#ifndef LOGINREGISTRO_H_
#define LOGINREGISTRO_H_

namespace inicio{

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
		Usuario registro();
		Usuario login();
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

			

	};

}

#endif