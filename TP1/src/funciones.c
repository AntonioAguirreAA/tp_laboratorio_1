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

	printf("\n1. Ingresar 1er operando (A=x)\n");
	printf("2. Ingresar 2do operando (B=y)\n");
	printf("3. Calcular todas las operaciones\n"
			"	a) Calcular la suma (A+B)\n"
			"	b) Calcular la resta (A-B)\n"
			"	c) Calcular la division (A/B)\n"
			"	d) Calcular la multiplicacion (A*B)\n"
			"	e) Calcular el factorial (A!)\n");
	printf("4. Informar resultados\n"
			"	a) “Resultado de A+B”\n"
			"	b) “Resultado de A-B”\n"
			"	c) “Resultado de A/B“\n"
			"	d) “Resultado de A*B\n"
			"	e) “Factorial de A y B\n");
	printf("5. Salir\n");
	respuestaMenu = getInt("Ingrese una opción: ");
	while (respuestaMenu < 1 || respuestaMenu > 5)
	{
		respuestaMenu = getInt("Ingrese una opción válida: ");
	}

	return respuestaMenu;
}

/**
 * @fn int getInt(char[])
 * @brief Obtiene un int sin límites
 *
 * @param mensaje
 * @return int ingresado por el usuario
 */
int getInt(char mensaje[])
{
	int respuesta;

	printf(mensaje);
	scanf("%d",&respuesta);

	return respuesta;
}

/**
 * @fn void SumaOperandos(int, int)
 * @brief Opcion que suma los operandos
 *
 * @param numeroA
 * @param numeroB
 */
int SumaOperandos(int numeroA, int numeroB)
{
	int resultado;

	resultado = numeroA + numeroB;

	return resultado;
}

/**
 * @fn void RestaOperandos(int, int)
 * @brief Opcion que resta los operandos A - B
 *
 * @param numeroA
 * @param numeroB
 */
int RestaOperandos(int numeroA , int numeroB)
{
	int resultado;

	resultado = numeroA - numeroB;

	return resultado;
}

/**
 * @fn void DivisionOperandos(int, int)
 * @brief Opcion que divide los operandos A/B
 *
 * @param numeroA
 * @param numeroB
 */
float DivisionOperandos(int numeroA , int numeroB)
{
	float resultado;

	resultado = (numeroA + 0.0) / numeroB;

	return resultado;
}

/**
 * @fn void MultiplicacionOperandos(int, int)
 * @brief Opcion que multiplica los operandos
 *
 * @param numeroA
 * @param numeroB
 */
int MultiplicacionOperandos(int numeroA , int numeroB)
{
	int resultado;

	resultado = numeroA * numeroB;

	return resultado;
}

/**
 * @fn void FactorialOperandos(int, int)
 * @brief Opcion que muestra el factorial de los dos operandos
 *
 * @param numeroA
 * @param numeroB
 */
long int FactorialOperandos(int numero)
{
	int i;
	long int resultado = 1;

	if (numero <= 0)
	{

		resultado = -1;

	}	else	{

		if(numero == 0)
		{
			resultado = 0;
		}	else	{
			for(i=1 ; i<=numero ; i++)
			{
				resultado = resultado * i;
			}
		}

	}

	return resultado;
}

void imprimirResultados(int suma,int resta,float division,int multiplicacion,long int factorialA,long int factorialB)
{
	printf("\nEl resultado de A+B es: %d\n",suma);
	printf("El resultado de A-B es: %d\n",resta);
	printf("El resultado de A/B es: %.2f\n",division);
	printf("El resultado de A*B es: %d\n",multiplicacion);
	if(factorialA == -1)
	{
		printf("No se puede obtener el factorial de A porque A = 0\n");
	}	else	{
		printf("El factorial de A es: %ld\n",factorialA);
	}
	if(factorialB == -1)
	{
		printf("No se puede obtener el factorial de B porque B = 0\n");
	}	else	{
		printf("El factorial de B es: %ld\n",factorialB);
	}
}

void imprimirResultadosSinDivision(int suma,int resta,int multiplicacion,long int factorialA,long int factorialB)
{
	printf("\nEl resultado de A+B es: %d\n",suma);
	printf("El resultado de A-B es: %d\n",resta);
	printf("No se puede dividir porque el operando B es igual a 0\n");
	printf("El resultado de A*B es: %d\n",multiplicacion);
	if(factorialA == -1)
	{
		printf("No se puede obtener el factorial de A porque A = 0\n");
	}	else	{
		printf("El factorial de A es: %ld\n",factorialA);
	}
	if(factorialB == -1)
	{
		printf("No se puede obtener el factorial de B porque B = 0\n");
	}	else	{
		printf("El factorial de B es: %ld\n",factorialB);
	}
}
