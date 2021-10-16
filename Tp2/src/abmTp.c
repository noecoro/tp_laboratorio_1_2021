

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"
#define EMP_LEN 1000

int main(void) {
    setbuf(stdout,NULL);
    Employee arrayEmp[EMP_LEN];

    int opcion;
    int idEmpleado = 0;
    int indiceAux;
    int idAux;
    int ordenarAux ;
    int totalPromedio;
    float promedioDeSalarios;
    int flagA = 0;


if(initEmployees(arrayEmp, EMP_LEN)==0)
	{
		printf("Array inicializado correctamente. \n\n");
	}
/*
	addEmployeesForzada(arrayEmp, EMP_LEN, &idEmpleado, "Jose", "Diaz", 10100, 1, 0);
	addEmployeesForzada(arrayEmp, EMP_LEN, &idEmpleado, "Mara", "Lopez", 11200, 2, 1);
	addEmployeesForzada(arrayEmp, EMP_LEN, &idEmpleado, "Luna", "Juarez", 12300, 3, 2);
*/
	do
		{
		if(utn_getNumero(&opcion,
						"1.Alta empleado\n"
						"2.Modificar empleado\n"
						"3.Baja empleado\n"
						"4.Informar\n"
						"5.Salir\n",
						"Opción inválida\n", 1, 5, 2) == 0)
				{
		switch(opcion)
			{
			case 1:
				indiceAux = getEmptyIndex(arrayEmp,EMP_LEN);

				if(indiceAux >= 0)
				{
    				if(addEmployees(arrayEmp, EMP_LEN, indiceAux, &idEmpleado) == 0)
    				{
    					printf("Alta exitosa\n");

    				}
				}
				else
				{
					printf("No hay lugar disponible\n");
				}
				flagA = 1;

					break;
			case 2:

				if(flagA == 1)
				{
						printEmployees(arrayEmp,EMP_LEN);
						if(utn_getNumero(&idAux,"Ingrese Id que va a modificar\n","Id incorrecto\n",0,1000,2))
						{
							indiceAux =  findEmployeeById(arrayEmp,EMP_LEN, idAux);
						}
							if(indiceAux >= 0 && modifyEmployeeArray(arrayEmp,EMP_LEN,indiceAux) == 0)
							{
								printf("Modificacion exitosa\n\n");

							}

				}

				else
				{
					printf("Error. debe ingresar a opcion 1\n");
				}


				break;
			case 3:
				if(flagA == 1 )
				{
				printEmployees(arrayEmp,EMP_LEN);
				if(utn_getNumero(&idAux,"Ingrese id que quiere dar de baja\n","Id incorrecto\n",0,1000,2))
				{
					indiceAux = findEmployeeById(arrayEmp,EMP_LEN,idAux);
				}
				if (indiceAux >= 0 && removeEmployee(arrayEmp,EMP_LEN,idAux) == 0)
				{
					printf("Baja exitosa\n");
				}
				else
				{
					printf("Id incorrecto\n");
				}

				}

				break;
			case 4:

				if(flagA == 1 )
				{
					if(utn_getNumero(&ordenarAux,"0.descendente\n1.ascendente","",0,1,1))
					{

						if(sortEmployees(arrayEmp,EMP_LEN,ordenarAux) == 0)
						{
							printf("ok\n");
						}

						printf("Listado empleados ordenados alfabéticamente por Apellido y Sector\n");
						if(printEmployees(arrayEmp,EMP_LEN) == 0)
						{
							printf("ok2\n");
						}

					}

					totalPromedio = promedioSalarios(arrayEmp,EMP_LEN,&promedioDeSalarios);
					printf("\nTotal salarios: %d | promedio: %f \n",totalPromedio,promedioDeSalarios);
					printf("\nEmpleados que igualan o superan el promedio: \n\n ");
					mostrarEmpleadosSuperanPromedio(arrayEmp,EMP_LEN);
				}


				break;

		}
	}
}while(opcion != 5);
	return EXIT_SUCCESS;
}

