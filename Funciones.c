#include<stdio.h>

typedef struct 
{
	float gwh[23];
	char nombre[30];
} energia;

float mediaInd(int numfuente, energia vector_fuente[], int x); 
float maximo(int numfuente, energia vector_fuente[], int x);
float minimo(int numfuente, energia vector_fuente[], int x);
float total(int numfuente, energia vector_fuente[], int x);
float totalglobal(energia vector_fuente[], int x, int nfuentes);

int main()
{
	
	return 0;
}


//numfuente es la posicion que cada fuente ocupa en el vector de estructuras, si numfuente es 2, calculas la media de la fuente 3
//funcion de la media de una fuente (media individual)
float mediaInd(int numfuente, energia vector_fuente[], int x)
{
	int i;
	float suma, media;
	if(x==1)
	{
		for(i=0; i<12; i++)
		{
			suma = suma + vector_fuente[numfuente].gwh[i];
		}
	}
	else if(x==2)
	{
		for(i=12; i<24; i++)
		{
			suma = suma + vector_fuente[numfuente].gwh[i];
		}
	}
	else if(x=0)
	{
		for(i=0; i<24; i++)
		{
			suma = suma + vector_fuente[numfuente].gwh[i];
		}
	}
	media = suma/24;
	return media;
}

float maximo(int numfuente, energia vector_fuente[], int x)
{
	int i;
	float max=0;
	if(x==1)
	{
		for(i=0; i<12; i++)
		{
			if(vector_fuente[numfuente].gwh[i] > max)
			{
				max = vector_fuente[numfuente].gwh[i];
			}
		}
	}
	else if(x==2)
	{
		for(i=12; i<24; i++)
		{
			if(vector_fuente[numfuente].gwh[i] > max)
			{
				max = vector_fuente[numfuente].gwh[i];
			}
		}
	}
	else if(x==0)
	{
		for(i=0; i<24; i++)
		{
			if(vector_fuente[numfuente].gwh[i] > max)
			{
				max = vector_fuente[numfuente].gwh[i];
			}
		}
	}
	return max;
}

float minimo(int numfuente, energia vector_fuente[], int x)
{
	int i;
	float min=vector_fuente[numfuente].gwh[0];
	if(x==1)
	{
		for(i=0; i<12; i++)
		{
			if(vector_fuente[numfuente].gwh[i] > min)
			{
				min = vector_fuente[numfuente].gwh[i];
			}
		}
	}
	else if(x==2)
	{
		for(i=12; i<24; i++)
		{
			if(vector_fuente[numfuente].gwh[i] > min)
			{
				min = vector_fuente[numfuente].gwh[i];
			}
		}
	}
	else if(x==0)
	{
		for(i=0; i<24; i++)
		{
			if(vector_fuente[numfuente].gwh[i] > min)
			{
				min = vector_fuente[numfuente].gwh[i];
			}
		}
	}
	return min;
}

float total(int numfuente, energia vector_fuente[], int x)
{
	int i;
	float suma=0;
	if(x==1)
	{
		for(i=0; i<12; i++)
		{
			suma = suma + vector_fuente[numfuente].gwh[i];
		}
	}
	else if(x==2)
	{
		for(i=12; i<24; i++)
		{
			suma = suma + vector_fuente[numfuente].gwh[i];
		}
	}
	else if(x==0)
	{
		for(i=0; i<24; i++)
		{
			suma = suma + vector_fuente[numfuente].gwh[i];
		}
	}
	return suma;
}

float totalglobal(energia vector_fuente[], int x, int nfuentes)
{
	float totalGlob=0;
	int i;
	if(x==1)
	{
		for(i=0; i<nfuentes; i++)
		{
			totalGlob = totalGlob + total(i, vector_fuente, 1);
		}
	}
	else if(x==2)
	{
		for(i=0; i<nfuentes; i++)
		{
			totalGlob = totalGlob + total(i, vector_fuente, 2);
		}
	}
	else if(x==0)
	{
		for(i=0; i<nfuentes; i++)
		{
			totalGlob = totalGlob + total(i, vector_fuente, 0);
		}
	}
	
	return totalGlob;
}


