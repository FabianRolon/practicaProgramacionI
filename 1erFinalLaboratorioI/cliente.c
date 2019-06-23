#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "cliente.h"
#include "utn.h"

Cliente* cliente_new()
{
    return (Cliente*) malloc(sizeof(Cliente));
}

void cliente_delete(Cliente *this)
{
    if(this != NULL)
    {
        free(this);
    }
}

Cliente* cliente_newParametrosStr(char* idStr,char* nombre,char* apellido, char* dni)
{
    Cliente* pCliente=cliente_new();
    void *retorno = NULL;
    if( pCliente!=NULL &&
        idStr != NULL &&
        nombre != NULL &&
        apellido != NULL &&
        dni != NULL)
    {
        if( !cliente_setIdString(pCliente, idStr)&&
            !cliente_setNombre(pCliente,nombre)&&
            !cliente_setApellido(pCliente,apellido)&&
            !cliente_setDni(pCliente,dni))
            {
                retorno = pCliente;
            }
            else
            {
                cliente_delete(pCliente);
            }
    }
    return retorno;
}

Cliente* cliente_newParametros(int id, char* nombre,char* apellido, char* dni)
{
    void *retorno = NULL;
    Cliente* pCliente = cliente_new();
    if( pCliente!=NULL &&
        id > 0 &&
        nombre != NULL &&
        apellido > 0 &&
        dni > 0)
    {
        if( !cliente_setId(pCliente, id) &&
            !cliente_setNombre(pCliente,nombre) &&
            !cliente_setApellido(pCliente,apellido) &&
            !cliente_setDni(pCliente,dni))
        {
            retorno = pCliente;
        }
        else
        {
            cliente_delete(pCliente);
        }
    }
    return retorno;
}

int cliente_setId(Cliente* this,int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int cliente_getId(Cliente* this,int* id)
{
    int retorno = -1;
    if(this != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}

int cliente_setNombre(Cliente* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL && isLetter(nombre))
    {
        strncpy(this->nombre,nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int cliente_getNombre(Cliente* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(nombre,this->nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int cliente_setApellido(Cliente* this,char* apellido)
{
    int retorno = -1;
    if(this != NULL && isLetter(apellido))
    {
        strncpy(this->apellido,apellido,sizeof(this->apellido));
        retorno = 0;
    }
    return retorno;
}
int cliente_getApellido(Cliente* this,char* apellido)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(apellido,this->apellido,sizeof(this->apellido));
        retorno = 0;
    }
    return retorno;
}

int cliente_setDni(Cliente* this,char* dni)
{
    int retorno = -1;
    if(this != NULL && isValidDNI(dni))
    {
        strncpy(this->dni,dni,sizeof(this->dni));
        retorno = 0;
    }
    return retorno;
}

int cliente_getDni(Cliente* this,char* dni)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(dni,this->dni,sizeof(this->dni));
        retorno = 0;
    }
    return retorno;
}

int cliente_setIdString(Cliente* this, char* idStr)
{
    int retorno = -1;
    if(this != NULL && idStr != NULL)
        if(isValidNumber(idStr))
        {
            retorno = cliente_setId(this,atoi(idStr));
        }
    return retorno;
}
int cliente_getIdString(Cliente* this, char* result)
{
    int retorno = -1;
    int bufferInt;

    if(this != NULL && result != NULL)
    {
        cliente_getId(this,&bufferInt);
        sprintf(result,"%d",bufferInt);
        retorno = 0;
    }
    return retorno;
}

int findClienteById(LinkedList* pArrayListCliente, int id, int *posicionId)
{
    int retorno = -1;
    int i;
    int idAux;
    Cliente *pCliente;
    if(pArrayListCliente != NULL && id > 0 && posicionId > 0)
    {
        for(i = 0; i < ll_len(pArrayListCliente); i++)
        {
            pCliente = ll_get(pArrayListCliente, i);
            if(pCliente != NULL)
            {
                cliente_getId(pCliente, &idAux);
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

int cliente_compare(void* this1, void* this2)
{
    int retorno;
    int auxCmp;
    char stringUno[1000];
    char stringDos[1000];
    if( !cliente_getNombre((Cliente*)this1,stringUno)&&
        !cliente_getNombre((Cliente*)this2,stringDos))
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

/*int cliente_salary(void* pCliente)
{
    int retorno = 0;
    if(pCliente != NULL)
    {
        if(((Cliente*)pCliente)->valorFloat >= 6000)
        {
            retorno = 1;
        }
    }
    return retorno;
}

int cliente_horas(void* pCliente)
{
    int retorno = 0;
    if(pCliente != NULL)
    {
        if(((Cliente*)pCliente)->valorEntero >= 300)
        {
            retorno = 1;
        }
    }
    return retorno;
}
*/
