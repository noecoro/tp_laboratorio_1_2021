#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"

/** \brief Para indicar que todas las posiciones en el array están vacías
 *         esta función pone la bandera (isEmpty) en  TRUE en todas
 *         las posic del arrray.
 * \param list Employee* Puntero a array de empleados
 * \param len int Array tamaño
 * \return int Return (-1) si Error Longitud no válida o puntero NULL - (0) if Ok
 *
 */
int emp_initEmployees(Employee* list, int len)
{
	int retorno = -1;
	int i;

	if(list != NULL && len >0)
	{
		for(i=0;i<len;i++)
		{
			list[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief Agregua en un array  existente de empleados los valores recibidos como parámetros
 *         en la primera posición vacía
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) si da Error Longitud no válida o puntero NULL o sin espacio libre
 - (0) sino  Ok
 *
 */
int emp_addEmployee(Employee* list, int len, int id, char* nombre,char* apellido,float salario,int sector)
{
	int retorno = -1;
	int indice;

	indice = emp_getEmptyIndex(list,len);
	if(	list != NULL && len > 0 && id >= 0 && nombre != NULL && apellido != NULL && salario > 0 && sector > 0 && indice >= 0)
	{
		retorno = 0;
		strncpy(list[indice].name,nombre,NAME_LEN);
		strncpy(list[indice].lastName,apellido,LASTNAME_LEN);
		list[indice].salary = salario;
		list[indice].sector = sector;
		list[indice].isEmpty = 0;
		list[indice].id = id;
	}
	return retorno;
}

/**
 * \brief Busca la primer posición vacia en el array de empleados.
 * \param list Puntero al array de empleados.
 * \param len Es la longitud del array.
 * \return Retorna el indice de la posicion vacia si encontró uno y -1 si obtuvo algún error o no existen indices vacios.
 *
 */
int emp_getEmptyIndex(Employee* list, int len)
{
	int retorno = -1;
	int i;
	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 1)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/** \brief
Encuentra un empleado por Id y devuelve la posición del índice en el array.
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee posición de índice o
 *  (-1) si Longitud no válida o NULL
 * puntero recibido o empleado no encontrado
 *
 */
int emp_findEmployeeById(Employee* list, int len,int id)
{
	int retorno = -1;
	int i;

	if(list != NULL && len > 0 && id > -1)
	{
		for( i= 0; i < len; i++)
		{
			if( list[i].id == id &&
				list[i].isEmpty == 0)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/** \brief Eliminar un empleado por Id (poner la bandera isEmpty en 1)
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1)
	si Error [Longitud no válida o puntero NULO o si no puede
	buscar un empleado] - (0) si está bien
 *
 */


int emp_removeEmployee(Employee* list, int len, int id)
{

	int retorno = -1;
	int i;

	if(list != NULL && len > 0 && id > -1)
	{
		for(i = 0; i < len; i++)
		{
			if( list[i].id == id &&
				list[i].isEmpty == 0)
			{
				retorno = 0;
				list[i].isEmpty = 1;
				break;
			}
		}
	}
	return retorno;
}

/** \brief print the content of employees array.
 * \param list Employee*
 * \param len int
 * \return int
 *
 */
int emp_printEmployees(Employee* list, int len)
{
	int retorno = -1;
	int i;

	if(list != NULL && len > 0)
	{
		printf("Id  Nombre       Apellido    Salario     Sector      \n");
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 0)
			{

				printf("%d   %s       %s         %.2f     %d \n",list[i].id, list[i].name,list[i].lastName,list[i].salary,list[i].sector);
			}
		}
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Cuenta la cantidad de empleados existentes.
 * \param list Puntero al array de empleados.
 * \param len Es la longitud del array.
 * \return Retorna contador Retorna la cantidad de empleados encontrada y -1 si tuvo algún error.
 *
 */
int emp_contEmployee(Employee* list, int len)
{
	int i;
	int contador = 0;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 0)
			{
				contador++;
			}
		}
	}
	return contador;
}

/**
 * \brief Modifica los datos ingresados de un empleado por ID.
 * \param list Puntero al array de empleados.
 * \param len Es la longitud del array.
 * \param id Identificacion del cliente a modificar.
 * \param option para verificar que campo desea modificar. 1 = Nombre; 2 = Apellido; 3 = Salario; 4 = Sector.
 * \return Retorna 0 si modifico los datos del cliente correctamente y -1 si tuvo algún error.
 *
 */

int emp_modifEmployee(Employee* list,int len, int indice)
{
	int retorno = -1;
	//int i;
	Employee auxiliar;
	int opcion;

	if(list != NULL && len > 0 && indice < len)
	{
		do
			{
				if(!utn_getNumeroEntero(&opcion, "\nIngrese opcion:\n1.Nombre\n2.Apellido\n3.Salario\n4.Sector\n5.Salir\n", "Error, Opcion incorrecta\n", 1, 5, 2))
				{
					switch(opcion)
					{
					case 1:
						utn_getNombre(auxiliar.name, NAME_LEN, "Ingrese nombre :\n", "Error, valor inválido\n", 2);
						strncpy(list[indice].name,auxiliar.name, NAME_LEN);
						printf("El nombre se modificó correctamente\n");
						break;
					case 2:
						utn_getDescripcion(auxiliar.lastName, LASTNAME_LEN, "Ingrese Apellido:\n", "Error, Valor inválido\n", 2);
						strncpy(list[indice].lastName,auxiliar.lastName, LASTNAME_LEN);
						printf("El apellido se modificó correctamente\n");
						break;
					case 3:
						utn_getNumeroFlotante(&auxiliar.salary, "Ingrese salario:\n", "Error, Valor inválido\n", 0, 100000, 2);
						list[indice].salary = auxiliar.salary;
						printf("El salario se modificó correctamente\n");
						break;
					case 4:
						utn_getNumeroEntero(&auxiliar.sector, "Ingrese sector:\n", "Error, Valor inválido\n", 0, 10, 2);
						list[indice].sector = auxiliar.sector;
						printf("El sector se modificó correctamente\n");
						break;
					}
					retorno = 0;//0
					list[indice].isEmpty = 0;

				}
			}while(opcion !=5);
	}
	return retorno;
}


