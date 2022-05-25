#include "loginregistro.h"
#include <iostream>

using namespace inicio;
using namespace std;

 main(){

    int opcion;
    Usuario u1;
    Usuario nuevo;

    cout<< "Que deseas hacer?" <<endl;
    cout <<" 1. iniciar sesion" <<endl;
    cout <<" 2. registrarse" <<endl;

    cin >> opcion;

    if (opcion == 1){
        u1.login();
    }
    else{
        if (opcion ==2){
            u1.registro();
        }
        else{
            cout<< "introduce 1 o 2" <<endl;
        }
    }



    return 0;
 }