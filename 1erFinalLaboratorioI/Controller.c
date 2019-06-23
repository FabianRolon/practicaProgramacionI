#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "cliente.h"
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
 * \param pArrayListCliente LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListCliente)
{
    int retorno = -1;

    FILE* pFile;
    pFile = NULL;
    pFile = fopen(path,"r");

    if(pFile!=NULL)
    {
        if(path != NULL && pArrayListCliente != NULL)
        {
             if(!parser_ClienteFromText(pFile , pArrayListCliente))
             {
                printf("\nCarga exitosa\n");
                fclose(pFile);
                retorno = 0;
             }
        }
     }
     return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListCliente LinkedList*
 * \return int
 *
 */
int controller_addCliente(LinkedList* pArrayListCliente)
{
    int retorno = -1;
    int idAux;
    char bufferId[MAX];
    char bufferNombre[MAX];
    char bufferApellido[MAX];
    char bufferDni[MAX];
    Cliente *bufferCliente;
    idAux = controller_nextId(pArrayListCliente);
    snprintf(bufferId,MAX, "%d", idAux);

    if (pArrayListCliente != NULL)
        {
            if( utn_getName("\n\nIngrese el nombre del cliente: ",
                "Error, vuelva a ingresar\n\n",1,50,2,
                bufferNombre) == 0 &&
                utn_getName("\n\nIngrese el apellido del cliente: ",
                "Error, vuelva a ingresar\n\n",1,51,2,
                bufferApellido) == 0 &&
                utn_getDNI("\n\nIngrese el DNI: ",
                "Error, vuelva a ingresar\n\n",1,51,2,bufferDni) == 0)
            {
                bufferCliente = cliente_newParametrosStr(   bufferId,
                                                            bufferNombre,
                                                            bufferApellido,
                                                            bufferDni);
                if(bufferCliente != NULL)
                {
                    ll_add(pArrayListCliente, bufferCliente);
                }
                else
                {
                    cliente_delete(bufferCliente);
                    printf("ERROR, el cliente no se agrego!\n");
                    retorno = -1;
                }

                printf("Exito, cliente agregado!\n");
                controller_saveAsText("data.csv",pArrayListCliente);
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

/** \brief Modificar datos de cliente
 *
 * \param path char*
 * \param pArrayListCliente LinkedList*
 * \return int
 *
 */
int controller_editCliente(LinkedList* pArrayListCliente)
{
    int retorno = -1;
    int opcion;
    int idIngresado;
    int posicionId;
    int auxId;
    char bufferId[MAX];
    char auxNombre[MAX];
    char bufferApellido[MAX];
    char bufferdni[MAX];
    char seguir = 's';
    Cliente *pCliente;
    if(pArrayListCliente != NULL)
    {
        if(!utn_getUnsignedInt("\nIngrese el ID de cliente a modificar: ",
            "\nError, ID inválido.",1,MAX_EMPLOYEE, 2, &idIngresado))
        {
            if( !findClienteById(  pArrayListCliente,
                                    idIngresado,
                                    &posicionId))
                    {
                        pCliente = ll_get(pArrayListCliente, posicionId);
                        if(pCliente != NULL)
                        {
                            if( !cliente_getId(pCliente, &auxId)&&
                                !cliente_getNombre(pCliente, auxNombre)&&
                                !cliente_getApellido(pCliente, bufferApellido)&&
                                !cliente_getDni(pCliente, bufferdni))
                                {
                                    printf("\n\nLos datos del cliente son:\n\n");
                                    printf("Nombre : %s Id: %d Apellido: %s DNI: %s\n",
                                           auxNombre,
                                           auxId,
                                           bufferApellido,
                                           bufferdni );
                                }
                        }

                        while(seguir == 's')
                        {
                            printf("Elija el dato que desea modificar\n\n");

                            printf("\n\n1-Nombre");
                            printf("\n\n2-Apellido");
                            printf("\n\n3-DNI");
                            printf("\n\n4-Salir de la modificacion");

                            utn_getUnsignedInt("\n\t\tIngrese opcion: ", "Ingreso incorrecto\n", 1, 4, 2, &opcion);


                            switch(opcion)
                            {
                                case 1:
                                    if (!utn_getName("\n\nIngrese el nombre del cliente: ",
                                        "Error, vuelva a ingresar\n\n",1,50,2,
                                        auxNombre))
                                    {
                                        printf("El dato fue modificado con exito.\n\n");
                                    }
                                    break;
                                case 2:
                                    if (!utn_getName("\n\nIngrese el apellido del cliente: ",
                                        "Error, vuelva a ingresar\n\n",1,51,2,
                                        bufferApellido))
                                    {
                                        printf("El dato fue modificado con exito.\n\n");
                                    }
                                    break;

                                case 3:
                                     if (   !utn_getDNI("\n\nIngrese el DNI: ",
                                            "Error, vuelva a ingresar\n\n",1,51,2,bufferdni))
                                        {
                                            printf("El dato fue modificado con exito.\n\n");
                                        }

                                    break;

                                case 4:
                                    snprintf(bufferId,MAX, "%d", auxId);
                                    pCliente = cliente_newParametrosStr(bufferId,
                                                                        auxNombre,
                                                                        bufferApellido,
                                                                        bufferdni);
                                    if(pCliente != NULL)
                                        ll_set(pArrayListCliente, posicionId, pCliente);
                                    seguir = 'n';
                                    retorno = 0;
                                    break;
                            }
                        }
                    }
                    else
                    {
                        printf("\nNo se encontro el id");
                        retorno = -2;
                    }
        }
    }
    return retorno;
}

/** \brief Baja de Cliente
 *
 * \param pArrayListCliente LinkedList*
 * \return int -1 si NULL o ERROR
                0 exito
 *
 */
int controller_removeCliente(LinkedList* pArrayListCliente)
{
    int retorno = -1;
    int idIngresado;
    int posicionId;
    Cliente *pCliente;
    if (pArrayListCliente != NULL)
    {
        if( !utn_getUnsignedInt("\nIngrese el ID de empleado a dar de baja: ",
            "\nError, ID inválido.",1,MAX_EMPLOYEE, 2, &idIngresado))
            {
                if( !findClienteById(pArrayListCliente,
                    idIngresado,
                    &posicionId))
                    {
                        pCliente = ll_pop(pArrayListCliente, posicionId);
                        if(pCliente != NULL)
                        {
                            cliente_delete(pCliente);
                            printf("\n¡Cliente borrado exitosamente!\n\n");
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

/** \brief Listar Clientes
 *
 * \param pArrayListCliente LinkedList*
 * \return int
 *
 */
int controller_ListCliente(LinkedList* pArrayListCliente)
{
    int retorno = -1;
    int i;
    char option = 'n';
    char option2 = 'n';
    int pagina = 99;
    int bufferId;
    Cliente *cliente;
    char bufferNombre[1000];
    char bufferApellido[1000];
    char bufferDni[1000];
    printf("Cargando lista...\n");
    ll_sort(pArrayListCliente, cliente_compare, ASCENDENTE);
    if(pArrayListCliente != NULL)
    {
        do
        {
            for(i = 0; i < ll_len(pArrayListCliente); i++)
            {
                cliente = (Cliente*)ll_get(pArrayListCliente, i);
                if( !cliente_getNombre(cliente, bufferNombre)&&
                    !cliente_getId(cliente, &bufferId)&&
                    !cliente_getApellido(cliente,bufferApellido)&&
                    !cliente_getDni(cliente, bufferDni))
                    {
                        printf("Id: %d Nombre : %s  Apellido: %s DNI: %s\n",
                                bufferId,
                                bufferNombre,
                                bufferApellido,
                                bufferDni );
                        retorno = 0;
                    }
                    else
                    {
                        printf("\nNo se pudo mostrar al cliente\n");
                        retorno = -1;
                    }

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
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListCliente LinkedList*
 * \return int
 *
 */
int controller_sortCliente(LinkedList* pArrayListCliente)
{
    int retorno = -1;
    if(pArrayListCliente != NULL)
    {
        ll_sort(pArrayListCliente, cliente_compare, ASCENDENTE);
        retorno = 0;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv(modo texto)
 *
 * \param path char*
 * \param pArrayListCliente LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListCliente)
{
    int retorno = -1;
    char bufferIdStr[MAX];
    char bufferNombre[MAX];
    char bufferApellido[MAX];
    char bufferDni[MAX];
    FILE* pFile = NULL;
    Cliente *pCliente = NULL;
    if(path != NULL && pArrayListCliente != NULL)
    {
        pFile = fopen(path, "w");
        if(pFile != NULL)
        {
          //  fprintf (pFile, "id,nombre,horasTrabajadas,sueldo\n");
            for(int i =0 ; i<ll_len(pArrayListCliente) ; i++)
            {
                pCliente = (Cliente*)ll_get(pArrayListCliente, i);
                if(pCliente != NULL)
                {
                    if( !cliente_getNombre(pCliente, bufferNombre)&&
                        !cliente_getIdString(pCliente, bufferIdStr)&&
                        !cliente_getApellido(pCliente, bufferApellido)&&
                        !cliente_getDni(pCliente, bufferDni))
                        {
                            fprintf (pFile, "%s,%s,%s,%s\n",
                                     bufferIdStr,
                                     bufferNombre,
                                     bufferApellido,
                                     bufferDni);

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

/** \brief Guarda los datos de los clientes en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListCliente LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListCliente)
{
    int retorno = -1;
    FILE* pFile = NULL;
    Cliente * pCliente = NULL;
    if(path != NULL && pArrayListCliente != NULL)
    {
        pFile = fopen(path, "wb");
        if(pFile != NULL)
        {
            for(int i =0 ; i<ll_len(pArrayListCliente) ; i++)
            {
                pCliente = ll_get(pArrayListCliente, i);
                if(pCliente != NULL)
                    fwrite(pCliente, sizeof(Cliente), 1, pFile);
            }
            fclose(pFile);
            printf("Guardado con exito\n");
            retorno = 0;
        }
    }
    return retorno;
}


int controller_nextId(LinkedList* pArrayListCliente)
{
    int retorno = -1;
    int i;
    int idAux;
    int idMax;
    Cliente *pCliente;
    if(pArrayListCliente != NULL)
    {
        for(i=0;i<ll_len(pArrayListCliente);i++)
        {
            pCliente = (Cliente*)ll_get(pArrayListCliente, i);
            if(i == 0)
            {
                cliente_getId(pCliente, &idMax);
            }
            else
            {
                cliente_getId(pCliente, &idAux);
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
    printf("\n\n1-Alta de cliente");
    printf("\n\n2-Modificar datos de cliente");
    printf("\n\n3-Baja de cliente");
    printf("\n\n4-Listar clientes");
    printf("\n\n5-Realizar una venta");
    printf("\n\n6-Anular una venta");
    printf("\n\n7-Informar ventas");
    printf("\n\n8-Informar ventas por producto");
    printf("\n\n9-Generar informe de ventas");
    printf("\n\n10-Informar cantidad de ventas por cliente");
    printf("\n\n11-Salir\n");
}




