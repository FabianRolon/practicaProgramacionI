#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANO_ARRAY 10

int isValidName(char* sName);

int main()
{
   /**
    char nombre[257]={'H','O','L','A','\0'}; //se declara la cantidad que quiero usar +1, ese +1 es
    char nombre2[257]="HOLA";//esto equivale a lo de arriba                        //para el "\0" que determinja el final de los datos usar

    //sizeof(nombre); //dice que tamaño tiene asignado en memoria ese array
    strncpy(nombre, nombre2,sizeof(nombre)); //se le pasa destino, origen y tamaño (nunca me tengo que psar del tamaño del destino)
    printf("\n%s",nombre);                                       //para que no provoque un overflow
    fgets(nombre, sizeof(nombre), stdin);
    printf("\n%s",nombre);
    strlen(); //da la cantidad de caracteres de un string
    strcmp(); //me dice cual es mas grande de los string que quiera

    //tarea: aplicacion que pida el nombre de usuario, guarda en buffer,
    //vamos a verificar la cant de char,
    //verificar que no tenga caracteres que no quiera,
    //si es un nombre guardar en la variable de destino y mostrar en pantalla.
    **/

    char nombre[TAMANO_ARRAY];
    char buffer[TAMANO_ARRAY];

    printf("Ingrese su nombre querido usuario: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strlen(buffer)-1] = '\0';

    if(isValidName(buffer))
    {
        strncpy(nombre, buffer,sizeof(nombre));
        printf("\n%s",nombre);
    }
    else
    {
        printf("\nERROR, INGRESE SOLO LETRAS");
    }
    return 0;
}


int isValidName(char *sName)
{
   int i;
   int retorno = 1;

    for(i = 0; *(sName+i) != '\0'; i++)
    {
        if((*(sName+i) != ' ') && (*(sName+i) < 'a' || *(sName+i) > 'z') && (*(sName+i) < 'A' || *(sName+i) > 'Z'))
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}

int utn_isValidNumber(char *str)
{
 return 1;
}
