#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
}Fecha;

int getFecha(char *msg, char *msgError, int minSize, int maxSize, int reintentos, int *resultadoMes, int *resultadoDia, int *resultadoAnio);
int isValidNumber(char* stringRecibido);
int getString(char* msg, char* msgError, int min, int max, int reintentos, char* resultado);
int isValidDia(int resultadoMes, int dia);

#endif
