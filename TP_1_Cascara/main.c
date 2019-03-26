#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int A=0;
    int B=0;
    int suma;
    int resta;
    float division;
    int multiplicacion;

    while(seguir=='s')
    {


        if(A == 0)
        {
            printf("\n1- Ingresar 1er operando (A=x)\n");
        }
        else
        {
            printf("\n1- Ingresar 1er operando (A=%d)\n", A);
        }
        if(B == 0)
        {
            printf("2- Ingresar 2do operando (B=y)\n");
        }
        else
        {
            printf("2- Ingresar 2do operando (B=%d)\n", B);
        }
            printf("3- Calcular la suma (A+B)\n");
            printf("4- Calcular la resta (A-B)\n");
            printf("5- Calcular la division (A/B)\n");
            printf("6- Calcular la multiplicacion (A*B)\n");
            printf("7- Calcular el factorial (A!)\n");
            printf("8- Calcular todas las operacione\n");
            printf("9- Salir\n");

            scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                A = ingresarNumero("\nIngrese 1er operando:");
                break;

            case 2:
                B = ingresarNumero("\nIngrese 2do operando:");
                break;

            case 3:
                suma = sumador(A, B);
                printf("\nLa suma es: %d\n\n", suma);
                break;

            case 4:
                resta = restador(A, B);
                printf("\nLa resta es: %d\n\n", resta);
                break;

            case 5:
                division = dividir(A, B);
                printf("\nLa division es: %.2f\n\n", division);
                break;

            case 6:
                multiplicacion = multiplicador(A, B);
                printf("\nLa multiplicacion es: %d\n\n", multiplicacion);
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                seguir = 'n';
                break;
        }

    }
    return 0;
}
