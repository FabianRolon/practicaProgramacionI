#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    char bufferId[2000];
    char bufferNombre[2000];
    char bufferHorasTrabajadas[2000];
    char bufferSueldo[2000];
    Employee *bufferEmp;
 //   int bufferId2, bufferSueldo2, bufferHoras;

    pFile = NULL;                         /// hacer esto siempre. Siempre abro,utilizo y  cierro el archivo en el momento que lo uso xq se puede estar actualizando en ese momento y esa info no la puedo ver
    //FILE *pFileBkp = NULL;                          ///para escribir en el archivo

    pFile = fopen("data.csv","r");               ///apertura de archivo.Primer parametro le indico la ruta de donde esta el archivo,segundo parametro es el modo de apertura (lectura"R"-escritura"W"(sobre escribe lo q tiene)-
    //pFile =fopen("data.csv","w");///Para esribir                                                    si el archivo no se puede abrir me devuelve NULL

    if(pFile!=NULL)
    {

        while(!feof(pFile))                         ///Esta funcion me dice Verdadero cuando se termina el archivo,entonces lo niego para q lea hasta el final
        {

            //fscanf(pFile,"%s",bufferStr);///para leer UNA linea.
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);               ///Asi se crea una mascara,q va a guardar todo lo q encuentra mientras no sea una "," hasta el buffer
            bufferEmp = employee_newParametros(bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
            /*employee_getNombre(bufferEmp, bufferNombre);
            employee_getIdString(bufferEmp, bufferId);
            employee_getHorasTrabajadasStr(bufferEmp, bufferHorasTrabajadas);
            employee_getSueldoStr(bufferEmp, bufferSueldo);
            printf("%s %s %s %s\n", bufferNombre, bufferId, bufferHorasTrabajadas, bufferSueldo);*/
            ll_add(pArrayListEmployee, bufferEmp);                                                                   ///La coma en la mascara le indica q tiene q pasar al siguiente lugar
            //printf("%s %s %s %s\n",bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);                                        ///Imprimo lo que leyo de esa linea
            //fprintf(pFile,"%s\n",bufferStr); ///para mostrar lo q escribi





        }
        fclose(pFile);///Cierro
       // fclose(pFileBkp);
        retorno = 0;

    }

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{


    return 1;
}
