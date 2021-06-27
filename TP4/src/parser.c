#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	char id[51];
	char nombre[51];
	char horas[51];
	char sueldo[51];
	Employee *eAux;

	fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo);
	while(!feof(pFile))
	{
		//verificar lectura
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo);
		eAux = employee_newParametros(id,nombre,horas,sueldo);//verificar
		ll_add(pArrayListEmployee,eAux);//verificar
	}

    return 1;
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
	int exito = 0;

	Employee* eAux;

	while(!feof(pFile))
	{
		eAux = employee_new();
		if(fread(eAux,sizeof(Employee),1,pFile)==1)
		{
			ll_add(pArrayListEmployee,eAux);//verificar
		}
	}

    return exito;
}
