/*
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"

/**
 * @fn int validarNumero(char[])
 * @brief Valida que la cadena contenga solo numeros
 *
 * @param checkInt
 * @return 0: si tiene solo numeros
 * 			-1: si tiene al menos un caracter
 */
int validarNumero(char checkInt[])
{
	int exito = 0;
	int len;

	len = strlen(checkInt);

	for(int i=0 ; i<len ; i++)
	{
		if(!isdigit(checkInt[i]))
		{
			exito = -1;
			break;
		}
	}

	return exito;
}

/**
 * @fn int validarCaracteres(char[])
 * @brief Valida que la cadena contenga solo letras
 *
 * @param checkInt
 * @return 0: si solo tiene letras
 * 			1: si tiene al menos un numero
 */
int validarCaracteres(char checkInt[])
{
	int exito = 0;
	int len;

	len = strlen(checkInt);

	for(int i=0 ; i<len ; i++)
	{
		if(isdigit(checkInt[i]))
		{
			exito = -1;
			break;
		}
	}

	return exito;
}

int getInt(char mensaje[])
{
	int aux;
	char checkInt[151];
	int esNumero;

	printf("%s", mensaje);
	scanf("%s",checkInt);

	esNumero=validarNumero(checkInt);

	while(esNumero==-1)
	{
		printf("Ingrese un numero válido: ");
		scanf("%s",checkInt);

		esNumero=validarNumero(checkInt);
	}
	aux = atoi(checkInt);

	return aux;
}

float getFloat(char mensaje[])
{
	float aux;
	char checkInt[151];
	int esNumero;

	printf("%s", mensaje);
	scanf("%s",checkInt);

	esNumero=validarNumero(checkInt);

	while(esNumero==-1)
	{
		printf("Ingrese un numero válido: ");
		scanf("%s",checkInt);

		esNumero=validarNumero(checkInt);
	}
	aux = atof(checkInt);

	return aux;
}

void getString(char mensaje[], char cadena[])
{
	int esCaracter;

	printf("%s", mensaje);
	scanf("%s",cadena);

	esCaracter=validarCaracteres(cadena);

	while(esCaracter==-1)
	{
		printf("Ingrese una cadena sin numeros: ");
		scanf("%s",cadena);

		esCaracter=validarCaracteres(cadena);
	}
}
