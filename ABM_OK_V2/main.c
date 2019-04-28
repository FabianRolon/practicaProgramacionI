#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "pantalla.h"
#include "funciones_string.h"

#define CANTIDAD_PANTALLA 10

int main()
{
    int idGenerator = 1;
    char seguir = 's'; //MENU
    int opcion; //MENU
    int valor;
    int posLibre;
    Pantalla pantallas[CANTIDAD_PANTALLA];

    valor = pan_Inicializar(pantallas, CANTIDAD_PANTALLA);

    if (valor == 0)
    {
        printf("Sistema inicializado correctamente\n\n\n");
    }
    while (seguir == 's')
    {
        printf("\t\tMENU");
        printf("\n\n1-Alta pantalla");
        printf("\n\n2-Baja pantalla");
        printf("\n\n3-Modificar pantalla");
        printf("\n\n4-Mostrar pantallas");

        printf("\n\n5-Salir\n");


        getInt("\n\t\tIngrese opcion: ", "Ingreso incorrecto\n", 1, 6, 2, &opcion);
        //system("cls"); //limpia la pantalla en windows
        system("clear"); //limpia pantalla en linux
        switch (opcion)
        {
        case 1:

            if(pan_buscarLibre(pantallas,CANTIDAD_PANTALLA, &posLibre) != 0)
            {
                printf("LLENO\n\n");
            }
            else
            {
                switch (pan_AltaPantalla(pantallas, CANTIDAD_PANTALLA, posLibre, idGenerator))
                {
                case 0:
                    printf("Dato ingresado correctamente\n\n");
                    idGenerator++;
                    break;
                case 1:
                    printf("Dato ingresado INCORRECTAMENTE\n\n");
                    break;
                }
            }
            break;

        case 4:

            pan_mostrarArray(pantallas, CANTIDAD_PANTALLA);
            break;

        case 2:
            if (pan_baja(pantallas, CANTIDAD_PANTALLA)==0)
            {
                printf("Exito");
            }
            break;

        case 5:
            seguir = 'f';
            break;
        case 3:
            if(pan_modificacion(pantallas, CANTIDAD_PANTALLA) == 0)
            break;
        }
    }
    return 0;
}
