#ifndef CONTRATACIONES_H_INCLUDED
#define CONTRATACIONES_H_INCLUDED

typedef struct
{
    int idPantalla;
    char cuitCliente[20];
    int isEmpty;
}Contrataciones;

int con_Inicializar(Contrataciones *arrayContratacion, int cantidad);
int con_buscarContratacionesPorCuit(Contrataciones* arrayContratacion, Pantalla *arrayPantalla, int cantidadContratacion, int cantidadPantalla);
int pub_buscarPosicionContratacionPorId(Contrataciones *arrayContratacion, int cantidad, int *contratacionEncontrada, int id);
int con_buscarLibre(Contrataciones *arrayContratacion, int cantidad, int *devuelve);
int con_baja(Contrataciones *arrayContratacion, int cantidad);

#endif // CONTRATACIONES_H_INCLUDED
