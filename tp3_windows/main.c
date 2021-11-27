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
	setbuf(stdout, NULL);

    char rta = 'n';

    int flagTexto = 0;
    int flagBin = 0;

    int idEmpleado = 1000;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do {

    	switch(menu()){

    	case 1:
        	if(flagBin != 1 && flagTexto == 0)
        	{
        		if(controller_loadFromText("data.csv",listaEmpleados) == 0)
				{
					flagTexto = 1;
				}
        	}
        	else
			{
				printf("El archivo ya fue cargado.\n");
			}


    		break;

    	case 2:
        	if(flagTexto != 1 && flagBin == 0)//si no fue cargado como texto
        	{
        		if(!controller_loadFromBinary("data.bin", listaEmpleados))
        		{
        			flagBin = 1; //se cargo como binario
        		}//Ya existe el archivo
        	}
        	else
        	{
        		printf("El archivo ya fue cargado.\n");
        	}
        	break;

    		break;

    	case 3:
    		if(flagTexto == 1 || flagBin == 1)
    		{
    		controller_addEmployee(listaEmpleados,&idEmpleado);
    		printf("\nAlta exitosa");// se agrega
    		}
    		else
    		{
    		printf("Error. No hay archivo cargado.\n");
    		}
    		break;

    	case 4:
        	if(flagTexto == 1 || flagBin == 1)
			{
				controller_editEmployee(listaEmpleados);
				printf("\nModificacion exitosa.");
			}
			else
			{
				printf("Error. No hay archivo cargado.\n");
			}
    		break;

    	case 5:
        	if(flagTexto == 1 || flagBin == 1)
			{
        		controller_removeEmployee(listaEmpleados);
        		printf("\nBaja exitosa.");
			}
			else
			{
				printf("Error. No hay archivo cargado.\n");
			}
    		break;

    	case 6:
    		controller_ListEmployee(listaEmpleados);
    		break;

    	case 7:
            //ORDENAR EMPLEADOS por nombre
        	if(flagTexto == 1 || flagBin == 1)
			{
				controller_sortEmployee(listaEmpleados);
			}
			else
			{
				printf("Error. No hay archivo cargado.\n");
			}
    		break;

    	case 8:
    		if(controller_saveAsText("data.csv", listaEmpleados) != 0)
    		{
			printf("\nExito al crear el archivo de texto");
    		}
    		else
    		{
    	    	printf("\nDeben existir datos en el sistema para poder cargarlos en un archivo");
    	    }
    		break;

    	case 9:
			if(controller_saveAsBinary("data.bin", listaEmpleados) != 0)
			{
				printf("\nExitos al crear el archivo binario");
				flagBin = 1;
			}

			else
			{
				printf("\nSe deben cargar los datos del archivo de texto para poder escribir en el archivo binario.");
			}
    		break;

    	case 10:
    		printf("\nDesea salir s/n?\n");
    		fflush(stdin);
    		rta = getchar();

    		break;

    	default:
    		printf("\nDato invalido. Reingrese numero\n");
    	    	}

    } while(rta == 'n');

    ll_deleteLinkedList(listaEmpleados);
    return 0;
}


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



