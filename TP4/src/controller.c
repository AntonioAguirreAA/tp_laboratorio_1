#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "functions.h"
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int exito = 0;

	ll_clear(pArrayListEmployee);

	FILE* pArchivo;
	pArchivo = fopen(path,"r");//ARCHIVO ABIERTO
	if(pArchivo!=NULL && pArrayListEmployee!=NULL)
	{
		parser_EmployeeFromText(pArchivo , pArrayListEmployee);

		exito = 1;
		printf("Datos cargados del csv.");
	}

	fclose(pArchivo);//ARCHIVO CERRADO

    return exito;
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
	int exito = 0;

	ll_clear(pArrayListEmployee);

	FILE* pArchivo;
	pArchivo = fopen(path,"rb");//ARCHIVO ABIERTO
	if(pArchivo!=NULL && pArrayListEmployee!=NULL)
	{
		parser_EmployeeFromBinary(pArchivo,pArrayListEmployee);

		exito = 1;
		printf("Datos cargados del binario.");
	}

	fclose(pArchivo);//ARCHIVO CERRADO

    return exito;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee , int* lastId)
{
	int exito = 0;
	char nombre[128];

	Employee* eAux;

	eAux = employee_new();

	employee_setId(eAux,*lastId);
	getString("Ingrese el nombre: ",nombre);
	employee_setNombre(eAux,nombre);
	employee_setHorasTrabajadas(eAux,getInt("Ingrese las horas trabajadas: "));
	employee_setSueldo(eAux,getInt("Ingrese el sueldo: "));

	ll_add(pArrayListEmployee,eAux);

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
	int exito = 0;

	int idMod;
	int indexMod;
	Employee* eAux;
	char nombre[128];

	int opcion;

	eAux = employee_new();

	idMod = getInt("Ingrese una ID de la lista para modificar: ");
	indexMod = employee_verifyId(pArrayListEmployee,&idMod);
	while(indexMod == 0)
	{
		idMod = getInt("Ingrese una ID valida: ");
		indexMod = employee_verifyId(pArrayListEmployee,&idMod);
	}

	eAux = ll_get(pArrayListEmployee,indexMod);

	printf("¿Que campo desea modificar?\n");
	printf("1)Nombre 2)Horas 3)Sueldo\n");
	opcion = getIntLimit("","Ingrese una opcion valida",1,3);
	switch(opcion)
	{
		case 1:
			getString("Ingrese el nombre: ",nombre);
			employee_setNombre(eAux,nombre);
			break;

		case 2:
			employee_setHorasTrabajadas(eAux,getInt("Ingrese las horas trabajadas: "));
			break;

		case 3:
			employee_setSueldo(eAux,getInt("Ingrese el sueldo: "));
			break;
	}

	ll_set(pArrayListEmployee,indexMod,eAux);

    return exito;
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
	int exito = 0;

	int idRemove;
	int indexRemove;

	idRemove = getInt("Ingrese una ID de la lista para eliminar: ");
	indexRemove = employee_verifyId(pArrayListEmployee,&idRemove);
	while(indexRemove == 0)
	{
		idRemove = getInt("Ingrese una ID valida: ");
		indexRemove = employee_verifyId(pArrayListEmployee,&idRemove);
	}

	ll_remove(pArrayListEmployee,indexRemove);

    return exito;
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
	int exito = -1;

	Employee* aux;
	int i;
	int len;

	len = ll_len(pArrayListEmployee);

	exito = 0;

	for(i=0;i<len;i++)
	{
	aux = ll_get(pArrayListEmployee,i);
	printf("%d / %s / %d / %d\n",aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);
	}


    return exito;
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
	int exito = 0;
	int respuesta;

	if (pArrayListEmployee != NULL)
	{
		printf("\n1)Ordenar por nombre\n");
		printf("2)Ordenar por id\n");
		respuesta = getIntLimit("Ingrese un criterio para ordenar: ", "Ingrese una opcion valida",1,2);

		switch(respuesta)
		{
			case 1:
				ll_sort(pArrayListEmployee, employee_compareName, 1);
				break;
			case 2:
				ll_sort(pArrayListEmployee, employee_compareId, 1);
				break;
		}

		exito = 1;
	}

    return exito;
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
	int exito = 0;

	int i;
	int len;

	FILE* pArchivo;
	Employee* aux;

	pArchivo = fopen(path,"w");//ARCHIVO ABIERTO

	if(pArchivo != NULL && pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);

		fprintf(pArchivo,"%s,%s,%s,%s\n","Id","Nombre","HorasTrabajadas","Sueldo");//CABECERA

		for(i=0 ; i<len ; i++)
		{
			aux =  ll_get(pArrayListEmployee,i);
			fprintf(pArchivo,"%d,%s,%d,%d\n",aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);
		}

		//fprintf(pArchivo,"%d,%s,%d,%d\n",1015,"Antonio",100,40000);//PRUEBA

		fclose(pArchivo);//ARCHIVO CERRADO

		printf("Texto guardado.");

		exito = 1;
	}

    return exito;
}

