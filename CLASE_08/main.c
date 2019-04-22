#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define QTY_EMPLEADOS 10
#define LONGITUD_CADENA 50

int main()
{
    char seguir = 's';
    int choice = 0;
    char aNombre[QTY_EMPLEADOS][LONGITUD_CADENA];
    inicializar(aNombre, LONGITUD_CADENA);
    int posicionArray;
    char bufferNombre [LONGITUD_CADENA];

    while(seguir == 's')
    {
        printf("************************\n");
        printf("*");
        printf("Base datos de Nombres ");
        printf("*\n");
        printf("************************\n\n");
        printf("1- Dar de alta a un usuario\n");
        printf("2- Dar de baja a un usuario\n");
        printf("3- Modificar a un usuario\n");
        printf("4- Ordenar en orden alfabetico\n");
        printf("5- Mostrar lista\n");
        printf("6- Finalizar\n");

        getInt(" ","ERROR! Su eleccion no es correcta.\n", 1, 6, 3, &choice);


        switch(choice)
        {
            case 1:
                posicionArray = encontrarVacio(aNombre, QTY_EMPLEADOS);
                if(posicionArray == -1)
                {
                    printf("No hay mas espacio disponible\n");
                    break;
                }
                getString(  "Ingrese el nombre del usuario a dar de alta\n",
                            "ERROR! Ingrese un nombre valido\n",2, LONGITUD_CADENA, 2, &aNombre[posicionArray-1][LONGITUD_CADENA]);
                break;

            case 2:
                getString(  "Ingrese el nombre del usuario a dar de baja\n",
                            "ERROR! Ingrese un nombre valido\n",2, LONGITUD_CADENA, 2, bufferNombre);

                posicionArray = encontrarNombre(aNombre, bufferNombre, QTY_EMPLEADOS);
                strncpy(aNombre[posicionArray], "\0", QTY_EMPLEADOS);
                break;

            case 3:
                getString(  "Ingrese el nombre del usuario a modificar\n",
                            "ERROR! Ingrese un nombre valido\n",2, LONGITUD_CADENA, 2, bufferNombre);

                posicionArray = encontrarNombre(aNombre, bufferNombre, QTY_EMPLEADOS);
                getString(  "Ingrese la modidficacion\n",
                            "ERROR! Ingrese un nombre valido\n",2, LONGITUD_CADENA, 2, &aNombre[posicionArray-1][LONGITUD_CADENA]);
                strncpy(aNombre[posicionArray], &aNombre[posicionArray-1][LONGITUD_CADENA], QTY_EMPLEADOS);
                break;

            case 4:
                ordenarArray(aNombre, QTY_EMPLEADOS);
                break;

            case 5:
                printArrayArray(aNombre, QTY_EMPLEADOS);
                break;

            case 6:
                seguir = 'n';
                break;
        }
    }
    return 0;
}




