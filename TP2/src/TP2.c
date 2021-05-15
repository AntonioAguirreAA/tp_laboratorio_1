/*
 Programa: Trabajo Practico N� 2

 Objetivo: Una empresa requiere un sistema para administrar su n�mina de empleados. Se sabe que
dicha n�mina bajo ninguna circunstancia superara los 1000 empleados.

El sistema deber� tener el siguiente men� de opciones:
1. ALTAS: Se debe permitir ingresar un empleado calculando autom�ticamente el n�mero
de Id. El resto de los campos se le pedir� al usuario.
2. MODIFICAR: Se ingresar� el N�mero de Id, permitiendo modificar: o Nombre o Apellido
o Salario o Sector
3. BAJA: Se ingresar� el N�mero de Id y se eliminar� el empleado del sistema.
4. INFORMAR:
	1. Listado de los empleados ordenados alfab�ticamente por Apellido y Sector.
	2. Total y promedio de los salarios, y cu�ntos empleados superan el salario promedio.

 Version: 0.1

 Autor: Antonio Aguirre (1�"C")
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "functions.h"

#define EMPLEN 1000

#define TRUE 1
#define FALSE 0

#define ALTA 1
#define BAJA 2
#define MOD 3
#define LIST 4
#define SALARY 5
#define EXIT 6

int main(void)
{
	setbuf(stdout, NULL);
	int reply;
	int idGlobal;
	int flagEmptyEmployees;
	sEmployee ListEmployee[EMPLEN];
	initEmployees(ListEmployee,EMPLEN);
	flagEmptyEmployees = TRUE;
	idGlobal = 0;

	/*------------------------MENU DE OPCIONES------------------------*/
	while(reply != EXIT)
	{
		reply = ShowMenu();
		switch(reply)
		{
			case ALTA:
				idGlobal++;
				inputEmployeeData(ListEmployee,EMPLEN,idGlobal);
				flagEmptyEmployees = FALSE;
				break;

			case BAJA:
				if(flagEmptyEmployees == TRUE)
				{
					printf("Debe ingresar algun empleado primero");
				}	else	{
					bajaFunction(ListEmployee,EMPLEN);
					flagEmptyEmployees = checkEmpty(ListEmployee,EMPLEN);
				}
				break;

			case MOD:
				if(flagEmptyEmployees == TRUE)
				{
					printf("Debe ingresar algun empleado primero");
				}	else	{
					modFunction(ListEmployee,EMPLEN);
				}
				break;
			case LIST:
				if(flagEmptyEmployees == TRUE)
				{
					printf("Debe ingresar algun empleado primero");
				}	else	{
					printEmployees(ListEmployee,EMPLEN);
				}
				break;
			case SALARY:
				if(flagEmptyEmployees == TRUE)
				{
					printf("Debe ingresar algun empleado primero");
				}	else	{
					salaryPromFunction(ListEmployee,EMPLEN);
				}
				break;
		}
	}


	return EXIT_SUCCESS;
}
