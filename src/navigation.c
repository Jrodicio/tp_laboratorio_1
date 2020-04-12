#include <stdio.h>

void menu (int numeroUno, int numeroDos, int ingresoUno, int ingresoDos)
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
		printf("1. Ingresar 1er operando (A=%d)\n",numeroUno);
	}
	else
	{
		printf("1. Ingresar 1er operando (A=x)\n");
	}
	if (ingresoDos == 1)
	{
		printf("2. Ingresar 2do operando (B=%d)\n",numeroDos);
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
