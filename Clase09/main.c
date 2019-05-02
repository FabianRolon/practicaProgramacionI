#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"

int main()
{


    Empleado modelo;

    modelo.isEmpty = 1;
    modelo.idEmpleado = 1;

    strncpy(modelo.nombre, "FABIAN", 50);

    emp_mostrar(&modelo, 50);


    return 0;
}
