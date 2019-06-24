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

Venta* venta_newParametrosStr(char* idVenta,char* idCliente,char* codigoProducto, char* cantidad, char *precioUnitario)
{
    Venta* pVenta=venta_new();
    void *retorno = NULL;
    if( pVenta!=NULL &&
        idVenta != NULL &&
        idCliente != NULL &&
        codigoProducto != NULL &&
        cantidad != NULL &&
        precioUnitario != NULL)
    {
        if( !venta_setIdVentaStr(pVenta, idVenta)&&
            !venta_setIdClienteStr(pVenta,idCliente)&&
            !venta_setCodigoDeProductoStr(pVenta,codigoProducto)&&
            !venta_setCantidadStr(pVenta,cantidad) &&
            !venta_getPrecioUnitarioStr(pVenta, precioUnitario))
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

Venta* venta_newParametros(int idVenta,int idCliente,int codigoProducto, int cantidad, float precioUnitario)
{
    Venta* pVenta=venta_new();
    void *retorno = NULL;
    if( pVenta!=NULL &&
        idVenta > 0 &&
        idCliente > 0 &&
        codigoProducto > 0 &&
        cantidad > 0 &&
        precioUnitario > 0)
    {
        if( !venta_setIdVenta(pVenta, idVenta)&&
            !venta_setIdCliente(pVenta,idCliente)&&
            !venta_setCodigoDeProducto(pVenta,codigoProducto)&&
            !venta_setCantidad(pVenta,cantidad)&&
            !venta_setPrecioUnitario(pVenta, precioUnitario))
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

int venta_setIdCliente(Venta* this,int idCliente)
{
    int retorno = -1;
    if(this != NULL && idCliente >= 0)
    {
        this->idCliente = idCliente;
        retorno = 0;
    }
    return retorno;
}

int venta_getIdCliente(Venta* this,int* idCliente)
{
    int retorno = -1;
    if(this != NULL)
    {
        *idCliente = this->idCliente;
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

int venta_setPrecioUnitario(Venta* this,float precioUnitario)
{
    int retorno = -1;
    if(this != NULL && precioUnitario >= 0)
    {
        this->precioUnitario = precioUnitario;
        retorno = 0;
    }
    return retorno;
}

int venta_getPrecioUnitario(Venta* this,float* precioUnitario)
{
    int retorno = -1;
    if(this != NULL)
    {
        *precioUnitario = this->precioUnitario;
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
            retorno = venta_setIdVenta(this,atoi(idStr));
        }
    return retorno;
}
int venta_getIdVentaStr(Venta* this, char* result)
{
    int retorno = -1;
    int bufferInt;

    if(this != NULL && result != NULL)
    {
        venta_getIdVenta(this,&bufferInt);
        sprintf(result,"%d",bufferInt);
        retorno = 0;
    }
    return retorno;
}

int venta_setIdClienteStr(Venta* this, char* idStr)
{
    int retorno = -1;
    if(this != NULL && idStr != NULL)
        if(isValidNumber(idStr))
        {
            retorno = venta_setIdCliente(this,atoi(idStr));
        }
    return retorno;
}

int venta_getIdClienteStr(Venta* this, char* result)
{
    int retorno = -1;
    int bufferInt;

    if(this != NULL && result != NULL)
    {
        venta_getIdCliente(this,&bufferInt);
        sprintf(result,"%d",bufferInt);
        retorno = 0;
    }
    return retorno;
}

int venta_setCodigoDeProductoStr(Venta* this, char* codigoProducto)
{
    int retorno = -1;
    if(this != NULL && codigoProducto != NULL)
        if(isValidNumber(codigoProducto))
        {
            retorno = venta_setCodigoDeProducto(this,atoi(codigoProducto));
        }
    return retorno;
}

int venta_getCodigoDeProductoStr(Venta* this, char* result)
{
    int retorno = -1;
    int bufferInt;

    if(this != NULL && result != NULL)
    {
        venta_getCodigoDeProducto(this,&bufferInt);
        sprintf(result,"%d",bufferInt);
        retorno = 0;
    }
    return retorno;
}


int venta_setCantidadStr(Venta* this, char* cantidad)
{
    int retorno = -1;
    if(this != NULL && cantidad != NULL)
        if(isValidNumber(cantidad))
        {
            retorno = venta_setCantidad(this,atoi(cantidad));
        }
    return retorno;
}

int venta_getCantidadStr(Venta* this, char* result)
{
    int retorno = -1;
    int bufferInt;

    if(this != NULL && result != NULL)
    {
        venta_getCantidad(this,&bufferInt);
        sprintf(result,"%d",bufferInt);
        retorno = 0;
    }
    return retorno;
}

int venta_setprecioUnitarioStr(Venta* this, char* precioUnitario)
{
    int retorno = -1;
    if(this != NULL && precioUnitario != NULL)
        if(isValidFloatNumber(precioUnitario))
        {
            retorno = venta_setCantidad(this,atof(precioUnitario));
        }
    return retorno;
}

int venta_getPrecioUnitarioStr(Venta* this, char* result)
{
    int retorno = -1;
    float bufferInt;

    if(this != NULL && result != NULL)
    {
        venta_getPrecioUnitario(this,&bufferInt);
        sprintf(result,"%f",bufferInt);
        retorno = 0;
    }
    return retorno;
}

int findVentaById(LinkedList* pArrayListVenta, int id, int *posicionId)
{
    int retorno = -1;
    int i;
    int idAux;
    Venta *pVenta;
    if(pArrayListVenta != NULL && id > 0 && posicionId > 0)
    {
        for(i = 0; i < ll_len(pArrayListVenta); i++)
        {
            pVenta = ll_get(pArrayListVenta, i);
            if(pVenta != NULL)
            {
                venta_getIdVenta(pVenta, &idAux);
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

float precioPorCantidad (int codigoProducto, int cantidad)
{
    float retorno = 0;
    switch(codigoProducto)
    {
        case 1000:
            retorno =(float) 8999.99*cantidad;
            break;
        case 1001:
            retorno =(float) 12999.99*cantidad;
            break;
        case 1002:
            retorno =(float) 19480.99*cantidad;
            break;
    }
    return retorno;
}

float precioUnitario (int codigoProducto)
{
    float retorno = 0;
    switch(codigoProducto)
    {
        case 1000:
            retorno =(float) 8999.99;
            break;
        case 1001:
            retorno =(float) 12999.99;
            break;
        case 1002:
            retorno =(float) 19480.99;
            break;
    }
    return retorno;
}

