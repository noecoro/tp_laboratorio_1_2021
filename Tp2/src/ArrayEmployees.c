//biblios

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"
#define TRUE 1
#define FALSE 0
#define NOTFOUND -1
#define NOTOK -1
#define OK 0
int menu()
{
    int opcion;

    printf("\n\n===== Gestion de empleados ==== \n\n");
    printf("\n\n1.  Alta.\n");
    printf("2.  Modificar.\n");
    printf("3.  Baja.\n");
    printf("4.  Informar.\n");
    printf("5.  Salir.\n");
    if(utn_getNumero(&opcion, "Ingrese opcion: ","",1,5,0) == -1)
    {
        opcion = 0;
    }

    return opcion;

}
/**
 * \brief Imprime el array de empleados
 * \param list Array de empleados a ser impreso
 * \param length Limite del array de empleados
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int printEmployees(Employee* list,int length)
{
	int respuesta = -1;
	int i;

	if(list != NULL && length >= 0)
	{
		respuesta = 0;

		printf("Id   nombre    apellido    salario    sector \n");
		for(i = 0;i < length;i ++)
		{
			if(list[i].isEmpty == 0)
			{
				printf("%d- %8s - %8s -  %8.f  %3d\n",	list[i].id,
																		list[i].name,
																		list[i].lastName,
																		list[i].salary,
																		list[i].sector);
			}
		}
	}
	return respuesta;
}

int initEmployees(Employee* list, int len )
{
	int retorno = NOTOK;
	int i;
	if(list != NULL && len >= 0)
	{
		for(i = 0; i < len; i++)
		{
			list[i].isEmpty = 1; //1;
		}
		retorno = OK;//0
	}
	return retorno;
}
/**
 * \brief Buscar primer posicion vacia
 * \param array Array de empleados
 * \param limite Limite del array de empleados
 * \return Retorna el indice de la posicion vacia y -1 (ERROR)
 *
 */
int getEmptyIndex(Employee* list,int len)
{
	int respuesta = -1;
	int i;
	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == 1)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}
