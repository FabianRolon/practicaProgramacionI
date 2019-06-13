#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"

Employee* employee_new()
{
    return (Employee*) malloc(sizeof(Employee));
}

void employee_delete(Employee *this)
{

    if(this != NULL)
    {
        free(this);
    }
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo)
{
    Employee* emp=employee_new();
    if( emp!=NULL &&
        idStr != NULL &&
        nombreStr != NULL &&
        horasTrabajadasStr != NULL &&
        sueldo != NULL)
    {
        employee_setIdString(emp, idStr);
        employee_setNombre(emp,nombreStr);
        employee_setHorasTrabajadasStr(emp,horasTrabajadasStr);
        employee_setSueldoStr(emp,sueldo);
    }


    return emp;
}

Employee* employee_newParametrosInt(int id, char* nombreStr,int horasTrabajadas, int sueldo)
{
    Employee *retorno = NULL;
    Employee* pEmployee = employee_new();
    if( pEmployee!=NULL &&
        id > 0 &&
        nombreStr != NULL &&
        horasTrabajadas > 0 &&
        sueldo > 0)
    {
        if( !employee_setId(pEmployee, id) &&
            !employee_setNombre(pEmployee,nombreStr) &&
            !employee_setHorasTrabajadas(pEmployee,horasTrabajadas) &&
            !employee_setSueldo(pEmployee,sueldo))
        {
            retorno = pEmployee;
        }
        else
        {
            employee_delete(pEmployee);
        }
    }
    return retorno;
}
int employee_setId(Employee* this,int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno = -1;
    if(this != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL && isLetter(nombre))
    {
        strncpy(this->nombre,nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(nombre,this->nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas >= 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo >= 0)
    {
        this->sueldo = sueldo;
        retorno = 0;
    }
    return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = -1;
    if(this != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 0;
    }
    return retorno;
}

int employee_setIdString(Employee* this, char* idStr)
{
    int retorno = -1;
    if(this != NULL && idStr != NULL && (isValidNumber(idStr)))
    {
        retorno = employee_setId(this,atoi(idStr));///si salio bien retorna 0 sino -1
    }
    return retorno;
}
int employee_getIdString(Employee* this, char* result)
{
    int retorno = -1;
    int bufferInt;

    if(this != NULL && result != NULL)
    {
        employee_getId(this,&bufferInt);
        sprintf(result,"%d",bufferInt);
        retorno = 0;
    }
    return retorno;
}

int employee_setHorasTrabajadasStr(Employee* this,char* horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas != NULL && (isValidNumber(horasTrabajadas)))
    {

        retorno = employee_setHorasTrabajadas(this,atoi(horasTrabajadas));///si salio bien retorna 0 sino -1
    }
    return retorno;
}

int employee_getHorasTrabajadasStr(Employee* this,char* result)
{
    int retorno = -1;
    int bufferInt;

    if(this != NULL && result != NULL)
    {
        employee_getHorasTrabajadas(this,&bufferInt);
        sprintf(result,"%d",bufferInt);
        retorno = 0;
    }
    return retorno;
}

int employee_setSueldoStr(Employee* this,char *sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo != NULL && (isValidNumber(sueldo)))
    {

        retorno = employee_setSueldo(this,atoi(sueldo));///si salio bien retorna 0 sino -1
    }
    return retorno;
}
int employee_getSueldoStr(Employee* this,char* result)
{
    int retorno = -1;
    int bufferInt;

    if(this != NULL && result != NULL)
    {
        employee_getSueldo(this,&bufferInt);
        sprintf(result,"%d",bufferInt);
        retorno = 0;
    }
    return retorno;
}
int findEmployeeById(LinkedList* pArrayListEmployee, int id, int *posicionId)
{
    int retorno = -1;
    int i;
    int idAux;
    Employee *pEmployee;
    if(pArrayListEmployee != NULL && id > 0 && posicionId > 0)
    {
        for(i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            pEmployee = ll_get(pArrayListEmployee, i);
            if(pEmployee != NULL)
            {
                employee_getId(pEmployee, &idAux);
                if(id == idAux)
                {
                    *posicionId = i;
                    retorno = 0;
                }
            }
        }
    }
    return retorno;
}

