/*
 *
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}sEmployee;

int initEmployees(sEmployee[],int);

int inputEmployeeData(sEmployee[],int,int);
int addEmployee(sEmployee[],int,int,char[],char[],float,int);

int checkEmpty(sEmployee[],int);

int findEmployeeById(sEmployee[],int,int);
int removeEmployee(sEmployee[],int,int);
int bajaFunction(sEmployee[],int);

int modFunction(sEmployee[],int);

int sortEmployees(sEmployee[],int,int);

int printOneEmployee(sEmployee);
int printEmployees(sEmployee[],int);
int printEmployeeNormalList(sEmployee[],int);

int salaryPromFunction(sEmployee[],int);

#endif /* ARRAYEMPLOYEES_H_ */
