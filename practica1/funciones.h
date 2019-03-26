#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define CANTIDAD_INGRESOS 5


int cargarNumeros()
{
    int i;
    int numero;
    int sumaTotal=0;
    int maximo;
    int minimo;

    for(i=0;i<CANTIDAD_INGRESOS;i++)
    {
        printf("Ingrese %d numeros:",CANTIDAD_INGRESOS);
        scanf("%d", &numero);
        sumaNumeros(&sumaTotal, numero);
        if(i == 0)
        {
            maximo = numero;
            minimo = numero;
        }
        calculadorMaximoMinimo(numero, &maximo, &minimo);
    }
    printf("\nEl promedio es %.2f", (float)sumaTotal/CANTIDAD_INGRESOS);
    printf("\nEl Maximo es: %d", maximo);
    printf("\nEl Minimo es: %d", minimo);
    return 0;
}


#endif // FUNCIONES_H_INCLUDED
