#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Parser.h"
#include "utn.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{//controller abre llama al parser y cierra nada mas
	 int ok = -1;
	 FILE* pFile;
	    if(path != NULL && pArrayListEmployee != NULL)
	    {

	        pFile = fopen(path, "r");
	        if(pFile != NULL)
	        {
	            if( parser_EmployeeFromText(pFile, pArrayListEmployee) == 1)
	            {
	                ok = 1;
	                printf("Empleados cargados correctamente. \n");
	            }
	            else
	            {
	                printf("No se pudieron cargar los empleados.\n");
	            }
	            fclose(pFile);
	        }
	        else
	        {
	            printf("\nEl archivo no pudo abrirse.\n");
	        }
	    }

	    return ok;
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
	 int ok=-1;
	    FILE* pFile;
	    if(path!=NULL && pArrayListEmployee!=NULL)
	    {

	        pFile=fopen(path,"rb");
	        if( pFile != NULL)
	        {
	            if(parser_EmployeeFromBinary(pFile,pArrayListEmployee)==1)
	            {
	                ok=0;
	                printf("Empleados cargados correctamente. \n");
	            }
	            else
	            {
	                printf("No se pudieron cargar los empleados.\n");
	            }

	        }
	        else
	        {
	            printf("\nEl archivo no pudo abrirse.\n");
	        }
	        fclose(pFile);
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

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	Employee* nuevoEmpleado;
		int exito = 0;
		int nuevoId = 1000;
		char nombre[128];
		int sueldo;
		int horasTrabajadas;

		nuevoId = ll_len(pArrayListEmployee);

		nuevoId = nuevoId + 1;

		printf("\n\tAlta \n\n");

		printf("El ID del nuevo Empleado es: %d", nuevoId);

		printf("\nIngrese nombre del Empleado: ");
		fflush(stdin);
		gets(nombre);
		if(pArrayListEmployee != NULL)
		{


		while(strlen(nombre) > 128)
		{
			printf("Invalido. Reingrese nombre del Empleado: ");
			gets(nombre);
			fflush(stdin);
		}

		printf("\nIngrese cantidad de Horas Trabajadas: ");
		fflush(stdin);
		scanf("%d", &horasTrabajadas);
		while(horasTrabajadas < 0 || horasTrabajadas > 1000)
		{
			printf("Invalido. Reingrese cantidad de Horas Trabajadas: ");
			fflush(stdin);
			scanf("%d", &horasTrabajadas);
		}

		printf("\nIngrese sueldo del Empleado: ");
		fflush(stdin);
		scanf("%d", &sueldo);
		while(sueldo < 0)
		{
			printf("Invalido. Reingrese Sueldo del Empleado: ");
			fflush(stdin);
			scanf("%d", &sueldo);
		}

		nuevoEmpleado = employee_newParametros(&nuevoId, nombre, &horasTrabajadas, &sueldo);// con  o sin &&
		//ll_add(pArrayListEmployee, nuevoEmpleado);
		if(nuevoEmpleado != NULL){
			ll_add(pArrayListEmployee, nuevoEmpleado);
			exito = 1;
		}
		}
	    return exito;
	}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
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
	 int ok = -1;
	    int tam = ll_len(pArrayListEmployee);
	    int flag = 0;
	    Employee* auxEmp;

	    if( pArrayListEmployee != NULL)
	    {
	        ok = 1;
	        printf("\n  Id                Nombre  Horas Trabajadas          Sueldo \n");

	        for(int i = 0; i< tam; i++)
	        {
	            auxEmp = (Employee*) ll_get(pArrayListEmployee, i);
	            if (  auxEmp  != NULL )
	            {
	                mostrarEmpleado( auxEmp );
	                flag = 1;
	            }
	        }

	        if(flag == 0)
	        {
	            printf("\nNo hay empleados que mostrar\n");
	        }
	    }
	    return ok;

    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
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
	  FILE* f = fopen(path,"w") ;
	    int tam =  ll_len(pArrayListEmployee);
	    Employee* auxEmp;
	    int ok = -1;

	    if(f != NULL)
	    {
	        fprintf(f,"  Id           Nombre  Horas Trabajadas          Sueldo \n");
	        for (int i =0; i<tam; i++)
	        {
	            auxEmp = (Employee*) ll_get(pArrayListEmployee, i);
	            if (auxEmp !=NULL)
	            {
	                fprintf(f, "%d,%s,%d,%d\n", auxEmp->id, auxEmp->nombre, auxEmp->horasTrabajadas, auxEmp->sueldo);
	                ok = 1;
	            }
	        }
	        fclose(f);

	    }
	    return ok;
    return 1;
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
	   FILE* f = fopen(path,"wb") ;
	    int tam =  ll_len(pArrayListEmployee);
	    Employee* auxEmp;
	    int ok = -1;


	    if(f != NULL)
	    {
	        for (int i =0; i<tam; i++)
	        {
	            auxEmp = (Employee*) ll_get(pArrayListEmployee, i);
	            if (auxEmp != NULL)
	            {
	                fwrite(auxEmp, sizeof(Employee), 1, f);
	                ok = 1;
	            }
	        }
	        fclose(f);

	    }
    return ok;
}
/** \brief abre el archivo proximoId.bin en modo lectura, si no existe lo crea y si existe lee el numero de id que contiene y lo guarda en la variable recibida por parametro
 *
 * \param puntero a varible del tipo entero
 * \return devuelve 1 si pudo conseguir el id del archivo y -1 si el archivo no existia
 *
 */
int obtenerIdDelArchivo(int* id)
{

    *id = 1000;
    int succes = -1;

    FILE* f;
    f = fopen("proximoId.bin","rb");

    if(f != NULL)
    {
        fread(id, sizeof(int), 1, f);
        fclose(f);
        succes = 1;
    }

    return succes;
}
/** \brief al id recibido por parametro le suma 1 y lo escribe en el archivo proximoId.bin
 *
 * \param variable del tipo entero
 * \return 1 si pudo actualizar el archivo con la nueva variable, -1 en caso contrario
 *
 */

int actualizarId(int id)
{
    int proxId =id;
    proxId++;
    int succes  = -1;
    FILE* f;
    f = fopen("proximoid.bin","wb");

    if(f != NULL)
    {
        fwrite(&proxId,sizeof(int),1,f);

        fclose(f);
        succes = 1;
    }

    return succes;
}
