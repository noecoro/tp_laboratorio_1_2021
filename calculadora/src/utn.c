#include <stdio.h>
#include <stdlib.h>

int menu(int a, int b, int* rtdo)
{
	printf("\n======CALCULADORA======\n");
	printf("===Menu===\n");
	printf("1. Ingresar 1er operando (A=%d)\n",a);
	printf("2. Ingresar 2do operando (B=%d)\n",b);
	printf("3. Calcular todas las operaciones\n");
	printf("4. Informar resultados\n");
	printf("5. Salir\n");
	scanf("%d",&(*rtdo));
	return 0;
}

int sumar(int a, int b)
{
	int rtdo;
	rtdo = a + b;
	return rtdo;
}

int restar(int a, int b)
{
	int rtdo;
	rtdo = a - b;
	return rtdo;
}

int multiplicar(int a, int b)
{
	int rtdo;
	rtdo = a * b;
	return rtdo;
}

float dividir(int a, int b)
{
	float rtdo;
	rtdo = (float)a / b;
	return rtdo;
}
int factorial(int a)
{
	int rtdo=1;
	if(a <0)
	{
		rtdo =0;
	}
	else if (a > 12)
	{
		rtdo = -1;
	}
	else
	{
		while(a >= 1)
		{

		rtdo *= a;
		a --;
	}
	}
	return rtdo;
}

void rtdoFactorial(int a, int factorial )
{
	switch (factorial)
	{
	case 0:
		printf("No es posible realizar el factorial de %d por ser negativo\n",a);
	break;
	case -1:
		printf("No es posible mostrar el factorial de %d por la longitud que tiene. Solo si es menor a 13\n",a);
	break;
	default:
		printf("El factorial de %d es: %d\n",a, factorial);

	}
}




