#include <stdio.h>


float suma (float numeroUno, float numeroDos)
{
	float resultado;
	resultado = numeroUno+numeroDos;
	return resultado;
}

float resta (float numeroUno, float numeroDos)
{
	float resultado;
	resultado = numeroUno-numeroDos;
	return resultado;
}

float multiplicacion (float numeroUno, float numeroDos)
{
	float resultado;
	resultado = numeroUno*numeroDos;
	return resultado;
}

float division (float numeroUno, float numeroDos)
{
	float resultado;
	resultado = numeroUno/numeroDos;
	return resultado;
}

long factorial(int numero)
{
    int i;
    long resultado;
    resultado = 1;
    for (i=numero; i > 0; i--)
    {
        resultado*=i;
    }
    return resultado;
}
