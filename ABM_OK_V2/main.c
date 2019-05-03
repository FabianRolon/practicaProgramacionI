#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "pantalla.h"
#include "publicidad.h"
#include "contrataciones.h"
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
    int valor3;
    int posLibrePantallas;
    int posLibrePublicidad;
    int posLibreContratacion;
    Pantalla pantallas[CANTIDAD_PANTALLA];
    Publicidad publicidades[CANTIDAD_PUBLICIDAD];
    Contrataciones contratacion[CANTIDAD_PUBLICIDAD];

    valor1 = pan_Inicializar(pantallas, CANTIDAD_PANTALLA);
    valor2 = pub_Inicializar(publicidades, CANTIDAD_PUBLICIDAD);
    valor3 = con_Inicializar(contratacion, CANTIDAD_PUBLICIDAD);

    if (valor1 == 0 && valor2 == 0 && valor3 == 0)
    {
        printf("Sistema inicializado correctamente\n\n\n");
    }

    strcpy(pantallas[0].direccion,"Mitre 750");
    pantallas[0].isEmpty=0;
    strcpy(pantallas[0].nombre,"Pantalla 1");
    pantallas[0].precio= 1000.20;
    pantallas[0].tipo=0;
    pantallas[0].idPantalla=0;

    strcpy(pantallas[1].direccion,"Belgrano 750");
    pantallas[1].isEmpty=0;
    strcpy(pantallas[1].nombre,"Pantalla 2");
    pantallas[1].precio= 2000.20;
    pantallas[1].tipo=0;
    pantallas[1].idPantalla=1;

    strcpy(publicidades[0].nombreVideo,"archivo1.mp4");
    strcpy(publicidades[0].cuitCliente,"20-20056658-5");
    publicidades[0].cantDias = 30;
    publicidades[0].isEmpty = 0;
    publicidades[0].idPublicidad = 0;

    strcpy(publicidades[1].nombreVideo,"archivo2.mp4");
    strcpy(publicidades[1].cuitCliente,"20-20056658-5");
    publicidades[1].cantDias = 30;
    publicidades[1].isEmpty = 0;
    publicidades[1].idPublicidad = 1;

    strcpy(publicidades[2].nombreVideo,"archivo3.mp4");
    strcpy(publicidades[2].cuitCliente,"20-20056659-5");
    publicidades[2].cantDias = 30;
    publicidades[2].isEmpty = 0;
    publicidades[2].idPublicidad = 2;

    contratacion[0].idPantalla = 0;
    strcpy(contratacion[0].cuitCliente,"20-20056659-5");
    contratacion[0].isEmpty = 0;

    contratacion[1].idPantalla = 1;
    strcpy(contratacion[1].cuitCliente,"20-20056659-5");
    contratacion[1].isEmpty = 0;

    contratacion[2].idPantalla = 0;
    strcpy(contratacion[2].cuitCliente,"20-20056658-5");
    contratacion[2].isEmpty = 0;



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


        getInt("\n\t\tIngrese opcion: ", "Ingreso incorrecto\n", 1, 10, 2, &opcion);
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
            pub_mostrarArray(publicidades, pantallas, CANTIDAD_PANTALLA, CANTIDAD_PUBLICIDAD);
            break;
        case 6:
            con_buscarContratacionesPorCuit(contratacion, pantallas, CANTIDAD_PUBLICIDAD, CANTIDAD_PANTALLA);
            con_baja(contratacion, CANTIDAD_PUBLICIDAD);
            break;
        }
    }
    return 0;
}
