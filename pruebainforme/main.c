int inf_orquestaConMenosMusicos(Orquesta* arrayOrquesta, int limiteOrquesta, Musico* arrayMusico, int limiteMusico)
{
    int retorno=-1;
    int i;
    int j;
    int contador=0;
    int indiceMaximo=1000;
    int indiceMinimo=0;
    int posicion;

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
                    posicion = i
                }
                contador=0;
            }

        }
            printf ("\nId de orquesta: %d. \n",arrayOrquesta[posicion].idOrquesta);
            printf ("Nombre de orquesta: %s. \n",arrayOrquesta[posicion].nombre);
            printf ("Lugar de orquesta: %s.\n",arrayOrquesta[posicion].lugar);
            printf ("Cantidad de musicos: %d\n",indiceMaximo);
            switch (arrayOrquesta[posicion].tipo)
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
                    if(contador == indiceMaximo && posicion != i)
                    {
                        printf ("\nId de orquesta: %d. \n",arrayOrquesta[i].idOrquesta);
                        printf ("Nombre de orquesta: %s. \n",arrayOrquesta[i].nombre);
                        printf ("Lugar de orquesta: %s.\n",arrayOrquesta[i].lugar);
                        printf ("Cantidad de musicos: %d\n",indiceMaximo);
                        switch (arrayOrquesta[i].tipo)
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
                    }
                    contador=0;
                }

            }
        retorno=0;
    }
    return retorno;
}
