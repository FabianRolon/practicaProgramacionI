#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "autores.h"
#include "libros.h"
#define CANTIDAD_AUTORES 10
#define CANTIDAD_LIBROS 10

int main()
{
    int generadorCodigoAutor = 1;
    int generadorCodigoLibro = 1;
    char seguir = 's';
    char salirLista = 'n'; //MENU
    int opcion; //MENU
    int valor1;
    int valor2;
//    int valor3;
    int posicionLibreAutor;
    int posLibreLibro;
//    int posLibreContratacion;
    Autores autor[CANTIDAD_AUTORES];
    Libros libro[CANTIDAD_LIBROS];

    valor1 = aut_Inicializar(autor, CANTIDAD_AUTORES);
    valor2 = lib_Inicializar(libro, CANTIDAD_LIBROS);

    if (valor1 == 0 && valor2 == 0)
    {
        printf("Sistema inicializado correctamente\n\n\n");
    }

    autor[0].codigoAutor=1;
    autor[0].isEmpty=0;
    strcpy(autor[0].nombre,"Jose Luis");
    strcpy(autor[0].apellido,"Borges");


    autor[1].codigoAutor=2;
    autor[1].isEmpty=0;
    strcpy(autor[1].nombre,"William");
    strcpy(autor[1].apellido,"Shakespeare");
    generadorCodigoAutor++;

    autor[2].codigoAutor=3;
    autor[2].isEmpty=0;
    strcpy(autor[2].nombre,"Gabriel");
    strcpy(autor[2].apellido,"Marquez");
    generadorCodigoAutor++;

    autor[3].codigoAutor=4;
    autor[3].isEmpty=0;
    strcpy(autor[3].nombre,"Carl");
    strcpy(autor[3].apellido,"Sagan");
    generadorCodigoAutor++;


    while (seguir == 's')
    {
        printf("\t\t*MENU*");
        printf("\n\nAUTORES");
        printf("\n\n1-Alta autor");
        printf("\n\n2-Baja autor");
        printf("\n\n3-Modificar autor");
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
            if(aut_buscarLibre(autor,CANTIDAD_AUTORES, &posicionLibreAutor) != 0)
            {
                printf("LLENO\n\n");
            }
            else
            {
                switch (aut_alta(autor, CANTIDAD_AUTORES, posicionLibreAutor, generadorCodigoAutor))
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
            if (aut_baja(autor, CANTIDAD_AUTORES) == 0)
            {
                printf("Exito");
            }
            break;
        case 3:
            if(aut_modificacion(autor, CANTIDAD_AUTORES) == 0)
            break;
        case 4:
            do
            {
                aut_mostrarArray(autor, CANTIDAD_AUTORES);
                utn_getChar("\n\tIngrese 's' para volver al menu anterior: ", "Ingreso incorrecto",1,2,2,&salirLista);

            }while(salirLista!='s');
            aut_mostrarArray(autor, CANTIDAD_AUTORES);
            break;
        case 5:
              if(lib_buscarLibre(libro,CANTIDAD_LIBROS, &posLibreLibro) != 0)
                {
                    printf("LLENO\n\n");
                }
                else
                {
                    switch (lib_alta(libro, autor, CANTIDAD_LIBROS, CANTIDAD_AUTORES, posLibreLibro, generadorCodigoLibro))
                    {
                    case 0:
                        printf("Dato ingresado correctamente\n\n");
                        generadorCodigoLibro++;
                        break;
                    case 1:
                        printf("Dato ingresado INCORRECTAMENTE\n\n");
                        break;
                    case 2:
                        printf("El codigo de autor no existe\n\n");
                        break;
                    }
                }
            break;
        case 6:
             if (aut_baja(autor, CANTIDAD_AUTORES) == 0)
                {
                    printf("Exito");
                }
            break;
        case 8:
            seguir = 'a';
            break;
        }
    }
    return 0;
}
