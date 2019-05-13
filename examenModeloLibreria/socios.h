#ifndef SOCIOS_H_INCLUDED
#define SOCIOS_H_INCLUDED

typedef struct
{
    int codigoSocio;
    int isEmpty;
    char nombre[31];
    char apellido[31];
    char sexo;
    char telefono[16];
    char email[31];
    int fechaDeAsociado;
}Socios;

int getSex(char *mensaje, char *mensajeError, char minimo, char maximo, int reintentos, char *resultado);
int isValidSex(char letra, char maximo, char minimo);
int getTelefono(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input);
int isValidTelephone(char* stringRecibido);
int isValidEmail(char* stringRecibido);
int getEmail(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input);






#endif
