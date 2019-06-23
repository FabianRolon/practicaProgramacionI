#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "cliente.h"
#include "parser.h"
#include "utn.h"

int main()
{
    int option = 0;
    int flag = 0;
    LinkedList* listaCliente = ll_newLinkedList();
    do
    {
        Controller_printMenu();
        utn_getUnsignedInt( "\n\t\tIngrese opcion: ",
                            "Ingreso incorrecto\n",1,12,2,&option);
        system("clear");
        switch (option)
        {
        case 1:
            if(!controller_loadFromText("data.csv", listaCliente))
                flag = 1;
            break;
        case 2:
             if(!controller_loadFromBinary("data.bin", listaCliente))
                flag = 1;
            break;
        case 3:
                if(!controller_addCliente(listaCliente))
                    flag = 1;
            break;
        case 4:
            if(flag)
            {
                controller_editCliente(listaCliente);
            }else{printf("\nNo hay datos cargados para modificar");}
            break;
        case 5:
            if(flag)
            {
                controller_removeCliente(listaCliente);
            }else{
                printf("\nNo hay datos cargados para dar de baja");}
            break;
        case 6:
            if(flag)
            {
                controller_ListCliente(listaCliente);
            }else{printf("\nNo hay datos cargados para mostrar");}
            break;
        case 7:
            if(flag)
            {
                controller_sortCliente(listaCliente);
                controller_ListCliente(listaCliente);
            }else{printf("\nNo hay datos cargados para mostrar");}
            break;
        case 8:
            if(flag)
            {
                controller_saveAsText("data.csv" ,listaCliente);
            }else{
                printf("\nNo hay datos cargados para guardar");}
            break;
        case 9:
            if(flag)
            {
                controller_saveAsBinary("data.bin", listaCliente);
            }else{
                printf("\nNo hay datos cargados para guardar");}
            break;
        case 10:
            option = 10;
            break;
        }
    }while(option != 10);
    return 0;
}
