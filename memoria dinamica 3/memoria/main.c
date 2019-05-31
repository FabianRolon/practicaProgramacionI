#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "funciones.h"
int main()
{
    Persona *pArrayEmpleado[1000];
    int ultimoElementoArrayEmpleado = 0;
    int indiceActual;
    int auxInt;
    int auxEstado;
    char auxApellido[50];
    char auxNombre[50];

    //LEER ARCHIVOS data.csv - ESCRIBIR ARCHIVO data_bkp.cvs
    char bufferId[4000];
    char bufferNombre[400];
    char bufferApellido[400];
    char bufferEstado[400];
    FILE *pFile = NULL;
    FILE *pFileBkp = NULL;
    pFile = fopen("data.csv","rb");
    pFileBkp = fopen("data_bkp.csv","wb");

    if(pFile != NULL && pFileBkp != NULL)
    {
        while(!feof(pFile))
        {
            //fscanf(pFile,"%s",bufferStr);
           // printf("%s\n",bufferStr);
           fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferApellido,bufferEstado);
           //funcion que crea empleado
           printf("%s\n",bufferApellido);
            // copiar a archivo bkp  fprintf(pFileBkp,"%s\n",bufferStr);
        }
        fclose(pFile);
        fclose(pFileBkp);
    }

    indiceActual = ultimoElementoArrayEmpleado;
    pArrayEmpleado[indiceActual] =  Per_new();


    if(pArrayEmpleado[indiceActual] != NULL)
    {
        ultimoElementoArrayEmpleado++;
        printf("OK");
        if(!Per_setId(pArrayEmpleado[indiceActual],14))
        {
            Per_getId(pArrayEmpleado[indiceActual], &auxInt);
            printf("\n El id es %d",auxInt);

        }
        if(!Per_setNombre(pArrayEmpleado[indiceActual],"Juan"))
        {

            Per_getNombre(pArrayEmpleado[indiceActual], auxNombre);
            printf("\n El nombre es %s",auxNombre);
        }
        if(!Per_setApellido(pArrayEmpleado[indiceActual],"Perez"))
        {

            Per_getApellido(pArrayEmpleado[indiceActual], auxApellido);
            printf("\n El apellido es %s",auxApellido);
        }



        if(!Per_setEstado(pArrayEmpleado[indiceActual],1))
        {
            Per_getEstado(pArrayEmpleado[indiceActual], &auxEstado);
            printf("\n El estado es %d",auxEstado);
        }

    }


    return 0;
}
