#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include <string.h>
Employee* employee_new(void)//reserv espacion en memoria no carga nada, carga los campos en el default ej: id,nombre etc en cero
{//reserv esp en memo p ese empleado q cree
	Employee* auxiliarP = NULL;
	auxiliarP = (Employee*) malloc(sizeof(Employee));

	if(auxiliarP != NULL)
	{
		employee_setId(auxiliarP, 0);
		employee_setNombre(auxiliarP, " ");
		employee_setHorasTrabajadas(auxiliarP, 0);
        employee_setSueldo(auxiliarP, 0);
	}

	return auxiliarP;
}

void employee_delete(Employee* this)//elimina un empleado se usa x ej: en la baja!
{
	if(this != NULL)
	{
		free(this);//paraliberar lo q pedi con malloc
	}
}


int employee_setId(Employee* this,int id)
{
	int retorno = 1;
	if ( this != NULL && id >0 )
	{
       this-> id = id;
       retorno = 0;
   }
	return retorno;
}

int employee_getId(Employee* this,int* id)
{
	int retorno = 1;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = 1;
    if (this != NULL  && strlen(nombre) >= 3  && strlen(nombre) < 127)
    {
        strcpy(this -> nombre, nombre);
        retorno = 0;
    }
	return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = 1;
	if(this != NULL && nombre != NULL)
	{

		strcpy(nombre,this->nombre);
		//retorno = 1;
		retorno = 0;
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int retorno = 1;

    if ( this != NULL && horasTrabajadas >0 && horasTrabajadas <= 2000 )
    {
        this-> horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }
    return  retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = 1;
	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

int employee_setSueldo(Employee* this, int sueldo)
{
    int retorno = 1;

    if ( this != NULL && sueldo >0)
    {
        this-> sueldo = sueldo;
        retorno = 0;
    }
    return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    //int retorno = -1;
    int retorno = 1;
    if ( this != NULL && sueldo != NULL)
    {
        *sueldo = this -> sueldo;
        retorno = 0;
    }
    return retorno;
}

Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{//reserv espac en memo  p ese emplead y ademas va a cargar los campos d la esturct con los datos q le pase ej: en id carga lo q le pase y asi con todos
    Employee* newEmployee = NULL;

    if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
    newEmployee = employee_new();//llamo al constructor inicializa los campos  y desp seteo los valores

    	if(newEmployee != NULL)
    	{

    		if ( employee_setId(newEmployee, atoi(idStr)) == 1 ||
                employee_setNombre(newEmployee, nombreStr) ==1 ||
                employee_setHorasTrabajadas(newEmployee, atoi(horasTrabajadasStr)) ==1||
                employee_setSueldo(newEmployee, atoi(sueldoStr)) == 1)
    			{

            employee_delete(newEmployee);//como free

            newEmployee = NULL;
    			}
    		printf("%d   %s   %d    %d\n", newEmployee->id,newEmployee->nombre,newEmployee->horasTrabajadas,newEmployee->sueldo);
    	}
    }
    return newEmployee;
}
//******************************_________=============
int mostrarEmpleado(Employee* this)
{
    int ok =-1;
    if(this != NULL)
    {
        ok = 1;
        printf("%4d  %20s  %4d                     %5d \n", this->id, this->nombre, this-> horasTrabajadas, this->sueldo);
    }
    return ok;
}
