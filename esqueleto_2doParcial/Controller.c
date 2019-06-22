#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"
#include "utn.h"
#define MAX_EMPLOYEE 9999
#define MAX 1000
#define ASCENDENTE 1
#define DESCENDENTE 0


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEntidad LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEntidad)
{
    int retorno = -1;

    FILE* pFile;
    pFile = NULL;
    pFile = fopen(path,"r");

    if(pFile!=NULL)
    {
        if(path != NULL && pArrayListEntidad != NULL)
        {
             if(!parser_EntidadFromText(pFile , pArrayListEntidad))
             {
                printf("\nCarga exitosa\n");
                fclose(pFile);
                retorno = 0;
             }
        }
     }
     return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEntidad LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEntidad)
{
    int retorno = -1;
    FILE* pFile;
    pFile = NULL;
    if(path != NULL && pArrayListEntidad != NULL)
    {
        pFile = fopen(path, "rb");
        if(!parser_EntidadFromBinary(pFile ,pArrayListEntidad))
        {
            printf("Carga exitosa\n");
            retorno = 0;
        }
    }
     return retorno;
}


/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEntidad LinkedList*
 * \return int
 *
 */
int controller_addEntidad(LinkedList* pArrayListEntidad)
{
    int retorno = -1;
    int idAux;
    char bufferId[MAX];
    char bufferString[MAX];
    char bufferValorEntero[MAX];
    char bufferValorFloat[MAX];
    Entidad *bufferEnt;
    idAux = controller_nextId(pArrayListEntidad);
    snprintf(bufferId,MAX, "%d", idAux);

    if (pArrayListEntidad != NULL)
        {
            if( utn_getName("\n\nIngrese el nombre del empleado: ",
                "Error, vuelva a ingresar\n\n",1,50,2,
                bufferString) == 0 &&
                utn_getAlfanumerico("\n\nIngrese las horas trabajadas: ",
                "Error, vuelva a ingresar\n\n",1,51,2,
                bufferValorEntero) == 0 &&
                utn_getAlfanumerico("\n\nIngrese el sueldo: ",
                "Error, vuelva a ingresar\n\n",1,51,2,bufferValorFloat) == 0)
            {
                bufferEnt = entidad_newParametrosStr( bufferId,
                                                   bufferString,
                                                   bufferValorEntero,
                                                   bufferValorFloat);
                ll_add(pArrayListEntidad, bufferEnt);
                printf("Exito, empleado agregado!\n");
                retorno = 0;
            }else
            {
                printf("ERROR, reintentos agotados!\n");
                retorno = -2;
            }
        }else
        {
            printf("ERROR, NULL\n");
        }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEntidad LinkedList*
 * \return int
 *
 */
int controller_editEntidad(LinkedList* pArrayListEntidad)
{
    int retorno = -1;
    int opcion;
    int idIngresado;
    int posicionId;
    int auxId;
    char bufferId[MAX];
    char auxString[MAX];
    char bufferValorEntero[MAX];
    char bufferValorFloat[MAX];
    int auxEntero;
    float auxValorFloat;
    char seguir = 's';
    Entidad *pEntidad;
    if(pArrayListEntidad != NULL)
    {
        if(!utn_getUnsignedInt("\nIngrese el ID de empleado a modificar: ",
            "\nError, ID inválido.",1,MAX_EMPLOYEE, 2, &idIngresado))
        {
            if( !findEntidadById(  pArrayListEntidad,
                                    idIngresado,
                                    &posicionId))
                    {
                        pEntidad = ll_get(pArrayListEntidad, posicionId);
                        if(pEntidad != NULL)
                        {
                            if( !entidad_getId(pEntidad, &auxId)&&
                                !entidad_getString(pEntidad, auxString)&&
                                !entidad_getValorEntero(pEntidad, &auxEntero)&&
                                !entidad_getValorFloat(pEntidad, &auxValorFloat))
                                {
                                    printf("\n\nLos datos del empleado son:\n\n");
                                    printf("String : %s Id: %d Horas: %d ValorFloat: %f\n",
                                           auxString,
                                           auxId,
                                           auxEntero,
                                           auxValorFloat );
                                }
                        }
                    }
                    snprintf(bufferValorEntero,MAX, "%d", auxEntero);
                    snprintf(bufferValorFloat, MAX, "%f", auxValorFloat);
            while(seguir == 's')
            {
                printf("Elija el dato que desea modificar\n\n");

                printf("\n\n1-String");
                printf("\n\n2-Horas trabajadas");
                printf("\n\n3-ValorFloat");
                printf("\n\n4-Salir de la modificacion");

                utn_getUnsignedInt("\n\t\tIngrese opcion: ", "Ingreso incorrecto\n", 1, 4, 2, &opcion);


                switch(opcion)
                {
                    case 1:
                        if (!utn_getName("\n\nIngrese el nombre del empleado: ",
                            "Error, vuelva a ingresar\n\n",1,50,2,
                            auxString))
                        {
                            printf("El dato fue modificado con exito.\n\n");
                        }
                        break;
                    case 2:
                        if (!utn_getAlfanumerico("\n\nIngrese las horas trabajadas: ",
                            "Error, vuelva a ingresar\n\n",1,51,2,
                            bufferValorEntero))
                        {
                            printf("El dato fue modificado con exito.\n\n");
                        }
                        break;

                    case 3:
                         if (   !utn_getAlfanumerico("\n\nIngrese el sueldo: ",
                                "Error, vuelva a ingresar\n\n",1,51,2,bufferValorFloat))
                            {
                                printf("El dato fue modificado con exito.\n\n");
                            }

                        break;

                    case 4:
                        snprintf(bufferId,MAX, "%d", auxId);
                        pEntidad = entidad_newParametrosStr( bufferId,
                                                            auxString,
                                                            bufferValorEntero,
                                                            bufferValorFloat);
                        if(pEntidad != NULL)
                            ll_set(pArrayListEntidad, posicionId, pEntidad);
                        seguir = 'n';
                        retorno = 0;
                        break;
                }
            }
        }
    }
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEntidad LinkedList*
 * \return int
 *
 */
int controller_removeEntidad(LinkedList* pArrayListEntidad)
{
    int retorno = -1;
    int idIngresado;
    int posicionId;
    Entidad *pEntidad;
    if (pArrayListEntidad != NULL)
    {
        if( !utn_getUnsignedInt("\nIngrese el ID de empleado a dar de baja: ",
            "\nError, ID inválido.",1,MAX_EMPLOYEE, 2, &idIngresado))
            {
                if( !findEntidadById(pArrayListEntidad,
                    idIngresado,
                    &posicionId))
                    {
                        pEntidad = ll_pop(pArrayListEntidad, posicionId);
                        if(pEntidad != NULL)
                        {
                            entidad_delete(pEntidad);
                            printf("\n¡Entleado borrado exitosamente!\n\n");
                            retorno = 0;
                        }
                    }
                    else
                    {
                        printf("\nNo se encontró el ID\n\n");
                        retorno = -2;
                    }
            }
            else
            {
                printf("\nReintentos agotados\n\n");
                retorno = -3;
            }
    }

    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEntidad LinkedList*
 * \return int
 *
 */
int controller_ListEntidad(LinkedList* pArrayListEntidad)
{
    int i;
    char option = 'n';
    char option2 = 'n';
    int pagina = 99;
    Entidad *empleado;
    char bufferString[1000];
    int bufferId, bufferHoras;
    float bufferValorFloat;

    do
    {
        for(i = 0; i < ll_len(pArrayListEntidad); i++)
        {
            empleado = (Entidad*)ll_get(pArrayListEntidad, i);
            entidad_getString(empleado, bufferString);
            entidad_getId(empleado, &bufferId);
            entidad_getValorEntero(empleado,&bufferHoras);
            entidad_getValorFloat(empleado, &bufferValorFloat);
            printf("String : %s Id: %d Horas: %d ValorFloat: %.2f\n",
                   bufferString,
                   bufferId,
                   bufferHoras,
                   bufferValorFloat );
            if(i == pagina)
            {
                do
                {
                    utn_getChar("\n\tPresione 's' para siguiente pagina: ",
                    "Error, vuelva a intentar",1,2,2,&option2);
                    pagina+=99;
                    system("clear");
                }while(option2 == 'n');
            }
        }
        utn_getChar("\n\tPresione 's' para volver al menu principal: ",
                    "Error, vuelva a intentar",1,2,2,&option);
    }while(option == 'n');
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEntidad LinkedList*
 * \return int
 *
 */
int controller_sortEntidad(LinkedList* pArrayListEntidad)
{
    int retorno = -1;
    if(pArrayListEntidad != NULL)
    {
        ll_sort(pArrayListEntidad, entidad_compare, ASCENDENTE);
        retorno = 0;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv(modo texto)
 *
 * \param path char*
 * \param pArrayListEntidad LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEntidad)
{
    int retorno = -1;
    int bufferId;
    int bufferValorEntero;
    float bufferValorFloat;
    char bufferIdStr[MAX];
    char bufferString[MAX];
    char bufferValorEnteroStr[MAX];
    char bufferValorFloatStr[MAX];
    FILE* pFile = NULL;
    Entidad *pEntidad = NULL;
    if(path != NULL && pArrayListEntidad != NULL)
    {
        pFile = fopen(path, "w");
        if(pFile != NULL)
        {
          //  fprintf (pFile, "id,nombre,horasTrabajadas,sueldo\n");
            for(int i =0 ; i<ll_len(pArrayListEntidad) ; i++)
            {
                pEntidad = (Entidad*)ll_get(pArrayListEntidad, i);
                if(pEntidad != NULL)
                {
                    if( !entidad_getString(pEntidad, bufferString)&&
                        !entidad_getId(pEntidad, &bufferId)&&
                        !entidad_getValorEntero(pEntidad,
                                                     &bufferValorEntero)&&
                        !entidad_getValorFloat(pEntidad, &bufferValorFloat))
                        {
                            snprintf(bufferIdStr,MAX, "%d", bufferId);
                            snprintf(bufferValorEnteroStr,MAX, "%d",
                                     bufferValorEntero);
                            snprintf(bufferValorFloatStr,MAX, "%f", bufferValorFloat);
                            fprintf (pFile, "%s,%s,%s,%s\n",
                                     bufferIdStr,
                                     bufferString,
                                     bufferValorEnteroStr,
                                     bufferValorFloatStr);

                        }else{printf("Error al guardar\n");}
                }else{printf("Error al guardar\n");}

            }
            fclose(pFile);
            printf("Se ha guardado correctamente\n");
            retorno = 0;
        }else{printf("Error al guardar\n");}
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEntidad LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEntidad)
{
    int retorno = -1;
    FILE* pFile = NULL;
    Entidad * pEntidad = NULL;
    if(path != NULL && pArrayListEntidad != NULL)
    {
        pFile = fopen(path, "wb");
        if(pFile != NULL)
        {
            for(int i =0 ; i<ll_len(pArrayListEntidad) ; i++)
            {
                pEntidad = ll_get(pArrayListEntidad, i);
                if(pEntidad != NULL)
                    fwrite(pEntidad, sizeof(Entidad), 1, pFile);
            }
            fclose(pFile);
            printf("Guardado con exito\n");
            retorno = 0;
        }
    }
    return retorno;
}


int controller_nextId(LinkedList* pArrayListEntidad)
{
    int retorno = -1;
    int i;
    int idAux;
    int idMax;
    Entidad *pEntidad;
    if(pArrayListEntidad != NULL)
    {
        for(i=0;i<ll_len(pArrayListEntidad);i++)
        {
            pEntidad = (Entidad*)ll_get(pArrayListEntidad, i);
            if(i == 0)
            {
                entidad_getId(pEntidad, &idMax);
            }
            else
            {
                entidad_getId(pEntidad, &idAux);
                if(idAux > idMax)
                {
                    idMax = idAux;
                }
            }
        }
        retorno = idMax+1;
    }
    return retorno;
}
void Controller_printMenu()
{
    printf("\t\t*MENU*");
    printf("\n\n1-Cargar los datos de los empleados desde el archivo data.csv (modo texto).");
    printf("\n\n2-Cargar los datos de los empleados desde el archivo data.bin (modo binario)");
    printf("\n\n3-Alta de empleado");
    printf("\n\n4-Modificar datos de empleado");
    printf("\n\n5-Baja de empleado");
    printf("\n\n6-Listar empleados");
    printf("\n\n7-Ordenar empleados");
    printf("\n\n8-Guardar los datos de los empleados en el archivo data.csv (modo texto)");
    printf("\n\n9-Guardar los datos de los empleados en el archivo data.bin (modo binario)");
    printf("\n\n10-Salir\n");
}

void Controller_filtrarPorValorFloat(LinkedList *pArrayListEntidad)
{
    LinkedList *entidadValorFloat  = ll_filter(pArrayListEntidad, entidad_salary);
    controller_ListEntidad(entidadValorFloat);
}

void Controller_filtrarPorHoras(LinkedList *pArrayListEntidad)
{
    LinkedList *entidadHoras = ll_filter(pArrayListEntidad, entidad_horas);
    controller_ListEntidad(entidadHoras);
}

