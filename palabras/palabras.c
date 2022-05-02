#include "../configuracion.h"
#include "palabras.h"
#include "../utilidades/utilidades.h"
#include <stdio.h>
#include <string.h>

void cargarPalabras()
//abre el fichero en modo lectura
{
    FILE *ficheroPalabras = fopen(RUTA_FICHERO_PALABRAS, "r");
    char palabra[7]; //palabra de 5 letras + \n + \0
    int i = 0;
    while (fgets(palabra, 7, ficheroPalabras)) //leo del fichero linea a linea y guardo el contenido en palabra
    {
        palabra[5] = 0; // Para quitar el \n
        strcpy(palabras[i], palabra); //copia la palabra leida en el array de palabras en la posicion i
        i++;
    }
}

int existePalabra(char palabra[6]) //si la palabra que recibe como parametro esta en el array (existe = 1, no existe = 0)
{
    for (int i = 0; i < NUM_PALABRAS; i++)
    {
        if (strcmp(palabra, palabras[i]) == 0)
        {
            return 1; //si existe la palabra devuelvo 1 y acaba el for y la funcion
        }
    }
    printfColor(COLOR_ROJO);
    printf("La palabra %s no es valida\n", palabra);
    printfColor(COLOR_DEFECTO);
    return 0; //se ha acabado el for, no ha encontrado, devuelve 0
}