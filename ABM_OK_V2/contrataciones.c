#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "pantalla.h"
#include "publicidad.h"
#include "contrataciones.h"
#include "funciones_string.h"

int con_Inicializar(Contrataciones *arrayContratacion, int cantidad)
{
    int retorno = -1;
    int i;

    for (i = 0; i < cantidad; i++)
    {
        arrayContratacion[i].isEmpty = 1;
        retorno=0;
    }

    return retorno;
}
