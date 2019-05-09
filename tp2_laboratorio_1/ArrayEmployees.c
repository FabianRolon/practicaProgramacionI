#include <string.h>
#include <stdio.h>
#include <stdlib.h>
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

/** \brief add in a existing list of employees the values received as parameters
 *     in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */
  int addEmployee(Employee* list, int len,  id, char name[],lastName[],float salary,int sector)
{
    return -1;
}
