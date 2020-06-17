#include "parser.h"

/* \fn int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
 * \brief Permite cargar un archivo CSV de empleados al linkedlist.
 * \param char* path: Ruta del archivo de empleados en formato CSV.
 * \param LinkedList* pArrayListEmployee: LinkedList donde se insertará cada empleado.
 * */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/* \fn int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
 * \brief Permite cargar un archivo BIN de empleados al linkedlist.
 * \param char* path: Ruta del archivo de empleados en formato BIN.
 * \param LinkedList* pArrayListEmployee: LinkedList donde se insertará cada empleado.
 * */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/* \fn int controller_loadFile(char* path, LinkedList* pArrayListEmployee, char* typeRead)
 * \brief Permite cargar un archivo de empleados en un LinkedList, se especifica el tipo de lectura variable entre "r" y "rb".
 * \param char* path: Ruta del archivo de empleados.
 * \param char* typeRead: Tipo de lectura
 * \param LinkedList* pArrayListEmployee: LinkedList donde se insertará cada empleado.
 * */
int controller_loadFile(char* path, LinkedList* pArrayListEmployee, char* typeRead);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
int controller_saveFile(char* path, LinkedList* pArrayListEmployee, char* typeOpen);
int controller_editEmployee(LinkedList* pArrayListEmployee);
Employee* controller_findEmployeeByID(LinkedList* pArrayListEmployee);
