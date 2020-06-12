#include "GetValues.h"

void inputArray (char* arrayChar,int longitudMaxima, char* mensajeIngreso)
{
	__fpurge(stdin);
    printf("\n%s",mensajeIngreso);
    __fpurge(stdin);
    fgets(arrayChar,longitudMaxima-1,stdin);
    quitarSaltosArray(arrayChar);
}

void quitarSaltosArray(char* arrayChar)
{
    int i;
    for (i = 0; arrayChar[i];i++)
    {
        if (arrayChar[i] == '\n')
        {
            arrayChar[i] = '\0';
        }
    }
}

int inputInt(char* mensajeIngreso, int* number)
{
	int retorno = 0;
	if (mensajeIngreso != NULL && number != NULL)
	{
		printf("\n%s",mensajeIngreso);
		__fpurge(stdin);
		scanf("%d",number);
		retorno = 1;
	}
	return retorno;
}

int inputPositiveInt(char* mensajeIngreso, int* number)
{
	int retorno = 0;
	if (mensajeIngreso != NULL && number != NULL)
	{
		printf("\n%s",mensajeIngreso);
		__fpurge(stdin);
		scanf("%d",number);
		if(number > 0)
		{
			retorno = 1;
		}
	}
	return retorno;
}

void arrayToLower(char* arrayChar)
{
	int i;
	for(i = 0; arrayChar[i]; i++)
	{
		arrayChar[i] = tolower(arrayChar[i]);
	}
}

void upperFirstLetters(char* arrayChar)
{
    int length;
    int i;

    arrayToLower(arrayChar);
    length = strlen(arrayChar);
    arrayChar[0] = toupper(arrayChar[0]);
    for (i=0; i<length-1;i++)
    {
        if (arrayChar[i] == ' ')
        {
            arrayChar[i+1]=toupper(arrayChar[i+1]);
        }
    }
}

void pausa(char* mensaje)
{
	printf("\n\n%sPulse <Enter> para continuar...\n",mensaje);
	__fpurge(stdin);
	getchar();
}

int msjConfirm(char* mensaje)
{
	int retorno = 0;
	char respuesta;

	do{
		printf("\n%s (S/n)",mensaje);
		__fpurge(stdin);
		scanf("%c",&respuesta);

	}while (respuesta != 'S' && respuesta != 's' && respuesta != 'N' && respuesta != 'n');

	if (respuesta == 'S' || respuesta == 's')
	{
		retorno = 1;
	}

	return retorno;
}
