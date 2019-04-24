#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"

int emp_mostrar(Empleado *aArray, int limite)
{

    printf("%s\n", aArray->nombre);
    printf("%d\n", aArray->idEmpleado);
    printf("%d\n", aArray->isEmpty);
    return 0;
}

