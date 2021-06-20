/*
 * functions.c
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

int getIntLimit(char *mensaje,char *mensajeError,int limitemin,int limitemax)
{
	int respuesta;

	printf(mensaje);
	scanf("%d",&respuesta);
	while(respuesta<limitemin && respuesta>limitemax)
	{
		printf(mensajeError);
		scanf("%d",&respuesta);
	}

	return respuesta;
}

int getInt(char* mensaje)
{
	int respuesta;

	printf(mensaje);
	scanf("%d",&respuesta);
	while(respuesta<0)
	{
		printf("Ingrese un valor válido: ");
		scanf("%d",&respuesta);
	}

	return respuesta;
}

void getString(char mensaje[], char cadena[])
{
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%s", cadena);
}

int ShowMenu ()
{
	int option;

	printf("\n------------MENU DE OPCIONES------------\n");
	printf("1) Cargar datos desde el archivo de texto\n");
	printf("2) Cargar datos desde el archivo binario\n");
	printf("3) Alta empleado\n");
	printf("4) Modificacion empleado\n");
	printf("5) Baja empleado\n");
	printf("6) Listar empleados\n");
	printf("7) Ordenar empleados\n");
	printf("8) Guardar datos en el archivo de texto\n");
	printf("9) Guardar datos en el archivo binario\n");
	printf("10) Salir\n");
	option = getIntLimit("Elija una opcion: ","Ingrese una opcion válida",1,10);

	return option;
}


