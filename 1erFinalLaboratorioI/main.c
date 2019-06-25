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
    int flag2 = 0;
    LinkedList* listaCliente = ll_newLinkedList();
    LinkedList* listaVenta = ll_newLinkedList();
    if(!controller_loadFromTextClientes("clientes.txt", listaCliente))
            flag = 1;
    if(!controller_loadFromTextVentas("ventas.txt", listaVenta))
            flag2 = 1;
    do
    {
        Controller_printMenu();
        utn_getUnsignedInt( "\n\t\tIngrese opcion: ",
                            "Ingreso incorrecto\n",1,12,2,&option);
        system("clear");
        switch (option)
        {
        case 1:
            if(!controller_addCliente(listaCliente))
                    flag = 1;
            break;
        case 2:
            if(flag)
            {
                controller_editCliente(listaCliente);
            }else{printf("\nNo hay datos cargados para modificar");}
            break;
        case 3:
            if(flag)
            {
                controller_removeCliente(listaCliente);
            }else{printf("\nNo hay datos cargados para dar de baja");}
            break;
        case 4:
            if(flag)
            {
                controller_ListCliente(listaCliente);
            }else{printf("\nNo hay datos cargados para mostrar");}
            break;
        case 5:
            if(flag)
            {
                if(!controller_addVenta(listaVenta,listaCliente))
                    flag2 = 1;
            }else{printf("\nNo hay clientes cargados para realizar la venta");}
            break;
        case 6:
            if(flag2)
            {
                controller_removeVenta(listaVenta);
            }else{printf("\nNo hay datos cargados para remover");}

            break;
        case 7:
            if(flag2)
            {
                controller_ListVenta(listaVenta, listaCliente);
            }else{printf("\nNo hay datos de ventas para listar\n");}
            break;
        case 8:
            controller_ventasPorProducto(listaCliente, listaVenta);
            break;
        case 9:
            if(flag2)
            {
                controller_saveAsTextInformeVenta("informes.txt" ,listaVenta, listaCliente);
            }else{printf("\nNo hay datos de ventas para informar\n");}
            break;
        case 10:

            break;
        case 11:
            option = 11;
            break;
        }
    }while(option != 11);
    return 0;
}
