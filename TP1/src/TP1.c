/*
 *Programa: Trabajo Practico N° 1
 *
 *Objetivo:
 	 Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
		1. Ingresar 1er operando (A=x)
		2. Ingresar 2do operando (B=y)
		3. Calcular todas las operaciones
			a) Calcular la suma (A+B)
			b) Calcular la resta (A-B)
			c) Calcular la division (A/B)
			d) Calcular la multiplicacion (A*B)
			e) Calcular el factorial (A!)
		4. Informar resultados
			a) “El resultado de A+B es: r”
			b) “El resultado de A-B es: r”
			c) “El resultado de A/B es: r” o “No es posible dividir por cero”
			d) “El resultado de A*B es: r”
			e) “El factorial de A es: r1 y El factorial de B es: r2”
		5. Salir
 *
 *Version: 0.1
 *
 *Autor: Antonio Aguirre
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

/**
 * @fn int main(void)
 * @brief Funcion principal, aquí se ingresarán los operandos y se
 * usara un while y un case para las opciones del menú.
 *
 * @param numeroA
 * @param numeroB
 * @param respuestaMenu
 * @return EXIT_SUCCESS
 */
int main(void) {

	setbuf(stdout, NULL);
	int respuestaMenu;
	//Operandos
	int numeroA;
	int numeroB;
	int numeroAingresado = -1;
	int numeroBingresado = -1;
	//Resultados
	int operacionesRealizadas = -1;
	int suma;
	int resta;
	float division;
	int multiplicacion;
	long int factorialA;
	long int factorialB;

	respuestaMenu = 0;

	//Menú de opciones
	while (respuestaMenu != 5)
	{
		respuestaMenu = MostrarMenu();

		switch (respuestaMenu)
		{
			case 1:
				numeroA = getInt("Ingrese el operando A:");
				numeroAingresado = 0;
				operacionesRealizadas = -1;
				break;

			case 2:
				numeroB = getInt("Ingrese el operando B:");
				numeroBingresado = 0;
				operacionesRealizadas = -1;
				break;

			case 3:
				if(numeroAingresado == 0 && numeroBingresado == 0)
				{
					suma = SumaOperandos(numeroA , numeroB);
					resta = RestaOperandos(numeroA , numeroB);
					if(numeroB != 0)
					{
						division = DivisionOperandos(numeroA , numeroB);
					}
					multiplicacion = MultiplicacionOperandos(numeroA , numeroB);
					factorialA = FactorialOperandos(numeroA);
					factorialB = FactorialOperandos(numeroB);
					operacionesRealizadas = 0;
					printf("\nCalculos realizados.\n");
				}	else	{
					printf("\nDebe ingresar los operandos primero.\n");
				}
				break;

			case 4:
				if(operacionesRealizadas==-1)
				{
					printf("Debe realizar las operaciones primero.\n");
				}	else	{
					if(numeroB==0)
					{
						imprimirResultadosSinDivision(suma,resta,multiplicacion,factorialA,factorialB);
					}	else	{
						imprimirResultados(suma,resta,division,multiplicacion,factorialA,factorialB);
					}
				}
				break;
		}
	}

	puts("Fin del programa.");
	return EXIT_SUCCESS;
}


