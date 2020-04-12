#include <stdio.h>
#include "maths.h"
#include "navigation.h"
#include "get_numbers.h"

int main()
{
	int opcion;
	int numeroUno;
	int numeroDos;

	int resultadoSuma;
	int resultadoResta;
	int resultadoMultiplicacion;
	float resultadoDivision;
	unsigned long long factorialUno;
	unsigned long long factorialDos;

	int ingresadoUno = 0;
	int ingresadoDos = 0;
	int calculosRealizados = 0;

	do
	{
		menu(numeroUno,numeroDos,ingresadoUno,ingresadoDos);
		opcion = getIntValidacion("Ingrese una opción: ","Opción inválida, vuelva a intentarlo: ",5,1);
		switch (opcion){
			case 1:
				numeroUno = getInt("Ingrese 1er operando: ");
				ingresadoUno = 1;
				calculosRealizados = 0;
			break;
			case 2:
				numeroDos = getInt("Ingrese 2do operando: ");
				ingresadoDos = 1;
				calculosRealizados = 0;
			break;
			case 3:
				if (ingresadoUno == 1  && ingresadoDos == 1)
				{
					resultadoSuma = suma(numeroUno,numeroDos);
					resultadoResta = resta(numeroUno,numeroDos);
					resultadoMultiplicacion = multiplicacion(numeroUno,numeroDos);
					resultadoDivision = division(numeroUno,numeroDos);
					factorialUno = factorial(numeroUno);
					factorialDos = factorial(numeroDos);
					calculosRealizados = 1;
				}
				else {
					printf("Debe ingresar ambos operandos para realizar los cálculos.");
				}
			break;
			case 4:
				if (calculosRealizados == 1){
					printf("\nResultados\n");
					printf("a. El resultado de %d+%d es: %d\n",numeroUno,numeroDos,resultadoSuma);
					printf("b. El resultado de %d-%d es: %d\n",numeroUno,numeroDos,resultadoResta);
					printf("c. El resultado de %d*%d es: %d\n",numeroUno,numeroDos,resultadoMultiplicacion);
					if (numeroDos != 0)
					{
						printf("d. El resultado de %d/%d es: %.2f\n",numeroUno,numeroDos,resultadoDivision);
					}
					else
					{
						printf("d. No es posible dividir por cero.\n");
					}
					if (numeroUno < 0){
						printf("e. No se puede calcular el factorial de %d por ser negativo. ",numeroUno);
					}
					else
					{
						printf("e. El factorial de %d es: %llu. ",numeroUno,factorialUno);
					}
					if (numeroDos < 0)
					{
						printf("No se puede calcular el factorial de %d por ser negativo.\n",numeroDos);
					}
					else{
						printf("El factorial de %d es: %llu\n",numeroDos,factorialDos);
					}

				}
				else
				{
					printf("Debe calcular los resultados antes de mostrarlos.\n");
				}
				pause("Pulse <Enter> para continuar...");
			break;

			case 5:
				printf("\nAdiós!\n");
			break;
		}

	} while (opcion != 5);
	return 0;
}
