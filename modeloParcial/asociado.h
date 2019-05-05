#ifndef ASOCIADO_H_INCLUDED
#define ASOCIADO_H_INCLUDED

typedef struct
{
    char nombre[20];
    char apellido[20];
    int isEmpty; // lleno=0 ; vacio=1
    int idAsociado; //autoincremental
    int edad;
    int dni;

}Asociado;

int aso_Inicializar(Asociado *arrayAsociado, int cantidad);
int aso_buscarLibre(Asociado *arrayAsociado, int cantidad, int *devuelve);
int aso_altaAsociado(Asociado *arrayAsociado, int cantidad, int posicionLibre, int id);
int getInt(
    char *mensaje,
    char *mensajeError,
    long minimo,
    long maximo,
    int reintentos,
    int *resultado);
int isValidInt(int numero, int maximo, int minimo);
int getChar(char *mensaje, char *mensajeError, char minimo, char maximo, int reintentos, char *resultado);
int isValidsAlphaNum(char *sAlphaNum);
int getStringD(char *pResult, char *pMsg, char *pMsgError, int min, int max, int intentos);
int getStringf(float *pResult, char *pMsg, char *pMsgError, int min, int max, int intentos);
int aso_buscarEnArrayPorId (Asociado *arrayAsociado, int cantidad, int *asociadoEncontrado,char *textoAMostrar);


#endif // ASOCIADO_H_INCLUDED
