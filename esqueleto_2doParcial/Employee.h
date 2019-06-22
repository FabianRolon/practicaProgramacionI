#ifndef entidad_H_INCLUDED
#define entidad_H_INCLUDED
typedef struct
{
    int id;
    char string[128];
    int valorEntero;
    float valorFloat;
}Entidad;

Entidad* entidad_new();
Entidad* entidad_newParametrosStr(char* idStr,char* stringStr,char* valorEnteroStr, char* valorFloatStr);
Entidad* entidad_newParametros(int id, char* stringStr,int valorEntero, int valorFloat);
void entidad_delete();

int entidad_setId(Entidad* this,int id);
int entidad_getId(Entidad* this,int* id);
int entidad_setIdString(Entidad* this, char* idStr);
int entidad_getIdString(Entidad* this, char* result);

int entidad_setString(Entidad* this,char* string);
int entidad_getString(Entidad* this,char* string);

int entidad_setValorEntero(Entidad* this,int valorEntero);
int entidad_getValorEntero(Entidad* this,int* valorEntero);
int entidad_setValorEnteroStr(Entidad* this,char* valorEntero);
int entidad_getValorEnteroStr(Entidad* this,char* result);

int entidad_setValorFloat(Entidad* this,float valorFloat);
int entidad_getValorFloat(Entidad* this,float* valorFloat);
int entidad_setValorFloatStr(Entidad* this,char *valorFloat);
int entidad_getValorFloatStr(Entidad* this,char* result);

int findEntidadById(LinkedList* pArrayListEntidad, int id, int *posicionId);
int entidad_compare(void* this1, void* this2);
int entidad_salary(void* pEntidad);
int entidad_horas(void* pEntidad);

#endif // entidad_H_INCLUDED
