#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"

int main()
{
    Fecha fecha[2];


    getFecha("\n\nIngrese la fecha MM/DD/AAAA: ", "\n\nError, ingreso incorrecto: ", 1, 2019, 3,&fecha[0].mes, &fecha[0].dia, &fecha[0].anio);

    printf("La fecha ingresada es: %d/%d/%d", fecha[0].dia, fecha[0].mes, fecha[0].anio);

    return 0;
}
