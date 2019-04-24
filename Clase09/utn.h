#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED


    int getInt(char *mensaje,
        char *mensajeError,
        int minimo, int maximo,
        int reintentos,
        int *resultado);

    int getFloat(
        char *mensaje,
        char *mensajeError,
        float minimo,
        float maximo,
        int reintentos,
        float *resultado);

    int getChar(
        char *mensaje,
        char *mensajeError,
        char minimo,
        char maximo,
        int reintentos,
        char *resultado);

    int getArrayInt(char* msg,
                    char* msgError,
                    int maximo,
                    int minimo,
                    int reintentos,
                    int* arrayResultado,
                    int limite);

    int getString(  char *mensaje,
                    char *mensajeError,
                    int minimo,
                    int maximo,
                    int reintentos,
                    char *sString);


    int isValidInt(int numero, int maximo, int minimo);
    int isValidFloat(float numero, float maximo, float minimo);
    int isValidChar(char letra, char maximo, char minimo);
    int isValidArrayInt(int numero, int maximo, int minimo);
    int isValidLengthString(char* buffer, int minimo, int maximo);
    int doSwap(int* primerValor, int* segundoValor);
    int ordenarArray(char *vector[10][50], int limite);
    int printArrayInt(int* arrayResultado, int limite);
    int encontrarNombre(char sArray[][50],char *nombre , int limite);
    int encontrarVacio(char sArray[][50], int limite);
    int inicializar(char sArray[][50], int limite);
    int printArrayArray(char aString[][50], int limite);


#endif // UTN_H_INCLUDED
