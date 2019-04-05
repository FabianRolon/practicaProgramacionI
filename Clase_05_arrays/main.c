#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD_ALUMNOS 5000
#include "utn.h"

 int getArrayInt(   char* Msg,
                    char* msgError,
                    int maximo,
                    int minimo,
                    int reintentos,
                    int* arrayResultado,
                    int limite);

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
int aEdades[10] = {8,1,0,4,9,5,2,3,6,7};

ordenarArray(aEdades, 10);
printArrayInt(aEdades, 10);

return 0;
}
