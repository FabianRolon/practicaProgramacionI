#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

 typedef struct
{
    int idEmpleado;
    int isEmpty;
    char nombre[50];
}Empleado;

int emp_initArray(Empleado *aArray, int limite);
int emp_lugarLibreArray(Empleado *aArray, int limite, int *indice);
int emp_alta(Empleado *aArray, int limite, int id);
int emp_baja(Empleado *aArray, int limite);
int emp_buscarPorNombre(Empleado *aArray, int limite, char *nombre, int *indice);
int emp_ordenarPorNombre(Empleado *aArray, int limite);
int emp_mostrar(Empleado *aArray, int limite);

#endif // EMPLEADO_H_INCLUDED
