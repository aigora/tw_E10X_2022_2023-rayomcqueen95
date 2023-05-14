#include<stdio.h>

typedef struct 
{
	int month, year;
	float gwh;
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
		while(fscanf(plectura, "%c", &c) != EOF)
		{
			//no se como leer el excel
		}
		
		//El vector de estructuras "fuente" guardará los datos de las fuentes energéticas leídas en el fichero.	
		energia fuente[40];
		int nfuentes=0;	
		int i;
		
		for(i=0; i<nfuentes; i++)
		{
			fuente[i].month =
		}
		
		
		return 0;
	}
}




