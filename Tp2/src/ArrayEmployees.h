
#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#define NAME_LEN 51
#define LASTNAME_LEN 51
typedef struct
{
	int id;
	char name[NAME_LEN];
	char lastName[LASTNAME_LEN];
	float salary;
	int sector;
	int isEmpty;

}Employee;
int menu();
int printEmployees(Employee* list,int length);
int initEmployees(Employee* list, int len );
int getEmptyIndex(Employee* list,int len);
int addEmployeesForzada(Employee* list, int len, int* id, char name[],char lastName[],float salary,int sector, int indice);
int addEmployees(Employee* list,int len, int indice, int* id);
int modifyEmployeeArray(Employee* list,int len, int indice);
int findEmployeeById(Employee* list, int len, int id);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);
int promedioSalarios(Employee* list, int len, float* promedioSalario);
int mostrarEmpleadosSuperanPromedio(Employee* list, int len);
#endif /* ARRAYEMPLOYEES_H_ */
