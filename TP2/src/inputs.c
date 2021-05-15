/*
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getInt(char mensaje[])
{
	int aux;
	printf("%s", mensaje);
	scanf("%d", &aux);
	return aux;
}

float getFloat(char mensaje[])
{
	float aux;
	printf("%s", mensaje);
	scanf("%f", &aux);
	return aux;
}

void getString(char mensaje[], char cadena[])
{
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%s", cadena);
}
