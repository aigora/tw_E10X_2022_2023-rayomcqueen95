#include<stdio.h>
//al realizar las operaciones, preguntar la fuente de la que se quiere calcular la media, max y min
typedef struct 
{
	float gwh[24];
	char nombre[30];
} energia;

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
		int linea;
		int i=0;
		int nfuentes = 16;//calcular numero de lineas para q no sea fijo
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
		char letra;
		printf("Que quieres hacer?\n \n");
	    printf("\t      Mostrar datos: -a- \n");
	    printf("\t \t Salir: -b- \n \n");
	    printf("Pulsa la tecla (minuscula) correspondiente a la accion que quieres realizar: ");
	    scanf(" %c",&letra);
	    switch(letra)
	    {//llave del switch del principio del menu
	    	case('a'):
	    		{//llave del case si elige 'mostrar datos'
	    			printf("Has seleccionado 'Mostrar datos'\n");
	    			printf("De que anyo quieres ver los datos?\n(Introduce el anyo correspondiente)\n");
	    			printf("\t-2021-\n");
		            printf("\t-2022-\n");
	    			int anyo;
	    			scanf(" %i",&anyo);
	    			switch(anyo)
	    			{//llave del case para elegir los datos del año
	    				case(2021):
	    					{//llave del case para '2021'
	    						for(i=0; i<nfuentes; i++) 
								{//lave del bucle for que muestra los datos de 2021
									//vector meses que vaya avanzando dentro del for
									printf("%s\n", fuente[i].nombre);
									printf("%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n \n", 
									fuente[i].gwh[0], fuente[i].gwh[1], fuente[i].gwh[2], fuente[i].gwh[3], fuente[i].gwh[4], fuente[i].gwh[5],fuente[i].gwh[6], fuente[i].gwh[7], fuente[i].gwh[8],
									fuente[i].gwh[9], fuente[i].gwh[10], fuente[i].gwh[11]);
									printf("------------------------------\n");
								}//lave del bucle for que muestra los datos de 2021
								printf("    Que quieres hacer?\n");
								printf("Realizar operaciones: -c-\n");
								printf("Mostrar datos de 2022: -d-\n");
								char letra2;
								scanf(" %c",&letra2);
								if (letra2 == 'c')
								{//llave para realizar las operaciones de 2021
									printf("Que operacion quieres realizar?\n");
									printf("\t Max -e-\n\t Min -f-\n\tMedia -g-\n\tTotal -h-\n");
									char letra3;
									scanf(" %c",&letra3);
									if(letra3 == 'e'){
										printf("\tmax\n");
									}if(letra3 == 'f'){
										printf("\tmin\n");
									}if(letra3 == 'g'){
										printf("\tmedia\n");
									}if(letra3 == 'h'){
										printf("\ttotal\n");
									}
									printf("  Que quieres hacer?\n");
									printf(" Hacer otra operacion -i-\n   Salir del programa -j-\nMostrar datos de 2022 -k-\n");
									char letra4;
									scanf(" %c",&letra4);
									if(letra4=='j')
									{//llave para salir del programa
										printf("--------------------------------\n");
										printf("Gracias por usar nuestro programa!");
										exit(0);
									}//llave para salir del programa
									if (letra4=='k')
									{//lave para mostrar datos de 2022
										for(i=0; i<nfuentes; i++)
										{//llave de bucle for que muestra 2022
											printf("%s\n", fuente[i].nombre);
											printf("%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n \n", 
											fuente[i].gwh[12], fuente[i].gwh[13], fuente[i].gwh[14], fuente[i].gwh[15], fuente[i].gwh[16], fuente[i].gwh[17],fuente[i].gwh[18], fuente[i].gwh[19], fuente[i].gwh[20],
											fuente[i].gwh[21], fuente[i].gwh[22], fuente[i].gwh[23]);	
										}//llave de bucle for que muestra 2022
										char letra12;
										do
										{//lave del do-while de op de 2022
											printf("  Que quieres hacer?\n");
											printf("\t Max -e-\n\t Min -f-\n\tMedia -g-\n\tTotal -h-\n   Salir del programa -l-\n  Operaciones globales -m-\n");
											scanf(" %c",&letra12);
											if(letra12 == 'e'){
												printf("\tmax\n");
											}if(letra12 == 'f'){
												printf("\tmin\n");
											}if(letra12 == 'g'){
												printf("\tmedia\n");
											}if(letra12 == 'h'){
												printf("\ttotal\n");
											}
											}while ((letra12 == 'e' || letra12 == 'f' || letra12 == 'g' || letra12 == 'h'));//lave del do-while de op de 2022
										if (letra12 == 'l'){
											printf("--------------------------------\n");
											printf("Gracias por usar nuestro programa!");
											exit(1);
										}
										if (letra12 == 'm'){
											printf("  Operaciones globales\n");
											printf("--------------------------------\n");
											printf("Gracias por usar nuestro programa!");
											exit(2);
										}
									}//lave para mostrar datos de 2022
									if (letra4=='i')
									{//lave para hacer las operaciones de 2021
										char letra10;
										do
										{//lave del do-while de las operaciones de 2021
										printf("  Que quieres hacer?\n");
										printf("\t Max -e-\n\t Min -f-\n\tMedia -g-\n\tTotal -h-\n   Salir del programa -l-\n  Mostrar datos de 2022 -m-\n");
										scanf(" %c",&letra10);
										if(letra10 == 'e'){
											printf("\tmax\n");
										}if(letra10 == 'f'){
											printf("\tmin\n");
										}if(letra10 == 'g'){
											printf("\tmedia\n");
										}if(letra10 == 'h'){
											printf("\ttotal\n");
										}
										}while ((letra10 == 'e' || letra10 == 'f' || letra10 == 'g' || letra10 == 'h'));//operaciones de 2021
										if(letra10 == 'l')
										{//llave para salir del programa
											printf("--------------------------------\n");
											printf("Gracias por usar nuestro programa!");
											exit(3);
										}//llave para salir del programa
										if(letra10=='m')
										{//lave para mostrar datos de 2022
											for(i=0; i<nfuentes; i++)
											{//llave de bucle for que muestra 2022
												printf("%s\n", fuente[i].nombre);
												printf("%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n \n", 
												fuente[i].gwh[12], fuente[i].gwh[13], fuente[i].gwh[14], fuente[i].gwh[15], fuente[i].gwh[16], fuente[i].gwh[17],fuente[i].gwh[18], fuente[i].gwh[19], fuente[i].gwh[20],
												fuente[i].gwh[21], fuente[i].gwh[22], fuente[i].gwh[23]);
											}//llave de bucle for que muestra 2022
											printf("  Que quieres hacer?\n");
											printf("\t Max -e-\n\t Min -f-\n\tMedia -g-\n\tTotal -h-\n");
											char letra5;
											scanf(" %c",&letra5);
											if(letra5 == 'e'){
												printf("\tmax\n");
											}if(letra5 == 'f'){
												printf("\tmin\n");
											}if(letra5 == 'g'){
												printf("\tmedia\n");
											}if(letra5 == 'h'){
												printf("\ttotal\n");
											}
											printf("--------------------------------\n");
											printf("      Que quieres hacer?\n");
											printf("Seguir haciendo operaciones de 2022 -n-\n   Hacer operaciones globales -o-\n     Salir del programa -p-\n");
											char letra6;
											scanf(" %c",&letra6);
											if(letra6=='p')
											{//lave para salir del programa
												printf("--------------------------------\n");
												printf("Gracias por usar nuestro programa!");
												exit(4);
											}//lave para salir del programa
											if (letra6=='o')
											{//llave para operaciones globales
												printf("\tOperaciones globales\n");
												printf("--------------------------------\n");
												printf("Gracias por usar nuestro programa!");
												exit(5);
											}//llave para operaciones globales
											if(letra6=='n')
											{
												char letra11;
												do
												{//llave del do-while de las operaciones de 2022
												printf("  Que quieres hacer?\n");
												printf("\t Max -e-\n\t Min -f-\n\tMedia -g-\n\tTotal -h-\n  Salir del programa -p-\n");
												scanf(" %c",&letra11);
												if(letra11 == 'e'){
													printf("\tmax\n");
												}if(letra11 == 'f'){
													printf("\tmin\n");
												}if(letra11 == 'g'){
													printf("\tmedia\n");
												}if(letra11 == 'h'){
													printf("\ttotal\n");
												}
												}while((letra11 == 'e' || letra11 == 'f' || letra11 == 'g' || letra11 == 'h'));//operaciones de 2022
												if(letra11=='p')
												{
													printf("--------------------------------\n");
													printf("Gracias por usar nuestro programa!");
													exit(6);
												}
											}
										}//lave para mostrar datos de 2022
									}//lave para mostrar las operaciones de 2021
								}//llave para realizar las operaciones de 2021
								if (letra2== 'd');
								{//lave del bucle for que muestra los datos de 2022
									for(i=0; i<nfuentes; i++)
									{//lave del bucle for que muestra los datos de 2022
										printf("%s\n", fuente[i].nombre);
										printf("%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n \n", 
										fuente[i].gwh[12], fuente[i].gwh[13], fuente[i].gwh[14], fuente[i].gwh[15], fuente[i].gwh[16], fuente[i].gwh[17],fuente[i].gwh[18], fuente[i].gwh[19], fuente[i].gwh[20],
										fuente[i].gwh[21], fuente[i].gwh[22], fuente[i].gwh[23]);
									}//lave del bucle for que muestra los datos de 2022
									printf("Que operacion quieres realizar?\n");
									printf("\t Max -e-\n\t Min -f-\n\tMedia -g-\n\tTotal -h-\n");
									char letra7;
									scanf(" %c",&letra7);
									if(letra7 == 'e'){
										printf("\tmax\n");
									}if(letra7 == 'f'){
										printf("\tmin\n");
									}if(letra7 == 'g'){
										printf("\tmedia\n");
									}if(letra7 == 'h'){
										printf("\ttotal\n");
									}
									printf("   Que quieres hacer?\n");
									printf(" Hacer otra operacion -i-\n  Salir del programa -j-\n");
									char letra8;
									scanf(" %c",&letra8);
									if(letra8=='j')
									{//llave para salir del programa
										printf("--------------------------------\n");
										printf("Gracias por usar nuestro programa!");
										exit(6);
									}//llave para salir del programa
									if(letra8=='i')
									{//llave operaciones 2022
										char letra9;
										do
										{//llave del do-while de las operaciones de 2022
											printf("  Que quieres hacer?\n");
											printf("\t Max -e-\n\t Min -f-\n\tMedia -g-\n\tTotal -h-\n  Salir del programa -l-\n");
											scanf(" %c",&letra9);
											if(letra9 == 'e'){
												printf("\tmax\n");
											}if(letra9 == 'f'){
												printf("\tmin\n");
											}if(letra9 == 'g'){
												printf("\tmedia\n");
											}if(letra9 == 'h'){
												printf("\ttotal\n");
											}
										}while((letra9=='e' || letra9=='f' || letra9=='g' || letra9=='h'));//llave del do-while de las operaciones de 2022
										if(letra9 == 'l')
											{//llave para salir del programa
												printf("--------------------------------\n");
												printf("Gracias por usar nuestro programa!");
												exit(7);
											}//llave para salir del programa
									}//llave operaciones 2022
								}//lave del bucle for que muestra los datos de 2022
							}break;
						case(2022):
							{//llave del case para '2022'
								for(i=0; i<nfuentes; i++) 
								{//lave del bucle for que muestra los datos de 2022
									//vector meses que vaya avanzando dentro del for
									printf("%s\n", fuente[i].nombre);
									printf("%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n \n", 
									fuente[i].gwh[12], fuente[i].gwh[13], fuente[i].gwh[14], fuente[i].gwh[15], fuente[i].gwh[16], fuente[i].gwh[17],fuente[i].gwh[18], fuente[i].gwh[19], fuente[i].gwh[20],
									fuente[i].gwh[21], fuente[i].gwh[22], fuente[i].gwh[23]);
								}//lave del bucle for que muestra los datos de 2022
								printf("  Que quieres hacer?\n");
								printf("Realizar operaciones: -c-\n");
								printf("Mostrar datos de 2021: -d-\n");
								char letra2;
								scanf(" %c",&letra2);
								if (letra2 == 'c')
								{//llave para realizar las operaciones de 2021
									printf("  Que operacion quieres realizar?\n");
									printf("\t Max -e-\n\t Min -f-\n\tMedia -g-\n\tTotal -h-\n");
									char letra3;
									scanf(" %c",&letra3);
									if(letra3 == 'e'){
										printf("\tmax\n");
									}if(letra3 == 'f'){
										printf("\tmin\n");
									}if(letra3 == 'g'){
										printf("\tmedia\n");
									}if(letra3 == 'h'){
										printf("\ttotal\n");
									}
									printf("    Que quieres hacer?\n");
									printf("  Hacer otra operacion -i-\n   Salir del programa -j-\n  Mostrar datos de 2021 -k-\n");
									char letra4;
									scanf(" %c",&letra4);
									if(letra4=='j')
									{//llave para salir del programa
										printf("--------------------------------\n");
										printf("Gracias por usar nuestro programa!");
										exit(0);
									}//llave para salir del programa
									if (letra4=='k')
									{//lave para mostrar datos de 2021
										for(i=0; i<nfuentes; i++)
										{//llave de bucle for que muestra 2021
											printf("%s\n", fuente[i].nombre);
											printf("%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n \n", 
											fuente[i].gwh[0], fuente[i].gwh[1], fuente[i].gwh[2], fuente[i].gwh[3], fuente[i].gwh[4], fuente[i].gwh[5],fuente[i].gwh[6], fuente[i].gwh[7], fuente[i].gwh[8],
											fuente[i].gwh[9], fuente[i].gwh[10], fuente[i].gwh[11]);	
										}//llave de bucle for que muestra 2021
										char letra12;
										do
										{//lave del do-while de op de 2021
											printf("   Que quieres hacer?\n");
											printf("\t Max -e-\n\t Min -f-\n\tMedia -g-\n\tTotal -h-\n   Salir del programa -l-\n  Operaciones globales -m-\n");
											scanf(" %c",&letra12);
											if(letra12 == 'e'){
												printf("\tmax\n");
											}if(letra12 == 'f'){
												printf("\tmin\n");
											}if(letra12 == 'g'){
												printf("\tmedia\n");
											}if(letra12 == 'h'){
												printf("\ttotal\n");
											}
											}while ((letra12 == 'e' || letra12 == 'f' || letra12 == 'g' || letra12 == 'h'));//lave del do-while de op de 2022
										if (letra12 == 'l'){
											printf("--------------------------------\n");
											printf("Gracias por usar nuestro programa!");
											exit(1);
										}
										if (letra12 == 'm'){
											printf("Operaciones globales\n");
											printf("--------------------------------\n");
											printf("Gracias por usar nuestro programa!");
											exit(2);
										}
									}//lave para mostrar datos de 2021
									if (letra4=='i')
									{//lave para hacer las operaciones de 2022
										char letra10;
										do
										{//lave del do-while de las operaciones de 2022
										printf("   Que quieres hacer?\n");
										printf("\t Max -e-\n\t Min -f-\n\tMedia -g-\n\tTotal -h-\n   Salir del programa -l-\n  Mostrar datos de 2021 -m-\n");
										
										scanf(" %c",&letra10);
										if(letra10 == 'e'){
											printf("max\n");
										}if(letra10 == 'f'){
											printf("min\n");
										}if(letra10 == 'g'){
											printf("media\n");
										}if(letra10 == 'h'){
											printf("total\n");
										}
										}while ((letra10 == 'e' || letra10 == 'f' || letra10 == 'g' || letra10 == 'h'));//operaciones de 2022
										if(letra10 == 'l')
										{//llave para salir del programa
											printf("--------------------------------\n");
											printf("Gracias por usar nuestro programa!");
											exit(3);
										}//llave para salir del programa
										if(letra10=='m')
										{//lave para mostrar datos de 2021
											for(i=0; i<nfuentes; i++)
											{//llave de bucle for que muestra 2021
												printf("%s\n", fuente[i].nombre);
												printf("%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n \n", 
												fuente[i].gwh[0], fuente[i].gwh[1], fuente[i].gwh[2], fuente[i].gwh[3], fuente[i].gwh[4], fuente[i].gwh[5],fuente[i].gwh[6], fuente[i].gwh[7], fuente[i].gwh[8],
												fuente[i].gwh[9], fuente[i].gwh[10], fuente[i].gwh[11]);
											}//llave de bucle for que muestra 2021
											printf(" Que operacion quieres hacer?\n");
											printf("\t Max -e-\n\t Min -f-\n\tMedia -g-\n\tTotal -h-\n");
											char letra5;
											scanf(" %c",&letra5);
											if(letra5 == 'e'){
												printf("max\n");
											}if(letra5 == 'f'){
												printf("min\n");
											}if(letra5 == 'g'){
												printf("media\n");
											}if(letra5 == 'h'){
												printf("total\n");
											}
											printf("\tQue quieres hacer?\n");
											printf("Seguir haciendo operaciones de 2021 -n-\n   Hacer operaciones globales -o-\n       Salir del programa -p-\n");
											char letra6;
											scanf(" %c",&letra6);
											if(letra6=='p')
											{//lave para salir del programa
												printf("--------------------------------\n");
												printf("Gracias por usar nuestro programa!");
												exit(4);
											}//lave para salir del programa
											if (letra6=='o')
											{//llave para operaciones globales
												printf("Operaciones globales\n");
												printf("--------------------------------\n");
												printf("Gracias por usar nuestro programa!");
												exit(5);
											}//llave para operaciones globales
											if(letra6=='n')
											{
												char letra11;
												do
												{//llave del do-while de las operaciones de 2021
												printf("    Que quieres hacer?\n");
												printf("\t Max -e-\n\t Min -f-\n\tMedia -g-\n\tTotal -h-\n   Salir del programa -p-\n");
												scanf(" %c",&letra11);
												if(letra11 == 'e'){
													printf("\tmax\n");
												}if(letra11 == 'f'){
													printf("\tmin\n");
												}if(letra11 == 'g'){
													printf("\tmedia\n");
												}if(letra11 == 'h'){
													printf("\ttotal\n");
												}
												}while((letra11 == 'e' || letra11 == 'f' || letra11 == 'g' || letra11 == 'h'));//operaciones de 2021
												if(letra11=='p')
												{
													printf("--------------------------------\n");
													printf("Gracias por usar nuestro programa!");
													exit(6);
												}
											}
										}//lave para mostrar datos de 2021
									}//lave para mostrar las operaciones de 2022
								}//llave para realizar las operaciones de 2021
								if (letra2== 'd');
								{//lave del bucle for que muestra los datos de 2021
									for(i=0; i<nfuentes; i++)
									{//lave del bucle for que muestra los datos de 2021
										printf("%s\n", fuente[i].nombre);
										printf("%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n \n", 
										fuente[i].gwh[0], fuente[i].gwh[1], fuente[i].gwh[2], fuente[i].gwh[3], fuente[i].gwh[4], fuente[i].gwh[5],fuente[i].gwh[6], fuente[i].gwh[7], fuente[i].gwh[8],
										fuente[i].gwh[9], fuente[i].gwh[10], fuente[i].gwh[11]);
									}//lave del bucle for que muestra los datos de 2022
									printf(" Que operacion quieres hacer?\n");
									printf("\t Max -e-\n\t Min -f-\n\tMedia -g-\n\tTotal -h-\n");
									char letra7;
									scanf(" %c",&letra7);
									if(letra7 == 'e'){
										printf("\tmax\n");
									}if(letra7 == 'f'){
										printf("\tmin\n");
									}if(letra7 == 'g'){
										printf("\tmedia\n");
									}if(letra7 == 'h'){
										printf("\ttotal\n");
									}
									printf("   Que quieres hacer?\n");
									printf(" Hacer otra operacion -i-\n  Salir del programa -j-\n");
									char letra8;
									scanf(" %c",&letra8);
									if(letra8=='j')
									{//llave para salir del programa
										printf("--------------------------------\n");
										printf("Gracias por usar nuestro programa!");
										exit(6);
									}//llave para salir del programa
									if(letra8=='i')
									{//llave operaciones 2022
										char letra9;
										do
										{//llave del do-while de las operaciones de 2022
											printf("  Que quieres hacer?\n");
											printf("\t Max -e-\n\t Min -f-\n\tMedia -g-\n\tTotal -h-\n  Salir del programa -l-\n");
											scanf(" %c",&letra9);
											if(letra9 == 'e'){
												printf("\tmax\n");
											}if(letra9 == 'f'){
												printf("\tmin\n");
											}if(letra9 == 'g'){
												printf("\tmedia\n");
											}if(letra9 == 'h'){
												printf("\ttotal\n");
											}
										}while((letra9=='e' || letra9=='f' || letra9=='g' || letra9=='h'));//llave del do-while de las operaciones de 2022
										if(letra9 == 'l')
											{//llave para salir del programa
												printf("--------------------------------\n");
												printf("Gracias por usar nuestro programa!");
												exit(7);
											}//llave para salir del programa
									}//llave operaciones 2022
								}//lave del bucle for que muestra los datos de 2022
							}break;
						default:
							{//pulsar la tecla correspondiente por si el usuario se equivoca
								do
				                {
				                    printf("Pulsa la tecla correspondiente a la accion que quieres realizar \n");
				                    scanf(" %i", &anyo);
				                } while (anyo != 2021 && anyo != 2022);
							}
					}//llave del case para elegir el año
				}//llave del case si elige 'mostrar datos'
			case('b'):
				{
					printf("--------------------------------\n");
					printf("Gracias por usar nuestro programa!");
				}break;
		}//llave del switch del principio del menu
	}//lave del else
return 0;
}
