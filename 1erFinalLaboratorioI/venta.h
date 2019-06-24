#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED
typedef struct
{
    int idVenta;
    int idCliente;
    int codigoDeProducto;
    int cantidad;
    float precioUnitario;
}Venta;
#endif // VENTA_H_INCLUDED

Venta* venta_new();
void venta_delete(Venta *this);

Venta* venta_newParametros(int idVenta,int idCliente,int codigoProducto, int cantidad, float precioUnitario);
Venta* venta_newParametrosStr(char* idVenta,char* idCliente,char* codigoProducto, char* cantidad, char *precioUnitario);

int venta_setIdVenta(Venta* this,int idVenta);
int venta_getIdVenta(Venta* this,int* idVenta);

int venta_setIdCliente(Venta* this,int idCliente);
int venta_getIdCliente(Venta* this,int* idCliente);

int venta_setCodigoDeProducto(Venta* this,int codigoProducto);
int venta_getCodigoDeProducto(Venta* this,int* codigoProducto);

int venta_setCantidad(Venta* this,int cantidad);
int venta_getCantidad(Venta* this,int* cantidad);

int venta_setPrecioUnitario(Venta* this,float precioUnitario);
int venta_getPrecioUnitario(Venta* this,float* precioUnitario);

int venta_setIdVentaStr(Venta* this, char* idStr);
int venta_getIdVentaStr(Venta* this, char* result);

int venta_setIdClienteStr(Venta* this, char* idStr);
int venta_getIdClienteStr(Venta* this, char* result);

int venta_setCodigoDeProductoStr(Venta* this, char* codigoProducto);
int venta_getCodigoDeProductoStr(Venta* this, char* result);

int venta_setCantidadStr(Venta* this, char* cantidad);
int venta_getCantidadStr(Venta* this, char* result);

int venta_setPrecioUnitarioStr(Venta* this, char* precioUnitario);
int venta_getPrecioUnitarioStr(Venta* this, char* result);

int findVentaById(LinkedList* pArrayListVenta, int id, int *posicionId);
float precioPorCantidad (int codigoProducto, int cantidad);
float precioUnitario (int codigoProducto);