/**
 * \brief Da de alta a un empleado
 * \param list Array de empleados a ser actualizado
 * \param len Limite del array de empleados
 * \param id Puntero Id a dar de alta
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int addEmployees(Employee* list,int len, int indice, int* id)
{
	int respuesta = -1;
	Employee bufferEmployee;

	if(list != NULL && len > 0 && indice < len && indice >= 0 && id != NULL)
	{
		if(	utn_getNombre(bufferEmployee.name,NAME_LEN,"\nIngrese nombre\n","\nERROR\n",2) == 0 &&
			utn_getNombre(bufferEmployee.lastName,LASTNAME_LEN,"\nIngrese apellido\n","\nERROR\n",2) == 0 &&
			utn_getNumeroFlotante(&bufferEmployee.salary,"\nIngrese salario?\n","\nERROR\n",0,10000,2) == 0 &&
			utn_getNumero(&bufferEmployee.sector,"Ingrese sector\n","Sector incorrecto\n",0,100,2)==0)
		{

			//respuesta = 0;
			bufferEmployee.id = *id;
			bufferEmployee.isEmpty = 0;
			list[indice] = bufferEmployee;
			printf("%d\n",list[indice].isEmpty);
			(*id)++;
			respuesta = 0;
		}
	}
	return respuesta;
}

/**
 * \brief Da de alta Forzada a un empleado
 * \param list Array de empleados a ser actualizado
 * \param len Limite del array de empleados
 * \param id Id a ser actualizada
 * \param name Nombre a ser asignado al empleado
 * \param lastName Apellido a ser asignado al empleado
 * \param salary Salario a ser asignado al empleado
 * \param sector Sector a ser asignado al empleado
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int addEmployeesForzada(Employee* list, int len, int* id, char name[],char lastName[],float salary,int sector, int indice)
{
	int respuesta = -1;
	Employee bufferEmployee;

	if(list != NULL && len > 0 && id != NULL && name != NULL && lastName != NULL && salary >= 0 && sector >=0 && indice >=0)
	{
			strncpy(bufferEmployee.name,name,NAME_LEN);
			strncpy(bufferEmployee.lastName,lastName,LASTNAME_LEN);
			respuesta = 0;
			bufferEmployee.salary = salary;
			bufferEmployee.sector = sector;
			bufferEmployee.isEmpty = 0;
			bufferEmployee.id = *id;
			list[indice] = bufferEmployee;
			(*id)++;
	}
	return respuesta;
}

/**
 * \brief Actualiza los datos de un empleado en una posicion del array
 * \param list Array de empleados a ser actualizado
 * \param len Limite del array de empleados
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int modifyEmployeeArray(Employee* list,int len, int indice)
{
	int respuesta = -1;
	Employee auxiliar;
	int opcion;
	if(list != NULL && len > 0 && indice < len)
	{
	do
	{
		if(utn_getNumero(&opcion, "\nIngrese el valor que desea modificar:\n1.Nombre\n2.Apellido\n3.Salario\n4.Sector\n5.Salir\n", "Opcion incorrecta\n", 1, 5, 2))
		{
			switch(opcion)
			{
			case 1:
				utn_getNombre(auxiliar.name, NAME_LEN, "Ingrese nombre empleado:\n", "Valor inválido\n", 2);
				strncpy(list[indice].name,auxiliar.name, NAME_LEN);
				printf("El nombre se modificó correctamente\n");
				break;
			case 2:
				utn_getDescripcion(auxiliar.lastName, LASTNAME_LEN, "Ingrese Apellido:\n", "Valor inválido\n", 2);
				strncpy(list[indice].lastName,auxiliar.lastName, LASTNAME_LEN);
				printf("El apellido se modificó correctamente\n");
				break;
			case 3:
				utn_getNumeroFlotante(&auxiliar.salary, "Ingrese salario:\n", "Valor inválido\n", 0, 100000, 2);
				list[indice].salary = auxiliar.salary;
				printf("El salario se modificó correctamente\n");
				break;
			case 4:
				utn_getNumero(&auxiliar.sector, "Ingrese sector:\n", "Valor inválido\n", 0, 10, 2);
				list[indice].sector = auxiliar.sector;
				printf("El sector se modificó correctamente\n");
				break;

			}
			respuesta = 0;
			list[indice].isEmpty = 0;

		}
	}while(opcion !=5);

	}

	return respuesta;
}
/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param list Array de empleados
* \param len int Tamaño del array
* \param id int id del array a encontrar
* \return int Return (-1) si no encuentra el valor buscado sino, retorna el indice donde se encuentra el valor buscado
*
*/
int findEmployeeById(Employee* list, int len, int id)
{
    int retorno=-1;
    int i;
    if(list!= NULL && len  >= 0)
    {
        for(i = 0;i < len;i++)
        {
            if(list[i].isEmpty==0 && list[i].id==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/**
 * \brief Elimina una posicion del array
 * \param list Array de empleados a ser modificado
 * \param len Limite del array de empleados
 * \param id id a ser eliminada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int removeEmployee(Employee* list, int len, int id)
{
	int respuesta = -1;
	int auxIndice;
	if(list != NULL && len > 0 && id < len)
	{
		auxIndice = findEmployeeById(list, len, id);
		respuesta = 0;
		list[auxIndice].isEmpty = 1;
	}
	return respuesta;
}


/**
 * \brief Ordena el array de empleados por apellido y sector
 * \param list Array de empleados
 * \param len Limite del array de empleados
 * 'param order indica 1 para ordenar ascendente o 0 para ordenar desendente
 * \return Retorna 0 si pudo o -1 (ERROR)
 *
 */

int sortEmployees(Employee* list, int len, int order)
{
	int rta = -1;
	int i;
	int flagSwap;
	Employee auxiliar;
	int auxiliarCmp;
	if(list != NULL && len > 0 && (order == 0 || order == 1))
	{
		rta = 0;
		do
		{
			flagSwap = 0;
			for(i=0;i<len-1;i++)
			{
				if(list[i].isEmpty || list[i+1].isEmpty)
				{
					continue;
				}
				auxiliarCmp = strncmp(list[i].lastName,list[i+1].lastName,LASTNAME_LEN);
				if(	 (auxiliarCmp > 0 && order == 1) ||
					(auxiliarCmp == 0 && list[i].sector < list[i+1].sector && order == 1) )
				{
					flagSwap = 1;


					auxiliar = list[i];
					list[i] = list[i+1];
					list[i+1]= auxiliar;
				}
				if(	 (auxiliarCmp < 0 && order == 0) ||
					(auxiliarCmp == 0 && list[i].sector > list[i+1].sector && order == 0) )
				{
					flagSwap = 1;
					auxiliar = list[i+1];
					list[i+1] = list[i];
					list[i]= auxiliar;
				}
			}
			len--;
		}while(flagSwap);
	}
	return rta;
}

/** \brief Suma todos los salarios y devuelve el promedio
* \param list Array de empleados
* \param len int Tamaño del array
* \param promedioSalario Puntero donde será guardado el promedio
* \return int Return (-1) ERROR, sino la suma de los salarios
*
*/
int promedioSalarios(Employee* list, int len, float* promedioSalario)
{
    int retorno=-1;
    int i;
    float sumaSalarios=0;
    int contador=0;
    float AuxSalarios;
    if(list!= NULL && len>=0 && promedioSalario != NULL)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty==0)
            {
            	sumaSalarios = sumaSalarios + list[i].salary;
                contador++;
            }
        }
        AuxSalarios = sumaSalarios / contador;
        retorno = sumaSalarios;
        *promedioSalario = AuxSalarios;
    }
    return retorno;
}



/** \brief Imprime los empleados que sumperan el salario promedio
* \param list Array de empleados
* \param len int Tamaño del array
* \return int Return (-1) ERROR, o 0 si salió bien
*
*/
int mostrarEmpleadosSuperanPromedio(Employee* list, int len)
{
    int retorno=-1;
    int i;
    float auxPromedio;
    if(list != NULL && len>=0)
    {
    	printf("Id   nombre    apellido    salario    sector \n");
        for(i=0;i<len;i++)
        {
        promedioSalarios(list, len, &auxPromedio);
            if(list[i].isEmpty==0 && list[i].salary >= auxPromedio)
            {
            	printf("%d- %8s - %8s - %8.2f %8d\n",	list[i].id,
														list[i].name,
														list[i].lastName,
														list[i].salary,
														list[i].sector);
            	retorno =0;
            }
        }
    }
    return retorno;
}


/**
 * \brief Ordenar el array de empleados por apellido y sector
 * \param list Array de empleados
 * \param len Limite del array de empleados
 * 'param order indica 1 para ordenar ascendente o 0 para ordenar desendente
 * \return Retorna 0 si pudo o -1 (ERROR)
 *
 */
//1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
/*int sortEmployees(Employee* list, int len, int order)
{
	int respuesta = -1;
	int i;
	int flagSwap;
	Employee auxiliar;
	//int auxiliarCmp;
	if(list != NULL && len > 0 && (order == 0 || order == 1))
	{
		respuesta = 0;
		do
		{
			flagSwap = 0;
			for(i=0;i<len-1;i++)
			{

				 if(strncmp(list[i].lastName,list[i+1].lastName,LASTNAME_LEN) >0
				|| (strncmp(list[i].lastName,list[i+1].lastName,LASTNAME_LEN) == 0
				&&  list[i].sector < list[i+1].sector ))
				 {

					flagSwap = 1;

					auxiliar = list[i];
					list[i] = list[i+1];
					list[i+1]= auxiliar;
				}


			}

			len--;
		}while(flagSwap);
	}
	return respuesta;
}*/
