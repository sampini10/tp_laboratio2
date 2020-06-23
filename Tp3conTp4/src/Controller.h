int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
//*******LinkedList Prueba*******//////
int controller_clear(LinkedList* pArrayListEmployee);
int controller_deleteLinkedList(LinkedList* pArrayListEmployee);
int controller_isEmpty(LinkedList* pArrayListEmployee);
int controller_push(LinkedList* pArrayListEmployee);
int controller_pop(LinkedList* pArrayListEmployee);
int controller_containsAll(LinkedList* pArrayListEmployee,LinkedList* pArrayList2);
LinkedList* controller_clone(LinkedList* pArrayListEmployee);



