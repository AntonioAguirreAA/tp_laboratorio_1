/*
 * funciones.h
 *
 *
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

int MostrarMenu();

int getInt(char []);

int SumaOperandos(int,int);
int RestaOperandos(int,int);
float DivisionOperandos(int,int);
int MultiplicacionOperandos(int,int);
long int FactorialOperandos(int);

void imprimirResultados(int,int,float,int,long int,long int);

void imprimirResultadosSinDivision(int,int,int,long int,long int);

#endif /* FUNCIONES_H_ */
