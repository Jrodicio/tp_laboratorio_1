#include <stdio.h>
#include "calc.h"


void menu (char numeroUno[], char numeroDos[]);
int getInt(char mensajeIngreso[], char errorIngreso[], int maximo, int minimo);

int main()
{
	int opcion;
	int numeroUno;
	int numeroDos;

	do
	{

		menu("x","y");
		opcion = getInt("Ingrese una opción: ","Opción inválida, vuelva a intentarlo: ",5,1);
	}while (opcion != 5);

	printf("\nAdiós!\n");
	return 0;
}

void menu (char numeroUno[], char numeroDos[])
{

	system("clear");
	printf("=======================================\n");
	printf("              Calculadora              \n");
	printf("=======================================\n");
	printf("=======================================\n");
	printf("            Menú de opciones           \n");
	printf("=======================================\n");
	printf("\n");
	printf("1. Ingresar 1er operando (A=%s)\n",numeroUno);
	printf("2. Ingresar 2do operando (B=%s)\n",numeroDos);
	printf("3. Calcular todas las operaciones\n");
	printf("4. Informar resultados\n");
	printf("5. Salir\n");
	printf("=======================================\n");

}
int getInt(char mensajeIngreso[], char errorIngreso[], int maximo, int minimo)
{
	int numero;

	printf("\n%s",mensajeIngreso);
	scanf("%d",&numero);

	while (numero < minimo || numero > maximo)
	{
		printf("\n%s",errorIngreso);
		scanf("%d",&numero);
	}

	return numero;
}
