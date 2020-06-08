#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{

	int opcionIngresada = 1;
    int i;
    int cantEmployee;
    Employee* auxEmployee;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
        switch(opcionIngresada)
        {
            case 1:
            	cantEmployee = controller_loadFromText("/data.csv",listaEmpleados);

                for(i=0; i<cantEmployee; i++)
				{
                	auxEmployee = (Employee*) ll_get(listaEmpleados, i);
                	printf("%5d | %10s | %5d | %7d\n", auxEmployee->id, auxEmployee->nombre, auxEmployee->horasTrabajadas, auxEmployee->sueldo);
				}
                break;
        }

        opcionIngresada = 10;

    }while(opcionIngresada != 10);
    return 0;
}
