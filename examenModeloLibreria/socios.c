#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "autores.h"
#include "libros.h"
#include "socios.h"

int soc_Inicializar(Socios *arraySocio, int cantidad)
{
    int retorno = -1;
    int i;

    for (i = 0; i < cantidad; i++)
    {
        arraySocio[i].isEmpty = 1;
        retorno=0;
    }

    return retorno;
}


int soc_buscarLibre(Socios *arraySocio, int cantidad, int *devuelve)
{
    int retorno=-1;
    for (int i=0; i<cantidad;i++)
    {
        if (arraySocio[i].isEmpty==1)
        {
            *devuelve=i;
            retorno=0;
            break;
        }

        retorno=1;
    }

    return retorno;
}

int soc_alta(Socios *arraySocio, int cantidadSocio, int posLibre, int id)
{
    int retorno = -1;

    if( getString(arraySocio[posLibre].nombre,"Ingrese el nombre: ","Error, vuelva a ingresar\n\n",2,31,2) == 0 &&
        getString(arraySocio[posLibre].apellido,"Ingrese el apellido: ","Error, vuelva a ingresar\n\n",2,31,2) == 0 &&
        getSex("Ingrese el sexo F o M: ", "Error! Ingrese la opcion correcta", 1,2,2,&arraySocio[posLibre].sexo) == 0 &&
        getTelefono("Ingrese el numero de telefono: ", "Error, vuelva a ingresar",2, 16, 2, arraySocio[posLibre].telefono) == 0 &&
        getEmail("Ingrese la direccion de Email: ", "Error, vuelva a ingresar",2, 31, 2, arraySocio[posLibre].email) == 0 &&
        getFecha("Ingrese la fecha MM/DD/AAAA: ", "Error, ingrese nuevamente", 1, 2019, 2 ) )
    {
            if(aut_existeId(arrayAutor, cantidadAutor, arrayAutor[posLibre].codigoAutor) == 0)
            {
                arraySocio[posLibre].codigoLibro = id;
                arraySocio[posLibre].isEmpty  = 0;
                retorno=0;
            }
            else
            {
                retorno = 2;
            }

    }
    else
    {
        retorno = 1;
    }

    return retorno;
}

int soc_buscarEnArrayPorId (Socios *arraySocio, int cantidad, int *socroEncontrado,char *textoAMostrar)
{
    int i;
    int retorno = 1;
    Socios auxLibro;

    if (getInt(textoAMostrar, "Ingreso incorrecto\n", 0, 100, 2, &auxLibro.codigoLibro) == 0)
    {
        for(i=0; i < cantidad; i++)
        {
            if (arraySocio[i].codigoLibro == auxLibro.codigoLibro)
            {
                retorno=0;
                *socroEncontrado=i;
                break;
            }
        }
    }
    return retorno;
}

int soc_baja(Socios *arraySocio, int cantidad)
{
    int retorno = -1;
    int posicionLibro;

    soc_mostrarArray(arraySocio, cantidad);
    switch (soc_buscarEnArrayPorId(arraySocio, cantidad,&posicionLibro,"Ingrese el codigo del socro a dar de baja: "))
    {
    case 0:
        if (arraySocio[posicionLibro].isEmpty == 0)
        {
            printf("Hubo coincidencia\n\n");
            arraySocio[posicionLibro].isEmpty = 2;
            printf("El socro borrado es: %d\n\n",arraySocio[posicionLibro].codigoLibro);
            retorno = 0;
        }
        break;
    case 1:
        printf("No se encontro el codigo\n\n");
        break;
    }
    return retorno;
}

void soc_mostrarArray(Socios *arraySocio, int cantidad)
{
    int i;

    printf("\n\n\t\t\t\t||Lista de Socios||\n\n");

    for (i = 0; i < cantidad ;i++)
    {
        if(arraySocio[i].isEmpty == 0)
        {

            printf("Codigo de autor: %d\n", arraySocio[i].codigoAutor);
            printf("Posicion: %d\n", i);
            printf("Estado: %d\n", arraySocio[i].isEmpty);
            printf("Titulo: %s\n", arraySocio[i].titulo);
            printf("Codigo de Libro: %d\n\n", arraySocio[i].codigoLibro);
        }
    }
}

int soc_modificacion(Socios *arraySocio, Autores *arrayAutor, int cantidadLibro, int cantidadAutor)
{

    int retorno = -1;
    int opcion;
    int posicionLibro;
    char seguir = 's';

    soc_mostrarArray(arraySocio, cantidadLibro);

    switch (soc_buscarEnArrayPorId(arraySocio, cantidadLibro,&posicionLibro,"Ingrese el codigo de socro a modificar: "))
    {
    case 0:
        if (arraySocio[posicionLibro].isEmpty == 0)
        {
            printf("Hubo coincidencia\n\n");

            while(seguir == 's')
            {
                printf("Elija el dato que desea modificar\n\n");

                printf("\n\n1-Titiulo");
                printf("\n\n2-Codigo de Autor");
                printf("\n\n3-Salir de la modificacion");

                getInt("\n\t\tIngrese opcion: ", "Ingreso incorrecto\n", 1, 3, 2, &opcion);


                switch(opcion)
                {
                    case 1:
                        if (getString(arraySocio[posicionLibro].titulo,"Ingrese el nuevo nombre de socro: ","Error",2,20,2)==0)
                        {
                            printf("El dato fue modificado con exito.\n\n");
                        }
                        break;
                    case 2:
                        aut_mostrarArray(arrayAutor, cantidadAutor);
                        if(getInt("\n\t\tIngrese el codigo de autor: ", "Ingreso incorrecto\n", 1, 10, 2, &arraySocio[posicionLibro].codigoAutor) == 0)
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
        printf("No se encontro el codigo de socro");
        break;
        }

    return retorno;
}

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

int getTelefono(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input)
{
    int retorno=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(&bufferStr, msg,msgError,minSize,maxSize,reintentos))
            {
                if(isValidTelephone(bufferStr)==1)
                {
                    strncpy(input,bufferStr,maxSize);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidTelephone(char* stringRecibido)
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'0' || stringRecibido[i]>'9') && (stringRecibido[i]!='-' || stringRecibido[i]!=' '))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

int getEmail(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input)
{
    int retorno=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr)) //==0 sin errores !0
            {
                if(isValidEmail(bufferStr)==1)
                {
                    strncpy(input,bufferStr,maxSize);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidEmail(char* stringRecibido)
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'-' && stringRecibido[i]!='+') || (stringRecibido[i]>'9' && stringRecibido[i]<'@') ||
           (stringRecibido[i]>'Z' && stringRecibido[i]!='_' && stringRecibido[i]<'a')|| stringRecibido[i]>'z')
        {
            retorno=0;
            break;
        }
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
