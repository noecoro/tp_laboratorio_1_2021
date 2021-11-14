#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
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
	    int cantParametros;//4
	    Employee* auxEmployee;
	    int ok = -1;
	   // char buffer[4][100];
	    char auxId[4024];//100
	    char auxNombre[4024];
	    char auxHsTrabajadas[4024];
	    char auxSueldo[4024];
	  //  int contador = 0;

	    if (pFile != NULL  && pArrayListEmployee != NULL)
	    {
	    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",auxId , auxNombre,auxHsTrabajadas ,auxSueldo );
	       // fscanf(pFile, "%*[^\n]\n");//text fscanf lectura fantasma esta opc "%*[^\n]\n" reemplaza hacer uno x 1 cada dato
	        while(!feof(pFile))
	        {
	           // auxEmployee = employee_new();
	            cantParametros = fscanf(pFile,"%[^,] , %[^,], %[^,], %[^\n]\n",auxId ,auxNombre,auxHsTrabajadas,auxSueldo );
	            if(cantParametros < 4)
	            {
	               break;
	            }
	            	auxEmployee = employee_newParametros(auxId ,auxNombre,auxHsTrabajadas ,auxSueldo);
	                ll_add(pArrayListEmployee, auxEmployee);
	              //  printf("");
	                ok = 1;
	               /* if(contador == 1000)
	                {
	                	break;
	                }
	                contador ++;
	                ok = 0;*/
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
    int ok=-1;
    Employee* auxEmployee;

    if(pFile!=NULL && pArrayListEmployee!= NULL)
    {
        while(!feof(pFile))
        {
            auxEmployee=employee_new();
            if ( fread ( auxEmployee, sizeof(Employee),1,pFile) != 0)
            {
                ll_add(pArrayListEmployee, auxEmployee);
                ok = 1;
            }
        }

    }
    return ok;

}
