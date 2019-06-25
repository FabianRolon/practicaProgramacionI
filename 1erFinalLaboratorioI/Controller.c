#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "cliente.h"
#include "venta.h"
#include "parser.h"
#include "Controller.h"
#include "utn.h"
#define MAX_CLIENTE 9999
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
int controller_loadFromTextClientes(char* path , LinkedList* pArrayListCliente)
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
                printf("\nCarga de clientes exitosa\n");
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
    idAux = controller_nextIdCliente(pArrayListCliente);
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
                controller_saveAsTextCliente("clientes.txt",pArrayListCliente);
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
            "\nError, ID inválido.",1,MAX_CLIENTE, 2, &idIngresado))
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
            "\nError, ID inválido.",1,MAX_CLIENTE, 2, &idIngresado))
            {
                if( !findClienteById(pArrayListCliente,
                    idIngresado,
                    &posicionId))
                    {
                        pCliente = ll_pop(pArrayListCliente, posicionId);
                        if(pCliente != NULL)
                        {
                            cliente_delete(pCliente);
                            controller_saveAsTextCliente("clientes.txt",pArrayListCliente);
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
                        printf("Id: %d\t Nombre : %s\t  Apellido: %s\t DNI: %s\n",
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
int controller_saveAsTextCliente(char* path , LinkedList* pArrayListCliente)
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
int controller_nextIdCliente(LinkedList* pArrayListCliente)
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
    printf("\n1-Alta de cliente");
    printf("\n2-Modificar datos de cliente");
    printf("\n3-Baja de cliente");
    printf("\n4-Listar clientes");
    printf("\n5-Realizar una venta");
    printf("\n6-Anular una venta");
    printf("\n7-Informar ventas");
    printf("\n8-Informar ventas por producto");
    printf("\n9-Generar informe de ventas");
    printf("\n10-Informar cantidad de ventas por cliente");
    printf("\n11-Salir\n");
}

int controller_addVenta(LinkedList* pArrayListVenta, LinkedList *pArrayListCliente)
{
    int retorno = -1;
    int idPosAux;
    int bufferIdVenta = controller_nextIdVenta(pArrayListVenta);
    int bufferIdCliente;
    int bufferCodigoProducto;
    int bufferCantidad;
    float bufferPrecioUnitario;
    Venta *bufferVenta;

    if (pArrayListCliente != NULL)
        {
            utn_getUnsignedInt("\n\nIngrese el ID del cliente: ",
                "Error, vuelva a ingresar\n\n",1,50,2,
                &bufferIdCliente);
            if(!findClienteById(pArrayListCliente, bufferIdCliente, &idPosAux))
            {

                if( utn_getUnsignedInt("\n\n1000 - TV_LG\n"
                    "1001 -​ ​PS4​\n"
                    "1002 -​ IPHONE7\n"
                    "Ingrese el codigo de producto: ",
                    "Error, vuelva a ingresar\n\n",1,30,2,
                    &bufferCodigoProducto) == 0 &&
                    utn_getUnsignedInt("\n\nIngrese la cantidad: ",
                    "Error, vuelva a ingresar\n\n",1,51,2,&bufferCantidad) == 0)
                {
                        bufferPrecioUnitario = precioUnitario(bufferCodigoProducto);
                        bufferVenta = venta_newParametros(  bufferIdVenta,
                                                            bufferIdCliente,
                                                            bufferCodigoProducto,
                                                            bufferCantidad,
                                                            bufferPrecioUnitario);
                        if(bufferVenta != NULL)
                        {
                            ll_add(pArrayListVenta, bufferVenta);
                        }
                        else
                        {
                            cliente_delete(bufferVenta);
                            printf("ERROR, el cliente no se agrego!");
                            retorno = -1;
                        }

                        printf("Exito, cliente agregado!");
                        controller_saveAsTextVenta("ventas.txt",pArrayListVenta);
                        retorno = 0;

                }else
                {
                    printf("ERROR, reintentos agotados!");
                    retorno = -2;
                }
            }else
            {
                printf("ERROR, no se encontro el id!");
                retorno = -3;
            }
        }else
        {
            printf("ERROR, NULL");
        }
    return retorno;
}

int controller_ListVenta(LinkedList* pArrayListVenta, LinkedList *pArrayListCliente)
{
    int retorno = -1;
    int i;
    int auxPosicion;
    char option = 'n';
    char option2 = 'n';
    int pagina = 99;
    int bufferCodigoProducto;
    Venta *venta;
    Cliente *cliente;
    int bufferIdVenta;
    int bufferIdCliente;
    int bufferCantidad;
    char bufferNombre[MAX];
    char bufferApellido[MAX];
    char bufferDni[MAX];
    float bufferPrecioUnitario;
    float montoFacturado;
    printf("Cargando lista...\n");
    if(pArrayListVenta != NULL)
    {
        do
        {
            for(i = 0; i < ll_len(pArrayListVenta); i++)
            {
                venta = (Venta*)ll_get(pArrayListVenta, i);
                if( !venta_getIdVenta(venta, &bufferIdVenta)&&
                    !venta_getIdCliente(venta, &bufferIdCliente)&&
                    !venta_getCantidad(venta, &bufferCantidad)&&
                    !venta_getCodigoDeProducto(venta, &bufferCodigoProducto)&&
                    !venta_getPrecioUnitario(venta,&bufferPrecioUnitario))
                    {
                        montoFacturado = precioPorCantidad(bufferCodigoProducto, bufferCantidad);
                        findClienteById(pArrayListCliente, bufferIdCliente, &auxPosicion);
                        cliente = (Cliente*)ll_get(pArrayListCliente, auxPosicion);
                        if( !cliente_getNombre(cliente, bufferNombre)&&
                            !cliente_getApellido(cliente, bufferApellido)&&
                            !cliente_getDni(cliente, bufferDni))
                        {
                        printf("IdVenta: %d\t Nombre: %s\t Apellido: %s\t DNI: %s\t  CodProducto: %d\t Monto Facturado: %.2f\t PU: %f\n",
                                bufferIdVenta,
                                bufferNombre,
                                bufferApellido,
                                bufferDni,
                                bufferCodigoProducto,
                                montoFacturado,
                                bufferPrecioUnitario);
                        retorno = 0;
                        }
                    }
                    else
                    {
                        printf("\nNo se pudo mostrar la venta\n");
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

int controller_saveAsTextVenta(char* path , LinkedList* pArrayListVenta)
{
    int retorno = -1;
    char bufferIdVenta[MAX];
    char bufferIdCliente[MAX];
    char bufferCodigoProducto[MAX];
    char bufferCantidad[MAX];
    char bufferPrecioUnitario[MAX];
    FILE* pFile = NULL;
    Venta *pVenta = NULL;
    if(path != NULL && pArrayListVenta != NULL)
    {
        pFile = fopen(path, "w");
        if(pFile != NULL)
        {
          //  fprintf (pFile, "id,nombre,horasTrabajadas,sueldo\n");
            for(int i =0 ; i<ll_len(pArrayListVenta) ; i++)
            {
                pVenta = (Venta*)ll_get(pArrayListVenta, i);
                if(pVenta != NULL)
                {
                    if( !venta_getIdVentaStr(pVenta, bufferIdVenta)&&
                        !venta_getIdClienteStr(pVenta, bufferIdCliente)&&
                        !venta_getCodigoDeProductoStr(pVenta, bufferCodigoProducto)&&
                        !venta_getCantidadStr(pVenta, bufferCantidad)&&
                        !venta_getPrecioUnitarioStr(pVenta, bufferPrecioUnitario))
                        {
                            fprintf (pFile, "%s,%s,%s,%s,%s\n",
                                     bufferIdVenta,
                                     bufferIdCliente,
                                     bufferCodigoProducto,
                                     bufferCantidad,
                                     bufferPrecioUnitario);

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

int controller_nextIdVenta(LinkedList* pArrayListVenta)
{
    int retorno = -1;
    int i;
    int idAux;
    int idMax;
    Venta *pVenta;
    if(pArrayListVenta != NULL)
    {
        for(i=0;i<ll_len(pArrayListVenta);i++)
        {
            pVenta = (Venta*)ll_get(pArrayListVenta, i);
            if(i == 0)
            {
                venta_getIdVenta(pVenta, &idMax);
            }
            else
            {
                venta_getIdVenta(pVenta, &idAux);
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

int controller_loadFromTextVentas(char* path , LinkedList* pArrayListVenta)
{
    int retorno = -1;

    FILE* pFile;
    pFile = NULL;
    pFile = fopen(path,"r");

    if(pFile!=NULL)
    {
        if(path != NULL && pArrayListVenta != NULL)
        {
             if(!parser_VentaFromText(pFile , pArrayListVenta))
             {
                printf("\nCarga de ventas exitosa\n");
                fclose(pFile);
                retorno = 0;
             }
        }
     }
     return retorno;
}

int controller_removeVenta(LinkedList* pArrayListVenta)
{
    int retorno = -1;
    int idIngresado;
    int posicionId;
    Venta *pVenta;
    if (pArrayListVenta != NULL)
    {
        if( !utn_getUnsignedInt("\nIngrese el ID de venta a anular: ",
            "\nError, ID inválido.",1,MAX_CLIENTE, 2, &idIngresado))
            {
                if( !findVentaById(pArrayListVenta,
                    idIngresado,
                    &posicionId))
                    {
                        pVenta = ll_pop(pArrayListVenta, posicionId);
                        if(pVenta != NULL)
                        {
                            venta_delete(pVenta);
                            controller_saveAsTextVenta("ventas.txt",pArrayListVenta);
                            printf("\n¡Venta anulada exitosamente!\n\n");
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

int controller_saveAsTextInformeVenta(char* path ,LinkedList *pArrayListVenta , LinkedList* pArrayListCliente)
{
    int retorno = -1;
    int i;
    int auxPosicion;
    char bufferNombre[MAX];
    char bufferApellido[MAX];
    char bufferDni[MAX];
    Venta *pVenta;
    char bufferIdVenta[MAX];
    int bufferIdCliente;
    int bufferCantidad;
    int bufferCodigoProducto;
    char bufferCodigoProductoStr[MAX];
    float bufferPrecioUnitario;
    float montoFacturado;
    char montoFacturadoStr[MAX];
    FILE* pFile = NULL;
    Cliente *pCliente = NULL;
    if(path != NULL && pArrayListCliente != NULL && pArrayListVenta != NULL)
    {
        pFile = fopen(path, "w");
        if(pFile != NULL)
        {
            for(i = 0; i < ll_len(pArrayListVenta); i++)
            {
                pVenta = (Venta*)ll_get(pArrayListVenta, i);
                if( !venta_getIdVentaStr(pVenta, bufferIdVenta)&&
                    !venta_getIdCliente(pVenta, &bufferIdCliente)&&
                    !venta_getCantidad(pVenta, &bufferCantidad)&&
                    !venta_getCodigoDeProducto(pVenta, &bufferCodigoProducto)&&
                    !venta_getPrecioUnitario(pVenta,&bufferPrecioUnitario))
                    {
                        montoFacturado = precioPorCantidad(bufferCodigoProducto, bufferCantidad);
                        findClienteById(pArrayListCliente, bufferIdCliente, &auxPosicion);
                        pCliente = (Cliente*)ll_get(pArrayListCliente, auxPosicion);
                        if( !cliente_getNombre(pCliente, bufferNombre)&&
                            !cliente_getApellido(pCliente, bufferApellido)&&
                            !cliente_getDni(pCliente, bufferDni))
                        {
                            sprintf(montoFacturadoStr, "%.2f", montoFacturado);
                            sprintf(bufferCodigoProductoStr, "%d", bufferCodigoProducto);
                        fprintf(pFile,"%s,%s,%s,%s,%s,%s\n",
                                bufferIdVenta,
                                bufferNombre,
                                bufferApellido,
                                bufferDni,
                                bufferCodigoProductoStr,
                                montoFacturadoStr);

                        }else
                        {
                            printf("Error al guardar\n");
                            break;
                        }
                    }else
                    {
                        printf("Error al guardar\n");
                        break;
                    }
                }
                printf("Se ha guardado correctamente\n");
                retorno = 0;
                fclose(pFile);
            }else{printf("Error al guardar\n");}
        }
        return retorno;
}

int controller_ventasPorProducto(LinkedList *pArrayListCliente, LinkedList *pArrayListVenta)
{
    int retorno = -1;
    int bufferCodigoProducto;
    LinkedList *filtradaCodigo = NULL;
    if(pArrayListCliente != NULL && pArrayListVenta != NULL)
    {
        utn_getUnsignedInt("\n\n1000 - TV_LG\n"
                    "1001 -​ ​PS4​\n"
                    "1002 -​ IPHONE7\n"
                    "Ingrese el codigo de producto: ",
                    "Error, vuelva a ingresar\n\n",1,30,2,
                    &bufferCodigoProducto);
        switch(bufferCodigoProducto)
        {
            case 1000:
                filtradaCodigo = ll_filter(pArrayListVenta, venta_1000);
                controller_ListVenta(filtradaCodigo, pArrayListCliente);
                retorno = 0;
                break;
            case 1001:
                filtradaCodigo = ll_filter(pArrayListVenta, venta_1001);
                controller_ListVenta(filtradaCodigo, pArrayListCliente);
                retorno = 0;
                break;
            case 1002:
                filtradaCodigo = ll_filter(pArrayListVenta, venta_1002);
                controller_ListVenta(filtradaCodigo, pArrayListCliente);
                retorno = 0;
                break;
            default:
                printf("\n\nNo se encontro el codigo de producto ingresado");
        }
    }
    return retorno;
}


