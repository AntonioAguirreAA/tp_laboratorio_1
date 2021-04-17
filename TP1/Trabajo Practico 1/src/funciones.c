/*
 * funciones.c
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/**
 * @fn int MostrarMenu(int)
 * @brief Muestra el menú y retorna la elección del usuario
 *
 * @return respuestaMenu
 */
int MostrarMenu()
{
	int respuestaMenu;

	printf("\n1) Suma [A+B]\n");
	printf("2) Resta [A-B]\n");
	printf("3) Division [A/B]\n");
	printf("4) Multiplicacion [A*B]\n");
	printf("5) Factorial [A!] [B!]\n");
	printf("6) Salir\n");
	scanf("%d",&respuestaMenu);
	while (respuestaMenu < 1 || respuestaMenu > 6)
	{
		printf("Ingrese una opción válida: ");
		scanf("%d",&respuestaMenu);
	}

	return respuestaMenu;
}

/**
 * @fn void SumaOperandos(int, int)
 * @brief Opcion que suma los operandos
 *
 * @param numeroA
 * @param numeroB
 */
void SumaOperandos(int numeroA, int numeroB)
{
	int resultado;

	resultado = numeroA + numeroB;

	printf("\nEl resultado de la suma es: %d\n", resultado);
}

/**
 * @fn void RestaOperandos(int, int)
 * @brief Opcion que resta los operandos A - B
 *
 * @param numeroA
 * @param numeroB
 */
void RestaOperandos(int numeroA , int numeroB)
{
	int resultado;

	resultado = numeroA - numeroB;

	printf("\nEl resultado de la resta es: %d\n", resultado);
}

/**
 * @fn void DivisionOperandos(int, int)
 * @brief Opcion que divide los operandos A/B
 *
 * @param numeroA
 * @param numeroB
 */
void DivisionOperandos(int numeroA , int numeroB)
{
	float resultado;

	if (numeroB == 0)
	{

		printf("\nNo se puede dividir por 0.\n");

	}	else	{

		resultado = (numeroA + 0.0) / numeroB;

		printf("\nEl resultado de la division es: %f\n", resultado);

	}
}

/**
 * @fn void MultiplicacionOperandos(int, int)
 * @brief Opcion que multiplica los operandos
 *
 * @param numeroA
 * @param numeroB
 */
void MultiplicacionOperandos(int numeroA , int numeroB)
{
	int resultado;

	resultado = numeroA * numeroB;

	printf("\nEl resultado de la multiplicacion es: %d\n", resultado);
}

/**
 * @fn void FactorialOperandos(int, int)
 * @brief Opcion que muestra el factorial de los dos operandos
 *
 * @param numeroA
 * @param numeroB
 */
void FactorialOperandos(int numeroA , int numeroB)
{
	int i;
	long resultado;

	resultado = 1;

	//Factorial del operandoA
	if (numeroA < 0)
	{
		printf("\nEl operando A es negativo, no se puede sacar el factorial de un número negativo.\n");

	}	else	{

		for(i=1 ; i<=numeroA ; i++)
			{
				resultado = resultado * i;
			}

		printf("\nFactorial del operando A[%d]: %ld\n", numeroA , resultado);
	}

	resultado = 1;

	//Factorial del operandoB
	if (numeroB < 0)
		{
			printf("\nEl operando B es negativo, no se puede sacar el factorial de un número negativo.\n");

		}	else	{

			for(i=1 ; i<=numeroB ; i++)
				{
					resultado = resultado * i;
				}

			printf("\nFactorial del operando B[%d]: %ld\n", numeroB , resultado);
		}
}
