#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "asociado.h"
#define CANTIDAD_ASOCIADOS 10

int main()
{
    int idGeneratorAsociado = 1;
    char seguir = 's'; //MENU
    int opcion; //MENU
    int valor1;
//    int valor2;
//    int valor3;
    int posLibreAsociado;
//    int posLibreContratacion;
    Asociado asociados[CANTIDAD_ASOCIADOS];

    valor1 = aso_Inicializar(asociados, CANTIDAD_ASOCIADOS);

    strcpy(asociados[0].apellido, "Rolon");
    strcpy(asociados[0].nombre, "Fabian");
    asociados[0].dni = 34158249;
    asociados[0].edad = 30;
    asociados[0].isEmpty = 0;
    asociados[0].idAsociado = 1;

    strcpy(asociados[1].apellido, "Juarez");
    strcpy(asociados[1].nombre, "Analia");
    asociados[1].dni = 31379410;
    asociados[1].edad = 33;
    asociados[1].isEmpty = 0;
    asociados[1].idAsociado = 2;

    strcpy(asociados[2].apellido, "Suarez");
    strcpy(asociados[2].nombre, "Oriana");
    asociados[2].dni = 52141222;
    asociados[2].edad = 18;
    asociados[2].isEmpty = 0;
    asociados[2].idAsociado = 3;


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
        printf("\n\n4-Listar asociados\n");
        printf("\n\n5-Salir\n");


        getInt("\n\t\tIngrese opcion: ", "Ingreso incorrecto\n", 1, 10, 2, &opcion);
//        system("cls"); //limpia la pantalla en windows
        system("clear"); //limpia pantalla en linux

        switch(opcion)
        {
        case 1:
            if(aso_buscarLibre(asociados,CANTIDAD_ASOCIADOS, &posLibreAsociado) != 0)
            {
                printf("LLENO\n\n");
            }
            else
            {
                switch (aso_altaAsociado(asociados, CANTIDAD_ASOCIADOS, posLibreAsociado, idGeneratorAsociado))
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
        case 2:
            if (aso_baja(asociados, CANTIDAD_ASOCIADOS) == 0)
            {
                printf("Exito");
            }
            break;
        case 5:
            seguir = 'f';
            break;
        case 3:
            if(aso_modificaion(asociados, CANTIDAD_ASOCIADOS) == 0)
            break;
        case 4:
            aso_mostrarArray(asociados, CANTIDAD_ASOCIADOS);
            break;
        }
    }

    return 0;
}
