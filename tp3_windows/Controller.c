#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int exito = 0;

	FILE* pArchivo;

	pArchivo = fopen(path, "r");

	if(pArchivo == NULL){

		printf("\nNo pudo leer el archivo\n");
	}
	else{
		printf("\nLectura del archivo exitosa\n");
		if(parser_EmployeeFromText(pArchivo, pArrayListEmployee) != 0){

			exito = 1;
		}
		fclose(pArchivo);
	}

    return exito;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int ok = 0;

	FILE* pArchivo;

	pArchivo = fopen(path, "rb");

	if(pArchivo == NULL)
	{
		printf("\nNo pudo leer el archivo\\n");
	}
	else{
		printf("\nYa existe el archivo\n");

		if(parser_EmployeeFromBinary(pArchivo, pArrayListEmployee) != 0)
		{
			ok = 1;
		}
		fclose(pArchivo);
	}
	return ok;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* idEmployee)
{
	Employee* nuevoEmpleado = NULL;
	int ok = 0;
	char nombre[128];
	int sueldo;
	int horasTrabajadas;

	if(pArrayListEmployee != NULL){

		(*idEmployee)++;

		printf("\nAlta\n");

		printf("ID nuevo: %d", *idEmployee);

		printf("\nIngrese nombre: ");
		fflush(stdin);
		gets(nombre);
		while(strlen(nombre) > 128)
		{
			printf("Error. Reingrese nombre: ");
			gets(nombre);
			fflush(stdin);
		}

		printf("\nIngrese cantidad de Hs Trabajadas: ");
		fflush(stdin);
		scanf("%d", &horasTrabajadas);
		while(horasTrabajadas < 0 || horasTrabajadas > 1000)
		{
			printf("Error. Reingrese cantidad de Hs Trabajadas: ");
			fflush(stdin);
			scanf("%d", &horasTrabajadas);
		}
		printf("\nIngrese sueldo: ");
		fflush(stdin);
		scanf("%d", &sueldo);
		while(sueldo < 0)
		{
			printf("Error. Reingrese Sueldo: ");
			fflush(stdin);
			scanf("%d", &sueldo);
		}

		nuevoEmpleado = employee_newParametros(*idEmployee, nombre, horasTrabajadas, sueldo);

		if(nuevoEmpleado != NULL)
		{
			ll_add(pArrayListEmployee, nuevoEmpleado);
			ok = 1;
		}
	}

    return ok;
}

int controller_removeAllEmployes(LinkedList* pArrayListEmployee)
{

	int tam;
	int ok = 0;

	if(pArrayListEmployee != NULL)
	{
		tam = ll_len(pArrayListEmployee);

		for(int i = tam - 1; i >= 0; i--)
		{
			ll_remove(pArrayListEmployee, i);
			if(i == 0)
			{
				ok = 1;
			}
		}
	}
	return ok;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int ok = 0;
	int idAModificar;
	int indice;
	char rta;
	int opcion;
	char nombreEmpleado[128];
	int sueldo;
	int horasTrabajadas;
	Employee* nuevoEmpleado = NULL;
	if(pArrayListEmployee != NULL)
	{
		printf("\nModificacion\n");
		controller_ListEmployee(pArrayListEmployee);
		printf("\n\nIngrese ID a modificar: ");
		fflush(stdin);
		scanf("%d", &idAModificar);
		//printf("\n ID        Nombre           Hs          Sueldo    \n");
		indice = buscarEmpleado(idAModificar, pArrayListEmployee);
		while(indice == -1)
		{
			printf("\nError. Reingrese id: \n");
			fflush(stdin);
			scanf("%d", &idAModificar);
			indice =  buscarEmpleado(idAModificar, pArrayListEmployee);
		}
		if( indice == -1)
		{
			printf("\nNo hay empleados para modificar");
		}
		else
		{
			employee_showAnEmployee(pArrayListEmployee, indice);
			printf("\n\nDesea modificar s/n?: \n");
			fflush(stdin);
			rta = getchar();
		    nuevoEmpleado = (Employee*) ll_get(pArrayListEmployee, indice);
		    employee_getNombre(nuevoEmpleado, nombreEmpleado);
		    employee_getHorasTrabajadas(nuevoEmpleado, &horasTrabajadas);
		    employee_getSueldo(nuevoEmpleado, &sueldo);
		    if(nuevoEmpleado != NULL)
		    {
				if(rta == 's')
				{
					printf("\n1. Modificar Nombre\n");
					printf("2. Modificar Hs Trabajas\n");
					printf("3. Modificar Sueldo\n");
					printf("\nIngrese opcion: ");
					fflush(stdin);
					scanf("%d", &opcion);
					switch(opcion)
					{
						case 1:
							printf("\nIngrese nombre: ");
							fflush(stdin);
							gets(nombreEmpleado);
							//employee_showAnEmployee(pArrayListEmployee, indice);
							while(strlen(nombreEmpleado) > 128)
							{
								printf("Error. Reingrese nombre: ");
								fflush(stdin);
								gets(nombreEmpleado);
							}
							employee_setNombre(nuevoEmpleado, nombreEmpleado);
							ok = 1;
							break;
						case 2:
							printf("Ingrese hs trabajadas de  0 a 100): ");
							fflush(stdin);
							scanf("%d", &horasTrabajadas);
							while(horasTrabajadas > 100 || horasTrabajadas < 1)
							{
								printf("Error. Reingrese hs trabajadas de  0 a 100 ): ");
								fflush(stdin);
								scanf("%d", &horasTrabajadas);
							}
							employee_setHorasTrabajadas(nuevoEmpleado, horasTrabajadas);
							ok = 1;
							break;
						case 3:
							printf("Ingrese sueldo: ");
							fflush(stdin);
							scanf("%d", &sueldo);
							while(sueldo < 1)
							{
								printf("Error. Reingrese sueldo: ");
								fflush(stdin);
								scanf("%d", &sueldo);
							}
							employee_setSueldo(nuevoEmpleado, sueldo);
							ok = 1;
							break;
						default:
							printf("Error. Dato invalido");
							ok = 1;
							break;
					}
				}
				else
				{
					printf("\nCancelo la modificacion");
					ok = 1;
				}
		    }
		}
	}

    return ok;
}



