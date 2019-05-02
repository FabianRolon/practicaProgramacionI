#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "pantalla.h"
#include "funciones_string.h"

int pan_Inicializar(Pantalla *arrayPantalla, int cantidad)
{
    int retorno = -1;
    int i;

    for (i = 0; i < cantidad; i++)
    {
        arrayPantalla[i].isEmpty = 1;
        retorno=0;
    }

    return retorno;
}

int pan_buscarLibre(Pantalla *arrayPantalla, int cantidad, int *devuelve)
{
    int retorno=-1;
    for (int i=0; i<cantidad;i++)
    {
        if (arrayPantalla[i].isEmpty==1)
        {
            *devuelve=i;
            retorno=0;
            break;
        }

        retorno=1;
    }

    return retorno;
}

int pan_AltaPantalla(Pantalla *arrayPantalla, int cantidad, int posLibre, int id)
{
    int retorno = -1;

    if (    getString(arrayPantalla[posLibre].nombre,"Ingrese un nombre: ","error, vuelva a ingresar\n\n",2,20,2) == 0 &&
            getStringD(arrayPantalla[posLibre].direccion,"Ingrese la direccion: " ,"error, vuelva a ingresar\n\n",2,30,2) == 0 &&
            getStringf(&arrayPantalla[posLibre].precio, "Ingrese precio: ","error, vuelva a ingresar\n\n",2,999999,2) == 0 &&
            getChar("Ingrese tipo <LED = E/LCD = C: ","Error, vuelva a ingresar\n\n",'A','Z',2,&arrayPantalla[posLibre].tipo) == 0)
    {
        if(arrayPantalla[posLibre].tipo != 'E' && arrayPantalla[posLibre].tipo != 'C')
        {
            printf("INGRESO INCORRECTO!!!");
        }
        else
        {
            arrayPantalla[posLibre].idPantalla = id;
            arrayPantalla[posLibre].isEmpty  = 0;
            retorno=0;
        }
    }
    else
    {
        retorno = 1;
    }

    return retorno;
}

