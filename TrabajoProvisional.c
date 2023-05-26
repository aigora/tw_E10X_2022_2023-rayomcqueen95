#include<stdio.h>

typedef struct 
{
	float gwh[24];
	char nombre[30];
} energia;

float mediaInd(int numfuente, energia vector_fuente[], int x); 
float maximo(int numfuente, energia vector_fuente[], int x);
float minimo(int numfuente, energia vector_fuente[], int x);
float total(int numfuente, energia vector_fuente[], int x);
float totalglobal(energia vector_fuente[], int x, int nfuentes);

//hay que poner al principio, si elegimos mostrar los datos, las fechas como si fuera una tabla.
//poner opcion de mostrar una fuente individual, con las fechas encima

int main()
{

	FILE *plectura;
	plectura = fopen("generacion_por_tecnologias_21_22_puntos_simplificado.csv", "r");
	
	if (plectura == NULL)
	{
		printf("Error al abrir el fichero.\n");
		return -1;
	}
	else
	{
		printf("Fichero abierto correctamente.\n");
		
		char c;
		int nlineas = 0;
		while(fscanf(plectura, "%c", &c) != EOF)
		{
			if(c == '\n')
			{
				nlineas++;
			}
			if(nlineas==5)
			{
				break;
			}
		}
	
		int i;	
		int nfuentes = 16;//generacion total la contamos como fuente pero no lo es
		
		energia fuente[40];
			
		for(i=0; i<nfuentes; i++)
		{
			fscanf(plectura, "%[^,]s", fuente[i].nombre);
			fscanf(plectura, "%c", &c);
			fscanf(plectura, "%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f", 
			&fuente[i].gwh[0], &fuente[i].gwh[1], &fuente[i].gwh[2], &fuente[i].gwh[3], &fuente[i].gwh[4], &fuente[i].gwh[5], &fuente[i].gwh[6], &fuente[i].gwh[7], &fuente[i].gwh[8],
			&fuente[i].gwh[9], &fuente[i].gwh[10], &fuente[i].gwh[11], &fuente[i].gwh[12], &fuente[i].gwh[13], &fuente[i].gwh[14], &fuente[i].gwh[15], &fuente[i].gwh[16], &fuente[i].gwh[17], &fuente[i].gwh[18],
			&fuente[i].gwh[19], &fuente[i].gwh[20], &fuente[i].gwh[21], &fuente[i].gwh[22], &fuente[i].gwh[23]);
		}
		fclose(plectura);
		
	}//poner los comentariosss
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
		for(i=0; i<nfuentes-1; i++)
		{
			totalGlob = totalGlob + total(i, vector_fuente, 1);
		}
	}
	else if(x==2)
	{
		for(i=0; i<nfuentes-1; i++)
		{
			totalGlob = totalGlob + total(i, vector_fuente, 2);
		}
	}
	else if(x==0)
	{
		for(i=0; i<nfuentes-1; i++)
		{
			totalGlob = totalGlob + total(i, vector_fuente, 0);
		}
	}
	
	return totalGlob;
}





