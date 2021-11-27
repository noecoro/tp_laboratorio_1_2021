#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	char buffer[4][20];
	Employee* nuevoEmpleado;
	int cant;
	int ok = 0;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{

		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

		while(!feof(pFile))
		{
			cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

			if( cant < 4){
				break;
			}

			nuevoEmpleado = employee_newParametrosString(buffer[0], buffer[1], buffer[2], buffer[3]);
			ll_add(pArrayListEmployee, nuevoEmpleado);

			if(nuevoEmpleado != NULL){

				ok = 1;
			}
		}
	}
	return ok;
}



/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* nuevoEmpleado = NULL;
	Employee auxEmpleado;
	int cant = 0;
	int ok = 0;
	int cantidadMas = 0;//acu

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		while(!feof(pFile)){

			cant = fread(&auxEmpleado, sizeof(Employee), 1, pFile);

			if(cant < 1)
			{
				break;
			}
			nuevoEmpleado = employee_newParametros(auxEmpleado.id, auxEmpleado.nombre, auxEmpleado.horasTrabajadas, auxEmpleado.sueldo);
			ll_add(pArrayListEmployee, nuevoEmpleado);

			cantidadMas++;

			if(nuevoEmpleado != NULL && cant >= 1)
			{
				ok = 1;
			}
		}
	}
    return ok;
}

int parser_writeToText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* auxEmpleado = NULL;
	int ok = 0;
	int idEmployee;
	char nombre[128];
	int horasTrabajo;
	int sueldo;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");

		for(int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
			employee_getId(auxEmpleado, &idEmployee);
			employee_getNombre(auxEmpleado, nombre);
			employee_getHorasTrabajadas(auxEmpleado, &horasTrabajo);
			employee_getSueldo(auxEmpleado, &sueldo);

			fprintf(pFile, "%d,%s,%d,%d\n", idEmployee, nombre, horasTrabajo, sueldo);
		}
		ok = 1;
	}
	return ok;
}

int parser_writeToBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

	Employee* auxEmpleado = NULL;
	int ok = 0;
	int cantidadMas = 0;
	int cant = 0;


	if(pFile != NULL && pArrayListEmployee != NULL){

		for(int i = 0; i < ll_len(pArrayListEmployee); i++){

			auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);

			cant = fwrite(auxEmpleado, sizeof(Employee), 1, pFile);

			if(cant < 1){

				printf("\nHubo un problema en la escritura binaria\n");
				break;
			}
			cantidadMas += cant;
		}
		if(cantidadMas == ll_len(pArrayListEmployee)){
			ok = 1;
		}
	}
	return ok;
}
