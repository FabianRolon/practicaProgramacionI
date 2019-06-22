#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEntidad LinkedList*
 * \return int
 *
 */
int parser_EntidadFromText(FILE* pFile , LinkedList* pArrayListEntidad)
{
    int retorno = -1;
    char bufferId[2000];
    char bufferString[2000];
    char bufferValorEntero[2000];
    char bufferValorFloat[2000];
    Entidad *bufferEnt;
    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferString,bufferValorEntero,bufferValorFloat);
            bufferEnt = entidad_newParametrosStr(bufferId,bufferString,bufferValorEntero,bufferValorFloat);
            if(bufferEnt != NULL)
                ll_add(pArrayListEntidad, bufferEnt);
        }
        retorno = 0;
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEntidad LinkedList*
 * \return int
 *
 */
int parser_EntidadFromBinary(FILE* pFile , LinkedList* pArrayListEntidad)
{
    int retorno = -1;
    Entidad aEntidad;
    Entidad *pEntidad = entidad_new();
    if(pArrayListEntidad != NULL)
    {
        if(pFile!=NULL)
        {
            while(!feof(pFile))
            {
                pEntidad = entidad_newParametros(   aEntidad.id,
                                                    aEntidad.string,
                                                    aEntidad.valorEntero,
                                                    aEntidad.valorFloat);
                fread(&aEntidad, sizeof(Entidad), 1, pFile);
                if(pEntidad != NULL)
                {
                    ll_add(pArrayListEntidad, pEntidad);
                }
                else
                {
                    entidad_delete(pEntidad);
                }
            }
            fclose(pFile);

            printf("\nCarga exitosa\n");
            retorno = 0;
        }
    }
     return retorno;
}
