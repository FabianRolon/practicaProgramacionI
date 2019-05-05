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

int aso_altaAsociado(Asociado *arrayAsociado, int cantidad, int posicionLibre, int id)
{
    int retorno = -1;

    if (    getString(arrayAsociado[posicionLibre].nombre,"Ingrese el nombre: ","Error, vuelva a ingresar\n\n",2,20,2) == 0 &&
            getStringD(arrayAsociado[posicionLibre].apellido,"Ingrese el apellido: " ,"Error, vuelva a ingresar\n\n",2,30,2) == 0 &&
            getInt("Ingrese la edad: ", "Error, vuelva a ingresar\n\n", 18, 99, 2, arrayAsociado[posicionLibre].edad) == 0 &&
            getInt("Ingrese el nº de DNI: ", "Error, vuelva a ingresar\n\n", 1, 99999999, 2, arrayAsociado[posicionLibre].dni) == 0)
        {
            arrayAsociado[posicionLibre].idAsociado = id;
            arrayAsociado[posicionLibre].isEmpty  = 0;
            retorno=0;
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

int aso_buscarEnArrayPorId (Asociado *arrayAsociado, int cantidad, int *asociadoEncontrado,char *textoAMostrar)
{
    int i;
    int retorno = 1;
    Pantalla auxPantalla;

    if (getInt(textoAMostrar, "Ingreso incorrecto\n", 0, 100, 2, &auxPantalla.idPantalla) == 0)
    {
        for(i=0; i < cantidad; i++)
        {
            if (arrayAsociado[i].idPantalla == auxPantalla.idPantalla)
            {
                retorno=0;
                *asociadoEncontrado=i;
                break;
            }
        }
    }
    return retorno;
}

int getStringf(float *pResult, char *pMsg, char *pMsgError, int min, int max, int intentos)
{
    int ret=-1;
    float arrayAuxiliar;
    while(intentos>0)
    {
        printf("%s",pMsg);
        //fflush( stdin ); //LIMPIA BUFFER WINDOWS
        __fpurge(stdin); //LIMPIA BUFFER LINUX
        scanf("%f", &arrayAuxiliar);
        if( pResult != NULL && arrayAuxiliar >= min && arrayAuxiliar <= max)
        {
            *pResult = arrayAuxiliar;

            ret=0;
            break;
        }
        else
        {
            printf("%s",pMsgError);
        }
        intentos--;
    }
    return ret;
}

int getStringD(char *pResult, char *pMsg, char *pMsgError, int min, int max, int intentos)
{
    int retorno=-1;
    char arrayAuxiliar[50];
    while(intentos>0)
    {
        printf("%s",pMsg);
        //fflush( stdin ); //LIMPIA BUFFER WINDOWS
        __fpurge(stdin); //LIMPIA BUFFER LINUX
        fgets(arrayAuxiliar,sizeof(arrayAuxiliar),stdin);
        arrayAuxiliar[strlen(arrayAuxiliar)-1] = '\0';
        if( pResult != NULL && strlen(arrayAuxiliar) >= min && strlen(arrayAuxiliar) <= max && !(isValidsAlphaNum(arrayAuxiliar))==0)
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

int isValidsAlphaNum(char *sAlphaNum)
{
   int i;
   int retorno = 1;

    for(i = 0; *(sAlphaNum+i) != '\0'; i++)
    {
        if((*(sAlphaNum+i) != '.') && (*(sAlphaNum+i) != ' ') && (*(sAlphaNum+i) < 'a' || *(sAlphaNum+i) > 'z') && (*(sAlphaNum+i) < 'A' || *(sAlphaNum+i) > 'Z') && (*(sAlphaNum+i) < '0' || *(sAlphaNum+i) > '9'))
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}

int getChar(char *mensaje, char *mensajeError, char minimo, char maximo, int reintentos, char *resultado)
{
    char buffer;
    int retorno = -1;

    if(mensaje != NULL && mensajeError != NULL && resultado != NULL && maximo >= minimo && reintentos >= 0)
    {
        do
        {
            printf("%s", mensaje);

            //fflush( stdin );
            __fpurge(stdin);

            scanf("%c", &buffer);

            if(isValidChar(buffer, maximo, minimo))
            {
                *resultado = buffer;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
        }while(reintentos--);
    }
    return retorno;
}

int isValidChar(char letra, char maximo, char minimo)
{
    if(letra >= minimo && letra <= maximo)
    {
        return 1;
    }
    return 0;
}

void aso_mostrarArray(Pantalla *arrayPantalla, int cantidad)
{
    int i;

    printf("\n\n\t\t\t\t||Lista de Pantallas||\n\n");

    for (i = 0; i < cantidad ;i++)
    {
        if(arrayPantalla[i].isEmpty == 0)
        {

            printf("ID Pantalla: %d\n", arrayPantalla[i].idPantalla);
            printf("Posicion: %d\n", i);
            printf("Estado: %d\n", arrayPantalla[i].isEmpty);
            printf("Nombre: %s\n", arrayPantalla[i].nombre);
            printf("Direccion: %s\n", arrayPantalla[i].direccion);
            printf("Precio: $%.2f\n", arrayPantalla[i].precio);
            printf("Tipo: %c\n\n", arrayPantalla[i].tipo);
        }

        //printf("Press 'Enter' to continue: ... ");
        //while ( getchar() != '\n');
    }

}
