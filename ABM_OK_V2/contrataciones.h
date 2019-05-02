#ifndef CONTRATACIONES_H_INCLUDED
#define CONTRATACIONES_H_INCLUDED

typedef struct
{
    int idPantalla;
    char cuitCliente[20];
    int isEmpty;
}Contrataciones;

int con_Inicializar(Contrataciones *arrayContratacion, int cantidad);


#endif // CONTRATACIONES_H_INCLUDED
