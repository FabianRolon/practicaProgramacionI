#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

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
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    FILE *pFile = NULL;
    pFile = fopen("data.csv","r");

    do{
            printf("\t\t*MENU*");
            printf("\n\n1-Cargar los datos de los empleados desde el archivo data.csv (modo texto).");
            printf("\n\n2-Cargar los datos de los empleados desde el archivo data.csv (modo binario)");
            printf("\n\n3-Alta de empleado");
            printf("\n\n4-Modificar datos de empleado");
            printf("\n\n5-Baja de empleado");
            printf("\n\n6-Listar empleados");
            printf("\n\n7-Ordenar empleados");
            printf("\n\n8-Guardar los datos de los empleados en el archivo data.csv (modo texto)");
            printf("\n\n9-Guardar los datos de los empleados en el archivo data.csv (modo binario)");
            printf("\n\n10-Salir\n");

            utn_getUnsignedInt("\n\t\tIngrese opcion: ","Ingreso incorrecto\n",1,12,2,&option);
            system("clear");
            switch (option)
            {
            case 1:
                controller_loadFromText("data.csv", listaEmpleados);

                break;
            case 2:

                break;
            case 3:
                controller_addEmployee(listaEmpleados);
                break;
            case 4:

                break;
            case 5:

                break;
            case 6:
                controller_ListEmployee(listaEmpleados);
                break;
            case 10:
                option = 10;
            case 7:

                break;
            case 8:

                break;
            }

    }while(option != 10);


    return 0;
}
