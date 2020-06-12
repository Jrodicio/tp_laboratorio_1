#include "Menu.h"


void mostrarMenu(char* menu[128])
{
	int i;
	for (i=0;menu[i];i++)
	{
		printf("\n%d. %s",i+1,menu[i]);
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
