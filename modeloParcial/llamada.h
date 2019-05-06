#ifndef LLAMADA_H_INCLUDED
#define LLAMADA_H_INCLUDED

typedef struct
{
    char estado[10];
    int idAsociado;
    char motivo;

}Llamada;

int lla_Inicializar(Llamada *arrayLlamada, int cantidad);
int lla_buscarLibre(Llamada *arrayLlamada, int cantidad, int *devuelve);
int lla_altaLlamada(Llamada *arrayLlamadas, int cantidad, int posicionLibre, int id);



#endif // LLAMADA_H_INCLUDED
