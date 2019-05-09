#ifndef AUTORES_H_INCLUDED
#define AUTORES_H_INCLUDED

typedef struct
{
    int codigoAutor;
    char apellido[20];
    char nombre[20];
    int isEmpty;

}Autores;

int aut_Inicializar(Autores *arrayAutor, int cantidad);
int aut_buscarLibre(Autores *arrayAutor, int cantidad, int *devuelve);
int aut_buscarEnArrayPorId (Autores *arrayAutor, int cantidad, int *autorEncontrado,char *textoAMostrar);
int aut_alta(Autores *arrayAutor, int cantidad, int posLibre, int id);
int aut_baja(Autores *arrayAutor, int cantidad);
void aut_mostrarArray(Autores *arrayAutor, int cantidad);
int aut_modificacion(Autores *arrayAutor, int cantidad);
int aut_existeId (Autores *arrayAutor, int cantidad, int id);

int getString(char *pResult,char *pMsg,char *pMsgError,int min,int max,int intentos);
int validarLetra (char letras[]);
int getInt(
    char *mensaje,
    char *mensajeError,
    long minimo,
    long maximo,
    int reintentos,
    int *resultado);
int isValidInt(int numero, int maximo, int minimo);





#endif // AUTORES_H_INCLUDED
