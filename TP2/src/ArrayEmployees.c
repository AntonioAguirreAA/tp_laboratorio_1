/*
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "inputs.h"

#define OCUPADO 1
#define DISPONIBLE 0

#define TRUE 1
#define FALSE 0

/**
 * @fn int initEmployees(sEmployee[], int)
 * @brief Inicializa el listado de empleados
 *
 * @param ListEmployee
 * @param len
 * @return
 */
int initEmployees(sEmployee ListEmployee[], int len)
{
	int i;

	for(i=0 ; i<len ; i++)
	{
		ListEmployee[i].isEmpty = DISPONIBLE;
	}

	return 0;
}

/**
 * @fn int addEmployee(sEmployee[], int, int, char[], char[], float, int)
 * @brief
 *
 * @param ListEmployee
 * @param len
 * @param idGlobal
 * @param name
 * @param lastName
 * @param salary
 * @param sector
 * @return
 */
int addEmployee(sEmployee ListEmployee[],int len , int idGlobal , char name[] , char lastName[] , float salary , int sector)
{
	int i;
	int flagAnyEmpty;

	flagAnyEmpty=TRUE;

	for(i=0 ; i<len ; i++)
	{
		if (ListEmployee[i].isEmpty == DISPONIBLE)
		{
			ListEmployee[i].isEmpty=OCUPADO;
			ListEmployee[i].id=idGlobal;
			strcpy(ListEmployee[i].name,name);
			strcpy(ListEmployee[i].lastName,lastName);
			ListEmployee[i].salary=salary;
			ListEmployee[i].sector=sector;
			flagAnyEmpty = FALSE;
			printf("\nEmpleado agregado correctamente.\n");
			break;
		}
	}

	if(flagAnyEmpty == TRUE)
	{
		printf("\nNo hay espacios disponibles para agregar empleados.\n");
	}

	return 0;
}

/**
 * @fn int inputEmployeeData(sEmployee[], int, int)
 * @brief
 *
 * @param ListEmployee
 * @param len
 * @param idGlobal
 * @return
 */
int inputEmployeeData(sEmployee ListEmployee[], int len , int idGlobal)
{
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	printf("\n------------ALTA DE EMPLEADO------------\n");
	getString("Ingrese el nombre del empleado: ",name);
	getString("Ingrese el apellido del empleado: ",lastName);
	salary = getFloat("Ingrese el salario: ");
	sector = getInt("Ingrese el sector: ");

	addEmployee(ListEmployee,len,idGlobal,name,lastName,salary,sector);

	return 0;
}

/**
 * @fn int checkEmpty(sEmployee[], int)
 * @brief
 *
 * @param ListEmployee
 * @param len
 * @return
 */
int checkEmpty(sEmployee ListEmployee[], int len)
{
	int i;
	int state;
	state = TRUE;
	for(i=0;i<len;i++)
	{
		if(ListEmployee[i].isEmpty==OCUPADO)
		{
			state = FALSE;
			break;
		}
	}
	return state;
}

/**
 * @fn int findEmployeeById(sEmployee[], int, int)
 * @brief
 *
 * @param ListEmployee
 * @param len
 * @param idToFind
 * @return
 */
int findEmployeeById(sEmployee ListEmployee[], int len ,int idToFind)
{
	int indexId;
	int i;
	indexId = -1;

	for ( i = 0; i < len; i++)
	{
		if (ListEmployee[i].isEmpty==OCUPADO && ListEmployee[i].id == idToFind)
		{
			indexId = i;
			break;
		}	
	}

	return indexId;
}

/**
 * @fn int removeEmployee(sEmployee[], int, int)
 * @brief
 *
 * @param ListEmployee
 * @param len
 * @param idToRemove
 * @return
 */
int removeEmployee(sEmployee ListEmployee[], int len ,int idToRemove)
{
	int i;
	for ( i = 0; i < len; i++)
	{
		if(ListEmployee[i].id == idToRemove)
		{
			ListEmployee[i].isEmpty = DISPONIBLE;
			printf("\nEmpleado id[%d] eliminado.",ListEmployee[i].id);
		}
	}
	return 0;
}

/**
 * @fn int bajaFunction(sEmployee[], int)
 * @brief
 *
 * @param ListEmployee
 * @param len
 * @return
 */
int bajaFunction(sEmployee ListEmployee[], int len)
{
	int idToRemove;
	printEmployeeNormalList(ListEmployee,len);
	idToRemove = getInt("Ingrese la ID del empleado que desea borrar: ");
	while(findEmployeeById(ListEmployee,len,idToRemove) == -1)
	{
		idToRemove = getInt("Ingrese una ID valida: ");
	}
	removeEmployee(ListEmployee,len,idToRemove);
	return 0;
}

/**
 * @fn int modFunction(sEmployee[], int)
 * @brief
 *
 * @param ListEmployee
 * @param len
 * @return
 */
int modFunction(sEmployee ListEmployee[], int len)
{
	printEmployeeNormalList(ListEmployee,len);
	int idToModificate;
	int indexToModificate;
	int reply;

	//Pide y verifica el ID
	idToModificate = getInt("Ingrese la ID del empleado que desea modificar: ");
	indexToModificate=findEmployeeById(ListEmployee,len,idToModificate);

	while(indexToModificate == -1)
	{
		idToModificate = getInt("Ingrese una ID valida: ");
		indexToModificate=findEmployeeById(ListEmployee,len,idToModificate);
	}

	//Pide y verifica campo a modificar
	printf("¿Que desea modificar?\n");
	printf("1) Nombre\n");
	printf("2) Apellido\n");
	printf("3) Salario\n");
	printf("4) Sector\n");
	scanf("%d",&reply);
	while(reply<1 || reply>6)
	{
		getInt("Ingrese una opcion valida: ");
	}

	//Modifica el campo elegido
	switch(reply)
	{
		case 1:
			getString("Ingrese el nuevo nombre: ",ListEmployee[indexToModificate].name);
			break;
		case 2:
			getString("Ingrese el nuevo apellido: ",ListEmployee[indexToModificate].lastName);
			break;
		case 3:
			ListEmployee[indexToModificate].salary=getFloat("Ingrese el nuevo salario: ");
			break;
		case 4:
			ListEmployee[indexToModificate].sector=getInt("Ingrese el nuevo sector: ");
			break;
		}
	return 0;
}

