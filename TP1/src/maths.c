#include <stdio.h>


long long int suma (long long int numeroUno, long long int numeroDos)
{
	long long int resultado;
	resultado = numeroUno+numeroDos;
	return resultado;
}

long long int resta (long long int numeroUno, long long int numeroDos)
{
	long long int resultado;
	resultado = numeroUno-numeroDos;
	return resultado;
}

long long int multiplicacion (long long int numeroUno, long long int numeroDos)
{
	long long int resultado;
	resultado = numeroUno*numeroDos;
	return resultado;
}

double division (double numeroUno, double numeroDos)
{
	double resultado = 0;
	if (numeroDos != 0)
	{
		resultado = numeroUno/numeroDos;
	}
	return resultado;

}

unsigned long long factorial(long long int numero)
{
    int i;
    unsigned long long resultado;
    resultado = 1;
    if (numero >= 0 && numero <= 20){
    	for (i=numero; i > 0; i--)
    	{
    		resultado*=i;
    	}
    }
    else
    {
    	resultado = 0;
    }

    return resultado;
}
