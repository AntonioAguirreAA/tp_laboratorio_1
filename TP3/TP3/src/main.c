#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "functions.h"
#include "input.h"

#define LOADTXT 1
#define LOADBIN 2
#define ALTA 3
#define MOD 4
#define BAJA 5
#define LIST 6
#define SORT 7
#define SAVETXT 8
#define SAVEBIN 9
#define EXIT 10

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout, NULL);
    int option = 0;

    int lastId;

	LinkedList* listaEmpleados = ll_newLinkedList();


	/*---------------------------MENU---------------------------*/
    while(option != 10)
    {
    	option = ShowMenu();
        switch(option)
        {
            case 1:
            	if(controller_loadFromText("data.csv" , listaEmpleados)==0)
            	{
            		printf("\nEl archivo no existe\n");
            	}	else	{
					lastId = controller_getLastId("lastId.bin");
					if (lastId == 0)
					{
						lastId = controller_findLastId(listaEmpleados);
						controller_setLastId("lastId.bin",&lastId);
					}
            	}
                break;

            case 2:
            	if(controller_loadFromBinary("data.bin" , listaEmpleados)==0)
            	{
            		printf("\nEl archivo no existe\n");
            	}	else	{
					lastId = controller_getLastId("lastIdBin.bin");
					if (lastId == 0)
					{
					lastId = controller_findLastId(listaEmpleados);
					controller_setLastId("lastIdBin.bin",&lastId);
					}
            	}
            	break;

            case 3:
            	if(ll_isEmpty(listaEmpleados)==1)
            	{
            		printf("\nDebe cargar la lista primero.\n");
            	}	else	{
					lastId++;
					controller_addEmployee(listaEmpleados,&lastId);
            	}
            	break;

            case 4:
            	if(ll_isEmpty(listaEmpleados)==1)
            	{
            		printf("\nDebe cargar la lista primero.\n");
            	}	else	{
                	controller_editEmployee(listaEmpleados);
            	}
            	break;

            case 5:
            	if(ll_isEmpty(listaEmpleados)==1)
            	{
            		printf("\nDebe cargar la lista primero.\n");
            	}	else	{
                	controller_removeEmployee(listaEmpleados);
            	}
            	break;

            case 6:
            	if(ll_isEmpty(listaEmpleados)==1)
            	{
            		printf("\nDebe cargar la lista primero.\n");
            	}	else	{
                	controller_ListEmployee(listaEmpleados);
            	}
            	break;

            case 7:
            	if(ll_isEmpty(listaEmpleados)==1)
            	{
            		printf("\nDebe cargar la lista primero.\n");
            	}	else	{
                	controller_sortEmployee(listaEmpleados);
            	}
            	break;

            case 8:
            	if(ll_isEmpty(listaEmpleados)==1)
            	{
            		printf("\nDebe cargar la lista primero.\n");
            	}	else	{
            		controller_saveAsText("data.csv",listaEmpleados);
            		controller_setLastId("lastId.bin",&lastId);
            	}
            	break;

            case 9:
            	if(ll_isEmpty(listaEmpleados)==1)
            	{
            		printf("\nDebe cargar la lista primero.\n");
            	}	else	{
            		controller_saveAsBinary("data.bin",listaEmpleados);
            		controller_setLastId("lastIdBin.bin",&lastId);
            	}
            	break;

        }
    }

    printf("\nFin del progama.");
    return 0;
}