/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int exito = 0;

	int i;
	int len;

	FILE* pArchivo;
	Employee* aux;

	pArchivo = fopen(path,"wb");//ARCHIVO ABIERTO

	if(pArchivo != NULL && pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);

		for(i=0 ; i<len ; i++)
		{
			aux = ll_get(pArrayListEmployee,i);
			fwrite(aux,sizeof(Employee),1,pArchivo);
		}

		fclose(pArchivo);//ARCHIVO CERRADO

		printf("Binario guardado.");

		exito = 1;
	}

    return exito;
}

/**
 * @brief Obtiene la id mas alta que se haya registrado de la linked list
 *
 * @param path
 * @return
 */
int controller_findLastId(LinkedList* pArrayListEmployee)
{
	int lastId = 0;

	int len;
	int i;
	Employee* aux;

	len = ll_len(pArrayListEmployee);
	for(i=0 ; i<len ; i++)
	{
		aux = ll_get(pArrayListEmployee,i);
		if(aux->id > lastId)
		{
			lastId = aux->id;
		}
	}

	return lastId;
}

/**
 * @brief Obtiene la id mas alta que se haya registrado del archivo lastId.bin o lastIdBin.bin
 *
 * @param path
 * @return
 */
int controller_getLastId(char* path)
{
	int lastId = 0;

	FILE* pUltimaId;

	pUltimaId = fopen(path,"rb");//ARCHIVO ABIERTO
	if(pUltimaId != NULL)
	{
		fread(&lastId,sizeof(int),1,pUltimaId);
	}
	fclose(pUltimaId);//ARCHIVO CERRADO

	return lastId;
}

/**
 * @brief Guarda la id mas alta que se haya registrado en el archivo lastId.bin o lastIdBin.bin
 *
 * @param path
 * @param lastId
 * @return
 */
int controller_setLastId(char* path , int* lastId)
{
	int exito = 0;

	FILE* pUltimaId;

	pUltimaId = fopen(path,"wb");//ARCHIVO ABIERTO
	if(pUltimaId != NULL)
	{
		fwrite(lastId,sizeof(int),1,pUltimaId);
		exito = 1;
	}
	fclose(pUltimaId);//ARCHIVO CERRADO

	return exito;
}

/**
 * @fn int controller_testTP(LinkedList*)
 * @brief Clona la lista existente con ll_clone, la compara con ll_containsAll, la muestra y la elimina con ll_deleteLinkedList
 *
 * @param pArrayListEmployee
 * @return 0 = ll==NULL
 * 			1 = OK
 */
int controller_testTP(LinkedList* pArrayListEmployee)
{
	int exito = 0;

	LinkedList* clon;

	int contains;

	if(pArrayListEmployee!=NULL)
	{
		clon = ll_newLinkedList();

		clon = ll_clone(pArrayListEmployee);

		controller_ListEmployee(pArrayListEmployee);
		printf("\n^^^ Lista Clonada.\n");

		contains = ll_containsAll(pArrayListEmployee,clon);
		printf("\nContains: %d\n",contains);

		printf("---Delete---");
		if(ll_deleteLinkedList(clon)==0)
		{
			printf("Lista eliminada\n");
		}	else	{
			printf("Lista no eliminada");
		}

		exito = 1;
	}

	return exito;
}
