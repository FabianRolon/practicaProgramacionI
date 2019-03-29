#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

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


        }while(reintentos>=0);
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


#endif // UTN_H_INCLUDED
