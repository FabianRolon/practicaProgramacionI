#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
   /* int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
        }
    }while(option != 10);*/
    FILE *pFileBkp = NULL;
   pFileBkp = fopen("data.csv","r");
   int i;
   Employee *empleado;
   char bufferNombre[1000];
   int bufferId, bufferSueldo, bufferHoras;
   // int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
   /* do{
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
        }
    }while(option != 10);*/
    parser_EmployeeFromText(pFileBkp, listaEmpleados);
    for(i = 0; i < ll_len(listaEmpleados); i++)
    {

        empleado = (Employee*)ll_get(listaEmpleados, i);
        employee_getNombre(empleado, bufferNombre);
        employee_getId(empleado, &bufferId);
        employee_getHorasTrabajadas(empleado,&bufferHoras);
        employee_getSueldo(empleado, &bufferSueldo);
        printf("Nombre : %s Id: %d Horas: %d Sueldo: %d\n", bufferNombre, bufferId, bufferHoras, bufferSueldo );
    }


    return 0;
}
