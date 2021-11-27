#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

Employee* employee_new(){

Employee* nuevoEmpleado = (Employee*) malloc (sizeof(Employee));

   if(nuevoEmpleado != NULL){

    employee_setId(nuevoEmpleado, 0);
    employee_setNombre(nuevoEmpleado, " ");
    employee_setHorasTrabajadas(nuevoEmpleado, 0);
    employee_setSueldo(nuevoEmpleado, 0);
   }

   return nuevoEmpleado;
}
Employee* employee_newParametros(int id, char* nombre, int horasTrabajadas, int sueldo)
{
	Employee* nuevoEmpleado = NULL;

	nuevoEmpleado =	employee_new();

	if(nuevoEmpleado != NULL)
	{
		if(!(employee_setId(nuevoEmpleado, id) &&
			employee_setNombre(nuevoEmpleado, nombre) &&
			employee_setHorasTrabajadas(nuevoEmpleado, horasTrabajadas) &&
			employee_setSueldo(nuevoEmpleado, sueldo)))
		{
			employee_delete(nuevoEmpleado);
			nuevoEmpleado = NULL;
		}
	}

	return nuevoEmpleado;
}

Employee* employee_newParametrosString(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* nuevoEmpleado = NULL;

	nuevoEmpleado =	employee_new();

	if(nuevoEmpleado != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
	{
		if(!(employee_setIdStr(nuevoEmpleado, idStr) &&
				employee_setNombre(nuevoEmpleado, nombreStr) &&
				employee_setHorasTrabajadasStr(nuevoEmpleado, horasTrabajadasStr) &&
				employee_setSueldoStr(nuevoEmpleado, sueldoStr)))
		{
			employee_delete(nuevoEmpleado);
			nuevoEmpleado = NULL;
		}
	}
	return nuevoEmpleado;
}
void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int employee_setId(Employee* this,int id)
{
	int retorno = 0;

	if(this != NULL && id > 0)
	{
		this->id = id;
		retorno = 1;
	}

	return retorno;
}

int employee_setIdStr(Employee* this, char* id)
{
	int retorno = 0;

	if(this != NULL && id != NULL)
	{
		this->id = atoi(id);
		retorno = 1;
	}
	return retorno;
}

int employee_getId(Employee* this,int* id)
{
	int retorno = 0;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 1;
	}
	return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = 0;

	if(this != NULL)
	{
		if(strlen(nombre) < 128)
		{
			strcpy(this->nombre, nombre);
			retorno = 1;
		}
	}
	return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = 0;

	if(this != NULL && nombre != NULL)
	{
		if(strlen(nombre) <  128)
		{
			strcpy(nombre, this->nombre);
			retorno = 1;
		}
	}

	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = 0;

	if(this != NULL && horasTrabajadas > 0)
	{
		this->horasTrabajadas = horasTrabajadas;
		retorno = 1;
	}
	return retorno;
}

int employee_setHorasTrabajadasStr(Employee* this, char* horasTrabajadas)
{
	int retorno = 0;

	if(this != NULL && horasTrabajadas != NULL)
	{
		this->horasTrabajadas = atoi(horasTrabajadas);
		retorno = 1;
	}
	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = 0;

	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 1;
	}
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = 0;

	if(this != NULL && sueldo > 0)
	{
		this->sueldo = sueldo;
		retorno = 1;
	}
	return retorno;
}
int employee_setSueldoStr(Employee* this, char* sueldo)
{
	int retorno = 0;

	if(this != NULL && sueldo > 0)
	{
		this->sueldo = atoi(sueldo);
		retorno = 1;
	}
	return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = 0;

	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		retorno = 1;
	}
	return retorno;
}


int  buscarEmpleado(int id, LinkedList* pArrayListEmployee)
{
	 int employeeIndex = -1;
	 int idAux;
	 Employee* auxEmployee;

	 for(int index = 0; index < ll_len(pArrayListEmployee); index++)
	 {
	   auxEmployee = ll_get(pArrayListEmployee, index);
	   if(employee_getId(auxEmployee, &idAux)  &&  idAux == id)
	   {
	     employeeIndex = index;
	   break;
	    }
	}
 return employeeIndex;
}
/** \brief castea a puntero a empleado los parametros recibidos y compara los nombres de los empleados recibidos por parametro
 *
 * \param puntero a void
 * \param puntero a void
 * \return devuelve 0 si los nombers de los empleados son iguales, 1 si el nombre del empA es mayor al nombre del empB y -1 si el nombre del empA es menor al nombre del empB
 *
 */

int employee_sortByName(void* firstEmployee, void* secondEmployee)
{
	int retorno = 0;//si son iguales
	char firstName[128];
	char secondName[128];

	employee_getNombre(firstEmployee, firstName);
	employee_getNombre(secondEmployee, secondName);

	if(strcmp(firstName, secondName) > 0)//el 1ro es mayor
	{
		retorno = 1;
	}
	else if(strcmp(firstName, secondName) < 0)// el 2do es menor
	{
		retorno = -1;
	}

	return retorno;
}


int employee_showAnEmployee(LinkedList* list, int indice)
{
	int exito = 0;
	int idEmployee;
	char nombre[128];
	int horasTrabajo;
	int sueldo;

	Employee* this = NULL;

	if(list != NULL && indice > 0)
	{
		this = (Employee*) ll_get(list, indice);
		employee_getId(this, &idEmployee);
		employee_getNombre(this, nombre);
		employee_getHorasTrabajadas(this, &horasTrabajo);
		employee_getSueldo(this, &sueldo);

		printf("%d        %-10s     %d       %d\n", idEmployee, nombre, horasTrabajo, sueldo);
		exito = 1;
	}
	return exito;
}
//*Ñ::::::::::::::::::::
