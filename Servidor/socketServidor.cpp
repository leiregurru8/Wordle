#undef UNICODE

#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT 0x501

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include "../Bd/C++/getData.h"
#include "../Bd/sqlite/sqlite3.h"
#include "../wordlecpp/loginregistro.h"
// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")
// #pragma comment (lib, "Mswsock.lib")
using namespace std;
#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"
#define MaxUsuarios 100
#define MaxPartidas 5000



char* leerContrasenya();
   
int leerPuerto();

int __cdecl main(void) 
{   
    
    char* contrasenya=leerContrasenya();
    char*contra=new char[strlen(contrasenya)+1];
    int puerto=leerPuerto();
    bool contraCorrecta=false;
    while(contraCorrecta==false){
        cout<<"Introduce tu contrasenya: "<<endl;
        cout<<"x para salir: "<<endl;
        cin>>contra;
        if(strcmp(contra,contrasenya)==0){
            contraCorrecta=true;
        }
        if(contra[0]=='x'){
            return 0;
        }
    }
    sqlite3 *db;
	sqlite3_open("../Bd/db.db", &db);
    Usuario *usuarios=new Usuario[MaxUsuarios];
    usuarios=listaUsuarios(db,MaxUsuarios);
	Partida *partidas=new Partida[MaxPartidas];
    partidas=listaPartidas(db,MaxPartidas);

//AQUI ESTAMOSSSS
   // leerBD(db,usuarios,partidas);



    WSADATA wsaData;
    int iResult;

    SOCKET ListenSocket = INVALID_SOCKET;
    SOCKET ClientSocket = INVALID_SOCKET;

    struct addrinfo *result = NULL;
    struct addrinfo hints;

    int iSendResult;
    char *recvbuf;
    recvbuf=new char[DEFAULT_BUFLEN];
    //char recvbuf[DEFAULT_BUFLEN];
    int recvbuflen = DEFAULT_BUFLEN;
    char *sendbuf = "this is a test";

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;


    // Resolve the server address and port
    iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
    if ( iResult != 0 ) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        return 1;
    }

    // Create a SOCKET for connecting to server
    ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (ListenSocket == INVALID_SOCKET) {
        printf("socket failed with error: %ld\n", WSAGetLastError());
        freeaddrinfo(result);
        WSACleanup();
        return 1;
    }

    // Setup the TCP listening socket
    iResult = bind( ListenSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    freeaddrinfo(result);

    iResult = listen(ListenSocket, SOMAXCONN);
    if (iResult == SOCKET_ERROR) {
        printf("listen failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    // Accept a client socket
    ClientSocket = accept(ListenSocket, NULL, NULL);
    if (ClientSocket == INVALID_SOCKET) {
        printf("accept failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    Usuario u;
    char* mensaje=new char[15];
    bool coincide=false;
    closesocket(ListenSocket);
    // Receive until the peer shuts down the connection
    while(iResult!=0){
        while(coincide==false){
            //Recibe mensaje
            iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
            for(int i =0;i<iResult;i++){
                cout<<recvbuf[i];
            }
            recvbuf=new char[iResult];
            cout<<"////";
            cout<<recvbuf<<endl;
            if(strcmp(recvbuf,"x")){
                return 0;
            }         
            for (int i = 0; i < 1000; i++)
            {
                if(strcmp(recvbuf,usuarios[i].getNombreUsu())==0){
                    mensaje=("Introduce tu contrasenya: ");
                    sendbuf=new char[strlen(mensaje)+1];
                    for(int i=0;i<strlen(mensaje);i++){
                        sendbuf[i]=mensaje[i];
                    } 
                    iSendResult = send( ClientSocket, sendbuf, (int)strlen(sendbuf), 0 );
                    coincide=true;
                    u=usuarios[i];
                    
                    
                }                            
            }
            if(coincide==false){
                mensaje=("No se encuentra ese usuario,intentelo de nuevo");
                sendbuf=new char[strlen(mensaje)+1];
                for(int i=0;i<strlen(mensaje);i++){
                    sendbuf[i]=mensaje[i];
                }
                iSendResult = send( ClientSocket, sendbuf, (int)strlen(sendbuf), 0 ); 
            }                       
            
        }
        

        if (iSendResult == SOCKET_ERROR) {
            printf("send failed with error: %d\n", WSAGetLastError());
            closesocket(ClientSocket);
            WSACleanup();
            return 1;
        }

        //Recibe mensaje
        iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
        for(int i =0;i<iResult;i++){
            cout<<recvbuf[i];
        }
        cout<<endl;
            
        recvbuf=new char[iResult];

    }

     //Envia mensaje
        coincide=false;

        char *input;
        input = new char;
        while(coincide==false){  
            if(strcmp(recvbuf,u.getContrasenya())==0){
                mensaje=("1.Jugar al Wordle\n 2. Perfil\n  3. Ver estadísticas\n 4. Salir\n Elija una opcion: ");
        cin >> input;
        cin.ignore();
                sendbuf=new char[strlen(mensaje)+1];
                    for(int i=0;i<strlen(mensaje);i++){
                        sendbuf[i]=mensaje[i];
                    }
                coincide=true;

            }else{
                mensaje=("Contrasenya incorrecta, intentelo de nuevo ");
                sendbuf=new char[strlen(mensaje)+1];
                for(int i=0;i<strlen(mensaje);i++){
                    sendbuf[i]=mensaje[i];
                }
                iSendResult = send( ClientSocket, sendbuf, (int)strlen(sendbuf), 0 ); 
            }                          
        }

        if (iSendResult == SOCKET_ERROR) {
            printf("send failed with error: %d\n", WSAGetLastError());
            closesocket(ClientSocket);
            WSACleanup();
            return 1;
        } 


        //Recibe mensaje
        iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
        for(int i =0;i<iResult;i++){
            cout<<recvbuf[i];
        }
        cout<<endl;
            
        recvbuf=new char[iResult];

        
        //Envia el mensaje  
        if(recvbuf[0]=='x')
                return 0;
        sscanf(recvbuf,"%i",input);
        
        switch (*input)
        {
        case '1':
        
            break;

        case '2':
            strcat(mensaje, "2;");
            mensaje=(u.obtenerDatos());
            iSendResult = send( ClientSocket, mensaje, (int)strlen(sendbuf), 0 ); 
            break;
        case '3':

            break;
        }
}
            


  