#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define QTY_EMPLEADOS 10

int printArray(char aString[][50], int limite);
int inicializar(char sArray[][50], int limite);
int encontrarVacio(char sArray[][50], int limite);
int encontrarNombre(char sArray[][50],char *nombre , int limite);

int main()
{
    char auxName[500] = "test";

    char arrayNombre[QTY_EMPLEADOS][50];

    strncpy(arrayNombre[0], "JUAN", 50);
    strncpy(arrayNombre[1], "PEDRO", 50);
    strncpy(arrayNombre[2], "LALO", 50);
    strncpy(arrayNombre[3], "asdf", 50);
    strncpy(arrayNombre[4], "ahjjk", 50);
    strncpy(arrayNombre[5], "\0", 50);

    printf("%d\n", encontrarNombre(arrayNombre,"PEDRO", 50));


    if(getName( "Nombre?: ",
                "Error",
                2,
                5,
                2,
                auxName) == 0)
    {
        printf("OK: %s",auxName);
    }
    else
    {
        printf("ER: %s",auxName);
    }
    return 0;
}

int printArray(char aString[][50], int limite)
{
    int i;

    for (i = 0; i < limite; i++)
    {
        printf("%s\n", aString[i]);
    }
    return 0;
}

int inicializar(char sArray[][50], int limite)
{
    int i;
    for(i = 0; i < limite; i++)
    {
        strncpy(sArray[i], "\0", limite);
    }

    return 0;
}

int encontrarVacio(char sArray[][50], int limite)
{
    int i;
    int retorno = -1;

    for(i = 0; i < limite; i++)
    {
        if(strcmp(sArray[i], "\0") == 0)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

int encontrarNombre(char sArray[][50],char *nombre , int limite)
{
    int i;
    int retorno = -1;

    for(i = 0; i < limite; i++)
    {
        if(strcmp(sArray[i], nombre) == 0)
        {
            retorno = i;
        }
    }
    return retorno;
}


