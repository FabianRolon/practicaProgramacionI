#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "utn.h"

int isValidInt(int numero, int maximo, int minimo) //las funcionjes con is devuelven "TRUE" or "FALSE"
{
    if(numero >= minimo && numero <=maximo)
    {
        return 1;
    }
        return 0;
}

int getInt(
    char *mensaje,
    char *mensajeError,
    int minimo,
    int maximo,
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
            //fflush(stdin);
            __fpurge(stdin);
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

int getFloat(
char *mensaje,
char *mensajeError,
float minimo,
float maximo,
int reintentos,
float *resultado)
{
    float buffer;
    int retorno = -1;

    if(mensaje != NULL && mensajeError != NULL && resultado != NULL && maximo >= minimo && reintentos >= 0)
    {
        do
        {
            printf("%s", mensaje);
            scanf("%f", &buffer);
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
            reintentos--;
        }while(reintentos >=0);
    }
    return retorno;
}

int isValidFloat(float numero, float maximo, float minimo)
{
    if(numero >= minimo && numero <= maximo)
    {
        return 1;
    }
    return 0;
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

int isValidArrayInt(int numero, int maximo, int minimo) //las funcionjes con is devuelven "TRUE" or "FALSE"
{
    if(numero >= minimo && numero <=maximo)
    {
        return 1;
    }
        return 0;
}



int getArrayInt(    char *msg,
                    char *msgError,
                    int maximo,
                    int minimo,
                    int reintentos,
                    int *arrayResultado,
                    int limite)
{
    int retorno = -1;
    int j = 0;
    int buffer;

    if(msg != NULL && msgError != NULL && arrayResultado != NULL && maximo >= minimo && reintentos >= 0 && limite > 0)
    {

        for(j = 0; j < limite; j++)
        {
            getInt(msg,msgError,minimo, maximo, reintentos, &buffer);
            *(arrayResultado+j) = buffer;
            retorno = 0;
        }

    }
    return retorno;
}



int printArrayInt(int *arrayResultado, int limite)
{
    int i;
    for(i = 0; i<limite; i++)
    {
        printf("%d\n", arrayResultado[i]);
    }
    return 0;
}

int doSwap(int *primerValor, int *segundoValor)
{
    int aux;
    aux = *primerValor;
    *primerValor = *segundoValor;
    *segundoValor = aux;
    return 0;
}

int ordenarArray(int *vector, int limite)
{
    int i;
    int flagSwap;

    do
    {
        flagSwap = 0;
        for(i = 0; i <limite-1; i++)     //int aEdades[10] = {8,1,0,4,9,5,2,3,6,7};
        {
            flagSwap = 0;
            if(*(vector+i) > *(vector+(i+1)))
            {
                doSwap(&vector[i], &vector[i+1]);
                flagSwap = 1;
            }
        }
    }while(flagSwap);

    return 0;
}


int getString(  char *mensaje,
                char *mensajeError,
                int minimo,
                int maximo,
                int reintentos,
                char *sString)
{
    int retorno = -1;
    char buffer[4096];

    if( mensaje != NULL &&
        mensajeError != NULL &&
        maximo >= minimo &&
        minimo >= 0 &&
        reintentos >= 0 &&
        sString != NULL)
    {
        do
        {
            printf("%s", mensaje);
            fgets(buffer, maximo+1, stdin);
            buffer[strlen(buffer)-1] = '\0';
            if(!isValidLengthString(buffer, minimo, maximo))
            {
                strncpy(sString, buffer, maximo);
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
        }while(reintentos--);

    }
    else
    {
        printf("%s", mensajeError);
    }
    return retorno;
}

int isValidLengthString(char* buffer, int minimo, int maximo)
{
    int retorno = 1;
    int lengthBuffer;
    lengthBuffer = strlen(buffer);

    if(lengthBuffer >= minimo && lengthBuffer < maximo)
    {
        retorno = 0;
    }

    return retorno;
}



