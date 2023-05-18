#include<stdio.h>

typedef struct 
{
	int month[23];
	float gwh[23];
	char nombre[30];
} energia;


float mediaInd(int numfuente, energia vector_fuente[]); //int tam?);
float maximo(int numfuente, energia vector_fuente[]);
float minimo(int numfuente, energia vector_fuente[]);
float total(int numfuente, energia vector_fuente[]);

int main()
{
	
	return 0;
}


//numfuente es la posicion que cada fuente ocupa en el vector de estructuras, si numfuente es 2, calculas la media de la fuente 3
//funcion de la media de una fuente (media individual)
float mediaInd(int numfuente, energia vector_fuente[])
{
	int i;
	float suma, media;
	for(i=0; i<24; i++)
	{
		suma = suma + vector_fuente[numfuente].gwh[i];
	}
	media = suma/24;
	return media;
}

float maximo(int numfuente, energia vector_fuente[])
{
	int i;
	float max=0;
	for(i=0; i<24; i++)
	{
		if(vector_fuente[numfuente].gwh[i] > max)
		{
			max = vector_fuente[numfuente].gwh[i];
		}
	}
	return max;
}

float minimo(int numfuente, energia vector_fuente[])
{
	int i;
	float min=vector_fuente[numfuente].gwh[0];
	for(i=0; i<24; i++)
	{
		if(vector_fuente[numfuente].gwh[i] < min)
		{
			min = vector_fuente[numfuente].gwh[i];
		}
	}
	return min;
}

float total(int numfuente, energia vector_fuente[])
{
	int i;
	float suma=0;
	for(i=0; i<24; i++)
	{
		suma = suma + vector_fuente[numfuente].gwh[i];
	}
	return suma;
}



