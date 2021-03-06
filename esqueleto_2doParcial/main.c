#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

int main()
{
    int option = 0;
    int flag = 0;
    LinkedList* listaEntidad = ll_newLinkedList();
    do
    {
        Controller_printMenu();
        utn_getUnsignedInt( "\n\t\tIngrese opcion: ",
                            "Ingreso incorrecto\n",1,12,2,&option);
        system("clear");
        switch (option)
        {
        case 1:
            if(!controller_loadFromText("data.csv", listaEntidad))
                flag = 1;
            break;
        case 2:
             if(!controller_loadFromBinary("data.bin", listaEntidad))
                flag = 1;
            break;
        case 3:
                if(!controller_addEntidad(listaEntidad))
                    flag = 1;
            break;
        case 4:
            if(flag)
            {
                controller_editEntidad(listaEntidad);
            }else{printf("\nNo hay datos cargados para modificar");}
            break;
        case 5:
            if(flag)
            {
                controller_removeEntidad(listaEntidad);
            }else{
                printf("\nNo hay datos cargados para dar de baja");}
            break;
        case 6:
            if(flag)
            {
                controller_ListEntidad(listaEntidad);
            }else{printf("\nNo hay datos cargados para mostrar");}
            break;
        case 7:
            if(flag)
            {
                controller_sortEntidad(listaEntidad);
                controller_ListEntidad(listaEntidad);
            }else{printf("\nNo hay datos cargados para mostrar");}
            break;
        case 8:
            if(flag)
            {
                controller_saveAsText("data.csv" ,listaEntidad);
            }else{
                printf("\nNo hay datos cargados para guardar");}
            break;
        case 9:
            if(flag)
            {
                controller_saveAsBinary("data.bin", listaEntidad);
            }else{
                printf("\nNo hay datos cargados para guardar");}
            break;
        case 10:
            option = 10;
            break;
        case 11:
            Controller_filtrarPorHoras(listaEntidad);
            break;
        }
    }while(option != 10);
    return 0;
}
