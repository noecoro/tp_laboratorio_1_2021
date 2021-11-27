/*
 1. ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número
de Id. El resto de los campos se le pedirá al usuario.
2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
o Salario o Sector
3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
4. INFORMAR:
1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"
#include "Informe.h"

#define EMP_LEN 1000

int main(void) {

	setbuf(stdout, NULL);

	Employee arrayEmpleados[EMP_LEN];
	int opcion;
	int idEmpleado = 0;
	char auxName[NAME_LEN];
	char auxLastName[LASTNAME_LEN];
	float auxSalario;
	int auxSector;
	int auxId;
	int auxModif;
	int auxInf;
	int indiceAuxiliar;

	if(!emp_initEmployees(arrayEmpleados,EMP_LEN))
	{
		printf("Array, inicializado correctamente\n");
	}
	do
	{
		if(!utn_getNumeroEntero(&opcion,"\nMENU:"
								     "\n1. ALTA."
								     "\n2. MODIFICAR."
								     "\n3. BAJA."
								     "\n4. INFORMAR:"	//hacer submenu
								     "\n5. SALIR.\n","Error, opcion invalida.\n",1,5,2))
		{
			switch(opcion)
			{
			case 1: //alta
				indiceAuxiliar = emp_getEmptyIndex(arrayEmpleados, EMP_LEN);
				if(indiceAuxiliar >=0)
				{
				if ( !utn_getNombre(auxName,NAME_LEN,"Ingrese nombre: \n","Error, Nombre invalido.\n",2) &&
					 !utn_getNombre(auxLastName,LASTNAME_LEN,"Ingrese apellido: \n","Error, Apellido invalido.\n",2) &&
					 !utn_getNumeroFlotante(&auxSalario,"Ingrese salario de 0 a 10000: \n","Error, Salario invalido.\n",0,10000,2) &&
					 !utn_getNumeroEntero(&auxSector,"Ingrese sector 1 a 10: \n","Error, Sector invalido.\n",1,10,2) &&
					 !emp_addEmployee(arrayEmpleados,EMP_LEN,idEmpleado,auxName,auxLastName,auxSalario,auxSector))
				{
					idEmpleado++;
					printf("Alta exitosa!\n");
				}
				}
				else
				{
					printf("Error, No se pudo dar de alta.\n");
				}
				break;

			case 2://Modificar
				if( emp_contEmployee(arrayEmpleados,EMP_LEN) > 0 &&	emp_findEmployeeById(arrayEmpleados,EMP_LEN,auxId) >= 0  &&
					!emp_modifEmployee(arrayEmpleados,EMP_LEN,indiceAuxiliar) )
				{
					printf("Modificacion exitosa!\n");
				}
				else
				{
					printf("No hay empleados o ha superado la cantidad de intentos.\n");
				}

				break;

			case 3://Baja

				if( emp_contEmployee(arrayEmpleados,EMP_LEN) > 0 && !utn_getNumeroEntero(&auxId,"Ingrese ID: \n","Error, ID invalido",0,idEmpleado,2) &&
					emp_findEmployeeById(arrayEmpleados,EMP_LEN,auxId) >= 0 && !emp_removeEmployee(arrayEmpleados,EMP_LEN,auxId))
				{
					printf("Baja exitosa!\n");
				}
				else
				{
					printf("No existen empleados\n");
				}
				break;

			case 4://Informar:

				if( emp_contEmployee(arrayEmpleados,EMP_LEN) > 0 &&
					!utn_getNumeroEntero(&auxInf,"Ingrese opcion: \n"
												"1.-Empleados ordenados por Apellido y Sector.\n"
												"2.-Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n"
												,"Opcion invalida.\n",1,2,2))
				{
					if( auxInf == 1 &&
						!utn_getNumeroEntero(&auxModif,"Ingrese opcion: \n"
													"1. Ascendente.\n"
													"2.-Descendente.\n"
													,"Error, opcion invalida.\n",1,2,2) &&
						!info_sortEmployees(arrayEmpleados,EMP_LEN,auxModif))
					{
						printf("Ordenamiento exitoso!\n");
					}
					else if( auxInf == 2 &&
							 !info_totalAndAverageSalaryEmployees(arrayEmpleados,EMP_LEN))
					{
						printf("Promedio e informes exitoso!\n\n");
					}
				}
				else
				{
					printf("No existen empleados o supero los intentos.\n");
				}
				break;
			}
		}
	}while(opcion != 5);
	return EXIT_SUCCESS;
}
