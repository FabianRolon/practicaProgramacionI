#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "pantalla.h"
#include "publicidad.h"
#include "contrataciones.h"
#include "funciones_string.h"

int con_Inicializar(Contrataciones *arrayContratacion, int cantidad)
{
    int retorno = -1;
    int i;

    for (i = 0; i < cantidad; i++)
    {
        arrayContratacion[i].isEmpty = 1;
        retorno=0;
    }

    return retorno;
}

int con_buscarContratacionesPorCuit(Contrataciones* arrayContratacion, Pantalla *arrayPantalla, int cantidadContratacion, int cantidadPantalla)
{
    int i;
    int j;
    int retorno = 1;
    Contrataciones auxContratacion;

    if (getStringCuit(auxContratacion.cuitCliente,"Ingrese el CUIT del cliente: ", "Ingreso incorrecto\n", 11, 20, 2)==0)
    {

        retorno = -1;
        for(i = 0; i < cantidadContratacion; i++)
        {
            if (strcmp(arrayContratacion[i].cuitCliente, auxContratacion.cuitCliente)==0)
            {
                auxContratacion.idPantalla = arrayContratacion[i].idPantalla;

                for(j = 0; j < cantidadPantalla; j++)
                {
                    if (arrayPantalla[j].idPantalla == auxContratacion.idPantalla)
                    {
                        if(arrayPantalla[j].isEmpty == 0)
                        {

                            printf("ID Pantalla: %d\n", arrayPantalla[j].idPantalla);
                            printf("Posicion: %d\n", j);
                            printf("Estado: %d\n", arrayPantalla[j].isEmpty);
                            printf("Nombre: %s\n", arrayPantalla[j].nombre);
                            printf("Direccion: %s\n", arrayPantalla[j].direccion);
                            printf("Precio: $%.2f\n", arrayPantalla[j].precio);
                            printf("Tipo: %c\n\n", arrayPantalla[j].tipo);
                        }

                    }
                }
            }
        }
        retorno = 0;
    }
    return retorno;
 }

 int pub_buscarPosicionContratacionPorId(Contrataciones *arrayContratacion, int cantidad, int *contratacionEncontrada, int id)
{
    int i;
    int retorno = 1;

        for(i=0; i < cantidad; i++)
        {
            if (arrayContratacion[i].idPantalla == id)
            {
                retorno=0;
                *contratacionEncontrada = i;
                break;
            }
        }

    return retorno;
}

int con_buscarLibre(Contrataciones *arrayContratacion, int cantidad, int *devuelve)
{
    int retorno=-1;
    for (int i=0; i < cantidad;i++)
    {
        if (arrayContratacion[i].isEmpty==1)
        {
            *devuelve=i;
            retorno=0;
            break;
        }

        retorno=1;
    }

    return retorno;
}

int con_baja(Contrataciones *arrayContratacion, int cantidad)
{

    int id;
    int posContratacion;

    getInt("\n\t\tIngrese el Id para dar de baja: ", "Ingreso incorrecto\n", 0, 10, 2, &id);

    switch (pub_buscarPosicionContratacionPorId(arrayContratacion, cantidad, &posContratacion, id))
    {
    case 0:
        if (arrayContratacion[posContratacion].isEmpty==0)
        {
            printf("Hubo coincidencia\n\n");
            arrayContratacion[posContratacion].isEmpty = 1;
            printf("La pantalla borrada es: %d\n\n",arrayContratacion[posContratacion].idPantalla);
        }
        break;
    case 1:
        printf("No se encontro el Id y no entro al if\n\n");
        break;

    default:
        printf("Ingreso al if pero no encontro el nombre");
        break;
    }
    return 1;
}
