#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

    if(mensaje != NULL && mensajeError != NULL && resultado != NULL && maximo >= minimo && reintentos >= 0)
    {
        do
        {
            printf("%s", mensaje);//imprimir mensaje
            fflush(stdin);
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

    if(mensaje != NULL && mensajeError != NULL && resultado != NULL &&
       maximo >= minimo && reintentos >= 0)
    {
        do
        {
            printf("%s", mensaje);
            scanf("%f", &buffer);
            if(isValidFloat(buffer, maximo, minimo))
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



int sumador(int primerTermino, int segundoTermino)
{
    return primerTermino + segundoTermino;
}

int restador(int primerTermino, int segundoTermino)
{
    return primerTermino - segundoTermino;
}

float dividir(float dividendo, float divisor, char *mensajeError)
{
    if(divisor == 0)
    {
        printf("%s", mensajeError);
    }

    return dividendo / divisor;
}

int multiplicador(int primerTermino, int segundoTermino)
{
    return primerTermino * segundoTermino;
}

int calculaFactorial(int valor,long int *factorial, char *mensajeError)
{
    int retorno = -1;
    int i;
    long int acumulador = 1;
    int auxiliar = 0;

    if(factorial != NULL && mensajeError != NULL)
    {

        if(valor == 0)
        {
            *factorial = 1;
        }
        else
        {
            if(valor < 0)
            {
                printf("%s", mensajeError);
                retorno = -2;
            }
            else
            {
                for(i=0; i<valor; i++)
                {
                    auxiliar++;
                    acumulador *= auxiliar;
                }
                *factorial = acumulador;
                retorno = 0;
            }
        }
    }
    return retorno;
}
