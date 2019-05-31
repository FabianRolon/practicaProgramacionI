#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "funciones.h"

Persona* Per_new(void)
{
    return (Persona*) malloc(sizeof(Persona));
}

Persona* Per_newString(char * nombre,char * apellido,char * id,char * estado)
{
    return (Persona*) malloc(sizeof(Persona));
}

int Per_delete(Persona* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int Per_setId(Persona* this, int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int Per_getId(Persona* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->id;
        retorno = 0;
    }
    return retorno;
}

int Per_setApellido(Persona* this, char* apellido)
{
    int retorno = -1;
    if(this != NULL && apellido != NULL)
    {
        strcpy(this->apellido,apellido);
        retorno = 0;
    }
    return retorno;
}

int Per_getApellido(Persona* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strcpy(resultado,this->apellido);
        retorno = 0;
    }
    return retorno;
}



int Per_setNombre(Persona* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre,nombre);
        retorno = 0;
    }
    return retorno;
}

int Per_getNombre(Persona* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strcpy(resultado,this->nombre);
        retorno = 0;
    }
    return retorno;
}
int Per_setEstado(Persona* this, int estado)
{
    int retorno = -1;
    if(this != NULL && estado >= 0)
    {
        this->estado = estado;
        retorno = 0;
    }
    return retorno;
}
int Per_getEstado(Persona* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->estado;
        retorno = 0;
    }
    return retorno;
}
int Per_setEstadoString(Persona* this, char* estado)
{
    int retorno = -1;
    if(this != NULL && estado >= 0)
    {
        strcpy(this->estado,estado);
        retorno = 0;
    }
    return retorno;
}
int Per_getEstadoString(Persona* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strcpy(resultado,this->estado);
        retorno = 0;
    }
    return retorno;
}

int Per_setIdString(Persona* this, char* id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        strcpy(this->id,id);
        retorno = 0;
    }
    return retorno;
}
int Per_getIdString(Persona* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strcpy(resultado,this->id);
        retorno = 0;
    }
    return retorno;
}



