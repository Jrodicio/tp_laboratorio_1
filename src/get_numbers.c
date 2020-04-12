#include <stdio.h>

int getIntValidacion(char mensajeIngreso[], char errorIngreso[], int maximo, int minimo)
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

int getInt(char mensajeIngreso[])
{
	int numero;

	printf("\n%s",mensajeIngreso);
	scanf("%d",&numero);

	return numero;
}
