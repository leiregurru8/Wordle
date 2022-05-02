#ifndef _PALABRAS_H_
#define _PALABRAS_H_

char palabras[NUM_PALABRAS][6]; // 5 letras + \0
void cargarPalabras();
int existePalabra(char palabra[6]);

#endif