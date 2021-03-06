#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT 0x501

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;


// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")


#define DEFAULT_BUFLEN 1024
#define DEFAULT_PORT "27015"

int __cdecl main(int argc, char **argv) 
{
    WSADATA wsaData;
    SOCKET ConnectSocket = INVALID_SOCKET;
    struct addrinfo *result = NULL,
                    *ptr = NULL,
                    hints;
    char *sendbuf = "Conexión del cliente establece\0\n";
    char* recvbuf;
    recvbuf=new char[DEFAULT_BUFLEN];
    int iResult;
    int recvbuflen = DEFAULT_BUFLEN;               


    // Validate the parameters
    if (argc != 2) {
        printf("usage: %s server-name\n", argv[0]);
        return 1;
    }

        // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }

    ZeroMemory( &hints, sizeof(hints) );
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    // Resolve the server address and port
    iResult = getaddrinfo(argv[1], DEFAULT_PORT, &hints, &result);
    if ( iResult != 0 ) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        return 1;
    }

    
    // Attempt to connect to an address until one succeeds
    for(ptr=result; ptr != NULL ;ptr=ptr->ai_next) {

    // Create a SOCKET for connecting to server
    ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, 
        ptr->ai_protocol);
    if (ConnectSocket == INVALID_SOCKET) {
        printf("socket failed with error: %ld\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    
    // Connect to server.
    iResult = connect( ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        closesocket(ConnectSocket);
        ConnectSocket = INVALID_SOCKET;
        continue;
    }
        break;
    }

    freeaddrinfo(result);
    char* textoAEnviar=new char[15];

    if (ConnectSocket == INVALID_SOCKET) {
        printf("Unable to connect to server!\n");
        WSACleanup();
        return 1;
    }

    int a=1;
    while(a==1){  

        //Envia el mensaje
        cout<<"Bienvenido! Acceda con el usuario o x para salir"<<endl;
        
    
        cin.getline(textoAEnviar,35);
        sendbuf=new char[strlen(textoAEnviar)+1];

        for(int i=0;i<strlen(textoAEnviar);i++){
            sendbuf[i]=textoAEnviar[i];
        }

        sendbuf[strlen(textoAEnviar)]='\0';
        
        iResult = send( ConnectSocket, sendbuf, (int)strlen(sendbuf), 0 );

        if (iResult == SOCKET_ERROR) {
            printf("send failed with error: %d\n", WSAGetLastError());
            closesocket(ConnectSocket);
            WSACleanup();        
        }    

        //Recibir mensaje        

        iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
        if (iResult > 0) {
            for(int i=0;i<iResult;i++){
                cout<<recvbuf[i];
            }
            cout<<endl;
            
            recvbuf=new char[iResult];
            //necesito un metodo que interprete lo que me está llegando al cliente, a veces sera la info del usuario, otras veces otra cosa
            //el metodo de interpretar tiene un switch, que en funcion de la primera posicion de lo que devuelve el servidor yo sé qué esperar
            //si recvbuf igual a opcion de juego, abro el juego
            cout<<recvbuf;
        }else if ( iResult == 0 )
            printf("Connection closed\n");
        else
            printf("recv failed with error: %d\n", WSAGetLastError());

         

    }
    // Cerrar conexion
    iResult = shutdown(ConnectSocket, SD_SEND);
        if (iResult == SOCKET_ERROR) {
            printf("shutdown failed with error: %d\n", WSAGetLastError());
            closesocket(ConnectSocket);
            WSACleanup();
            return 1;
        }

    closesocket(ConnectSocket);
    WSACleanup();

    return 0;
}

void interpretar(char* mensaje){
    int a = 1;
    do{
        switch(mensaje[0]){
            case '1':
                //interpreto que quiere empezar a jugar
        }


    } while(a == 1);
}
