#ifndef _UTILIDADES_H_
#define _UTILIDADES_H_

int numeroAleatorio();
void imprimirPalabra(char palabra[6], char palabraAdivinar[6]);
void imprimirVacio();

#define COLOR_DEFECTO "[0m"
#define COLOR_VERDE "[0;32m"
#define COLOR_AMARILLO "[0;33m"
#define COLOR_ROJO "[0;31m"

void printfColor(char color[]);
void limpiarConsola();

#endif