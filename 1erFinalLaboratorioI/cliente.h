#ifndef cliente_H_INCLUDED
#define cliente_H_INCLUDED
typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    char dni[21];
}Cliente;

Cliente* cliente_new();
Cliente* cliente_newParametrosStr(char* idStr,char* nombre,char* apellido, char* dni);
Cliente* cliente_newParametros(int id, char* nombre,char* apellido, char* dni);
void cliente_delete();

int cliente_setId(Cliente* this,int id);
int cliente_getId(Cliente* this,int* id);
int cliente_setIdString(Cliente* this, char* idStr);
int cliente_getIdString(Cliente* this, char* result);

int cliente_setNombre(Cliente* this,char* nombre);
int cliente_getNombre(Cliente* this,char* nombre);

int cliente_setApellido(Cliente* this,char* apellido);
int cliente_getApellido(Cliente* this,char* apellido);

int cliente_setDni(Cliente* this,char* dni);
int cliente_getDni(Cliente* this,char* dni);

int findClienteById(LinkedList* pArrayListCliente, int id, int *posicionId);
int cliente_compare(void* this1, void* this2);
int cliente_salary(void* pCliente);
int cliente_horas(void* pCliente);

#endif // cliente_H_INCLUDED
