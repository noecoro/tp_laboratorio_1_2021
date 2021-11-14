#ifndef controller_H_INCLUDED//#ifndef PARSER_H_
#define controller_H_INCLUDED//#define PARSER_H_

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);//case 1
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);//case2
int controller_addEmployee(LinkedList* pArrayListEmployee);//case3
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
int obtenerIdDelArchivo(int* id);
int actualizarId(int id);


#endif
/*
 * controller encargado de atender los eventos
 eventos q pueden ocurrir en mi programa
 las opciones q elige el usuario


 */
