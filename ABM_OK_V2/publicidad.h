#ifndef PUBLICIDAD_H_INCLUDED
#define PUBLICIDAD_H_INCLUDED
typedef struct
{
    int idPublicidad;
    int isEmpty;
    int cuitCliente;
    int cantDias;
    char nombreVideo[50];
}Publicidad;

int pub_AltaPublicidad(Publicidad *arrayPublicidad, int cantidad, int posLibre);
int pub_Inicializar(Publicidad *arrayPublicidad, int cantidad);
int pub_buscarLibre(Publicidad *arrayPublicidad, int cantidad, int *devuelve);
int pub_buscarPosicionPantallaPorId (Pantalla *arrayPantalla, int cantidad, int *pantallaEncontrada, int id);


#endif // PUBLICIDAD_H_INCLUDED
