#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"
#include "utn.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    FILE* pFile;
    pFile = NULL;
    pFile = fopen(path,"r");

    if(pFile!=NULL)
    {
        if(path != NULL && pArrayListEmployee != NULL)
        {
             if(!parser_EmployeeFromText(pFile , pArrayListEmployee))
             {
                retorno = 0;
             }
        }
     }
     return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int idAux;
    char bufferId[1000];
    char bufferNombre[1000];
    char bufferHorasTrabajadas[1000];
    char bufferSueldo[1000];
    Employee *bufferEmp;
    idAux = controller_nextId(pArrayListEmployee);
    snprintf(bufferId,1000, "%d", idAux);

    if (pArrayListEmployee != NULL)
        {
            if( utn_getName("\n\nIngrese el nombre del empleado: ",
                "Error, vuelva a ingresar\n\n",1,50,2, bufferNombre) == 0 &&
                utn_getAlfanumerico("\n\nIngrese las horas trabajadas: ",
                "Error, vuelva a ingresar\n\n",1,51,2,bufferHorasTrabajadas) == 0 &&
                utn_getAlfanumerico("\n\nIngrese el sueldo: ",
                "Error, vuelva a ingresar\n\n",1,51,2,bufferSueldo) == 0)
            {
                bufferEmp = employee_newParametros(bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
                ll_add(pArrayListEmployee, bufferEmp);
                retorno = 1;
            }else
            {
                printf("ERROR1!\n");
            }
        }else
        {
            printf("ERROR2!\n");
        }


    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    Employee *empleado;
    char bufferNombre[1000];
    int bufferId, bufferSueldo, bufferHoras;

    for(i = 0; i < ll_len(pArrayListEmployee); i++)
    {
        empleado = (Employee*)ll_get(pArrayListEmployee, i);
        employee_getNombre(empleado, bufferNombre);
        employee_getId(empleado, &bufferId);
        employee_getHorasTrabajadas(empleado,&bufferHoras);
        employee_getSueldo(empleado, &bufferSueldo);
        printf("Nombre : %s Id: %d Horas: %d Sueldo: %d\n", bufferNombre, bufferId, bufferHoras, bufferSueldo );
    }
    controller_nextId(pArrayListEmployee);
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}


int controller_nextId(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    int idAux;
    int idMax;
    Employee *pEmployee;
    if(pArrayListEmployee != NULL)
    {
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            pEmployee = (Employee*)ll_get(pArrayListEmployee, i);
            if(i == 0)
            {
                employee_getId(pEmployee, &idMax);
            }
            else
            {
                employee_getId(pEmployee, &idAux);
                if(idAux > idMax)
                {
                    idMax = idAux;

                }
            }
        }
        retorno = idMax+1;
    }
    return retorno;
}
