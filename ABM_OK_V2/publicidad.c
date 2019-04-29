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
            getStringCuit(arrayPublicidad[posLibre].cuitCliente,"Ingrese el CUIT del cliente: ", "Ingreso incorrecto\n", 11, 20, 2) == 0 &&
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
            printf("Cuit del cliente: %s\n", arrayPublicidad[i].cuitCliente);
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

int getStringCuit(char *pResult, char *pMsg, char *pMsgError, int min, int max, int intentos)
{
    int retorno=-1;
    char arrayAuxiliar[30];
    while(intentos > 0)
    {
        printf("%s",pMsg);
        //fflush( stdin ); //LIMPIA BUFFER WINDOWS
        __fpurge(stdin); //LIMPIA BUFFER LINUX
        fgets(arrayAuxiliar,sizeof(arrayAuxiliar),stdin);
        arrayAuxiliar[strlen(arrayAuxiliar)-1] = '\0';
        if( pResult != NULL && strlen(arrayAuxiliar) >= min && strlen(arrayAuxiliar) <= max && !(isValidsNum(arrayAuxiliar))==0)
        {
            strncpy(pResult,arrayAuxiliar,max);

            retorno=0;
            break;
        }
        else
        {
            printf("%s",pMsgError);
        }
        intentos--;
    }
    return retorno;
}

int isValidsNum(char *sAlphaNum)
{
   int i;
   int retorno = 1;

    for(i = 0; *(sAlphaNum+i) != '\0'; i++)
    {
        if((*(sAlphaNum+i) != '-') && (*(sAlphaNum+i) < '0' || *(sAlphaNum+i) > '9'))
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}

int pub_baja(Publicidad *arrayPublicidad, int cantidad)
{

    int posPublicidad;

    switch (pan_buscarEnArrayPorId(arrayPantalla, cantidad,&posPantalla,"Ingrese el Id de la pantalla a dar de baja: "))
    {
    case 0:
        if (arrayPantalla[posPantalla].isEmpty==0)
        {
            printf("Hubo coincidencia\n\n");
            arrayPantalla[posPantalla].isEmpty=1;
            printf("La pantalla borrada es: %d\n\n",arrayPantalla[posPantalla].idPantalla);
        }
        break;
    case 1:
        printf("No se encontro el Id y no entro al if\n\n");
        break;

    default:
        printf("Ingreso al if pero no encontro el nombre");
        break;
    }
    return 1;
}

int pub_buscarEnArrayPorCuit (Publicidad* arrayPublicidad, int cantidad, int* idPantallaEncontrado)
{
    int i;
    int retorno = 1;
    Publicidad auxPublicidad;

    if (getStringCuit(auxPublicidad.cuitCliente,"Ingrese el CUIT del cliente: ", "Ingreso incorrecto\n", 11, 20, 2)==0)
    {
        retorno = -1;
        for(i = 0; i < cantidad; i++)
        {
            if (strcmp(arrayPublicidad[i].cuitCliente, auxPublicidad.cuitCliente)==0)
            {
                retorno = 0;
                *idPantallaEncontrado = arrayPublicidad[i].idPublicidad;
                break;
            }
        }
    }
    return retorno;
 }
