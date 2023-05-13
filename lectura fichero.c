#include<stdio.h>
//lectura de un fichero

int main(){
	FILE *plectura;
	// Atención a los separadores en la ruta del fichero, y a las comillas dobles
	plectura = fopen("C:/Users/34698/Desktop/COSAS UNI/INFORMÁTICA/TRABAJO/generacion_por_tecnologias_21_22_puntos.csv", "r");
	if (plectura == NULL)
	{
		printf("Error al abrir el fichero.\n");
		return -1;
	}
	else
	{
		printf("Fichero abierto correctamente.\n");
		return 0;
	}
}
