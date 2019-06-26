#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED
typedef struct
{
    int id;
    char tipo[128];
    int cantidad;
    float importe;
}Data;
#endif // DATA_H_INCLUDED

Data* data_new();
Data* data_newParametrosStr(char* idStr,char* tipoStr,char* cantidadStr, char* importeStr);
Data* data_newParametros(int id, char* tipoStr,int cantidad, int importe);
void data_delete();

int data_setId(Data* this,int id);
int data_getId(Data* this,int* id);
int data_setIdString(Data* this, char* idStr);
int data_getIdString(Data* this, char* result);

int data_setTipo(Data* this,char* tipo);
int data_getTipo(Data* this,char* tipo);

int data_setCantidad(Data* this,int cantidad);
int data_getCantidad(Data* this,int* cantidad);
int data_setCantidadStr(Data* this,char* cantidad);
int data_getCantidadStr(Data* this,char* result);

int data_setImporte(Data* this,float importe);
int data_getImporte(Data* this,float* importe);
int data_setImporteStr(Data* this,char *importe);
int data_getImporteStr(Data* this,char* result);

int data_GOLD(void* pData);
int data_REGULAR(void* pData);
int data_PLUS(void* pData);



