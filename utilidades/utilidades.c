#include "../configuracion.h"
#include "utilidades.h"
#include "../palabras/palabras.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

int numeroAleatorio() //devuelve un numero aleatorio
{
    int numero;
    srand(time(0)); // https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/
    do
    {
        numero = rand(); //aleatoriamente hasta encontrar un numero entre 0- num. palabras
    } while (numero > NUM_PALABRAS);

    return numero;
}

void printfColor(char color[]) //https://www.theurbanpenguin.com/4184-2/
{
    printf("\033%s", color); // escape para cambiar de color + codigo de color (utilidades.h)
}

void imprimirPalabra(char palabra[6], char palabraAdivinar[6])//la palabra que introducidda y la palabra a adivinar
{
    int correcto[] = {palabraAdivinar[0] == palabra[0], palabraAdivinar[1] == palabra[1], palabraAdivinar[2] == palabra[2], palabraAdivinar[3] == palabra[3], palabraAdivinar[4] == palabra[4]};
    int contiene[] = {strchr(palabraAdivinar, palabra[0]) != NULL, strchr(palabraAdivinar, palabra[1]) != NULL, strchr(palabraAdivinar, palabra[2]) != NULL, strchr(palabraAdivinar, palabra[3]) != NULL, strchr(palabraAdivinar, palabra[4]) != NULL};

    printfColor(correcto[0] ? COLOR_VERDE : (contiene[0] ? COLOR_AMARILLO : COLOR_DEFECTO));
    printf("┏━━━━━━━┓ ");
    printfColor(correcto[1] ? COLOR_VERDE : (contiene[1] ? COLOR_AMARILLO : COLOR_DEFECTO));
    printf("┏━━━━━━━┓ ");
    printfColor(correcto[2] ? COLOR_VERDE : (contiene[2] ? COLOR_AMARILLO : COLOR_DEFECTO));
    printf("┏━━━━━━━┓ ");
    printfColor(correcto[3] ? COLOR_VERDE : (contiene[3] ? COLOR_AMARILLO : COLOR_DEFECTO));
    printf("┏━━━━━━━┓ ");
    printfColor(correcto[4] ? COLOR_VERDE : (contiene[4] ? COLOR_AMARILLO : COLOR_DEFECTO));
    printf("┏━━━━━━━┓\n");

    printfColor(correcto[0] ? COLOR_VERDE : (contiene[0] ? COLOR_AMARILLO : COLOR_DEFECTO));
    printf("┃       ┃ ");
    printfColor(correcto[1] ? COLOR_VERDE : (contiene[1] ? COLOR_AMARILLO : COLOR_DEFECTO));
    printf("┃       ┃ ");
    printfColor(correcto[2] ? COLOR_VERDE : (contiene[2] ? COLOR_AMARILLO : COLOR_DEFECTO));
    printf("┃       ┃ ");
    printfColor(correcto[3] ? COLOR_VERDE : (contiene[3] ? COLOR_AMARILLO : COLOR_DEFECTO));
    printf("┃       ┃ ");
    printfColor(correcto[4] ? COLOR_VERDE : (contiene[4] ? COLOR_AMARILLO : COLOR_DEFECTO));
    printf("┃       ┃\n");

    printfColor(correcto[0] ? COLOR_VERDE : (contiene[0] ? COLOR_AMARILLO : COLOR_DEFECTO));
    printf("┃   %c   ┃ ", palabra[0]);
    printfColor(correcto[1] ? COLOR_VERDE : (contiene[1] ? COLOR_AMARILLO : COLOR_DEFECTO));
    printf("┃   %c   ┃ ", palabra[1]);
    printfColor(correcto[2] ? COLOR_VERDE : (contiene[2] ? COLOR_AMARILLO : COLOR_DEFECTO));
    printf("┃   %c   ┃ ", palabra[2]);
    printfColor(correcto[3] ? COLOR_VERDE : (contiene[3] ? COLOR_AMARILLO : COLOR_DEFECTO));
    printf("┃   %c   ┃ ", palabra[3]);
    printfColor(correcto[4] ? COLOR_VERDE : (contiene[4] ? COLOR_AMARILLO : COLOR_DEFECTO));
    printf("┃   %c   ┃\n", palabra[4]);

    printfColor(correcto[0] ? COLOR_VERDE : (contiene[0] ? COLOR_AMARILLO : COLOR_DEFECTO));
    printf("┃       ┃ ");
    printfColor(correcto[1] ? COLOR_VERDE : (contiene[1] ? COLOR_AMARILLO : COLOR_DEFECTO));
    printf("┃       ┃ ");
    printfColor(correcto[2] ? COLOR_VERDE : (contiene[2] ? COLOR_AMARILLO : COLOR_DEFECTO));
    printf("┃       ┃ ");
    printfColor(correcto[3] ? COLOR_VERDE : (contiene[3] ? COLOR_AMARILLO : COLOR_DEFECTO));
    printf("┃       ┃ ");
    printfColor(correcto[4] ? COLOR_VERDE : (contiene[4] ? COLOR_AMARILLO : COLOR_DEFECTO));
    printf("┃       ┃\n");

    printfColor(correcto[0] ? COLOR_VERDE : (contiene[0] ? COLOR_AMARILLO : COLOR_DEFECTO));
    printf("┗━━━━━━━┛ ");
    printfColor(correcto[1] ? COLOR_VERDE : (contiene[1] ? COLOR_AMARILLO : COLOR_DEFECTO));
    printf("┗━━━━━━━┛ ");
    printfColor(correcto[2] ? COLOR_VERDE : (contiene[2] ? COLOR_AMARILLO : COLOR_DEFECTO));
    printf("┗━━━━━━━┛ ");
    printfColor(correcto[3] ? COLOR_VERDE : (contiene[3] ? COLOR_AMARILLO : COLOR_DEFECTO));
    printf("┗━━━━━━━┛ ");
    printfColor(correcto[4] ? COLOR_VERDE : (contiene[4] ? COLOR_AMARILLO : COLOR_DEFECTO));
    printf("┗━━━━━━━┛\n");
    printfColor(COLOR_DEFECTO);
}

void imprimirVacio()
{
    printf("┏━━━━━━━┓ ");
    printf("┏━━━━━━━┓ ");
    printf("┏━━━━━━━┓ ");
    printf("┏━━━━━━━┓ ");
    printf("┏━━━━━━━┓\n");

    printf("┃       ┃ ");
    printf("┃       ┃ ");
    printf("┃       ┃ ");
    printf("┃       ┃ ");
    printf("┃       ┃\n");

    printf("┃       ┃ ");
    printf("┃       ┃ ");
    printf("┃       ┃ ");
    printf("┃       ┃ ");
    printf("┃       ┃\n");

    printf("┃       ┃ ");
    printf("┃       ┃ ");
    printf("┃       ┃ ");
    printf("┃       ┃ ");
    printf("┃       ┃\n");

    printf("┗━━━━━━━┛ ");
    printf("┗━━━━━━━┛ ");
    printf("┗━━━━━━━┛ ");
    printf("┗━━━━━━━┛ ");
    printf("┗━━━━━━━┛\n");
}

void limpiarConsola()
{
    printf("\e[1;1H\e[2J"); // para limpiar la consola , se queda arriba lo anterior, efecto limpiar
    //https://www.geeksforgeeks.org/clear-console-c-language/ -> el que mas rapido es
}