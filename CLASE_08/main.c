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

    while(seguir == 's')
    {

        printf("Base datos de Nombre\n\n\n");
        printf("1- Dar de alta a un usuario\n");
        printf("2- Dar de baja a un usuario\n");
        printf("3- Modificar a un usuario\n");
        printf("4- Ordenar\n");
        printf("5- Mostrar\n");
        printf("6- Finalizar\n");

        getInt("\n","ERROR! Su eleccion no es correcta.\n", 1, 6, 3, &choice);


        switch(choice)
        {
            case 1:
                inicializar(aNombre, LONGITUD_CADENA);
                posicionArray = encontrarVacio(aNombre, LONGITUD_CADENA);
                getString("Ingrese el nombre del usuario\n", "ERROR! Ingrese un nombre valido", 2, LONGITUD_CADENA, 2, &aNombre[posicionArray][LONGITUD_CADENA]);


                break;

            case 2:

                break;

            case 3:

                break;

            case 4:
                seguir = 'n';
                break;
        }
    }
    return 0;
}




