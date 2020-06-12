/*
 * Validations.c
 *
 *  Created on: 6 jun. 2020
 *      Author: julian
 */

#include "Validations.h"


int stringIsAlpha(char* string)
{
	char c;
	int retorno = 0;
	char* specialChars = "ñÑáéíóúÁÉÍÓÚ";

	if (strlen(string))
	{
		while ((c = *string) && ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || charInString(c,specialChars) || c == ' '))
		{
			string++;
		}
		retorno = (*string == '\0');
	}
	return retorno;
}

int charInString(char character, char* string)
{
	int i;
	char cString;
	int lenString = strlen(string);
	int retorno = 0;

	for(i=0;i<lenString;i++)
	{
		cString = string[i];
		if(character == cString)
		{
			retorno = 1;
			break;
		}
	}
	return retorno;
}

int intRange(int number, int min, int max)
{
	int retorno = 0;
	if (number >= min && number <= max)
	{
		retorno = 1;
	}
	return retorno;
}


