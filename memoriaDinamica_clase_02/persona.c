#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"
#include "utn.h"

Persona* Per_new(void)
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
        this->idPersona = id;
        retorno = 0;
    }
    return retorno;
}

int Per_getId(Persona* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->idPersona;
        retorno = 0;
    }
    return retorno;
}


int Per_setNombre(Persona* this, char* nombre, int tamanio)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL /* && !isValidName(nombre) && tamanio > 0*/)
    {
        strncpy(this->nombre, nombre, tamanio);
        retorno = 0;
    }
    return retorno;
}


int Per_getNombre(Persona* this, char* resultado, int tamanio)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strncpy(resultado, this->nombre, tamanio);
        retorno = 0;
    }
    return retorno;
}

int Per_setApellido(Persona* this, char* apellido, int tamanio)
{
    int retorno = -1;
    if(this != NULL && apellido != NULL /* && !isValidName(apellido) && tamanio > 0*/)
    {
        strncpy(this->apellido, apellido, tamanio);
        retorno = 0;
    }
    return retorno;
}

int Per_getApellido(Persona* this, char* resultado, int tamanio)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strncpy(resultado, this->apellido, tamanio);
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


