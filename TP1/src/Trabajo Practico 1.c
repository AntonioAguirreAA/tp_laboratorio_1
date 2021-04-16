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
#include "funciones.h"

#define SUMA 1
#define RESTA 2
#define DIVISION 3
#define MULTIPLICACION 4
#define FACTORIAL 5

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
	int numeroA;
	int numeroB;
	int respuestaMenu;

	respuestaMenu = 0;

	//Ingreso de operandos
	printf("Ingrese el operando A: ");
	scanf("%d", &numeroA);

	printf("Ingrese el operando B: ");
	scanf("%d", &numeroB);

	//Menú de opciones
	while (respuestaMenu != 6)
	{
		respuestaMenu = MostrarMenu();

		switch (respuestaMenu)
		{
			case SUMA:
				SumaOperandos(numeroA , numeroB);
				break;

			case RESTA:
				RestaOperandos(numeroA , numeroB);
				break;

			case DIVISION:
				DivisionOperandos(numeroA , numeroB);
				break;

			case MULTIPLICACION:
				MultiplicacionOperandos(numeroA , numeroB);
				break;

			case FACTORIAL:
				FactorialOperandos(numeroA , numeroB);
				break;
		}
	}

	puts("Fin del programa.");
	return EXIT_SUCCESS;
}


