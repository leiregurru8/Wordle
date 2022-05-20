#ifndef LOGINREGISTRO_H_
#define LOGINREGISTRO_H_

namespace inicio{

	class Usuario{
		private:
		char* nombreUsu;
		char* contrasenya;
		int edad;
		char* ciudad;
		char sexo;
		//array de partidas
		//estadisticas (opcional)

		public:
		Usuario();
		~Usuario();
		
		Usuario(char* nombreUsu, char* contrasenya, int edad, char* ciudad, char sexo);
		Usuario registro();
		Usuario login();
	}


}