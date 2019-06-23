#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"
#include "venta.h"

Venta* venta_new()
{
    return (Venta*) malloc(sizeof(Venta));
}

void venta_delete(Venta *this)
{
    if(this != NULL)
    {
        free(this);
    }
}

Venta* venta_newParametrosStr(char* idVenta,char* idCliente,char* codigoProducto, char* cantidad)
{
    Venta* pVenta=venta_new();
    void *retorno = NULL;
    if( pVenta!=NULL &&
        idVenta != NULL &&
        idCliente != NULL &&
        codigoProducto != NULL &&
        cantidad != NULL)
    {
        if( !venta_setIdVenta(pVenta, idVenta)&&
            !venta_setIdCliente(pVenta,idCliente)&&
            !venta_setCodigoDeProducto(pVenta,codigoProducto)&&
            !venta_setCantidad(pVenta,cantidad))
            {
                retorno = pVenta;
            }
            else
            {
                venta_delete(pVenta);
            }
    }
    return retorno;
}

int venta_setIdVenta(Venta* this,int idVenta)
{
    int retorno = -1;
    if(this != NULL && idVenta >= 0)
    {
        this->idVenta = idVenta;
        retorno = 0;
    }
    return retorno;
}

int venta_getIdVenta(Venta* this,int* idVenta)
{
    int retorno = -1;
    if(this != NULL)
    {
        *idVenta = this->idVenta;
        retorno = 0;
    }
    return retorno;
}

int venta_setIdVenta(Venta* this,int idVenta)
{
    int retorno = -1;
    if(this != NULL && idVenta >= 0)
    {
        this->idVenta = idVenta;
        retorno = 0;
    }
    return retorno;
}

int venta_getIdVenta(Venta* this,int* idVenta)
{
    int retorno = -1;
    if(this != NULL)
    {
        *idVenta = this->idVenta;
        retorno = 0;
    }
    return retorno;
}

int venta_setCodigoDeProducto(Venta* this,int codigoProducto)
{
    int retorno = -1;
    if(this != NULL && codigoProducto >= 0)
    {
        this->codigoDeProducto = codigoProducto;
        retorno = 0;
    }
    return retorno;
}

int venta_getCodigoDeProducto(Venta* this,int* codigoProducto)
{
    int retorno = -1;
    if(this != NULL)
    {
        *codigoProducto = this->codigoDeProducto;
        retorno = 0;
    }
    return retorno;
}

int venta_setCantidad(Venta* this,int cantidad)
{
    int retorno = -1;
    if(this != NULL && cantidad >= 0)
    {
        this->cantidad = cantidad;
        retorno = 0;
    }
    return retorno;
}

int venta_getCantidad(Venta* this,int* cantidad)
{
    int retorno = -1;
    if(this != NULL)
    {
        *cantidad = this->cantidad;
        retorno = 0;
    }
    return retorno;
}

int venta_setIdVentaStr(Venta* this, char* idStr)
{
    int retorno = -1;
    if(this != NULL && idStr != NULL)
        if(isValidNumber(idStr))
        {
            retorno = venta_setId(this,atoi(idStr));
        }
    return retorno;
}
int venta_getIdVentaStr(Venta* this, char* result)
{
    int retorno = -1;
    int bufferInt;

    if(this != NULL && result != NULL)
    {
        venta_getId(this,&bufferInt);
        sprintf(result,"%d",bufferInt);
        retorno = 0;
    }
    return retorno;
}


