#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
    int getInt(char *mensaje,
    char *mensajeError,
    int minimo, int maximo,
    int reintentos,
    int *resultado);

int getFloat(
    char *mensaje,
    char *mensajeError,
    float minimo,
    float maximo,
    int reintentos,
    float *resultado);

int getChar(
    char *mensaje,
    char *mensajeError,
    char minimo,
    char maximo,
    int reintentos,
    char *resultado);


int isValidInt(int numero, int maximo, int minimo);
int isValidFloat(float numero, float maximo, float minimo);
int isValidChar(char letra, char maximo, char minimo);

}
