#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include <stdio_ext.h>

/** \brief  To indicate that all position in the array are empty,
 *          this function put the flag (isEmpty) in TRUE in all
 *          position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len)
{

    int retorno = -1;
    int i;

    for (i = 0; i < cantidad; i++)
    {
        arrayLibro[i].isEmpty = 1;
        retorno=0;
    }

    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int findEmployeeById(Employee array[], int size, int valorBuscado, int* posicion)                    //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idEmployee==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca el primer lugar vacio en un array
* \param array employee Array de employee
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int emp_buscarEmpty(Employee array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief add in a existing list of employees the values received as parameters
 *     in the first empty position
 * \param array employee Array de employee
 * \param size int
 * \param id int
 * \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */
  int addEmployee(Employee array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(emp_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idEmployee=*contadorID;
            array[posicion].isEmpty=0;
            utn_getName("\nIngrese el nombre: ","\nError",1,TEXT_SIZE,1,array[posicion].name);
            utn_getName("\nIngrese el apellido: ","\nError",1,TEXT_SIZE,1,array[posicion].lastName);
            utn_getFloat("\nIngrese el salario: ","\nError",1,sizeof(float),0,1,1,&array[posicion].salary);
            utn_getUnsignedInt("\nIngrese el sector: ","\nError",1,sizeof(int),1,10,1,&array[posicion].sector);
            printf("\n Posicion: %d\n ID: %d\n Sector: %d\n Salario: %f\n Nombre: %s\n Apellido: %s",
                   posicion, array[posicion].idEmployee,array[posicion].sector,array[posicion].salary,array[posicion].name,array[posicion].lastName);
            retorno=0;
        }
    }
    return retorno;
}

/*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array employee Array de employee
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int removeEmployee(Employee array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(findEmployeeById(array,sizeArray,id,&posicion)==-1)
            printf("\nNo existe este ID");
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idEmployee=0;
            array[posicion].sector=0;
            array[posicion].salary=0;
            strcpy(array[posicion].name,"");
            strcpy(array[posicion].lastName,"");
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array employee Array de employee
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int employee_bajaValorRepetidoInt(Employee array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idEmployee==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idEmployee=0;                                                                   //cambiar campo id
                array[i].sector=0;                                                               //cambiar campo sector
                array[i].salary=0;                                                             //cambiar campo salary
                strcpy(array[i].name,"");                                                   //cambiar campo name
                strcpy(array[i].lastName,"");                                               //cambiar campo lastName
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array employee Array de employee
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int employee_modificar(Employee array[], int sizeArray)                                //cambiar employee
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(employee_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n Sector: %d\n Salario: %f\n Nombre: %s\n Apellido: %s",
                   posicion, array[posicion].idEmployee,array[posicion].sector,array[posicion].salary,array[posicion].name,array[posicion].lastName);
                utn_getChar("\nModificar: A B C D S(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,1,1,&array[posicion].sector);           //mensaje + cambiar campo sector
                        break;
                    case 'B':
                        utn_getFloat("\n: ","\nError",1,sizeof(float),0,1,1,&array[posicion].salary);             //mensaje + cambiar campo salary
                        break;
                    case 'C':
                        utn_getName("\n: ","\nError",1,TEXT_SIZE,1,array[posicion].name);                      //mensaje + cambiar campo name
                        break;
                    case 'D':
                        utn_getTexto("\n: ","\nError",1,TEXT_SIZE,1,array[posicion].lastName);             //mensaje + cambiar campo lastName
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array ante la igualdad de estos ordena por el campo ZZZZZZ
* \param array employee Array de employee
* \param size int Tamaño del array
* \param orderFirst int Determina si el orden del primer criterio es ascendete o descendente
* \param orderSecond int Determina si el orden del segunbdo criterio es ascendete o descendente
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int employee_ordenarPorDobleCriterio(Employee array[],int size, int orderFirst, int orderSecond)                              //cambiar employee
{
    int retorno=-1;
    int i;
    Employee buffer;
    int flagSwap;

    if(array!=NULL && size>=0)
    {
        do
        {
            flagSwap=0;
            for (i = 1; i < size-1; i++)
            {
                if( ((strcmp(array[i].name,array[i+1].name) < 0) && orderFirst) ||
                    ((strcmp(array[i].name,array[i+1].name) > 0) && !orderFirst) )
                {
                    flagSwap=1;
                    buffer = array[i];
                    array[i] = array[i+1];
                    array[i+1] = buffer;
                }
                else if(strcmp(array[i].name,array[i+1].name) == 0)
                {
                    if( ((array[i].salary < array[i+1].salary) && orderSecond) ||
                        ((array[i].salary > array[i+1].salary) && !orderSecond) )
                    {
                        flagSwap=1;
                        buffer = array[i];
                        array[i] = array[i+1];
                        array[i+1] = buffer;
                    }
                }
            }
        }while(flagSwap);
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array employee Array de employee
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int printEmployees(Employee array[], int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
                printf("\n Posicion: %d\n ID: %d\n Sector: %d\n Salario: %f\n Nombre: %s\n Apellido: %s",
                   posicion, array[posicion].idEmployee,array[posicion].sector,array[posicion].salary,array[posicion].name,array[posicion].lastName);
        }
        retorno=0;
    }
    return retorno;
}


