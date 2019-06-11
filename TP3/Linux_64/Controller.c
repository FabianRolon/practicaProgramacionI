#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"
#include "utn.h"
#define MAX_EMPLOYEE 9999

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
                printf("\nCarga exitosa\n");
                fclose(pFile);
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
    int retorno = -1;
    Employee aEmployee;
    Employee *pEmployee = employee_new();
    FILE* pFile;
    pFile = NULL;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path,"rb");
        if(pFile!=NULL)
        {
            while(!feof(pFile))
            {
                fread(&aEmployee, sizeof(Employee), 1, pFile);

                pEmployee = employee_newParametrosInt(aEmployee.id, aEmployee.nombre,aEmployee.horasTrabajadas,aEmployee.sueldo);
                if(pEmployee != NULL)
                {
                    ll_add(pArrayListEmployee, pEmployee);
                }
                else
                {
                    employee_delete(pEmployee);
                }
            }
            fclose(pFile);

            printf("\nCarga exitosa\n");
            retorno = 0;
        }
    }
     return retorno;
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
                printf("Exito, empleado agregado!\n");
                retorno = 0;
            }else
            {
                printf("ERROR, reintentos agotados!\n");
                retorno = -2;
            }
        }else
        {
            printf("ERROR, NULL\n");
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
    int retorno = -1;
    int idIngresado;
    int posicionId;
    Employee *pEmployee;
    if (pArrayListEmployee != NULL)
    {
        if( !utn_getUnsignedInt("\nIngrese el ID de empleado a dar de baja: ",
            "\nError, ID inválido.",1,MAX_EMPLOYEE, 2, &idIngresado))
            {
                if( findEmployeeById(pArrayListEmployee,
                    idIngresado,
                    &posicionId) ==0 )
                    {
                        pEmployee = ll_pop(pArrayListEmployee, posicionId);
                        if(pEmployee != NULL)
                        {
                            employee_delete(pEmployee);
                            printf("\n¡Empleado borrado exitosamente!\n\n");
                            retorno = 0;
                        }
                    }
                    else
                    {
                        printf("\nNo se encontró el ID\n\n");
                        retorno = -2;
                    }
            }
            else
            {
                printf("\nReintentos agotados\n\n");
                retorno = -3;
            }
    }

    return retorno;
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
    char option = 'n';
    Employee *empleado;
    char bufferNombre[1000];
    int bufferId, bufferSueldo, bufferHoras;

    do
    {
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
        utn_getChar("\n\tPresione 's' para volver al menu principal: ",
                    "Error, vuelva a intentar",1,2,2,&option);
    }while(option == 'n');
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
    int retorno = -1;
    FILE* pFile = NULL;
    Employee * pEmployee = NULL;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "wb"); //wb modo de escritura en modo binario
        if(pFile != NULL)
        {
            for(int i =0 ; i<ll_len(pArrayListEmployee) ; i++)
            {
                pEmployee = ll_get(pArrayListEmployee, i);//devuelve puntero a empleado
                if(pEmployee != NULL)
                    fwrite(pEmployee, sizeof(Employee), 1, pFile);//pEmployee es lo apuntado por el puntero, su contenido.
            }
            fclose(pFile);
            retorno = 0;
        }
    }
    return retorno;
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
void Controller_printMenu()
{
    printf("\t\t*MENU*");
    printf("\n\n1-Cargar los datos de los empleados desde el archivo data.csv (modo texto).");
    printf("\n\n2-Cargar los datos de los empleados desde el archivo data.csv (modo binario)");
    printf("\n\n3-Alta de empleado");
    printf("\n\n4-Modificar datos de empleado");
    printf("\n\n5-Baja de empleado");
    printf("\n\n6-Listar empleados");
    printf("\n\n7-Ordenar empleados");
    printf("\n\n8-Guardar los datos de los empleados en el archivo data.csv (modo texto)");
    printf("\n\n9-Guardar los datos de los empleados en el archivo data.csv (modo binario)");
    printf("\n\n10-Salir\n");
}
