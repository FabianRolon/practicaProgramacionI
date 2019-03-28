#include <stdio.h>
#include <stdlib.h>

/**hacer funcion que valide ,maximo, minimo, cantidad de reintentos,
validaciones: preguntar si el puntero no e NULL. Reintentos tiene que ser >= 0
**/

int getInt(char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos, int *resultado);
int isValidInt(int numero, int maximo, int minimo);


int main()
{
    int valor;
    getInt("Ingrese su edad:\n", "ERROR\n", 0, 150, 3, &valor);
    return 0;
}

int isValidInt(int numero, int maximo, int minimo) //las funcionjes con is devuelven "TRUE" or "FALSE"
{
    if(numero >= minimo && numero <=maximo)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

int getInt(char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos, int *resultado)
{
    int buffer; //variables que no estan validadas = buffer
    int retorno = -1;
    int i;

    if(mensaje != NULL && mensajeError != NULL && resultado != NULL && maximo >= minimo && reintentos >= 0)
    {
        for(i=0; i < reintentos; i++)
        {

            printf("%s", mensaje);//imprimir mensaje
            scanf("%d", &buffer);

            if(isValidInt(buffer, maximo, minimo))
            {
                *resultado = buffer;
                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
        }
        retorno = 0;
    }

    return retorno;
}
