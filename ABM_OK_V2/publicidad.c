#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "pantalla.h"
#include "publicidad.h"
#include "funciones_string.h"

int pub_AltaPublicidad(Publicidad *arrayPublicidad, int cantidad, int posLibre)
{
    int retorno = -1;

    if (    getInt("Ingrese el Id de la pantalla a contratar: ", "Ingreso incorrecto\n", 1, 100, 2, &arrayPublicidad[posLibre].idPublicidad) == 0 &&
            getInt("Ingrese el CUIT del cliente: ", "Ingreso incorrecto\n", 10000000000, 99999999999, 2, &arrayPublicidad[posLibre].cuitCliente) == 0 &&
            getInt("Ingrese la cantidad de dias contratados: ", "Ingreso incorrecto\n", 1, 365, 2, &arrayPublicidad[posLibre].cantDias) == 0 &&
            getStringD(arrayPublicidad[posLibre].nombreVideo,"Ingrese el nombre del archivo de video: " ,"error, vuelva a ingresar\n\n",2,30,2) == 0)
    {
            arrayPublicidad[posLibre].isEmpty  = 0;
            retorno=0;
    }
    else
    {
        retorno = 1;
    }

    return retorno;
}

int pub_Inicializar(Publicidad *arrayPublicidad, int cantidad)
{
    int retorno = -1;
    int i;

    for (i = 0; i < cantidad; i++)
    {
        arrayPublicidad[i].isEmpty = 1;
        retorno=0;
    }

    return retorno;
}

void pub_mostrarArray(Publicidad *arrayPublicidad, Pantalla *arrayPantalla,int cantidadPan, int cantidadPub)
{
    int i;
    int posPantalla;

    printf("\n\n\t\t\t\t||Lista de Publicidades||\n\n");

    for (i = 0; i < cantidadPub ;i++)
    {
        if(arrayPublicidad[i].isEmpty == 0)
        {
            pub_buscarPosicionPantallaPorId (arrayPantalla, cantidadPan, &posPantalla, arrayPublicidad[i].idPublicidad);
            printf("Nombre de la Pantalla: %s\n", arrayPantalla[posPantalla].nombre);
            printf("Posicion: %d\n", i);
            printf("Estado: %d\n", arrayPublicidad[i].isEmpty);
            printf("Nombre del video: %s\n", arrayPublicidad[i].nombreVideo);
            printf("Cantidad de dias: %d\n", arrayPublicidad[i].cantDias);
            printf("Cuit del cliente: $%d\n", arrayPublicidad[i].cuitCliente);
        }

        //printf("Press 'Enter' to continue: ... ");
        //while ( getchar() != '\n');
    }

}

int pub_buscarLibre(Publicidad *arrayPublicidad, int cantidad, int *devuelve)
{
    int retorno=-1;
    for (int i=0; i<cantidad;i++)
    {
        if (arrayPublicidad[i].isEmpty==1)
        {
            *devuelve=i;
            retorno=0;
            break;
        }

        retorno=1;
    }

    return retorno;
}

int pub_buscarPosicionPantallaPorId (Pantalla *arrayPantalla, int cantidad, int *pantallaEncontrada, int id)
{
    int i;
    int retorno = 1;

        for(i=0; i < cantidad; i++)
        {
            if (arrayPantalla[i].idPantalla == id)
            {
                retorno=0;
                *pantallaEncontrada=i;
                break;
            }
        }

    return retorno;
}
