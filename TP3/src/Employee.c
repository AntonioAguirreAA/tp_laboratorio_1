#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "functions.h"

Employee* employee_new()
{
	Employee* pAux;
	pAux = (Employee*)malloc(sizeof(Employee));
	return pAux;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	int id;
	int horas;
	int sueldo;

	Employee* aux;

	aux = employee_new();

	//verificar setters
	id = atoi(idStr);
	employee_setId(aux,id);

	employee_setNombre(aux,nombreStr);

	horas = atoi(horasTrabajadasStr);
	employee_setHorasTrabajadas(aux,horas);

	sueldo = atoi(sueldoStr);
	employee_setSueldo(aux,sueldo);

	return aux;
}

int employee_setId(Employee* this,int id)
{
	int exito = 0;

	if(this != NULL)
	{
		exito = 1;
		this->id = id;
	}

	return exito;
}
int employee_getId(Employee* this,int* id)
{
	int exito = 0;

	if(this != NULL)
	{
		exito = 1;
		*id = this->id;
	}

	return exito;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int exito = 0;

	if(this != NULL && nombre != NULL)//agregar al resto
	{
		exito = 1;
		strcpy(this->nombre , nombre);
	}

	return exito;
}
int employee_getNombre(Employee* this,char* nombre)
{
	int exito = 0;

	if(this != NULL)
	{
		exito = 1;
		strcpy(nombre , this->nombre);
	}

	return exito;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int exito = 0;

	if(this != NULL)
	{
		exito = 1;
		this->horasTrabajadas = horasTrabajadas;
	}

	return exito;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int exito = 0;

	if(this != NULL)
	{
		exito = 1;
		*horasTrabajadas = this->horasTrabajadas;
	}

	return exito;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int exito = 0;

	if(this != NULL)
	{
		exito = 1;
		this->sueldo = sueldo;
	}

	return exito;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int exito = 0;

	if(this != NULL)
	{
		exito = 1;
		*sueldo = this->sueldo;
	}

	return exito;
}

int employee_verifyId(LinkedList* pArrayListEmployee , int* idMod)
{
	int indexMod = 0;
	Employee* eAux;

	int len;
	len = ll_len(pArrayListEmployee);

	for(int i = 0 ; i<len ; i++)
	{
		eAux = ll_get(pArrayListEmployee,i);
		if(eAux->id == *idMod)
		{
			indexMod = i;
			break;
		}
	}

	return indexMod;
}

int employee_compareName(void* empleadoA, void* empleadoB)
{
	int comparacion;
	char nombreA[128];
	char nombreB[128];

	employee_getNombre((Employee*)empleadoA,nombreA);
	employee_getNombre((Employee*)empleadoB,nombreB);

	comparacion = strcmp(nombreA,nombreB);

	if(comparacion>0)
	{
		comparacion = 1;
	}	else	{
		if(comparacion<0)
		{
			comparacion = -1;
		}
	}

	return comparacion;
}

int employee_compareId(void* empleadoA, void* empleadoB)
{
	int comparacion;
	int idA;
	int idB;

	employee_getId((Employee*) empleadoA,&idA);
	employee_getId((Employee*) empleadoB,&idB);

	if(idA > idB)
	{
		comparacion = 1;
	}	else	{
		if(idA < idB)
		{
			comparacion = -1;
		}	else	{
			comparacion = 0;
		}
	}

	return comparacion;
}
