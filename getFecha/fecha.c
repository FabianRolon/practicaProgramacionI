#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fecha.h"

int getString(char* msg, char* msgError, int min, int max, int reintentos, char* resultado)
{
    int retorno=-1;
    char bufferStr[max+10];

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            printf("%s",msg);
            //fflush(stdin);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1]='\0';

            if(strlen(bufferStr)>=min && strlen(bufferStr)<max)
            {
                strncpy(resultado,bufferStr,max);
                retorno=0;
                break;
            }
            printf("%s",msgError);
            reintentos--;
        }
        while(reintentos>=0);
    }
    return retorno;
}

int getFecha(char *msg, char *msgError, int minSize, int maxSize, int reintentos, int *resultadoMes, int *resultadoDia, int *resultadoAnio)
{
    int retorno=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && resultadoMes!=NULL && resultadoDia!=NULL && resultadoAnio!=NULL)
    {
        do
        {
            printf("%s", msg);
            if(!getString("\nMes: ",msgError,minSize,maxSize,reintentos,bufferStr))
            {
                if(isValidNumber(bufferStr)==1)
                {
                    *resultadoMes=atoi(bufferStr);

                }
                else
                {
                    printf("%s",msgError);
                    break;
                }
                if(!getString("\nDia: ",msgError,minSize,maxSize,reintentos,bufferStr))
                {
//                    printf("%d", isValidDia(resultadoMes))
                    if(isValidNumber(bufferStr)==1 /*&& isValidDia(*resultadoMes, atoi(bufferStr)) == 0 */)
                    {
                        *resultadoDia=atoi(bufferStr);

                    }
                    else
                    {
                        printf("%s",msgError);
                        break;
                    }
                }
                else
                {
                    printf("%s",msgError);
                    break;
                }
                if(!getString("\nAnio: ",msgError,minSize,maxSize,reintentos,bufferStr))
                {
                    if(isValidNumber(bufferStr)==1)
                    {
                        *resultadoAnio=atoi(bufferStr);
                        retorno=0;
                        break;
                    }

                }
                else
                {
                    printf("%s",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidNumber(char* stringRecibido)
{
    int retorno=1;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'0' || stringRecibido[i]>'9'))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

/*int isValidDia(int resultadoMes, int dia)
{
    int retorno=1;


    if(resultadoMes == 4 && resultadoMes == 6 && resultadoMes == 9 && resultadoMes == 11 && (dia <= 30  || dia > 1))
    {
        if(resultadoMes == 2 && (dia < 29 || dia < 1))
        {
            retorno = 0;
        }
        retorno = 0;
    }

    return retorno;
}
*/

