#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void) {
	setbuf(stdout,NULL);

	int opcion;
	int nro1=0;
	int nro2=0;
	int rSumar;
	int rRestar;
	int rMultiplicar;
	float rDividir;
	int rFactorialNro1;
	int rFactorialNro2;
	int flagA;
	int flagBB;
	int flagC;
	flagA = 0;
	flagBB = 0;
	flagC = 0;

	do
	{
	menu(nro1, nro2,&opcion);
		{
			switch (opcion)
			{
			case 1:
				printf("Ingrese el valor del 1er operando \n");
				scanf("%d",&nro1);
				flagA=1;
				break;
			case 2:
				if (flagA == 1)
				{
					printf("Ingrese el valor del 2do operando\n");
					scanf("%d",&nro2);
					flagBB = 1;
				}
					else
					{
					printf("Error, primero debe ingresar el 1er operando \n");
					}
				break;
			case 3:
				if( flagA == 1 && flagBB ==1){
				printf("...Calculando todas las operaciones\n\n");
				rSumar = sumar(nro1,nro2);
				rRestar = restar(nro1,nro2);
				rMultiplicar = multiplicar(nro1,nro2);

				if(nro2 != 0)
				{
					rDividir = dividir(nro1,nro2);
				}
				rFactorialNro1 = factorial (nro1);
				rFactorialNro2 = factorial (nro2);

				flagC = 1;
				}
				else
				{
					printf("Error, debe tener ingresado el  primer operando y el segundo operando\n");
				}
				break;
			case 4:
				if( flagA == 1 && flagBB == 1 && flagC == 1){
				printf("\n\nLa suma de %d + %d es: %d",nro1,nro2,rSumar);
				printf("\nLa resta de %d - %d es: %d",nro1,nro2,rRestar);
				printf("\nLa multiplicacion de %d * %d es: %d",nro1,nro2,rMultiplicar);
				if (nro2 == 0)
				{
					printf("\nNo puede dividirse por cero\n");
				}
				else
				{
					printf("\nLa division de %d / %d es: %.2f\n",nro1,nro2,rDividir);
				}

				rtdoFactorial(nro1,rFactorialNro1);
				rtdoFactorial(nro2,rFactorialNro2);
				}
				else
				{
					printf("Error, no hay nada para mostrar \n");
				}
				break;

			}
		}


	}while(opcion!=5);
	return EXIT_SUCCESS;
}
