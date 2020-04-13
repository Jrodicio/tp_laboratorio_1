/*
 * navigation.c
 *
 *  Created on: 13 abr. 2020
 *      Author: julian
 */


#include <stdio.h>

void menu (long long int numeroUno, long long int numeroDos, int ingresoUno, int ingresoDos)
{
	system("clear");
	printf("=======================================\n");
	printf("              Calculadora              \n");
	printf("=======================================\n");
	printf("=======================================\n");
	printf("            Menú de opciones           \n");
	printf("=======================================\n");
	printf("\n");
	if (ingresoUno == 1)
	{
		printf("1. Ingresar 1er operando (A=%lld)\n",numeroUno);
	}
	else
	{
		printf("1. Ingresar 1er operando (A=x)\n");
	}
	if (ingresoDos == 1)
	{
		printf("2. Ingresar 2do operando (B=%lld)\n",numeroDos);
	}
	else
	{
		printf("2. Ingresar 2do operando (B=y)\n");
	}
	printf("3. Calcular todas las operaciones\n");
	printf("4. Informar resultados\n");
	printf("5. Salir\n");
	printf("=======================================\n");

}


void pause (char mensaje[])
{

	printf("%s",mensaje);
	__fpurge(stdin);
	getchar();

}
