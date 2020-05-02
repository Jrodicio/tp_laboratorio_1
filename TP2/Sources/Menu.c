#include <stdio.h>
#include "../Headers/Menu.h"
#include "../Headers/GetValues.h"

void printMenu(eMenu menu)
{
	int i;

	printf("%s\n",menu.titulo);

	for (i=0;i<menu.length;i++)
	{
		printf("\n%d. %s",i+1,menu.opcion[i]);
	}
	printf("\n");
}

void pausa (char mensaje[])
{

	printf("\n%s",mensaje);
	__fpurge(stdin); //Se realiza fpurge para limpiar el buffer y evitar saltar la pausa automaticamente por contenido basura.
	getchar();
}

int menuOptionGet()
{
	return 0;
}
