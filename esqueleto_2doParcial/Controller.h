int controller_loadFromText(char* path , LinkedList* pArrayListEntidad);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEntidad);
int controller_addEntidad(LinkedList* pArrayListEntidad);
int controller_editEntidad(LinkedList* pArrayListEntidad);
int controller_removeEntidad(LinkedList* pArrayListEntidad);
int controller_ListEntidad(LinkedList* pArrayListEntidad);
int controller_sortEntidad(LinkedList* pArrayListEntidad);
int controller_saveAsText(char* path , LinkedList* pArrayListEntidad);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEntidad);
int controller_nextId(LinkedList* pArrayListEntidad);
void Controller_printMenu();
void Controller_filtrarPorValorFloat(LinkedList *pArrayListEntidad);
void Controller_filtrarPorHoras(LinkedList *pArrayListEntidad);
