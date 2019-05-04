#ifndef ASOCIADO_H_INCLUDED
#define ASOCIADO_H_INCLUDED

typedef struct
{
    char nombre[20];
    char Apellido[20];
    int isEmpty; // lleno=0 ; vacio=1
    int idAsociado; //autoincremental
    int edad;
    int dni;

}Asociado;

int aso_Inicializar(Asociado *arrayAsociado, int cantidad);
int aso_buscarLibre(Asociado *arrayAsociado, int cantidad, int *devuelve);
int aso_AltaPantalla(Asociado *arrayAsociado, int cantidad, int posLibre, int id);
int getInt(
    char *mensaje,
    char *mensajeError,
    long minimo,
    long maximo,
    int reintentos,
    int *resultado);
int isValidInt(int numero, int maximo, int minimo);


#endif // ASOCIADO_H_INCLUDED
