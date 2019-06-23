#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "cliente.h"

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
int parser_ClienteFromBinary(FILE* pFile , LinkedList* pArrayListCliente)
{
    int retorno = -1;
    Cliente aCliente;
    Cliente *pCliente = cliente_new();
    if(pArrayListCliente != NULL)
    {
        if(pFile!=NULL)
        {
            while(!feof(pFile))
            {
                pCliente = cliente_newParametros(aCliente.id,
                                                    aCliente.nombre,
                                                    aCliente.apellido,
                                                    aCliente.dni);
                fread(&aCliente, sizeof(Cliente), 1, pFile);
                if(pCliente != NULL)
                {
                    ll_add(pArrayListCliente, pCliente);
                }
                else
                {
                    cliente_delete(pCliente);
                }
            }
            fclose(pFile);

            printf("\nCarga exitosa\n");
            retorno = 0;
        }
    }
     return retorno;
}
