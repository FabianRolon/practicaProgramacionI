#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "data.h"

/** \brief Parsea los datos los datos de los clientes desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListCliente LinkedList*
 * \return int
 *
 */
int parser_DataFromText(FILE* pFile , LinkedList* pArrayListData)
{
    int retorno = -1;
    char bufferId[2000];
    char bufferTipo[2000];
    char bufferCantidad[2000];
    char bufferImporte[2000];
    Data *bufferData;
    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferTipo,bufferCantidad,bufferImporte);
            bufferData = data_newParametrosStr(bufferId,bufferTipo,bufferCantidad,bufferImporte);
            if(bufferData != NULL)
                ll_add(pArrayListData, bufferData);
        }
        retorno = 0;
    }
    return retorno;
}

