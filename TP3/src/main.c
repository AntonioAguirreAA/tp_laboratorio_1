#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
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
            	controller_loadFromText("C:\\Users\\Tony\\eclipse-workspace\\TP3\\data.csv" , listaEmpleados);//INGRESAR RUTA CORRESPONDIENTE
            	lastId = controller_getLastId("C:\\Users\\Tony\\eclipse-workspace\\TP3\\lastId.bin");//INGRESAR RUTA CORRESPONDIENTE
            	if (lastId == 0)
            	{
            		lastId = controller_findLastId(listaEmpleados);
            		controller_setLastId("lastId.bin",&lastId);
            	}
                break;

            case 2:
            	lastId = controller_getLastId("C:\\Users\\Tony\\eclipse-workspace\\TP3\\lastIdBin.bin"); //INGRESAR RUTA CORRESPONDIENTE
            	if (lastId == 0)
            	{
            	lastId = controller_findLastId(listaEmpleados);
				controller_setLastId("lastIdBin.bin",&lastId);
            	}
            	controller_loadFromBinary("C:\\Users\\Tony\\eclipse-workspace\\TP3\\data.bin" , listaEmpleados);//INGRESAR RUTA CORRESPONDIENTE
            	break;

            case 3:
            	lastId++;
            	controller_addEmployee(listaEmpleados,&lastId);
            	break;

            case 4:
            	controller_editEmployee(listaEmpleados);
            	break;

            case 5:
            	controller_removeEmployee(listaEmpleados);
            	break;

            case 6:
            	controller_ListEmployee(listaEmpleados);
            	break;

            case 7:
            	controller_sortEmployee(listaEmpleados);
            	break;

            case 8:
            	controller_saveAsText("data.csv",listaEmpleados);
        		controller_setLastId("lastId.bin",&lastId);
            	break;

            case 9:
            	controller_saveAsBinary("data.bin",listaEmpleados);
				controller_setLastId("lastIdBin.bin",&lastId);
            	break;

        }
    }

    printf("\nFin del progama.");
    return 0;
}

