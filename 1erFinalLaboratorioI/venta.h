#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED
typedef struct
{
    int idVenta;
    int idCliente;
    int codigoDeProducto;
    int cantidad;
}Venta;
#endif // VENTA_H_INCLUDED

Venta* venta_new();
void venta_delete(Venta *this);
int venta_setIdVenta(Venta* this,int idVenta);
int venta_getIdVenta(Venta* this,int* idVenta);
int venta_setIdCliente(Venta* this,int idCliente);
int venta_getIdCliente(Venta* this,int* idCliente);
int venta_setCodigoDeProducto(Venta* this,int codigoProducto);
int venta_getCodigoDeProducto(Venta* this,int* codigoProducto);
int venta_setCantidad(Venta* this,int cantidad);
int venta_getCantidad(Venta* this,int* cantidad);