/**
 * @fn int sortEmployees(sEmployee[], int, int)
 * @brief
 *
 * @param ListEmployee
 * @param len
 * @param order
 * @return
 */
int sortEmployees(sEmployee ListEmployee[], int len, int order)
{
	int i;
	int j;
	sEmployee aux;

	if(order==1)//orden 1 ordena por sector y nombre
	{
		//Ordenamiento por sector
		for(i=0; i< len-1; i++)
		{
			for(j=i+1; j < len; j++)
			{
				if(ListEmployee[i].sector>ListEmployee[j].sector)
				{
					aux = ListEmployee[i];
					ListEmployee[i] = ListEmployee[j];
					ListEmployee[j] = aux;
				}
			}
		}
		//Ordenamiento por nombre para cada sector
		for(i=0; i< len-1; i++)
		{
			for(j=i+1; j < len; j++)
			{
				if(ListEmployee[i].sector==ListEmployee[j].sector && strcmp(ListEmployee[i].name, ListEmployee[j].name)>0)
				{
					aux = ListEmployee[i];
					ListEmployee[i] = ListEmployee[j];
					ListEmployee[j] = aux;
				}
			}
		}
	}	else	{
		if(order == 2)//orden 2 ordena por id
		{
			for(i=0; i< len-1; i++)
			{
				for(j=i+1; j < len; j++)
				{
					if(ListEmployee[i].id>ListEmployee[j].id)
					{
						aux = ListEmployee[i];
						ListEmployee[i] = ListEmployee[j];
						ListEmployee[j] = aux;
					}
				}
			}
		}
	}
	return 0;
}

/**
 * @fn int printOneEmployee(sEmployee)
 * @brief
 *
 * @param Employee
 * @return
 */
int printOneEmployee(sEmployee Employee)
{
	printf("%-4d|%-15s|%-15s|%-15.2f|%-10d\n",Employee.id,
									Employee.name,
									Employee.lastName,
									Employee.salary,
									Employee.sector);
	return 0;
}

/**
 * @fn int printEmployees(sEmployee[], int)
 * @brief
 *
 * @param ListEmployee
 * @param len
 * @return
 */
int printEmployees(sEmployee ListEmployee[], int len)
{
	int i;
	int flagFirstSector;

	flagFirstSector = TRUE;

	sortEmployees(ListEmployee,len,1);


	printf("\n ID |    Nombre     |   Apellido    |    Salario    |   Sector\n");
	printf("---------------------------------------------------------------\n");

	for (i=0 ; i<len ; i++)
	{
		if(ListEmployee[i].isEmpty==OCUPADO)
		{
			//Imprime un separador por sector
			if(flagFirstSector == TRUE || ListEmployee[i].sector != ListEmployee[i-1].sector)
			{
				flagFirstSector = FALSE;
				printf("----------------------Empleados del sector %d--------------------\n",ListEmployee[i].sector);
			}
			//Imprime los datos del array
			printOneEmployee(ListEmployee[i]);
		}
	}

	return 0;
}

/**
 * @fn int printEmployeeNormalList(sEmployee[], int)
 * @brief
 *
 * @param ListEmployee
 * @param len
 * @return
 */
int printEmployeeNormalList(sEmployee ListEmployee[], int len)
{
	int i;

	sortEmployees(ListEmployee,len,2);//orden 2 ordena por ID

	printf("\n ID |    Nombre     |   Apellido    |    Salario    |   Sector\n");
	printf("---------------------------------------------------------------\n");

	for (i=0 ; i<len ; i++)
	{
		if(ListEmployee[i].isEmpty==OCUPADO)
		{
			//Imprime los datos del array
			printOneEmployee(ListEmployee[i]);
		}
	}

	return 0;
}

/**
 * @fn int salaryPromFunction(sEmployee[], int)
 * @brief
 *
 * @param ListEmployee
 * @param len
 * @return
 */
int salaryPromFunction(sEmployee ListEmployee[], int len)
{
	int i;
	int contSalary;
	float acumuladorSalary;
	float promSalary;

	contSalary=0;
	acumuladorSalary=0;

	for (i=0;i<len;i++)
	{
		if(ListEmployee[i].isEmpty==OCUPADO)
		{
			contSalary++;
			acumuladorSalary+=ListEmployee[i].salary;
		}
	}

	promSalary = acumuladorSalary/contSalary;

	printf("\nEl total de salarios es: $%.2f\n",acumuladorSalary);
	printf("El promedio de salarios es : $%.2f\n",promSalary);
	printf("\nEmpleados con salario mayor al promedio:\n");
	printf("\n ID |    Nombre     |   Apellido    |    Salario    |   Sector\n");
	printf("---------------------------------------------------------------\n");
	for (i=0 ; i<len ; i++)
	{
		if(ListEmployee[i].isEmpty==OCUPADO && ListEmployee[i].salary>promSalary)
		{
			//Imprime los datos del array
			printOneEmployee(ListEmployee[i]);
		}
	}
	return 0;
}
