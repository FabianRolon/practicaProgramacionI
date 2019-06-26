#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "data.h"
#include "parser.h"
#include "Controller.h"
#include "utn.h"
#define MAX_CLIENTE 9999
#define MAX 1000
#define ASCENDENTE 1
#define DESCENDENTE 0


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListCliente LinkedList*
 * \return int
 *
 */
int controller_loadFromTextData(char* path , LinkedList* pArrayListData)
{
    int retorno = -1;

    FILE* pFile;
    pFile = NULL;
    pFile = fopen(path,"r");

    if(pFile!=NULL)
    {
        if(path != NULL && pArrayListData != NULL)
        {
             if(!parser_DataFromText(pFile , pArrayListData))
             {
                printf("\nCarga de clientes exitosa\n");
                fclose(pFile);
                retorno = 0;
             }
        }
     }
     return retorno;
}

int controller_ListData(LinkedList* pArrayListData)
{
    int retorno = -1;
    int i;
    char option = 'n';
    char option2 = 'n';
    int pagina = 99;
    int bufferId;
    Data *data;
    char bufferTipo[1000];
    int bufferCantidad;
    float bufferImporte;
    printf("Cargando lista...\n");
//    ll_sort(pArrayListCliente, cliente_compare, ASCENDENTE);
    if(pArrayListData != NULL)
    {
        do
        {
            for(i = 0; i < ll_len(pArrayListData); i++)
            {
                data = (Data*)ll_get(pArrayListData, i);
                if( !data_getTipo(data, bufferTipo)&&
                    !data_getId(data, &bufferId)&&
                    !data_getCantidad(data,&bufferCantidad)&&
                    !data_getImporte(data, &bufferImporte))
                    {
                        printf("Id: %d\t Tipo : %s\t  cantidad: %d\t Importe: %.2f\n",
                                bufferId,
                                bufferTipo,
                                bufferCantidad,
                                bufferImporte );
                        retorno = 0;
                    }
                    else
                    {
                        printf("\nNo se pudo mostrar al cliente\n");
                        retorno = -1;
                    }

                if(i == pagina)
                {
                    do
                    {
                        utn_getChar("\n\tPresione 's' para siguiente pagina: ",
                        "Error, vuelva a intentar",1,2,2,&option2);
                        pagina+=99;
                        system("clear");
                    }while(option2 == 'n');
                }
            }
            utn_getChar("\n\tPresione 's' para volver al menu principal: ",
                        "Error, vuelva a intentar",1,2,2,&option);
        }while(option == 'n');
    }
    return retorno;
}

void Controller_printMenu()
{
    printf("\t\t*MENU*");
    printf("\n1-Listar Data");
    printf("\n2-Generar Informe");
    printf("\n3-Salir\n");
}

int controller_Informe(char *path, LinkedList *pArrayListData)
{
    int retorno = -1;
    int i;
    int cantidadDeEntregas;
    int cantidadBultos = 0;
    int auxCantidadBultos;
    int cantidadDeEntregasRegular;
    int cantidadDeEntregasGold;
    int cantidadDeEntregasPlus;
    float promedioImportes;
    float promedioBultos;
    float auxImporte;
    float importeTotal = 0;

    Data *pData;
    FILE* pFile = NULL;
    LinkedList *regular = ll_newLinkedList();
    LinkedList *gold = ll_newLinkedList();
    LinkedList *plus = ll_newLinkedList();
    regular = ll_filter(pArrayListData, data_REGULAR);
    if(path != NULL && pArrayListData != NULL)
    {
        pFile = fopen(path, "w");
        if(pFile != NULL)
        {
            cantidadDeEntregas = ll_len(pArrayListData);
            regular = ll_filter(pArrayListData, data_REGULAR);
            gold = ll_filter(pArrayListData, data_GOLD);
            plus = ll_filter(pArrayListData, data_PLUS);

            for(i = 0; i < ll_len(pArrayListData); i++)
            {
                pData = ll_get(pArrayListData, i);
                data_getCantidad(pData, &auxCantidadBultos);
                data_getImporte(pData, &auxImporte);
                importeTotal = importeTotal + auxImporte;
                cantidadBultos = cantidadBultos + auxCantidadBultos;
            }
            promedioBultos = (cantidadBultos /(float) cantidadDeEntregas);
            promedioImportes = (float)(importeTotal / cantidadDeEntregas);

            cantidadDeEntregasRegular = ll_len(regular);
            cantidadDeEntregasGold = ll_len(gold);
            cantidadDeEntregasPlus = ll_len(plus);

            fprintf(pFile,  "*****************\n"
                            "Informe de ventas\n"
                            "*****************\n"
                            "Cantidad total de entregas: %d\n"
                            "Cantidad de entregas por tipo: %d (GOLD) - %d (REGULAR) - %d (PLUS)\n"
                            "Cantidad total de bultos entregados: %d\n"
                            "Promedio de bultos por entrega: %.2f\n"
                            "Importe promedio por entrega: %.2f\n",
                    cantidadDeEntregas,
                    cantidadDeEntregasGold,
                    cantidadDeEntregasRegular,
                    cantidadDeEntregasPlus,
                    cantidadBultos,
                    promedioBultos,
                    promedioImportes);
        }
        printf("\nInforme generado con exito\n");
        fclose(pFile);
    }
    return retorno;
}
