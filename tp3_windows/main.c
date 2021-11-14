#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);
	char confirm = 0;
	char seguir = 's';

	// LinkedList* listaEmpleados;//tiene cero lugares crece a medida q la uso si esta es xq tiene algo
  //  int option = 0;

    //Employee* pE;
    //pE = empleado_newparam("lalal","lalla2")
//ll_newLinkedList(); constructor de la lista va a tener la posicio de memor del 1er elemento de esa lista
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{

        switch(menu())
        {
            case 1:// 1
                controller_loadFromText("data.csv",listaEmpleados);//

                break;
            case 2://4
            	controller_loadFromBinary("data.bin",listaEmpleados);

            	break;
            case 3:
            	controller_addEmployee(listaEmpleados);

                break;
            case 4:
                break;
            case 5:
               break;
            case 6://2
                if( !ll_isEmpty(listaEmpleados))
                     {
                         controller_ListEmployee(listaEmpleados);
                     }
                     else
                     {
                         printf("La lista esta vacia. Debe cargar un empleado primero.\n\n");
                     }
                    // system("pause");
               break;
            case 7:
               break;
            case 8://5
                if( !ll_isEmpty(listaEmpleados))
                       {
                           controller_saveAsText("data.csv",listaEmpleados);
                           printf("Se han guardado los empleados.\n");
                       }
                       else
                       {
                           printf("La lista esta vacia. Debe cargar un empleado primero.\n");
                       }
                        system("pause");
               break;
            case 9://3
                if( !ll_isEmpty(listaEmpleados))
                     {

                         if(controller_saveAsBinary("data.bin",listaEmpleados))
                            {
                                 printf("Se han guardado los empleados.\n");
                            }else
                            {
                                printf("Error. Reintente.\n");
                            }

                     }
                     else
                     {
                         printf("La lista esta vacia. Debe cargar un empleado primero.\n");
                     }
                      system("pause");
               break;
            case 10:
                printf("Desea salir? s/n : ");
                fflush(stdin);
                scanf("%c", &confirm);
                if (confirm == 's')
               {
                	seguir = 'n';
               }
               break;
        }
    }while(seguir == 's');
    ll_deleteLinkedList(listaEmpleados);
    return 0;
}

