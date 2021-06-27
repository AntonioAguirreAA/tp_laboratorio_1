/*
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "inputs.h"

/**
 * @fn int ShowMenu()
 * @brief
 *
 * @return
 */
int ShowMenu()
{
	int reply;

	printf("\n------------MENU DE OPCIONES------------\n");
	printf("1) Alta empleado\n");
	printf("2) Baja empleado\n");
	printf("3) Modificar empleado\n");
	printf("4) Listado de empleados por sector y alfabeticamente\n");
	printf("5) Total y promedio de los salarios,\ny cuantos empleados superan el salario promedio\n");
	printf("6) Salir\n");
	reply = getInt("");
	while(reply<1 || reply>6)
	{
		reply = getInt("Ingrese una opcion valida: ");
	}

	return reply;
}
