/*
 * functions.h
 *
 *  Created on: 25 jun. 2021
 *      Author: Tony
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

int MostrarMenu();

int getInt(char []);

int SumaOperandos(int,int);
int RestaOperandos(int,int);
float DivisionOperandos(int,int);
int MultiplicacionOperandos(int,int);
long int FactorialOperandos(int);

void imprimirResultados(int,int,float,int,long int,long int);

void imprimirResultadosSinDivision(int,int,int,long int,long int);

#endif /* FUNCTIONS_H_ */