/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int ok = 0;
	int idPBaja;
	int indice;
	char rta;

	if(pArrayListEmployee)
	{
		printf("\nBaja\n");
		controller_ListEmployee(pArrayListEmployee);
		printf("\n\nIngrese ID: ");
		fflush(stdin);
		scanf("%d", &idPBaja);
		indice = buscarEmpleado(idPBaja, pArrayListEmployee);
		while(indice == -1)
		{
			printf("\nError. Reingrese ID: ");
			fflush(stdin);
			scanf("%d", &idPBaja);
			indice = buscarEmpleado(idPBaja, pArrayListEmployee);
		}
		if( indice == -1)
		{
			printf("\nNo hay empleados cargados");
		}
		else
		{
			employee_showAnEmployee(pArrayListEmployee, indice);
			printf("\n\nDesea continuar s/n?.\n");
			fflush(stdin);
			rta = getchar();
			if(rta == 's')
			{
				ll_remove(pArrayListEmployee, indice);
				ok = 1;
			}
			else
			{
				printf("\nBaja cancelada");
				ok = 1;
			}
		}
	}
    return ok;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int tam;
	int exito = 0;

	if(pArrayListEmployee != NULL)
	{

		tam = ll_len(pArrayListEmployee);

		printf("\nID      NOMBRE            HORAS          SUELDO\n");
		for(int i = 0; i < tam; i++)
		{
			employee_showAnEmployee(pArrayListEmployee, i);
			exito = 1;
		}
	}
	return exito;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int orden;
    int ordenOk = -1;
    if( pArrayListEmployee != NULL)
    {
        utn_getNumero(&orden, "Ordenar nombres(una vez seleccionada la opcion espere unos segundos).\n0. Ascendente\n1. Descendete\n","Error. Ingrese 1 o 0.", 0,1, 2);
        ll_sort(pArrayListEmployee, employee_sortByName, orden);
        controller_ListEmployee(pArrayListEmployee);
        ordenOk = 0;
    }
    return ordenOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int ok = 0;

	FILE* pArchivo;

	pArchivo = fopen(path, "w");

	if(pArchivo == NULL)
	{
		printf("\nNo se pudo crear el archivo\n");
	}
	else{

		if(parser_writeToText(pArchivo, pArrayListEmployee) != 0)
		{
			printf("\nSe pudieron escribir los datos en el archivo de texto");
		}
		fclose(pArchivo);
		ok = 1;
	}
	return ok;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int ok= 0;
	FILE* pArchivo;

	pArchivo = fopen(path, "wb");

	if(pArchivo == NULL)
	{
		printf("\nNo se pudo crear el archivo\n");
	}
	else{

		if(parser_writeToBinary(pArchivo, pArrayListEmployee) != 0)
		{
			printf("\nSe pudieron escribir los datos en el archivo binario");
		}
		fclose(pArchivo);
		ok = 1;
	}
	return ok;
}
