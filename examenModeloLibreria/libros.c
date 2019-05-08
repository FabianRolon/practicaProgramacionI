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

    if (    getString(arrayLibro[posLibre].titulo,"Ingrese un titulo: ","Error, vuelva a ingresar\n\n",2,20,2) == 0 &&
            getInt("Ingrese el codigo de autor: ", "Ingreso incorrecto\n", 1, 10, 2, &arrayLibro[posLibre].codigoAutor) == 0)
    {
        if(aut_existeId (arrayAutor, cantidadAutor, id) == 0)
        {
            arrayLibro[posLibre].codigoLibro = id;
            arrayLibro[posLibre].isEmpty  = 0;
            retorno=0;
        }
        else
        {
            retorno = 1;
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

