#include <stdio.h>
#include "Menu.h"
#include "GetValues.h"

void mostrarMenu(char* menu[128])
{
	int i;
	for (i=0;menu[i];i++)
	{
		printf("%d. %s\n",i+1,menu[i]);
	}
	printf("\n");
}

int inputMenuOption (char* menu[128])
{
	int opcionIngresada = 0;
	mostrarMenu(menu);
	inputInt("Ingrese opción deseada: ",&opcionIngresada);
	return opcionIngresada;
}
