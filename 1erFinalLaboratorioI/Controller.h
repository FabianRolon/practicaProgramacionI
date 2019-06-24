int controller_loadFromTextClientes(char* path , LinkedList* pArrayListCliente);
int controller_loadFromBinary(char* path , LinkedList* pArrayListCliente);
int controller_addCliente(LinkedList* pArrayListCliente);
int controller_editCliente(LinkedList* pArrayListCliente);
int controller_removeCliente(LinkedList* pArrayListCliente);
int controller_ListCliente(LinkedList* pArrayListCliente);
int controller_sortCliente(LinkedList* pArrayListCliente);
int controller_saveAsTextCliente(char* path , LinkedList* pArrayListCliente);
int controller_saveAsBinary(char* path , LinkedList* pArrayListCliente);
int controller_nextIdCliente(LinkedList* pArrayListCliente);
void Controller_printMenu();
void Controller_filtrarPorValorFloat(LinkedList *pArrayListCliente);
void Controller_filtrarPorHoras(LinkedList *pArrayListCliente);
int controller_addVenta(LinkedList* pArrayListVenta, LinkedList *pArrayListCliente);
int controller_ListVenta(LinkedList* pArrayListVenta);
int controller_saveAsTextVenta(char* path , LinkedList* pArrayListVenta);
int controller_nextIdVenta(LinkedList* pArrayListVenta);
int controller_loadFromTextVentas(char* path , LinkedList* pArrayListCliente);
int controller_removeVenta(LinkedList* pArrayListVenta);
