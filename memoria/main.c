#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"

int main()
{
    Empleado *pArrayEmpleado[1000];
    int ultimoElementoArrayEmpleado = 0;
    int indiceActual;
    int auxInt;
    float auxPeso;
    char auxNombre[31];
    int generadorId = 1;

    indiceActual = ultimoElementoArrayEmpleado;
    pArrayEmpleado[indiceActual] =  Emp_new();


    if(pArrayEmpleado[indiceActual] != NULL)
    {
        ultimoElementoArrayEmpleado++;
        printf("OK");
        if(!Emp_setId(pArrayEmpleado[indiceActual],generadorId))
        {
            generadorId++;
            Emp_getId(pArrayEmpleado[indiceActual], &auxInt);
            printf("\n El id es %d",auxInt);

        }
        if(!Emp_setPeso(*(pArrayEmpleado+indiceActual), 73.5))
        {
            Emp_getPeso(*(pArrayEmpleado+indiceActual), &auxPeso);
            printf("\n El peso es %f", auxPeso);
        }
        if(!Emp_setNombre(*(pArrayEmpleado+indiceActual),"Fabian", 31))
        {
            Emp_getNombre(*(pArrayEmpleado+indiceActual), auxNombre, 31);
            printf("\n El nombre es %s", auxNombre);
        }

    }


    return 0;
}
