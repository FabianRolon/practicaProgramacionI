#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "cliente.h"
#include "venta.h"

/** \brief Parsea los datos los datos de los clientes desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListCliente LinkedList*
 * \return int
 *
 */
int parser_ClienteFromText(FILE* pFile , LinkedList* pArrayListCliente)
{
    int retorno = -1;
    char bufferId[2000];
    char bufferNombre[2000];
    char bufferApellido[2000];
    char bufferDni[2000];
    Cliente *bufferCliente;
    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferApellido,bufferDni);
            bufferCliente = cliente_newParametrosStr(bufferId,bufferNombre,bufferApellido,bufferDni);
            if(bufferCliente != NULL)
                ll_add(pArrayListCliente, bufferCliente);
        }
        retorno = 0;
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListCliente LinkedList*
 * \return int
 *
 */
int parser_VentaFromText(FILE* pFile , LinkedList* pArrayListVenta)
{
    int retorno = -1;
    char bufferIdVenta[2000];
    char bufferIdCliente[2000];
    char bufferCodigoProducto[2000];
    char bufferCantidad[2000];
    char bufferPrecioUnitario[2000];
    float pU;
    Venta *bufferVenta;
    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferIdVenta,bufferIdCliente,bufferCodigoProducto,bufferCantidad,bufferPrecioUnitario);
            bufferVenta = venta_newParametrosStr(bufferIdVenta,bufferIdCliente,bufferCodigoProducto,bufferCantidad,bufferPrecioUnitario);
            venta_getPrecioUnitario(bufferVenta, &pU);
            if(bufferVenta != NULL)
                ll_add(pArrayListVenta, bufferVenta);
        }
        retorno = 0;
    }
    return retorno;
}
