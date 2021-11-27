
#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#define NAME_LEN 51
#define LASTNAME_LEN 51

typedef struct{
	char name[NAME_LEN];
	char lastName[LASTNAME_LEN];
	float salary;
	int sector;
	int id;
	int isEmpty;
}Employee;

int emp_initEmployees(Employee* list, int len);
int emp_addEmployee(Employee* list, int len, int id, char* name,char* lastName,float salary,int sector);
int emp_getEmptyIndex(Employee* list, int len);
int emp_findEmployeeById(Employee* list, int len,int id);
int emp_removeEmployee(Employee* list, int len, int id);
int emp_printEmployees(Employee* list, int len);
int emp_contEmployee(Employee* list, int len);
int emp_modifEmployee(Employee* list,int len, int indice);

#endif /* ARRAYEMPLOYEES_H_ */
