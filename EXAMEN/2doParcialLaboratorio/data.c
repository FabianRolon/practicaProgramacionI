#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "data.h"
#include "utn.h"
#define MAX 1000

Data* data_new()
{
    return (Data*) malloc(sizeof(Data));
}

void data_delete(Data *this)
{
    if(this != NULL)
    {
        free(this);
    }
}

Data* data_newParametrosStr(char* idStr,char* tipoStr,char* cantidadStr, char* importeStr)
{
    Data* pData=data_new();
    void *retorno = NULL;
    if( pData!=NULL &&
        idStr != NULL &&
        tipoStr != NULL &&
        cantidadStr != NULL &&
        importeStr != NULL)
    {
        if( !data_setIdString(pData, idStr)&&
            !data_setTipo(pData,tipoStr)&&
            !data_setCantidadStr(pData,cantidadStr)&&
            !data_setImporteStr(pData,importeStr))
            {
                retorno = pData;
            }
            else
            {
                data_delete(pData);
            }
    }
    return retorno;
}

Data* data_newParametros(int id, char* tipo,int cantidad, int importe)
{
    void *retorno = NULL;
    Data* pData = data_new();
    if( pData!=NULL &&
        id > 0 &&
        tipo != NULL &&
        cantidad > 0 &&
        importe > 0)
    {
        if( !data_setId(pData, id) &&
            !data_setTipo(pData,tipo) &&
            !data_setCantidad(pData,cantidad) &&
            !data_setImporte(pData,importe))
        {
            retorno = pData;
        }
        else
        {
            data_delete(pData);
        }
    }
    return retorno;
}

int data_setId(Data* this,int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int data_getId(Data* this,int* id)
{
    int retorno = -1;
    if(this != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}

int data_setTipo(Data* this,char* tipo)
{
    int retorno = -1;
    if(this != NULL && isLetter(tipo))
    {
        strncpy(this->tipo,tipo,sizeof(this->tipo));
        retorno = 0;
    }
    return retorno;
}
int data_getTipo(Data* this,char* tipo)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(tipo,this->tipo,sizeof(this->tipo));
        retorno = 0;
    }
    return retorno;
}

int data_setCantidad(Data* this,int cantidad)
{
    int retorno = -1;
    if(this != NULL && cantidad >= 0)
    {
        this->cantidad = cantidad;
        retorno = 0;
    }
    return retorno;
}

int data_getCantidad(Data* this,int* cantidad)
{
    int retorno = -1;
    if(this != NULL)
    {
        *cantidad = this->cantidad;
        retorno = 0;
    }
    return retorno;
}

int data_setImporte(Data* this, float importe)
{
    int retorno = -1;
    if(this != NULL && importe >= 0)
    {
        this->importe = importe;
        retorno = 0;
    }
    return retorno;
}
int data_getImporte(Data* this, float* importe)
{
    int retorno = -1;
    if(this != NULL)
    {
        *importe = this->importe;
        retorno = 0;
    }
    return retorno;
}

int data_setIdString(Data* this, char* idStr)
{
    int retorno = -1;
    if(this != NULL && idStr != NULL)
        if(isValidNumber(idStr))
        {
            retorno = data_setId(this,atoi(idStr));
        }
    return retorno;
}
int data_getIdString(Data* this, char* result)
{
    int retorno = -1;
    int bufferInt;

    if(this != NULL && result != NULL)
    {
        data_getId(this,&bufferInt);
        sprintf(result,"%d",bufferInt);
        retorno = 0;
    }
    return retorno;
}

int data_setCantidadStr(Data* this,char* cantidad)
{
    int retorno = -1;
    if(this != NULL && cantidad != NULL && (isValidNumber(cantidad)))
    {

        retorno = data_setCantidad(this,atoi(cantidad));
    }
    return retorno;
}

int data_getCantidadStr(Data* this,char* result)
{
    int retorno = -1;
    int bufferInt;

    if(this != NULL && result != NULL)
    {
        data_getCantidad(this,&bufferInt);
        sprintf(result,"%d",bufferInt);
        retorno = 0;
    }
    return retorno;
}

int data_setImporteStr(Data* this,char *importeStr)
{
    int retorno = -1;
    if(this != NULL && importeStr != NULL && (isValidFloatNumber(importeStr)))
    {
        retorno = data_setImporte(this,atof(importeStr));
    }
    return retorno;
}
int data_getImporteStr(Data* this,char* result)
{
    int retorno = -1;
    float bufferInt;

    if(this != NULL && result != NULL)
    {
        data_getImporte(this,&bufferInt);
        sprintf(result,"%f",bufferInt);
        retorno = 0;
    }
    return retorno;
}

int data_GOLD(void* pData)
{
    int retorno = 0;
    char auxTipo[MAX];

    if(pData != NULL)
    {
        data_getTipo(((Data*)pData),auxTipo);
        if(!strcmp("GOLD", auxTipo))
        {
            retorno = 1;
        }
    }
    return retorno;
}

int data_REGULAR(void* pData)
{
    int retorno = 0;
    char auxTipo[MAX];

    if(pData != NULL)
    {
        data_getTipo(((Data*)pData),auxTipo);
        if(!strcmp("REGULAR", auxTipo))
        {
            retorno = 1;
        }
    }
    return retorno;
}

int data_PLUS(void* pData)
{
    int retorno = 0;
    char auxTipo[MAX];

    if(pData != NULL)
    {
        data_getTipo(((Data*)pData),auxTipo);
        if(!strcmp("PLUS", auxTipo))
        {
            retorno = 1;
        }
    }
    return retorno;
}
