#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
#include "utn.h"

int main()
{
    Persona *pArrayPersona[1000];
    /*int ultimoElementoArrayPersona = 0;
    int indiceActual;
    int auxInt;
    char auxNombre[31];
    int generadorId = 1;

    indiceActual = ultimoElementoArrayPersona;
    pArrayPersona[indiceActual] =  Per_new();



    if(pArrayPersona[indiceActual] != NULL)
    {
        ultimoElementoArrayPersona++;
        printf("OK");
        if(!Per_setId(pArrayPersona[indiceActual],generadorId))
        {
            generadorId++;
            Per_getId(pArrayPersona[indiceActual], &auxInt);
            printf("\n El id es %d",auxInt);

        }
        if(!Per_setNombre(*(pArrayPersona+indiceActual),"Fabian", 31))
        {
            Per_getNombre(*(pArrayPersona+indiceActual), auxNombre, 31);
            printf("\n El nombre es %s", auxNombre);
        }
         if(!Per_setApellido(*(pArrayPersona+indiceActual),"Rolon", 31))
        {
            Per_getApellido(*(pArrayPersona+indiceActual), auxNombre, 31);
            printf("\n El Apellido es %s", auxNombre);
        }

    }*/

    FILE *pFile = NULL;
    char bufferId[1050],bufferNombre[1050],bufferApellido[1050],bufferEstado[1050];
    int i = 0;
    int auxId;
    int auxId2;
    pFile = fopen("data.csv","r");

    if(pFile == NULL)
    {
        printf("El archivo no existe");
    }
    else
    {
        do
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferApellido,bufferEstado);
            //printf("Lei: %s %s %s %s\n",bufferId,bufferNombre,bufferApellido,bufferEstado);

            pArrayPersona[i] =  Per_new();
            if(pArrayPersona[i] != NULL)
            {
                if(isValidNumber(bufferId))
                {
                    auxId = atoi(bufferId);
                    if(!Per_setId(pArrayPersona[i],auxId))
                    {
                        Per_getId(pArrayPersona[i], &auxId2);
                        printf("\n El id es: %d",auxId2);

                    }
                }
            }

        i++;

       }while(!feof(pFile));
        fclose(pFile);
    }








    return 0;
}
