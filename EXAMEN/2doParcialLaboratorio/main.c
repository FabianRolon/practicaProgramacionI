#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "data.h"
#include "parser.h"
#include "utn.h"

int main()
{
    int option = 0;
//    int flag = 0;
    LinkedList* listaData = ll_newLinkedList();

    controller_loadFromTextData("data.csv", listaData);


    do
    {
        Controller_printMenu();
        utn_getUnsignedInt( "\n\t\tIngrese opcion: ",
                            "Ingreso incorrecto\n",1,12,2,&option);
        system("clear");
        switch (option)
        {
        case 1:
        controller_ListData(listaData);
            break;
        case 2:
        controller_Informe("informes.txt", listaData);
            break;
        case 3:
            option = 3;
            break;
        }
    }while(option != 3);
    return 0;
}
