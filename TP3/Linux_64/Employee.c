#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "utn_strings.h"

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
    if(emp!=NULL &&
        idStr)
    {
        employee_setIdString(emp, idStr);
        employee_setNombre(emp,nombreStr);
        employee_setHorasTrabajadasStr(emp,horasTrabajadasStr);
        employee_setSueldoStr(emp,sueldo);
    }


    return emp;
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
    if(this != NULL && idStr != NULL && (!isNumber(idStr)))
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
    if(this != NULL && horasTrabajadas != NULL && (!isNumber(horasTrabajadas)))
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
    if(this != NULL && sueldo != NULL && (!isNumber(sueldo)))
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


