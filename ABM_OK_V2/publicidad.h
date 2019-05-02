#ifndef PUBLICIDAD_H_INCLUDED
#define PUBLICIDAD_H_INCLUDED
typedef struct
{
    int idPublicidad;
    int isEmpty;
    char cuitCliente[20];
    int cantDias;
    char nombreVideo[50];
}Publicidad;

int pub_AltaPublicidad(Publicidad *arrayPublicidad, int cantidad, int posLibre);
int pub_Inicializar(Publicidad *arrayPublicidad, int cantidad);
int pub_buscarLibre(Publicidad *arrayPublicidad, int cantidad, int *devuelve);
int pub_buscarPosicionPantallaPorId (Pantalla *arrayPantalla, int cantidad, int *pantallaEncontrada, int id);
int isValidsNum(char *sAlphaNum);
int getStringCuit(char *pResult, char *pMsg, char *pMsgError, int min, int max, int intentos);
void pub_mostrarArray(Publicidad *arrayPublicidad, Pantalla *arrayPantalla,int cantidadPan, int cantidadPub);
int pub_buscarEnArrayPorCuit(Publicidad* arrayPublicidad, int cantidad, int* idPantallaEncontrado, int *posArray);


#endif // PUBLICIDAD_H_INCLUDED
