#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <ctype.h>
#include "autores.h"


int aut_Inicializar(Autores *arrayAutor, int cantidad)
{
    int retorno = -1;
    int i;

    for (i = 0; i < cantidad; i++)
    {
        arrayAutor[i].isEmpty = 1;
        retorno=0;
    }

    return retorno;
}

int aut_buscarLibre(Autores *arrayAutor, int cantidad, int *devuelve)
{
    int retorno=-1;
    for (int i=0; i<cantidad;i++)
    {
        if (arrayAutor[i].isEmpty==1)
        {
            *devuelve=i;
            retorno=0;
            break;
        }

        retorno=1;
    }

    return retorno;
}

int aut_alta(Autores *arrayAutor, int cantidad, int posLibre, int id)
{
    int retorno = -1;

    if (    getString(arrayAutor[posLibre].nombre,"Ingrese un nombre: ","Error, vuelva a ingresar\n\n",2,20,2) == 0 &&
            getString(arrayAutor[posLibre].apellido,"Ingrese el apellido: " ,"Error, vuelva a ingresar\n\n",2,20,2) == 0)
    {

        arrayAutor[posLibre].codigoAutor = id;
        arrayAutor[posLibre].isEmpty  = 0;
        retorno=0;

    }
    else
    {
        retorno = 1;
    }

    return retorno;
}

int getString(char *pResult, char *pMsg, char *pMsgError, int min, int max, int intentos)
{
    int retorno = -1;
    char arrayAuxiliar[31];
    while(intentos > 0)
    {
        printf("%s",pMsg);
        //fflush( stdin ); //LIMPIA BUFFER WINDOWS
        __fpurge(stdin); //LIMPIA BUFFER LINUX
        fgets(arrayAuxiliar,sizeof(arrayAuxiliar),stdin);
        arrayAuxiliar[strlen(arrayAuxiliar)-1] = '\0';
        if( pResult != NULL && strlen(arrayAuxiliar) >= min && strlen(arrayAuxiliar) <= max && validarLetra(arrayAuxiliar)==0)
        {
            strncpy(pResult,arrayAuxiliar,max);

            retorno = 0;
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

int validarLetra (char letras[])
{
    int retorno=0;
    int i=0;
    int cantidadLetras;
    cantidadLetras=strlen(letras);
    while (i<cantidadLetras && retorno==0)
    {
        if (isalpha(letras[i])!=0)
        {
            i++;
        }
        else
        {
            retorno=1;
        }
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

int isValidInt(int numero, int maximo, int minimo) //las funciones con is devuelven "TRUE" or "FALSE"
{
    if(numero >= minimo && numero <=maximo)
    {
        return 1;
    }
        return 0;
}

int aut_buscarEnArrayPorId (Autores *arrayAutor, int cantidad, int *autorEncontrado,char *textoAMostrar)
{
    int i;
    int retorno = 1;
    Autores auxAutor;

    if (getInt(textoAMostrar, "Ingreso incorrecto\n", 0, 100, 2, &auxAutor.codigoAutor) == 0)
    {
        for(i=0; i < cantidad; i++)
        {
            if (arrayAutor[i].codigoAutor == auxAutor.codigoAutor)
            {
                retorno=0;
                *autorEncontrado=i;
                break;
            }
        }
    }
    return retorno;
}

int aut_baja(Autores *arrayAutor, int cantidad)
{
    int retorno = -1;
    int posicionAutor;

    aut_mostrarArray(arrayAutor, cantidad);
    switch (aut_buscarEnArrayPorId(arrayAutor, cantidad,&posicionAutor,"Ingrese el codigo de autor a dar de baja: "))
    {
    case 0:
        if (arrayAutor[posicionAutor].isEmpty == 0)
        {
            printf("Hubo coincidencia\n\n");
            arrayAutor[posicionAutor].isEmpty = 2;
            printf("El autor borrado es: %d\n\n",arrayAutor[posicionAutor].codigoAutor);
            retorno = 0;
        }
        break;
    case 1:
        printf("No se encontro el codigo\n\n");
        break;
    }
    return retorno;
}

void aut_mostrarArray(Autores *arrayAutor, int cantidad)
{
    int i;

    printf("\n\n\t\t\t\t||Lista de Autores||\n\n");

    for (i = 0; i < cantidad ;i++)
    {
        if(arrayAutor[i].isEmpty == 0)
        {

            printf("Codigo de autor: %d\n", arrayAutor[i].codigoAutor);
            printf("Posicion: %d\n", i);
            printf("Estado: %d\n", arrayAutor[i].isEmpty);
            printf("Nombre: %s\n", arrayAutor[i].nombre);
            printf("Apellido: %s\n", arrayAutor[i].apellido);
        }
    }
}

int aut_modificacion(Autores *arrayAutor, int cantidad)
{

    int retorno = -1;
    int opcion;
    int posicionAutor;
    char seguir = 's';

    aut_mostrarArray(arrayAutor, cantidad);

    switch (aut_buscarEnArrayPorId(arrayAutor, cantidad,&posicionAutor,"Ingrese el codigo de autor a modificar: "))
    {
    case 0:
        if (arrayAutor[posicionAutor].isEmpty == 0)
        {
            printf("Hubo coincidencia\n\n");

            while(seguir == 's')
            {
                printf("Elija el dato que desea modificar\n\n");

                printf("\n\n1-Nombre");
                printf("\n\n2-Apellido");
                printf("\n\n3-Salir de la modificacion");

                getInt("\n\t\tIngrese opcion: ", "Ingreso incorrecto\n", 1, 3, 2, &opcion);


                switch(opcion)
                {
                    case 1:
                        if (getString(arrayAutor[posicionAutor].nombre,"Ingrese el nuevo nombre de autor: ","Error",2,20,2)==0)
                        {
                            printf("El dato fue modificado con exito.\n\n");
                        }
                        break;
                    case 2:
                        if (getString(arrayAutor[posicionAutor].apellido,"Ingrese la nueva apellido: " ,"Error, vuelva a ingresar\n\n",2,30,2)==0)
                        {
                            printf("El dato fue modificado con exito.\n\n");
                        }
                        break;

                    case 3:
                        seguir = 'n';
                        retorno = 0;
                        break;
                }
            }
        }
        break;

    case 1:
        printf("No se encontro el codigo de autor");
        break;
        }

    return retorno;
}

int aut_existeId (Autores *arrayAutor, int cantidad, int id)
{
    int i;
    int retorno = 1;

        for(i=0; i < cantidad; i++)
        {
            if (arrayAutor[i].codigoAutor == id)
            {
                retorno=0;
                break;
            }
        }
    return retorno;
}

int utn_getChar(char* msg, char* msgError, int min, int max, int reintentos, char* resultado)
{
    int retorno=-1;
    char bufferChar[1];

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            if(!getString(bufferChar,msg,msgError,1,3,reintentos)) //==0
            {
                if(isValidChar(bufferChar[0])==1)
                {
                    *resultado=bufferChar[0];
                    retorno=0;
                    break;
                }
                else
                {
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidChar(char charRecibido)
{
    int retorno=1;
    if(charRecibido != ' ' && (charRecibido < 'a' || charRecibido > 'z') && (charRecibido < 'A' || charRecibido > 'Z'))
    {
        retorno=0;
    }
    return retorno;
}
