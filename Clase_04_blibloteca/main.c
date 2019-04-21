#include <stdio.h>
#include <stdlib.h>
#include "utn.h"


/**hacer funcion que valide ,maximo, minimo, cantidad de reintentos,
validaciones: preguntar si el puntero no e NULL. Reintentos tiene que ser >= 0
**/

int main()
{
    int valor;
    float altura;
    char letra;
    getInt("Ingrese su edad:\n", "ERROR!\n", 0, 150, 3, &valor);
    getFloat("\nIngrese su altura en metros:", "ERROR!\n", 0, 3.5, 3, &altura);
    getChar("\nIngrese una letra:", "\nERROR!", 'a', 'z', 3, &letra);
    return 0;
}












