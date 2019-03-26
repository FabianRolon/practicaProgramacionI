#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

int ingresarNumero(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}

int sumador(int primerTermino, int segundoTermino)
{
    return primerTermino + segundoTermino;
}

int restador(int primerTermino, int segundoTermino)
{
    return primerTermino - segundoTermino;
}

float dividir(float dividendo, float divisor)
{
    if(divisor == 0)
    {
        return -1;
    }

    return dividendo / divisor;
}

int multiplicador(int primerTermino, int segundoTermino)
{
    return primerTermino * segundoTermino;
}

#endif // FUNCIONES_H_INCLUDED
