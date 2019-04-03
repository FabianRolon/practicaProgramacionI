#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

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

int isValidInt(int numero, int maximo, int minimo);
int isValidFloat(float numero, float maximo, float minimo);

int sumador(int primerTermino, int segundoTermino);
int restador(int primerTermino, int segundoTermino);
float dividir(float dividendo, float divisor, char *mensajeError);
int multiplicador(int primerTermino, int segundoTermino);
int calculaFactorial(int valor,long int *factorial, char *mensajeError);

#endif // FUNCIONES_H_INCLUDED
