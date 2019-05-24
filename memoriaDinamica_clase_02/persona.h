#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

typedef struct
{
    int idPersona;
    char nombre[31];
    char apellido[31];
    int estado;
}Persona;

#endif // PERSONA_H_INCLUDED

Persona* Per_new(void);
int Per_delete(Persona* this);

int Per_setId(Persona* this, int id);
int Per_getId(Persona* this, int* resultado);
int Per_setNombre(Persona* this, char* nombre, int tamanio);
int Per_getNombre(Persona* this, char* resultado, int tamanio);
int Per_setApellido(Persona* this, char* apellido, int tamanio);
int Per_getApellido(Persona* this, char* resultado, int tamanio);
int Per_setEstado(Persona* this, int estado);
int Per_getEstado(Persona* this, int* resultado);
