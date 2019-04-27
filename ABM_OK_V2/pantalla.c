#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//#include <stdio_ext.h>
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

int pan_AltaPantalla(Pantalla *arrayPantalla, int cantidad, int posLibre)
{
    int idGenerator = 1;
    int retorno = -1;
    int aux;

    if (    getString(arrayPantalla[posLibre].nombre,"Ingrese un nombre: ","error, vuelva a ingresar\n\n",2,20,2) == 0 &&
            getStringD(arrayPantalla[posLibre].direccion,"Ingrese la direccion: " ,"error, vuelva a ingresar\n\n",2,30,2) == 0 &&
            getStringf(&arrayPantalla[posLibre].precio, "Ingrese precio: ","error, vuelva a ingresar\n\n",2,999999,2) == 0 &&
            getChar("Ingrese tipo <LED = E/LCD = C: ","error, vuelva a ingresar\n\n",'A','Z',2,&arrayPantalla[posLibre].tipo) == 0)
    {
        if(arrayPantalla[posLibre].tipo != 'E' && arrayPantalla[posLibre].tipo != 'C')
        {
            printf("INGRESO INCORRECTO!!!");
        }
        else
        {
            if(posLibre == 0)
            {
                arrayPantalla[posLibre].idPantalla = idGenerator;
                arrayPantalla[posLibre].isEmpty  = 0;
                retorno=0;
            }
            else
            {
                aux = (arrayPantalla[posLibre-1].idPantalla);
                aux++;
                arrayPantalla[posLibre].idPantalla = aux;
                arrayPantalla[posLibre].isEmpty  = 0;
                retorno=0;
            }
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
    switch (pan_buscarEnArray(arrayPantalla, cantidad,&posPantalla,"ingrese nombre de pantalla a eliminar"))
    {
    case 0:
        if (arrayPantalla[posPantalla].isEmpty==0)
        {
            printf("hubo coincidencia\n\n");
            arrayPantalla[posPantalla].isEmpty=1;
            printf("la pantalla borrada es: %s\n\n",arrayPantalla[posPantalla].nombre);

        }
        break;
    case 1:
        printf("no se encontro el nombre y no entro al if");
        break;

    default:
        printf("ingreso al if pero no encontro el nombre");
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

     int posPantalla;
    switch (pan_buscarEnArray(arrayPantalla, cantidad,&posPantalla,"ingrese el nombre de la pantalla a modificar"))
    {
    case 0:
        if (arrayPantalla[posPantalla].isEmpty==0)
        {
            printf("hubo coincidencia\n\n");
            if (getString(arrayPantalla[posPantalla].nombre,"ingrese el nuevo nombre de la pantalla","error",2,20,2)==0)
            {
                printf("la pantalla modificada es: %s\n\n",arrayPantalla[posPantalla].nombre);
            }

        }
        break;

    case 1:
        printf("no se encontro el nombre y no entro al if");
        break;

    default:
        printf("ingreso al if pero no encontro el nombre");
        break;
    }
    return 1;
}

int getStringf(float *pResult, char *pMsg, char *pMsgError, int min, int max, int intentos)
{
    int ret=-1;
    float arrayAuxiliar;
    while(intentos>0)
    {
        printf(pMsg);
        fflush( stdin ); //LIMPIA BUFFER WINDOWS
       // __fpurge(stdin); //LIMPIA BUFFER LINUX
        scanf("%f", &arrayAuxiliar);
        if( pResult != NULL && arrayAuxiliar >= min && arrayAuxiliar <= max)
        {
            *pResult = arrayAuxiliar;

            ret=0;
            break;
        }
        else
        {
            printf(pMsgError);
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
        printf(pMsg);
        fflush( stdin ); //LIMPIA BUFFER WINDOWS
       // __fpurge(stdin); //LIMPIA BUFFER LINUX
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
            printf(pMsgError);
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
        if((*(sAlphaNum+i) != ' ') && (*(sAlphaNum+i) < 'a' || *(sAlphaNum+i) > 'z') && (*(sAlphaNum+i) < 'A' || *(sAlphaNum+i) > 'Z') && (*(sAlphaNum+i) < '0' || *(sAlphaNum+i) > '9'))
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

            fflush( stdin );

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
    int minimo,
    int maximo,
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
            fflush(stdin);
            //__fpurge(stdin);
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

int isValidInt(int numero, int maximo, int minimo) //las funcionjes con is devuelven "TRUE" or "FALSE"
{
    if(numero >= minimo && numero <=maximo)
    {
        return 1;
    }
        return 0;
}
