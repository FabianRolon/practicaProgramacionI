#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "asociado.h"

#define CANTIDAD_ASOCIADO 10

int aso_Inicializar(Asociado *arrayAsociado, int cantidad)
{
    int retorno = -1;
    int i;

    for (i = 0; i < cantidad; i++)
    {
        arrayAsociado[i].isEmpty = 1;
        retorno=0;
    }

    return retorno;
}

int aso_buscarLibre(Asociado *arrayAsociado, int cantidad, int *devuelve)
{
    int retorno=-1;
    for (int i=0; i<cantidad;i++)
    {
        if (arrayAsociado[i].isEmpty==1)
        {
            *devuelve=i;
            retorno=0;
            break;
        }

        retorno=1;
    }

    return retorno;
}

int aso_AltaPantalla(Asociado *arrayAsociado, int cantidad, int posLibre, int id)
{
    int retorno = -1;

    if (    getString(arrayAsociado[posLibre].nombre,"Ingrese el nombre: ","Error, vuelva a ingresar\n\n",2,20,2) == 0 &&
            getStringD(arrayAsociado[posLibre].apellido,"Ingrese el apellido: " ,"Error, vuelva a ingresar\n\n",2,30,2) == 0 &&
            getInt("Ingrese la edad: ", "Error, vuelva a ingresar\n\n", 18, 99, 2, arrayAsociado[posLibre].edad) == 0 &&
            getInt("Ingrese el nº de DNI: ", "Error, vuelva a ingresar\n\n", 1, 99999999, 2, arrayAsociado[posLibre].dni) == 0)
    {
            arrayAsociado[posLibre].idPantalla = id;
            arrayAsociado[posLibre].isEmpty  = 0;
            retorno=0;
        }
    }
    else
    {
        retorno = 1;
    }

    return retorno;
}

int getInt(
    char *mensaje,
    char *mensajeError,
    long minimo,
    long maximo,
    int reintentos,
    int *resultado)
{
    int buffer; //variables que no estan validadas = buffer
    int retorno = -1;
    int i;

    if(mensaje != NULL && mensajeError != NULL && resultado != NULL && maximo >= minimo && reintentos >= 0)
    {
        for(i=0; i<= reintentos; i++)
        {
            printf("%s", mensaje);//imprimir mensaje
            fflush(stdin);
            //__fpurge(stdin);
            scanf("%d", &buffer);
            if(isValidInt(buffer, maximo, minimo))
            {
                *resultado = buffer;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
        }
    }
    return retorno;
}

int isValidInt(int numero, int maximo, int minimo) //las funciones con is devuelven "TRUE" or "FALSE"
{
    if(numero >= minimo && numero <=maximo)
    {
        return 1;
    }
        return 0;
}
