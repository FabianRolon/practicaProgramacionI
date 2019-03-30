#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

int getInt(char *mensaje,
    char *mensajeError,
    int minimo, int maximo,
    int reintentos,
    int *resultado);

int isValidInt(int numero, int maximo, int minimo);

int sumador(int primerTermino, int segundoTermino);
int restador(int primerTermino, int segundoTermino);
float dividir(float dividendo, float divisor);
int multiplicador(int primerTermino, int segundoTermino);

#endif // FUNCIONES_H_INCLUDED
