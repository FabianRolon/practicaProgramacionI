#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "asociado.h"
#include "llamada.h"

int lla_Inicializar(Llamada *arrayLlamada, int cantidad)
{
    int retorno = -1;
    int i;

    for (i = 0; i < cantidad; i++)
    {
        strncpy(arrayLlamada[i].estado, "1", 10);
        retorno=0;
    }

    return retorno;
}

int lla_buscarLibre(Llamada *arrayLlamada, int cantidad, int *devuelve)
{
    int retorno=-1;
    for (int i=0; i<cantidad;i++)
    {
        if (strcmp(arrayLlamada[i].estado, "1") == 0)
        {
            *devuelve=i;
            retorno=0;
            break;
        }

        retorno=1;
    }

    return retorno;
}

int lla_altaLlamada(Llamada *arrayLlamadas, int cantidad, int posicionLibre, int id)
{
    int retorno = -1;

    if (    getInt("Ingrese el id del asociado: ","Error, vuelva a ingresar\n\n", 2, 20, 2,&arrayLlamadas[posicionLibre].idAsociado) == 0 &&
            getString(&arrayLlamadas[posicionLibre].motivo, "Ingrese el Motivo: \n 1-ACV\n 2-GRIPE\n 3-INFARTO\n", "Error, ingrese nuevamente\n\n", 3, 7,2) == 0)
        {
            arrayLlamadas[posicionLibre].idAsociado = id;
            strncpy(arrayLlamadas[posicionLibre].estado, "PENDIENTE", 10);
            retorno=0;
        }
        else
        {
            retorno = 1;
        }

    return retorno;
}
