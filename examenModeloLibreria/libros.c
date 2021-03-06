#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <ctype.h>
#include "autores.h"
#include "libros.h"

int lib_Inicializar(Libros *arrayLibro, int cantidad)
{
    int retorno = -1;
    int i;

    for (i = 0; i < cantidad; i++)
    {
        arrayLibro[i].isEmpty = 1;
        retorno=0;
    }

    return retorno;
}

int lib_buscarLibre(Libros *arrayLibro, int cantidad, int *devuelve)
{
    int retorno=-1;
    for (int i=0; i<cantidad;i++)
    {
        if (arrayLibro[i].isEmpty==1)
        {
            *devuelve=i;
            retorno=0;
            break;
        }

        retorno=1;
    }

    return retorno;
}

int lib_alta(Libros *arrayLibro, Autores *arrayAutor, int cantidadLibro, int cantidadAutor, int posLibre, int id)
{
    int retorno = -1;

    if(    getString(arrayLibro[posLibre].titulo,"Ingrese un titulo: ","Error, vuelva a ingresar\n\n",2,20,2) == 0 )
    {
        aut_mostrarArray(arrayAutor, cantidadAutor);
        if(getInt("\n\t\tIngrese el codigo de autor: ", "Ingreso incorrecto\n", 1, 10, 2, &arrayLibro[posLibre].codigoAutor) == 0)
        {
            if(aut_existeId(arrayAutor, cantidadAutor, arrayAutor[posLibre].codigoAutor) == 0)
            {
                arrayLibro[posLibre].codigoLibro = id;
                arrayLibro[posLibre].isEmpty  = 0;
                retorno=0;
            }
            else
            {
                retorno = 2;
            }
        }
    }
    else
    {
        retorno = 1;
    }

    return retorno;
}

int lib_buscarEnArrayPorId (Libros *arrayLibro, int cantidad, int *libroEncontrado,char *textoAMostrar)
{
    int i;
    int retorno = 1;
    Libros auxLibro;

    if (getInt(textoAMostrar, "Ingreso incorrecto\n", 0, 100, 2, &auxLibro.codigoLibro) == 0)
    {
        for(i=0; i < cantidad; i++)
        {
            if (arrayLibro[i].codigoLibro == auxLibro.codigoLibro)
            {
                retorno=0;
                *libroEncontrado=i;
                break;
            }
        }
    }
    return retorno;
}

int lib_baja(Libros *arrayLibro, int cantidad)
{
    int retorno = -1;
    int posicionLibro;

    lib_mostrarArray(arrayLibro, cantidad);
    switch (lib_buscarEnArrayPorId(arrayLibro, cantidad,&posicionLibro,"Ingrese el codigo del libro a dar de baja: "))
    {
    case 0:
        if (arrayLibro[posicionLibro].isEmpty == 0)
        {
            printf("Hubo coincidencia\n\n");
            arrayLibro[posicionLibro].isEmpty = 2;
            printf("El libro borrado es: %d\n\n",arrayLibro[posicionLibro].codigoLibro);
            retorno = 0;
        }
        break;
    case 1:
        printf("No se encontro el codigo\n\n");
        break;
    }
    return retorno;
}

void lib_mostrarArray(Libros *arrayLibro, int cantidad)
{
    int i;

    printf("\n\n\t\t\t\t||Lista de Libros||\n\n");

    for (i = 0; i < cantidad ;i++)
    {
        if(arrayLibro[i].isEmpty == 0)
        {

            printf("Codigo de autor: %d\n", arrayLibro[i].codigoAutor);
            printf("Posicion: %d\n", i);
            printf("Estado: %d\n", arrayLibro[i].isEmpty);
            printf("Titulo: %s\n", arrayLibro[i].titulo);
            printf("Codigo de Libro: %d\n\n", arrayLibro[i].codigoLibro);
        }
    }
}

int lib_modificacion(Libros *arrayLibro, Autores *arrayAutor, int cantidadLibro, int cantidadAutor)
{

    int retorno = -1;
    int opcion;
    int posicionLibro;
    char seguir = 's';

    lib_mostrarArray(arrayLibro, cantidadLibro);

    switch (lib_buscarEnArrayPorId(arrayLibro, cantidadLibro,&posicionLibro,"Ingrese el codigo de libro a modificar: "))
    {
    case 0:
        if (arrayLibro[posicionLibro].isEmpty == 0)
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
                        if (getString(arrayLibro[posicionLibro].titulo,"Ingrese el nuevo nombre de libro: ","Error",2,20,2)==0)
                        {
                            printf("El dato fue modificado con exito.\n\n");
                        }
                        break;
                    case 2:
                        aut_mostrarArray(arrayAutor, cantidadAutor);
                        if(getInt("\n\t\tIngrese el codigo de autor: ", "Ingreso incorrecto\n", 1, 10, 2, &arrayLibro[posicionLibro].codigoAutor) == 0)
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
        printf("No se encontro el codigo de libro");
        break;
        }

    return retorno;
}
