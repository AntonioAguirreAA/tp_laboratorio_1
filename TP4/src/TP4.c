#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "input.h"
#include "Controller.h"
#include "Employee.h"
#include "functions.h"

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
     8. Clonar la lista, mostrarla y eliminarla (PRUEBA TP 4)
     9. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     10. Guardar los datos de los empleados en el archivo data.csv (modo binario).
     11. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
    int option = 0;

    int lastId;

    int exito;
    int listaVacia;

	LinkedList* listaEmpleados = ll_newLinkedList();


	/*---------------------------MENU---------------------------*/
    while(option != 11)
    {
    	listaVacia = ll_isEmpty(listaEmpleados);
    	option = ShowMenu();
        switch(option)
        {
            case 1:
            	exito = controller_loadFromText("C:\\Users\\Tony\\eclipse-workspace\\TP4\\data.csv" , listaEmpleados);//INGRESAR RUTA CORRESPONDIENTE
            	if(exito==1)
            	{
					lastId = controller_getLastId("C:\\Users\\Tony\\eclipse-workspace\\TP4\\lastId.bin");//INGRESAR RUTA CORRESPONDIENTE
					if (lastId == 0)
					{
						lastId = controller_findLastId(listaEmpleados);
						controller_setLastId("lastId.bin",&lastId);
					}
            	}	else	{
            		printf("\nNo existe el archivo.\n");
            	}
                break;

            case 2:
            	exito = controller_loadFromBinary("C:\\Users\\Tony\\eclipse-workspace\\TP4\\data.bin" , listaEmpleados);//INGRESAR RUTA CORRESPONDIENTE
            	if(exito==1)
            	{
					lastId = controller_getLastId("C:\\Users\\Tony\\eclipse-workspace\\TP4\\lastIdBin.bin"); //INGRESAR RUTA CORRESPONDIENTE
					if (lastId == 0)
					{
					lastId = controller_findLastId(listaEmpleados);
					controller_setLastId("lastIdBin.bin",&lastId);
					}
            	}	else	{
            		printf("\nNo existe el archivo.\n");
            	}
            	break;

            case 3:
            	lastId++;
            	controller_addEmployee(listaEmpleados,&lastId);
            	break;

            case 4:
            	if(listaVacia==0)
            	{
            		controller_editEmployee(listaEmpleados);
            	}	else	{
            		printf("Debe cargar una lista primero");
            	}
            	break;

            case 5:
            	if(listaVacia==0)
            	{
                	controller_removeEmployee(listaEmpleados);
            	}	else	{
            		printf("Debe cargar una lista primero");
            	}
            	break;

            case 6:
            	if(listaVacia==0)
            	{
                	controller_ListEmployee(listaEmpleados);
            	}	else	{
            		printf("Debe cargar una lista primero");
            	}
            	break;

            case 7:
            	if(listaVacia==0)
            	{
                	controller_sortEmployee(listaEmpleados);
            	}	else	{
            		printf("Debe cargar una lista primero");
            	}
            	break;

            case 8:
            	if(listaVacia==0)
            	{
            		controller_testTP(listaEmpleados);
            	}	else	{
            		printf("Debe cargar una lista primero");
            	}
            	break;

            case 9:
            	if(listaVacia==0)
            	{
            		controller_saveAsText("data.csv",listaEmpleados);
            		controller_setLastId("lastId.bin",&lastId);
            	}	else	{
            		printf("Debe cargar una lista primero");
            	}
            	break;

            case 19:
            	if(listaVacia==0)
            	{
            		controller_saveAsBinary("data.bin",listaEmpleados);
            		controller_setLastId("lastIdBin.bin",&lastId);
            	}	else	{
            		printf("Debe cargar una lista primero");
            	}
            	break;

        }
    }

    printf("\nFin del progama.");
    return 0;
}

