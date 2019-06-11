#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>


int isValidSex(char letra, char maximo, char minimo);

int main()
{

        int isValidSex(char letra, char maximo, char minimo)
        {
            int retorno = 1;

            if((letra != 'f') && (letra != 'F') && (letra != 'm') && (letra != 'M'))
            {
                retorno = 0;
            }
            return retorno;
        }




    int getSex(char *mensaje, char *mensajeError, char minimo, char maximo, int reintentos, char *resultado)
    {
        char buffer;
        int retorno = -1;
        int control;

        if(mensaje != NULL && mensajeError != NULL && resultado != NULL && maximo >= minimo && reintentos >= 0)
        {
            do
            {
                __fpurge(stdin);
                printf("%s", mensaje);
                scanf("%c", &buffer);

                printf("Lo ingresado es: %c\n\n", buffer);

                control = isValidSex(buffer, maximo, minimo);
                printf("isValidSex: %d\n\n", control);
                if(isValidSex(buffer, maximo, minimo))
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


    char sexo;

    getSex("\n\nIngrese el sexo F o M: ", "\n\n Error! Ingrese una opcion valida", 1, 2, 2, &sexo);

    printf("El sexo ingresado es : %c" , sexo);


    return 0;
}
