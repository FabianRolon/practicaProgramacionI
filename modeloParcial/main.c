#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "asociado.h"
#define CANTIDAD_ASOCIADOS 10

int main()
{
    int idGeneratorAsociado = 1;
    char seguir = 's'; //MENU
    int opcion; //MENU
    int valor1;
    int valor2;
    int valor3;
    int posLibrePantallas;
    int posLibrePublicidad;
    int posLibreContratacion;
    Asociado asociados[CANTIDAD_ASOCIADOS];

    valor1 = aso_Inicializar(asociados, CANTIDAD_ASOCIADOS);


    if (valor1 == 0)
    {
        printf("Sistema inicializado correctamente\n\n\n");
    }
    else
    {
        printf("Error al inicializar");
    }

    while (seguir == 's')
    {
        printf("\t\tMENU");
        printf("\n\n1-Alta Asociado");
        printf("\n\n2-Baja Asociado");
        printf("\n\n3-Modificar Asociado");
        printf("\n\n4-Mostrar pantallas");
        printf("\n\n5-Contratar una publicidad");
        printf("\n\n6-Cancelar Publicidad");
        printf("\n\n7-Mostrar publicidades");
        printf("\n\n8-Salir\n");


        getInt("\n\t\tIngrese opcion: ", "Ingreso incorrecto\n", 1, 10, 2, &opcion);
        system("cls"); //limpia la pantalla en windows
//        system("clear"); //limpia pantalla en linux

        switch (opcion)
        {
        case 1:

            if(aso_buscarLibre(asociado,CANTIDAD_ASOCIADOS, &posLibreAsociado) != 0)
            {
                printf("LLENO\n\n");
            }
            else
            {
                switch (pan_AltaPantalla(asociado, CANTIDAD_ASOCIADOS, posLibreAsociado, idGeneratorAsociado))
                {
                case 0:
                    printf("Dato ingresado correctamente\n\n");
                    idGeneratorAsociado++;
                    break;
                case 1:
                    printf("Dato ingresado INCORRECTAMENTE\n\n");
                    break;
                }
            }
            break;

        case 4:

            pan_mostrarArray(asociado, CANTIDAD_ASOCIADOS);
            break;

        case 2:
            if (pan_baja(asociado, CANTIDAD_ASOCIADOS)==0)
            {
                printf("Exito");
            }
            break;

        case 8:
            seguir = 'f';
            break;
        case 3:
            if(pan_modificacion(asociado, CANTIDAD_ASOCIADOS) == 0)
            break;
        case 5:
            pan_mostrarArray(asociado, CANTIDAD_ASOCIADOS);
            if( pub_buscarLibre(publicidades, CANTIDAD_PUBLICIDAD, &posLibrePublicidad) != 0 &&
                con_buscarLibre(contratacion, CANTIDAD_PUBLICIDAD, &posLibreContratacion) != 0)
            {
                printf("LLENO\n\n");
            }
            else
            {
                switch (pub_AltaPublicidad(publicidades, contratacion, CANTIDAD_PUBLICIDAD, posLibrePublicidad, posLibreContratacion))
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
            pub_mostrarArray(publicidades, asociado, CANTIDAD_ASOCIADOS, CANTIDAD_PUBLICIDAD);
            break;
        case 6:
            con_buscarContratacionesPorCuit(contratacion, asociado, CANTIDAD_PUBLICIDAD, CANTIDAD_ASOCIADOS);
            con_baja(contratacion, CANTIDAD_PUBLICIDAD);
            break;
        }
    }

    return 0;
}
