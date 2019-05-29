#include <stdio.h>
#include <stdlib.h>


int inf_orquestaConMenosMusicos(Orquesta* arrayOrquesta, int limiteOrquesta, Musico* arrayMusico, int limiteMusico)
{
    int retorno=-1;
    int i;
    int j;
    int contador=0;
    int indiceMaximo=1000;
    int auxPosicionOrquesta;

    if (arrayMusico!=NULL && arrayOrquesta!=NULL && limiteMusico>0 && limiteOrquesta>0)
    {
        for (i=0;i<limiteOrquesta;i++)
        {
            if (arrayOrquesta[i].isEmpty==1)
                continue;
            if (arrayOrquesta[i].isEmpty==0)
            {
                for (j=0;j<limiteMusico;j++)
                {
                    if (arrayMusico[j].isEmpty==1)
                        continue;
                    if (arrayMusico[j].isEmpty==0)
                    {
                        if (arrayOrquesta[i].idOrquesta==arrayMusico[j].idOrquesta)
                        {
                            contador++;
                        }
                    }
                }
                if(contador < indiceMaximo)
                {
                    indiceMaximo = contador;
                    auxPosicionOrquesta = i;
                }
            }
        }
        printf ("\nId de orquesta: %d. \n",arrayOrquesta[auxPosicionOrquesta].idOrquesta);
        printf ("Nombre de orquesta: %s. \n",arrayOrquesta[auxPosicionOrquesta].nombre);
        printf ("Lugar de orquesta: %s.\n",arrayOrquesta[auxPosicionOrquesta].lugar);
        printf ("Cantidad de musicos: %d\n",contador);
        switch (arrayOrquesta[auxPosicionOrquesta].tipo)
        {
            case 1:
                printf ("Tipo de orquesta : Sinfonica.\n");
                break;
            case 2:
                printf ("Tipo de orquesta: Filarmonica.\n");
                break;
            case 3:
                printf ("Tipo de orquesta: Camara.\n");
                break;
        }

      retorno = 0;
    }
    return retorno;
}

