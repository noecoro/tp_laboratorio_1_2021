#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"
#include "Informe.h"

/** \brief
Ordene los elementos en la matriz de empleados, el orden de los argumentos
 * indicar orden ARRIBA o ABAJO
 * \param list Employee*
 * \param len int
 * \param order int [1] ariiba - [2] para abajo descendente
 * \return int Return (-1)
si Error [longitud no válida o puntero NULO] - (0) si está bien
 *
 */
int info_sortEmployees(Employee* list, int len, int order)
{
	int retorno = -1;
	int swap;
	int i;
	Employee auxiliar;
	int auxiliarCmp;
	if(list != NULL && len > 0)
	{
		do
		{
			swap = 0;
			for(i=0;i<len-1;i++)
			{
				if(list[i].isEmpty || list[i+1].isEmpty)
				{
					continue;
				}
				auxiliarCmp = strncmp(list[i].lastName,list[i+1].lastName,LASTNAME_LEN);
				if(	order == 1 && //Ascendente.
					(auxiliarCmp > 0 ||
					(auxiliarCmp == 0 && list[i].sector > list[i+1].sector)) )
				{
					swap = 1;
					auxiliar = list[i];
					list[i] = list[i+1];
					list[i+1]=auxiliar;
				}
				else if( order == 2 && //Descendente.
						 (auxiliarCmp < 0 ||
						 (auxiliarCmp == 0 && list[i].sector > list[i+1].sector)) )
				{
					swap = 1;
					auxiliar = list[i];
					list[i] = list[i+1];
					list[i+1]=auxiliar;
				}
			}
			len--;
		}while(swap);
		if( !emp_printEmployees(list,len))
		{
			printf("Empleados ordenados correctamente.\n");
		}
	}
	return retorno;
}

/** \brief Obtiene el total de salarios, junto con el promedio y la cantidad de empledos que superan el salario promedio.
 * \param list Puntero al array de empleados.
 * \param len Longitud del array de empleados.
 * \return int Return 0 si pudo obtener correctamente la informacion y -1 si tuvo error.
 *
 */
int info_totalAndAverageSalaryEmployees(Employee* list, int len)
{
	int retorno = -1;
	int i;
	float acumuladorSalary = 0;
	int contEmployee = 0;
	int contSupAverage = 0;
	float averageSalary;

	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == 0)
			{
				acumuladorSalary += list[i].salary;
				contEmployee++;
			}
		}

		if(contEmployee > 0)
		{
			averageSalary = acumuladorSalary / (float)contEmployee;
		}

		for(i=0;i<len;i++)
		{
			if( list[i].isEmpty == 0 &&
				list[i].salary > averageSalary)
			{
				contSupAverage++;
			}
		}
		retorno = 0;
	}

	printf("El total de  salarios es: %.2f - Y su promedio es: %.2f\n",acumuladorSalary,averageSalary);
	printf("Eempleados que superan el salario promedio: %d\n",contSupAverage);
	return retorno;
}
