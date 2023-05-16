#include<stdio.h>

typedef struct 
{
	int month[11], year[50];
	float gwh[11];
	char nombre[30];
} energia;


int main()
{
	FILE *plectura;
	plectura = fopen("generacion_por_tecnologias_21_22_puntos.csv", "r");
	
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
		}
		
		//El vector de estructuras "fuente" guardará los datos de las fuentes energéticas leídas en el fichero.	
		energia fuente[40];
		int nfuentes=0;	
		int i, j;
		
		for(i=0; i<nfuentes; i++)
		{
			for(j=0; j<=11; j++)
			{
				fuente[i].gwh[j] = //energia generada en ese mes por esa fuente
			}
		}
		
		
		return 0;
	}
}




