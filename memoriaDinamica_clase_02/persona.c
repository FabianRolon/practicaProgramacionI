#ifndef PERSONA_C_INCLUDED
#define PERSONA_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"
#include "utn.h"
#define MAX_CARACTER 50

///sprintf(bufferId,"&d",id)--->



Persona* Per_new(void)///crea una persona vacio
{
    return (Persona*) malloc(sizeof(Persona));
}

Persona* Per_newStr(char *nombre,char *apellido,char *id,char *estado)///funcion q recibe todos los parametros como string y crea un empleado con todos los datos.Y me devuelve una persona si se pudo hacer
{
    Persona* retorno= NULL;
    Persona* pAuxPersona= NULL;

    if(nombre!=NULL && apellido!=NULL && id!=NULL && estado!=NULL)
    {
        pAuxPersona= Per_new();///guarda en aux el lugar q me consiguio para persona
        if(pAuxPersona != NULL)
        {
            if(!Per_setNombre(pAuxPersona,nombre) &&         ///agrego nombre
                !Per_setApellido(pAuxPersona,apellido) &&    ///agrego apellido
                !Per_setIdStr(pAuxPersona,id) &&
                !Per_setEstadoStr(pAuxPersona,estado))
                {
                    retorno= pAuxPersona;

                }
            else
            {
                Per_delete(pAuxPersona);
            }

        }
    }


    return 0;
}
///----
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


///---DE TODAS LAS FUNCIONES Q SEAN SET... SIEMPRE HACERLE UN SETsTRING
int Per_setId(Persona* this, int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;/// solo aca puede aparecer la flecha.porque es la unica q accede de manera segura
        retorno = 0;
    }
    return retorno;
}

int Per_setIdStr(Persona* this, char* id)///ok lo hizo el profe- valida q el string q recibe no sea null
{
    int retorno = -1;
    if(this != NULL && id != NULL && (!isValidNumber(id)))
    {

        retorno = Per_setId(this,atoi(id));///si salio bien retorna 0 sino -1
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

int Per_getIdStr(Persona* this, char* resultado)///ok,lo hizo el profe
{
    int retorno = -1;
    int bufferInt;

    if(this != NULL && resultado != NULL)
    {
        Per_getId(this,&bufferInt);
        sprintf(resultado,"%d",bufferInt);
        retorno = 0;
    }
    return retorno;
}


///----
int Per_setNombre(Persona* this, char *nombre)
{
    int retorno = -1;
    if(this != NULL && (!isValidNombre(nombre)))
    {
        strncpy(this->nombre,nombre,MAX_CARACTER);
        retorno = 0;
    }
    return retorno;
}

int Per_getNombre(Persona* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strncpy(resultado,this->nombre,MAX_CARACTER);
        retorno = 0;
    }
    return retorno;
}
///---
int Per_setApellido(Persona* this, char *apellido)
{
    int retorno = -1;
    if(this != NULL && (!isValidNombre(apellido)))
    {
        strncpy(this->apellido,apellido,MAX_CARACTER);
        retorno = 0;
    }
    return retorno;
}

int Per_getApellido(Persona* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strncpy(resultado,this->apellido,MAX_CARACTER);
        retorno = 0;
    }
    return retorno;
}
///---
int Per_setEstado(Persona* this, int estado)
{
    int retorno = -1;
    if(this != NULL &&  estado>= 0)
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
///---
int Per_constructor(Persona* this,int id,int estado,char nombre,char apellido)
{
    int retorno=-1;

    if(this != NULL)
    {
        Per_new();
        Per_setId(this,id);
        Per_setNombre(this,&nombre);
        Per_setApellido(this,&apellido);
        Per_setEstado(this,estado);
        retorno=0;
    }
    return retorno;
}

#endif // PERSONA_C_INCLUDED



