#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "pantalla.h"
#include "publicidad.h"
#include "funciones_string.h"

#define CANTIDAD_PANTALLA 10
#define CANTIDAD_PUBLICIDAD 10

int main()
{
    int idGeneratorPan = 1;
    char seguir = 's'; //MENU
    int opcion; //MENU
    int valor1;
    int valor2;
    int posLibrePantallas;
    int posLibrePublicidad;
    Pantalla pantallas[CANTIDAD_PANTALLA];
    Publicidad publicidades[CANTIDAD_PUBLICIDAD];

    valor1 = pan_Inicializar(pantallas, CANTIDAD_PANTALLA);
    valor2 = pub_Inicializar(publicidades, CANTIDAD_PUBLICIDAD);

    if (valor1 == 0 && valor2 == 0)
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
        printf("\n\n5-Contratar una publicidad");
        printf("\n\n6-Cancelar Publicidad");
        printf("\n\n7-Mostrar publicidades");
        printf("\n\n8-Salir\n");


        getInt("\n\t\tIngrese opcion: ", "Ingreso incorrecto\n", 1, 7, 2, &opcion);
        //system("cls"); //limpia la pantalla en windows
        system("clear"); //limpia pantalla en linux

        switch (opcion)
        {
        case 1:

            if(pan_buscarLibre(pantallas,CANTIDAD_PANTALLA, &posLibrePantallas) != 0)
            {
                printf("LLENO\n\n");
            }
            else
            {
                switch (pan_AltaPantalla(pantallas, CANTIDAD_PANTALLA, posLibrePantallas, idGeneratorPan))
                {
                case 0:
                    printf("Dato ingresado correctamente\n\n");
                    idGeneratorPan++;
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

        case 8:
            seguir = 'f';
            break;
        case 3:
            if(pan_modificacion(pantallas, CANTIDAD_PANTALLA) == 0)
            break;
        case 5:
            pan_mostrarArray(pantallas, CANTIDAD_PANTALLA);
            if(pub_buscarLibre(publicidades, CANTIDAD_PANTALLA, &posLibrePublicidad) != 0)
            {
                printf("LLENO\n\n");
            }
            else
            {
                switch (pub_AltaPublicidad(publicidades, CANTIDAD_PUBLICIDAD, posLibrePublicidad))
                {
                case 0:
                    printf("Dato ingresado correctamente\n\n");
                    break;
                case 1:
                    printf("Dato ingresado INCORRECTAMENTE\n\n");
                    break;
                }
            }
            break;
        case 7:
            pub_mostrarArray(publicidades, pantallas, CANTIDAD_PANTALLA, CANTIDAD_PUBLICIDAD);
            break;
        }
    }
    return 0;
}
