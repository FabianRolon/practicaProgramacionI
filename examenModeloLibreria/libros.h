#ifndef LIBROS_H_INCLUDED
#define LIBROS_H_INCLUDED

typedef struct
{
    int codigoAutor;
    char titulo[20];
    int isEmpty;
    int codigoLibro;
}Libros;

int lib_Inicializar(Libros *arrayLibro, int cantidad);
int lib_buscarLibre(Libros *arrayLibro, int cantidad, int *devuelve);
int lib_alta(Libros *arrayLibro, Autores *arrayAutor, int cantidadLibro, int cantidadAutor, int posLibre, int id);
int lib_buscarEnArrayPorId (Libros *arrayLibro, int cantidad, int *libroEncontrado,char *textoAMostrar);




#endif // LIBROS_H_INCLUDED
