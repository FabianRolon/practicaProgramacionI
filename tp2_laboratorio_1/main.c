#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "ArrayEmployees.h"
#define QUANTITY_EMPLOYEES 1000

int main()
{
    int idEmployeeGenerator = 1;
    char seguir = 's'; //MENU
    int opcion; //MENU
    int value;
    int posicionLibreAutor;
    Employee arrayEmployees[QUANTITY_EMPLOYEES];


    value = initEmployees(arrayEmployees, QUANTITY_EMPLOYEES);

    if (value == 0)
    {
        printf("System correctly initialized\n\n\n");
    }
    else
    {
        printf("Error initializing");
    }


    while (seguir == 's')
    {
        printf("\t\t*MENU*");
        printf("\n\nAUTORES");
        printf("\n\n1-Alta arrayEmployees");
        printf("\n\n2-Baja arrayEmployees");
        printf("\n\n3-Modificar arrayEmployees");
        printf("\n\n4-Listar autores");
        printf("\n\nLIBROS");
        printf("\n\n5-Alta libro");
        printf("\n\n6-Baja libro");
        printf("\n\n7-Modificar libro");
        printf("\n\n8-Listar libros");
        printf("\n\n8-Salir\n");


        getInt("\n\t\tIngrese opcion: ", "Ingreso incorrecto\n", 1, 10, 2, &opcion);
        //system("cls"); //limpia la pantalla en windows
        system("clear"); //limpia pantalla en linux

        switch (opcion)
        {
        case 1:
            if(aut_buscarLibre(arrayEmployees,QUANTITY_EMPLOYEES, &posicionLibreAutor) != 0)
            {
                printf("LLENO\n\n");
            }
            else
            {
                switch (aut_alta(arrayEmployees, QUANTITY_EMPLOYEES, posicionLibreAutor, generadorCodigoAutor))
                {
                case 0:
                    printf("Dato ingresado correctamente\n\n");
                    generadorCodigoAutor++;
                    break;
                case 1:
                    printf("Dato ingresado INCORRECTAMENTE\n\n");
                    break;
                }
            }
            break;
        case 2:
            if (aut_baja(arrayEmployees, QUANTITY_EMPLOYEES) == 0)
            {
                printf("Exito");
            }
            break;
        case 3:
            if(aut_modificacion(arrayEmployees, QUANTITY_EMPLOYEES) == 0)
            break;
        case 4:
            aut_mostrarArray(arrayEmployees, QUANTITY_EMPLOYEES);
            break;
        case 5:
              if(lib_buscarLibre(libro,CANTIDAD_LIBROS, &posLibreLibro) != 0)
                {
                    printf("LLENO\n\n");
                }
                else
                {
                    switch (lib_alta(libro, arrayEmployees, CANTIDAD_LIBROS, QUANTITY_EMPLOYEES, posLibreLibro, generadorCodigoLibro))
                    {
                    case 0:
                        printf("Dato ingresado correctamente\n\n");
                        generadorCodigoLibro++;
                        break;
                    case 1:
                        printf("Dato ingresado INCORRECTAMENTE\n\n");
                        break;
                    case 2:
                        printf("El codigo de arrayEmployees no existe\n\n");
                        break;
                    }
                }
            break;
        case 6:
             if (aut_baja(arrayEmployees, QUANTITY_EMPLOYEES) == 0)
                {
                    printf("Exito");
                }
            break;
        }
    }
    return 0;
}
