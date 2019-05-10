#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "fantasma.h"  //cambiar por nombre entidad
#include "autor.h"
#include "libros.h"

#define QTY_ARRAY_TIPO 10
#define QTY_ARRAY_AUTOR 10
#define QTY_ARRAY_LIBRO 10
#define SORT_UP 1
#define SORT_DOWN 0

int main()
{
    int opcion;
    int contadorIdFantasma=0;                   //cambiar

    Fantasma arrayFantasma[QTY_ARRAY_TIPO];                   //cambiar
    fantasma_Inicializar(arrayFantasma,QTY_ARRAY_TIPO);                   //cambiar
    fantasma_mock(arrayFantasma, QTY_ARRAY_TIPO, &contadorIdFantasma) ;                     //cambiar fantasma


    int contadorIdautor=0;
    Autor arrayAutor[QTY_ARRAY_AUTOR];                   //cambiar
    autor_Inicializar(arrayAutor,QTY_ARRAY_AUTOR);                   //cambiar
    autor_mock(arrayAutor, QTY_ARRAY_AUTOR, &contadorIdautor) ;                     //cambiar fantasma

    int contadorIdLibro=0;                   //cambiar

    Libro arrayLibro[QTY_ARRAY_LIBRO];                   //cambiar
    libro_Inicializar(arrayLibro,QTY_ARRAY_LIBRO);                   //cambiar
    libro_mock(arrayLibro, QTY_ARRAY_LIBRO, &contadorIdLibro) ;



    do
    {
        utn_getUnsignedInt("\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar \n5) Ordenar \n\n 6) Alta autor \n7) Modificar autor \n8) Baja autor \n9) Listar autor \n10) Ordenar autor 11) Alta libro \n12) Modificar libro \n13) Baja libro \n14) Listar libro \n15) Ordenar libro  \n16) Salir\n",                                                                                                                                        //cambiar
                      "\nError",1,sizeof(int),1,11,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta
                fantasma_alta(arrayFantasma,QTY_ARRAY_TIPO,&contadorIdLibro);                   //cambiar
                break;

            case 2: //Modificar
                fantasma_modificar(arrayFantasma,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 3: //Baja
                fantasma_baja(arrayFantasma,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 4://Listar
                fantasma_listar(arrayFantasma,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 5://Ordenar
                fantasma_ordenarPorDobleCriterio(arrayFantasma,QTY_ARRAY_TIPO,SORT_UP,SORT_DOWN);                   //cambiar
                break;
            case 6: //Alta
                autor_alta(arrayAutor,QTY_ARRAY_TIPO,&contadorIdautor);                   //cambiar
                break;

            case 7: //Modificar
                autor_modificar(arrayAutor,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 8: //Baja
                autor_baja(arrayAutor,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 9://Listar
                autor_listar(arrayAutor,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 10://Ordenar
                autor_ordenarPorDobleCriterio(arrayAutor,QTY_ARRAY_TIPO,SORT_UP,SORT_DOWN);                   //cambiar
                break;
            case 11: //Alta
                libro_alta(arrayLibro,arrayAutor, QTY_ARRAY_LIBRO,&contadorIdLibro);                   //cambiar
                break;

            case 12: //Modificar
                libro_modificar(arrayLibro,QTY_ARRAY_LIBRO);                   //cambiar
                break;

            case 13: //Baja
                libro_baja(arrayLibro,QTY_ARRAY_LIBRO);                   //cambiar
                break;

            case 14://Listar
                libro_listar(arrayLibro,QTY_ARRAY_LIBRO);                   //cambiar
                break;

            case 15://Ordenar
                libro_ordenarPorDobleCriterio(arrayLibro,QTY_ARRAY_LIBRO,SORT_UP,SORT_DOWN);                   //cambiar
                break;

            case 16://Salir
                break;

            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=16);
    return 0;
}
