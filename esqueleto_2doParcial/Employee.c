#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"

Entidad* entidad_new()
{
    return (Entidad*) malloc(sizeof(Entidad));
}

void entidad_delete(Entidad *this)
{
    if(this != NULL)
    {
        free(this);
    }
}

Entidad* entidad_newParametrosStr(char* idStr,char* stringStr,char* valorEnteroStr, char* ValorFloatStr)
{
    Entidad* pEntidad=entidad_new();
    void *retorno = NULL;
    if( pEntidad!=NULL &&
        idStr != NULL &&
        stringStr != NULL &&
        valorEnteroStr != NULL &&
        ValorFloatStr != NULL)
    {
        if( !entidad_setIdString(pEntidad, idStr)&&
            !entidad_setString(pEntidad,stringStr)&&
            !entidad_setValorEnteroStr(pEntidad,valorEnteroStr)&&
            !entidad_setValorFloatStr(pEntidad,ValorFloatStr))
            {
                retorno = pEntidad;
            }
            else
            {
                entidad_delete(pEntidad);
            }
    }
    return retorno;
}

Entidad* entidad_newParametros(int id, char* stringStr,int valorEntero, int valorFloat)
{
    void *retorno = NULL;
    Entidad* pEntidad = entidad_new();
    if( pEntidad!=NULL &&
        id > 0 &&
        stringStr != NULL &&
        valorEntero > 0 &&
        valorFloat > 0)
    {
        if( !entidad_setId(pEntidad, id) &&
            !entidad_setString(pEntidad,stringStr) &&
            !entidad_setValorEntero(pEntidad,valorEntero) &&
            !entidad_setValorFloat(pEntidad,valorFloat))
        {
            retorno = pEntidad;
        }
        else
        {
            entidad_delete(pEntidad);
        }
    }
    return retorno;
}

int entidad_setId(Entidad* this,int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int entidad_getId(Entidad* this,int* id)
{
    int retorno = -1;
    if(this != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}

int entidad_setString(Entidad* this,char* string)
{
    int retorno = -1;
    if(this != NULL && isLetter(string))
    {
        strncpy(this->string,string,sizeof(this->string));
        retorno = 0;
    }
    return retorno;
}
int entidad_getString(Entidad* this,char* string)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(string,this->string,sizeof(this->string));
        retorno = 0;
    }
    return retorno;
}

int entidad_setValorEntero(Entidad* this,int valorEntero)
{
    int retorno = -1;
    if(this != NULL && valorEntero >= 0)
    {
        this->valorEntero = valorEntero;
        retorno = 0;
    }
    return retorno;
}

int entidad_getValorEntero(Entidad* this,int* valorEntero)
{
    int retorno = -1;
    if(this != NULL)
    {
        *valorEntero = this->valorEntero;
        retorno = 0;
    }
    return retorno;
}

int entidad_setValorFloat(Entidad* this, float ValorFloatStr)
{
    int retorno = -1;
    if(this != NULL && ValorFloatStr >= 0)
    {
        this->valorFloat = ValorFloatStr;
        retorno = 0;
    }
    return retorno;
}
int entidad_getValorFloat(Entidad* this, float* ValorFloatStr)
{
    int retorno = -1;
    if(this != NULL)
    {
        *ValorFloatStr = this->valorFloat;
        retorno = 0;
    }
    return retorno;
}

int entidad_setIdString(Entidad* this, char* idStr)
{
    int retorno = -1;
    if(this != NULL && idStr != NULL)
        if(isValidNumber(idStr))
        {
            retorno = entidad_setId(this,atoi(idStr));
        }
    return retorno;
}
int entidad_getIdString(Entidad* this, char* result)
{
    int retorno = -1;
    int bufferInt;

    if(this != NULL && result != NULL)
    {
        entidad_getId(this,&bufferInt);
        sprintf(result,"%d",bufferInt);
        retorno = 0;
    }
    return retorno;
}

int entidad_setValorEnteroStr(Entidad* this,char* valorEntero)
{
    int retorno = -1;
    if(this != NULL && valorEntero != NULL && (isValidNumber(valorEntero)))
    {

        retorno = entidad_setValorEntero(this,atoi(valorEntero));
    }
    return retorno;
}

int entidad_getValorEnteroStr(Entidad* this,char* result)
{
    int retorno = -1;
    int bufferInt;

    if(this != NULL && result != NULL)
    {
        entidad_getValorEntero(this,&bufferInt);
        sprintf(result,"%d",bufferInt);
        retorno = 0;
    }
    return retorno;
}

int entidad_setValorFloatStr(Entidad* this,char *ValorFloatStr)
{
    int retorno = -1;
    if(this != NULL && ValorFloatStr != NULL && (isValidFloatNumber(ValorFloatStr)))
    {
        retorno = entidad_setValorFloat(this,atof(ValorFloatStr));
    }
    return retorno;
}
int entidad_getValorFloatStr(Entidad* this,char* result)
{
    int retorno = -1;
    float bufferInt;

    if(this != NULL && result != NULL)
    {
        entidad_getValorFloat(this,&bufferInt);
        sprintf(result,"%f",bufferInt);
        retorno = 0;
    }
    return retorno;
}
int findEntidadById(LinkedList* pArrayListEntidad, int id, int *posicionId)
{
    int retorno = -1;
    int i;
    int idAux;
    Entidad *pEntidad;
    if(pArrayListEntidad != NULL && id > 0 && posicionId > 0)
    {
        for(i = 0; i < ll_len(pArrayListEntidad); i++)
        {
            pEntidad = ll_get(pArrayListEntidad, i);
            if(pEntidad != NULL)
            {
                entidad_getId(pEntidad, &idAux);
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

int entidad_compare(void* this1, void* this2)
{
    int retorno;
    int auxCmp;
    char stringUno[1000];
    char stringDos[1000];
    if( !entidad_getString((Entidad*)this1,stringUno)&&
        !entidad_getString((Entidad*)this2,stringDos))
        {
            auxCmp = strcmp(stringUno,stringDos);
            if(auxCmp < 0)
            {
                retorno = -1;
            }
            if(!auxCmp)
            {
                retorno = 0;
            }
            if(auxCmp > 0)
            {
                retorno = 1;
            }
        }
    return retorno;
}

int entidad_salary(void* pEntidad)
{
    int retorno = 0;
    if(pEntidad != NULL)
    {
        if(((Entidad*)pEntidad)->valorFloat >= 6000)
        {
            retorno = 1;
        }
    }
    return retorno;
}

int entidad_horas(void* pEntidad)
{
    int retorno = 0;
    if(pEntidad != NULL)
    {
        if(((Entidad*)pEntidad)->valorEntero >= 300)
        {
            retorno = 1;
        }
    }
    return retorno;
}
