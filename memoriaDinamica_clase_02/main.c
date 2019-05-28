#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"
#include "utn.h"

int main()
{
   // Persona *pArrayPersona[1000];
  //  int ultimoElementoArrayPersona = 0;
    //int indiceActual;
   // int bufferInt;
    char bufferId[2000];
    char bufferEstado[2000];
    char bufferApellido[2000];
    char bufferNombre[2000];
    //char bufferStr[4000];

    FILE *pFile = NULL;                         /// hacer esto siempre. Siempre abro,utilizo y  cierro el archivo en el momento que lo uso xq se puede estar actualizando en ese momento y esa info no la puedo ver
    FILE *pFileBkp = NULL;                          ///para escribir en el archivo

    pFile = fopen("data.csv","r");               ///apertura de archivo.Primer parametro le indico la ruta de donde esta el archivo,segundo parametro es el modo de apertura (lectura"R"-escritura"W"(sobre escribe lo q tiene)-
    //pFile =fopen("data.csv","w");///Para esribir                                                    si el archivo no se puede abrir me devuelve NULL

    if(pFile!=NULL)
    {

        while(!feof(pFile))                         ///Esta funcion me dice Verdadero cuando se termina el archivo,entonces lo niego para q lea hasta el final
        {

            //fscanf(pFile,"%s",bufferStr);///para leer UNA linea.
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferApellido,bufferEstado);               ///Asi se crea una mascara,q va a guardar todo lo q encuentra mientras no sea una "," hasta el buffer
                                                                                ///La coma en la mascara le indica q tiene q pasar al siguiente lugar
            printf("%s %s %s %s\n",bufferId,bufferNombre,bufferApellido,bufferEstado);                                        ///Imprimo lo que leyo de esa linea
            //fprintf(pFile,"%s\n",bufferStr);///para mopstrar lo q escribi



        }
        fclose(pFile);///Cierro
        fclose(pFileBkp);


    }



  /*  indiceActual = ultimoElementoArrayPersona;
    pArrayPersona[indiceActual] =  Per_new();

        if(pArrayPersona[indiceActual] != NULL)
    {
        ultimoElementoArrayPersona++;
        //printf("OK");
        if(!Per_setId(pArrayPersona[indiceActual],14))
        {
            Per_getId(pArrayPersona[indiceActual],&bufferId);
            printf("\n El id es %d",bufferId);

        }

        if(!Per_setNombre(pArrayPersona[indiceActual],"carla"))
        {
            Per_getNombre(pArrayPersona[indiceActual],bufferNombre);
            printf("\n El nombre es %s",bufferNombre);
        }

        if(!Per_setApellido(pArrayPersona[indiceActual],"Trovato"))
        {
            Per_getApellido(pArrayPersona[indiceActual],bufferApellido);
            printf("\n El nombre es %s",bufferApellido);
        }*/
    return 0;

}
