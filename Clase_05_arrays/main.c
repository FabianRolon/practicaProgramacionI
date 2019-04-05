#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD_ALUMNOS 10
#include "utn.h"

int main()
{
    /**int* pEdades;
    int bufferEdad;
    int aEdades[CANTIDAD_ALUMNOS];
    aEdades[100] = 22;
    bufferEdad = aEdades[100];
    pEdades = &aEdades[88];
    //pEdades = &aEdades[0]; = pEdades = aEdades;
    pEdades = aEdades; //el compilador sabe que con ese codigo quiero la direccion de memoria del primer elemento del array
    *(pEdades+88) = 11; //= pEdades[88] = 11;
    bufferEdad = *(pEdades+188); //la version mickey mouse es bufferEdad = aEdades[100];, es lo mismo

    getArrayInt("Ingrese el valor array", "ERROR", CANTIDAD_ALUMNOS, 0, 3, &aEdades);

**/
int aEdades[CANTIDAD_ALUMNOS];
getArrayInt("Ingrese el valor: ", "\nError", CANTIDAD_ALUMNOS, 1, 3, aEdades, 10);

ordenarArray(aEdades, 10);
printArrayInt(aEdades, 10);

return 0;
}
