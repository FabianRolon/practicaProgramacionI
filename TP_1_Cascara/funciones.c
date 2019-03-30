#include <stdio.h>
#include <stdlib.h>

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
        }
    }
    return retorno;
}

int isValidInt(int numero, int maximo, int minimo) //las funcionjes con is devuelven "TRUE" or "FALSE"
{
    if(numero >= minimo && numero <=maximo)
    {
        return 1;
    }
        return 0;
}

int sumador(int primerTermino, int segundoTermino)
{
    return primerTermino + segundoTermino;
}

int restador(int primerTermino, int segundoTermino)
{
    return primerTermino - segundoTermino;
}

float dividir(float dividendo, float divisor)
{
    if(divisor == 0)
    {
        return -1;
    }

    return dividendo / divisor;
}

int multiplicador(int primerTermino, int segundoTermino)
{
    return primerTermino * segundoTermino;
}
