#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "ArrayEmployees.h"


#define QTY_ARRAY_EMPLOYEE 10
#define SORT_UP 1
#define SORT_DOWN 0

int main()
{
    int opcion;
    int contadorIdemployee=0;                   //cambiar

    Employee arrayEmployee[QTY_ARRAY_TIPO];                   //cambiar
    employee_Inicializar(arrayEmployee,QTY_ARRAY_TIPO);                   //cambiar

    //*******************************************************************
    arrayEmployee[0].idEmployee=0;
    arrayEmployee[0].isEmpty=0;
    arrayEmployee[0].sector=0;
    arrayEmployee[0].salary=0;
    strcpy(arrayEmployee[0].lastName,"CCCCC");
    strcpy(arrayEmployee[0].name,"CCCCC");
    contadorIdemployee++;

    arrayEmployee[1].idEmployee=1;
    arrayEmployee[1].isEmpty=0;
    arrayEmployee[1].sector=0;
    arrayEmployee[1].salary=0;
    strcpy(arrayEmployee[1].lastName,"AAAAA");
    strcpy(arrayEmployee[1].name,"AAAAA");
    contadorIdemployee++;

    arrayEmployee[2].idEmployee=0;
    arrayEmployee[2].isEmpty=0;
    arrayEmployee[2].sector=0;
    arrayEmployee[2].salary=20;
    strcpy(arrayEmployee[2].lastName,"BBBBB");
    strcpy(arrayEmployee[2].name,"BBBBBB");
    contadorIdemployee++;

    arrayEmployee[3].idEmployee=0;
    arrayEmployee[3].isEmpty=0;
    arrayEmployee[3].sector=0;
    arrayEmployee[3].salary=10;
    strcpy(arrayEmployee[3].lastName,"BBBBB");
    strcpy(arrayEmployee[3].name,"BBBBBB");
    contadorIdemployee++;


    //********************************************************************

    do
    {
        utn_getUnsignedInt("\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar \n5) Ordenar \n6) Salir\n",                   //cambiar
                      "\nError",1,sizeof(int),1,11,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta
                employee_alta(arrayEmployee,QTY_ARRAY_TIPO,&contadorIdemployee);                   //cambiar
                break;

            case 2: //Modificar
                employee_modificar(arrayEmployee,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 3: //Baja
                employee_baja(arrayEmployee,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 4://Listar
                employee_listar(arrayEmployee,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 5://Ordenar
                employee_ordenarPorDobleCriterio(arrayEmployee,QTY_ARRAY_TIPO,SORT_UP,SORT_DOWN);                   //cambiar
                break;

            case 6://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=6);
    return 0;
}
