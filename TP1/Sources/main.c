/*
 * main.c
 *
 *  Created on: 13 abr. 2020
 *      Author: julian
 */

#include <stdio.h>
#include "../Headers/maths.h"
#include "../Headers/navigation.h"
#include "../Headers/get_numbers.h"

int main()
{
	//Declaración de variables
	//Variables de entrada
	int opcion;
	long long int primerNumero = 0;
	long long int segundoNumero = 0;

	//Variables de salida
	long long int resultadoSuma;
	long long int resultadoResta;
	long long int resultadoMultiplicacion;
	double resultadoDivision;
	unsigned long long factorialUno;
	unsigned long long factorialDos;

	//Variables flag, inicializadas en 0
	int ingresadoPrimerNumero = 0;
	int ingresadoSegundoNumero = 0;
	int calculosRealizados = 0;

	//Bucle do while con switch para interactuar con menú de opciones
	do
	{
		menu(primerNumero,segundoNumero,ingresadoPrimerNumero,ingresadoSegundoNumero);
		opcion = getIntValidacion("Ingrese una opción: ","Opción inválida, vuelva a intentarlo: ",5,1);
		switch (opcion)
		{
			case 1:
				//Caso que la opción sea 1. Ingresar 1er operando. Seteamos flag de primer numero en 1 y calculos realizados en 0.
				primerNumero = getInt("Ingrese 1er operando: ");
				ingresadoPrimerNumero = 1;
				calculosRealizados = 0;
			break;
			case 2:
				//Caso que la opción sea 1. Ingresar 2do operando. Seteamos flag de segundo numero en 1 y calculos realizados en 0.
				segundoNumero = getInt("Ingrese 2do operando: ");
				ingresadoSegundoNumero = 1;
				calculosRealizados = 0;
			break;
			case 3:
				//Caso opcion 3. Realizar calculos. Verificamos con los flags que ambos numeros hayan sido ingresados, realizamos calculos y seteamos flag en 1. Sino informamos error.
				if (ingresadoPrimerNumero == 1  && ingresadoSegundoNumero == 1)
				{
					resultadoSuma = suma(primerNumero,segundoNumero);
					resultadoResta = resta(primerNumero,segundoNumero);
					resultadoMultiplicacion = multiplicacion(primerNumero,segundoNumero);
					resultadoDivision = division(primerNumero,segundoNumero);
					factorialUno = factorial(primerNumero);
					factorialDos = factorial(segundoNumero);
					calculosRealizados = 1;
				}
				else {
					printf("Debe ingresar ambos operandos para realizar los cálculos.");
				}
			break;
			case 4:

				if (calculosRealizados == 1){
					printf("\nResultados\n");
					printf("a. El resultado de (%lld)+(%lld) es: %lld\n",primerNumero,segundoNumero,resultadoSuma);
					printf("b. El resultado de (%lld)-(%lld) es: %lld\n",primerNumero,segundoNumero,resultadoResta);
					printf("c. El resultado de (%lld)*(%lld) es: %lld\n",primerNumero,segundoNumero,resultadoMultiplicacion);
					if (segundoNumero != 0)
					{
						printf("d. El resultado de (%lld)/(%lld) es: %.4f\n",primerNumero,segundoNumero,resultadoDivision);
					}
					else
					{
						printf("d. No es posible dividir por cero.\n");
					}
					if (factorialUno == 0){
						printf("e. No se puede calcular el factorial de %lld por ser negativo o mayor a 20. ",primerNumero);
					}
					else
					{
						printf("e. El factorial de %lld es: %llu. ",primerNumero,factorialUno);
					}
					if (segundoNumero < 0)
					{
						printf("No se puede calcular el factorial de %lld por ser negativo o mayor a 20.\n",segundoNumero);
					}
					else{
						printf("El factorial de %lld es: %llu\n",segundoNumero,factorialDos);
					}

				}
				else
				{
					printf("Debe calcular los resultados (Opción 3) antes de mostrarlos.\n");
				}
				pause("\nPulse <Enter> para continuar...");
			break;

			case 5:
				printf("\nAdiós!\n");
			break;
		}

	} while (opcion != 5);
	return 0;
}