void pan_mostrarArray(Pantalla *arrayPantalla, int cantidad)
{
    int i;

    printf("\n\n\t\t\t\t||Lista de Pantallas||\n\n");

    for (i = 0; i < cantidad ;i++)
    {
        if(arrayPantalla[i].isEmpty == 0)
        {

            printf("ID Pantalla: %d\n", arrayPantalla[i].idPantalla);
            printf("Posicion: %d\n", i);
            printf("Estado: %d\n", arrayPantalla[i].isEmpty);
            printf("Nombre: %s\n", arrayPantalla[i].nombre);
            printf("Direccion: %s\n", arrayPantalla[i].direccion);
            printf("Precio: $%.2f\n", arrayPantalla[i].precio);
            printf("Tipo: %c\n\n", arrayPantalla[i].tipo);
        }

        //printf("Press 'Enter' to continue: ... ");
        //while ( getchar() != '\n');
    }

}
int pan_baja(Pantalla *arrayPantalla, int cantidad)
{

    int posPantalla;

    pan_mostrarArray(arrayPantalla, cantidad);
    switch (pan_buscarEnArrayPorId(arrayPantalla, cantidad,&posPantalla,"Ingrese el Id de la pantalla a dar de baja: "))
    {
    case 0:
        if (arrayPantalla[posPantalla].isEmpty==0)
        {
            printf("Hubo coincidencia\n\n");
            arrayPantalla[posPantalla].isEmpty=1;
            printf("La pantalla borrada es: %d\n\n",arrayPantalla[posPantalla].idPantalla);
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

int pan_buscarEnArray (Pantalla *arrayPantalla, int cantidad, int *pantallaEncontrada,char *textoAMostrar)
{
    int retorno=1;
    Pantalla auxPantalla;

    if (getString(auxPantalla.nombre,textoAMostrar,"Vuelva a ingresar",2,20,3)==0)
    {
        //auxEmpleados.nombre=tolower(auxEmpleados.nombre);
        retorno=-1;
        for(int i=0;i<cantidad;i++)
        {
            //empleados[i].nombre=tolower(empleados[i].nombre);
            if (strcmp(arrayPantalla[i].nombre, auxPantalla.nombre)==0)
            {
                retorno=0;
                *pantallaEncontrada=i;
                break;
            }
        }
    }
    return retorno;
}

int pan_modificacion(Pantalla *arrayPantalla, int cantidad)
{

    int retorno = -1;
    int opcion;
    int posPantalla;
    char seguir = 's';

    pan_mostrarArray(arrayPantalla, cantidad);

    switch (pan_buscarEnArrayPorId(arrayPantalla, cantidad,&posPantalla,"Ingrese el Id de la pantalla a modificar: "))
    {
    case 0:
        if (arrayPantalla[posPantalla].isEmpty == 0)
        {
            printf("Hubo coincidencia\n\n");

            while(seguir == 's')
            {
                printf("Elija el dato que desea modificar\n\n");

                printf("\n\n1-Nombre");
                printf("\n\n2-Direccion");
                printf("\n\n3-Precio");
                printf("\n\n4-Tipo");
                printf("\n\n5-Salir de la modificacion");

                getInt("\n\t\tIngrese opcion: ", "Ingreso incorrecto\n", 1, 6, 2, &opcion);


                switch(opcion)
                {
                    case 1:
                        if (getString(arrayPantalla[posPantalla].nombre,"Ingrese el nuevo nombre de la pantalla: ","error",2,20,2)==0)
                        {
                            printf("El dato fue modificado con exito.\n\n");
                        }
                        break;
                    case 2:
                        if (getStringD(arrayPantalla[posPantalla].direccion,"Ingrese la nueva direccion: " ,"error, vuelva a ingresar\n\n",2,30,2)==0)
                        {
                            printf("El dato fue modificado con exito.\n\n");
                        }
                        break;
                    case 3:
                        if(getStringf(&arrayPantalla[posPantalla].precio, "Ingrese el nuevo precio: ","error, vuelva a ingresar\n\n",2,999999,2) == 0)
                        {
                            printf("El dato fue modificado con exito.\n\n");
                        }
                        break;
                    case 4:
                        if(getChar("Ingrese el nuevo tipo <LED = E/LCD = C: ","error, vuelva a ingresar\n\n",'A','Z',2,&arrayPantalla[posPantalla].tipo) == 0)
                        {
                            printf("El dato fue modificado con exito.\n\n");
                        }
                        break;
                    case 5:
                        seguir = 'n';
                        retorno = 0;
                        break;
                }
            }
        }
        break;

    case 1:
        printf("No se encontro el Id de la pantalla");
        break;

    default:
        printf("Ingreso al if pero no encontro el nombre");
        break;
        }

    return retorno;
}

int getStringf(float *pResult, char *pMsg, char *pMsgError, int min, int max, int intentos)
{
    int ret=-1;
    float arrayAuxiliar;
    while(intentos>0)
    {
        printf("%s",pMsg);
        //fflush( stdin ); //LIMPIA BUFFER WINDOWS
        __fpurge(stdin); //LIMPIA BUFFER LINUX
        scanf("%f", &arrayAuxiliar);
        if( pResult != NULL && arrayAuxiliar >= min && arrayAuxiliar <= max)
        {
            *pResult = arrayAuxiliar;

            ret=0;
            break;
        }
        else
        {
            printf("%s",pMsgError);
        }
        intentos--;
    }
    return ret;
}

int getStringD(char *pResult, char *pMsg, char *pMsgError, int min, int max, int intentos)
{
    int retorno=-1;
    char arrayAuxiliar[50];
    while(intentos>0)
    {
        printf("%s",pMsg);
        //fflush( stdin ); //LIMPIA BUFFER WINDOWS
        __fpurge(stdin); //LIMPIA BUFFER LINUX
        fgets(arrayAuxiliar,sizeof(arrayAuxiliar),stdin);
        arrayAuxiliar[strlen(arrayAuxiliar)-1] = '\0';
        if( pResult != NULL && strlen(arrayAuxiliar) >= min && strlen(arrayAuxiliar) <= max && !(isValidsAlphaNum(arrayAuxiliar))==0)
        {
            strncpy(pResult,arrayAuxiliar,max);

            retorno=0;
            break;
        }
        else
        {
            printf("%s",pMsgError);
        }
        intentos--;
    }
    return retorno;
}

int isValidsAlphaNum(char *sAlphaNum)
{
   int i;
   int retorno = 1;

    for(i = 0; *(sAlphaNum+i) != '\0'; i++)
    {
        if((*(sAlphaNum+i) != '.') && (*(sAlphaNum+i) != ' ') && (*(sAlphaNum+i) < 'a' || *(sAlphaNum+i) > 'z') && (*(sAlphaNum+i) < 'A' || *(sAlphaNum+i) > 'Z') && (*(sAlphaNum+i) < '0' || *(sAlphaNum+i) > '9'))
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}

int getChar(char *mensaje, char *mensajeError, char minimo, char maximo, int reintentos, char *resultado)
{
    char buffer;
    int retorno = -1;

    if(mensaje != NULL && mensajeError != NULL && resultado != NULL && maximo >= minimo && reintentos >= 0)
    {
        do
        {
            printf("%s", mensaje);

            //fflush( stdin );
            __fpurge(stdin);

            scanf("%c", &buffer);

            if(isValidChar(buffer, maximo, minimo))
            {
                *resultado = buffer;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
        }while(reintentos--);
    }
    return retorno;
}

int isValidChar(char letra, char maximo, char minimo)
{
    if(letra >= minimo && letra <= maximo)
    {
        return 1;
    }
    return 0;
}

int getInt(
    char *mensaje,
    char *mensajeError,
    long minimo,
    long maximo,
    int reintentos,
    int *resultado)
{
    int buffer; //variables que no estan validadas = buffer
    int retorno = -1;
    int i;

    if(mensaje != NULL && mensajeError != NULL && resultado != NULL && maximo >= minimo && reintentos >= 0)
    {
        for(i=0; i<= reintentos; i++)
        {
            printf("%s", mensaje);//imprimir mensaje
            //fflush(stdin);
            __fpurge(stdin);
            scanf("%d", &buffer);
            if(isValidInt(buffer, maximo, minimo))
            {
                *resultado = buffer;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
        }
    }
    return retorno;
}

int isValidInt(int numero, int maximo, int minimo) //las funciones con is devuelven "TRUE" or "FALSE"
{
    if(numero >= minimo && numero <=maximo)
    {
        return 1;
    }
        return 0;
}

int pan_buscarEnArrayPorId (Pantalla *arrayPantalla, int cantidad, int *pantallaEncontrada,char *textoAMostrar)
{
    int i;
    int retorno = 1;
    Pantalla auxPantalla;

    if (getInt(textoAMostrar, "Ingreso incorrecto\n", 1, 100, 2, &auxPantalla.idPantalla) == 0)
    {
        for(i=0; i < cantidad; i++)
        {
            if (arrayPantalla[i].idPantalla == auxPantalla.idPantalla)
            {
                retorno=0;
                *pantallaEncontrada=i;
                break;
            }
        }
    }
    return retorno;
}

