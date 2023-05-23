#include<stdio.h>
#include<stdlib.h>

//al realizar las operaciones, preguntar la fuente de la que se quiere calcular la media, max y min

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
		printf("Fichero abierto correctamente.\n\n");
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
		int nfuentes = 16;
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
		printf("Hola :)\nBienvenido a nuestro programa.\nAqui estan recogidos los datos de la energia electrica\ngenerada en Espanya durante 2021-2022\n\n");
		printf("Que quieres hacer?\n \n");
	    printf("\t      Mostrar datos: -a- \n");
	    printf("\t \t Salir: -b- \n \n");
	    printf("Pulsa la tecla (minuscula) correspondiente a la accion que quieres realizar:\n");
	    scanf(" %c",&letra);
	    switch(letra)
	    {//Switch del principio del programa (entrar o salir del programa) 
	    	case('a'):
	    		{//llave para entrar en el programa al inicio
	    			printf("\nHas seleccionado 'Mostrar datos'\n");
	    			printf("De que anyo quieres ver los datos?\n(Introduce el anyo correspondiente)\n");
	    			printf("\t-2021-\n");
		            printf("\t-2022-\n");
	    			int anyo;
	    			scanf(" %i",&anyo);	
	    			while(anyo != 2021 && anyo != 2022)
	    			{
	    				printf("Selecciona 2021 o 2022\n");
	    				scanf("%i", &anyo);
					}
	    			switch(anyo)
	    			{//llave del case para elegir los datos del año
	    				case(2021):
	    					{//llave del case para '2021'
	    						printf("\n");
	    						for(i=0; i<nfuentes; i++) 
								{//lave del bucle for que muestra los datos de 2021
									//vector meses que vaya avanzando dentro del for
									printf("%i) %s\n", i+1, fuente[i].nombre);
									printf("(Mes): (Gigavatios por hora)\n");
									printf("Enero: %f\nFebrero: %f\nMarzo: %f\nAbril: %f\nMayo: %f\nJunio: %f\nJulio: %f\nAgosto: %f\nSeptiembre: %f\nOctubre: %f\nNoviembre: %f\nDiciembre: %f\n \n", 
									fuente[i].gwh[0], fuente[i].gwh[1], fuente[i].gwh[2], fuente[i].gwh[3], fuente[i].gwh[4], fuente[i].gwh[5],fuente[i].gwh[6], fuente[i].gwh[7], fuente[i].gwh[8],
									fuente[i].gwh[9], fuente[i].gwh[10], fuente[i].gwh[11]);
									printf("------------------------------\n");
								}//lave del bucle for que muestra los datos de 2021
								
								printf("\nQue operacion quieres realizar?\n");
								printf("\t Max -e-\n\t Min -f-\n\tMedia -g-\n\tTotal -h-\n");
								char letra3;
								scanf(" %c",&letra3);
								while(letra3 != 'e' && letra3 != 'f' && letra3 != 'g' && letra3 != 'h')
								{
									printf("Elige una opcion valida:\n");
									scanf(" %c", &letra3);
								}
								
								int x;
								printf("Sobre que fuente? Selecciona posicion en la lista de arriba, de 1 a %i:\n", nfuentes);
								scanf(" %i", &x);
								while(x < 1 || x > nfuentes)
								{
									printf("Selecciona una posicion valida\n");
									scanf(" %i", &x);
								}
								
								switch(letra3)
								{//switch de operaciones 2021
									case 'e':
										{
											printf("Maximo 2021: %f\n\n", maximo(x-1, fuente, 1));
											break;
										}
									case 'f':
										{
											printf("Minimo 2021: %f\n\n", minimo(x-1, fuente, 1));
											break;
										}
									case 'g':
										{
											printf("Media 2021: %f\n\n", mediaInd(x-1, fuente, 1));
											break;
										}
									case 'h':
										{
											printf("Total 2021: %f\n\n", total(x-1, fuente, 1));
											break;
										}
								}//switch de operaciones 2021
								printf("------------------------------\n");
								
								char otra;
								printf("Quieres hacer otra operacion?\n\tSi -y-\n\tNo -n-\n");
								scanf(" %c", &otra);
								while(otra != 'y' && otra != 'n')
								{
									printf("Selecciona una opcion valida:\n");
									scanf(" %c", &otra);
								}
								if(otra == 'y')
								{//OPCION quiero seguir haciendo operaciones 
									char letra4;
									do
									{
										printf("\nQue otra operacion quieres realizar?\n");
										printf("\t Max -e-\n\t Min -f-\n\tMedia -g-\n\tTotal -h-\n\tNo quiero hacer mas operaciones -s-\n");
										scanf(" %c",&letra4);
										
										while(letra4 != 'e' && letra4 != 'f' && letra4 != 'g' && letra4 != 'h' && letra4 != 's')
										{
											printf("Elige una opcion valida:\n");
											scanf(" %c", &letra4);
										}
										if(letra4 == 's')
										{
											break;
										}
										
										int x;
										printf("Sobre que fuente? Selecciona posicion en la lista de arriba, de 1 a %i:\n", nfuentes);
										scanf(" %i", &x);
										while(x < 1 || x > nfuentes)
										{
											printf("Selecciona una posicion valida\n");
											scanf(" %i", &x);
										}
										
										switch(letra4)
										{//switch de operaciones 2021 BUCLE
											case 'e':
												{
													printf("Maximo 2021: %f\n\n", maximo(x-1, fuente, 1));
													break;
												}
											case 'f':
												{
													printf("Minimo 2021: %f\n\n", minimo(x-1, fuente, 1));
													break;
												}
											case 'g':
												{
													printf("Media 2021: %f\n\n", mediaInd(x-1, fuente, 1));
													break;
												}
											case 'h':
												{					
													printf("Total 2021: %f\n\n", total(x-1, fuente, 1));
													break;
												}
										}//switch de operaciones 2021 BUCLE
										printf("------------------------------\n");
										
									}while(letra4 != 's');
								}//OPCION quiero seguir haciendo operaciones
								
								printf("  \nQue quieres hacer?\n");
								printf("Salir del programa -j-\nMostrar datos de 2022 -k-\n\n");
								char letra5;
								scanf(" %c",&letra5);
								
								while(letra5 != 'j' && letra5 != 'k')
								{
									printf("Selecciona una opcion valida:\n");
									scanf(" %c", &letra5);
								}
								printf("\n");
										
								if(letra5=='j')
								{//llave para salir del programa
									printf("--------------------------------\n");
									printf("Gracias por usar nuestro programa!");
									exit(0);
								}//llave para salir del programa
								else if(letra5=='k')
								{//lave para mostrar datos de 2022 (habiendo escogido primero 2021)
									for(i=0; i<nfuentes; i++)
									{//llave de bucle for que muestra 2022
										printf("%i) %s\n", i+1, fuente[i].nombre);
										printf("(Mes): (Gigavatios por hora)\n");
										printf("Enero: %f\nFebrero: %f\nMarzo: %f\nAbril: %f\nMayo: %f\nJunio: %f\nJulio: %f\nAgosto: %f\nSeptiembre: %f\nOctubre: %f\nNoviembre: %f\nDiciembre: %f\n \n", 
										fuente[i].gwh[12], fuente[i].gwh[13], fuente[i].gwh[14], fuente[i].gwh[15], fuente[i].gwh[16], fuente[i].gwh[17],fuente[i].gwh[18], fuente[i].gwh[19], fuente[i].gwh[20],
										fuente[i].gwh[21], fuente[i].gwh[22], fuente[i].gwh[23]);	
									}//llave de bucle for que muestra 2022
									printf("----------------------------\n");
									printf(" Que quieres hacer?\n");
									printf("Realizar operaciones: -c-\n");
									printf("Salir del programa: -s-\n");
									
									char quehacer;
									scanf(" %c", &quehacer);
									while(quehacer != 'c' && quehacer != 's')
									{
										printf("Elige una opcion valida\n");
										scanf(" %c", &quehacer);
									}
									
									if(quehacer == 'c')
									{
										char letra12;
										printf("  Que quieres hacer?\n");
										printf("\t Max -e-\n\t Min -f-\n\tMedia -g-\n\tTotal -h-\n\t Operaciones globales(los dos anyos incluidos) -Igual pero letras en mayuscula-\n\t TOTAL GLOBAL DE TODAS LAS FUENTES SUMADAS -x-\n");
										scanf(" %c",&letra12);
										while(letra12 != 'e' && letra12 != 'f' && letra12 != 'g' && letra12 != 'h' && letra12 != 'E' && letra12 != 'F' && letra12 != 'G' && letra12 != 'H' && letra12 != 'x')
										{
											printf("Elige una opcion valida:\n");
											scanf(" %c", &letra12);
										}
										
										int y;
										if(letra12 != 'x')
										{
											printf("Sobre que fuente? Selecciona posicion en la lista de arriba, de 1 a %i:\n", nfuentes);
											scanf(" %i", &y);
											while(y < 1 || y > nfuentes)
											{
												printf("Selecciona una posicion valida\n");
												scanf(" %i", &y);
											}
										}
										
										switch(letra12)
										{//switch de operaciones 2022 y globales
											case 'e':
												{
													printf("Maximo 2022: %f\n\n", maximo(y-1, fuente, 2));
													break;
												}
											case 'f':
												{
													printf("Minimo 2022: %f\n\n", minimo(y-1, fuente, 2));
													break;
												}
											case 'g':
												{
													printf("Media 2022: %f\n\n", mediaInd(y-1, fuente, 2));
													break;
												}
											case 'h':
												{
													printf("Total 2022: %f\n\n", total(y-1, fuente, 2));
													break;
												}
											case 'E':
												{
													printf("Maximo 2021-2022: %f\n\n", maximo(y-1, fuente, 0));
													break;
												}
											case 'F':
												{
													printf("Minimo 2021-2022: %f\n\n", minimo(y-1, fuente, 0));
													break;
												}
											case 'G':
												{
													printf("Media 2021-2022: %f\n\n", mediaInd(y-1, fuente, 0));
													break;
												}
											case 'H':
												{
													printf("Total 2021-2022: %f\n\n", total(y-1, fuente, 0));
													break;
												}
											case 'x':
												{
													printf("Elige:\n TOTAL GLOBAL 2021 -1-\nTOTAL GLOBAL 2022 -2-\nTOTAL GLOBAL 2021-2022 -0-\n");
													int p;
													scanf(" %i", &p);
													while(p != 1 && p != 2 && p != 0)
													{
														printf("Elige una opcion valida");
														scanf(" %i", &p);
													}
													
													if(p == 1)
													{
														printf("Total GLOBAL 2021: %f\n\n", totalglobal(fuente, 1, nfuentes));
													}
													else if(p == 2)
													{
														printf("Total GLOBAL 2022: %f\n\n", totalglobal(fuente, 2, nfuentes));
													}
													else if(p == 0)
													{
														printf("Total GLOBAL 2021-2022: %f\n\n", totalglobal(fuente, 0, nfuentes));
													}
													break;
												}
										}//switch de operaciones 2022 y globales
										printf("------------------------------\n");
											
										char otra2;
										printf("Quieres hacer otra operacion?\n\tSi -y-\n\tNo -n-\n");
										scanf(" %c", &otra2);
										while(otra2 != 'y' && otra2 != 'n')
										{
											printf("Selecciona una opcion valida:\n");
											scanf(" %c", &otra2);
										}
										if(otra2 == 'y')
										{
											char letra69;
											do
											{
												printf("\nQue otra operacion quieres realizar?\n");
												printf("\t Max -e-\n\t Min -f-\n\tMedia -g-\n\tTotal -h-\n\t Operaciones globales(los dos anyos incluidos) -Igual pero letras en mayuscula-\n\t TOTAL GLOBAL DE TODAS LAS FUENTES SUMADAS -x-\n\t Salir -s-");
										
												scanf(" %c",&letra69);
												
												while(letra69 != 'e' && letra69 != 'f' && letra69 != 'g' && letra69 != 'h' && letra69 != 'E' && letra69 != 'F' && letra69 != 'G' && letra69 != 'H' && letra69 != 's' && letra69 != 'x' )
												{
													printf("Elige una opcion valida:\n");
													scanf(" %c", &letra69);
												}
												if(letra69 == 's')
												{
													printf("--------------------------------\n");
													printf("Gracias por usar nuestro programa!");
													exit(0);
												}
												
												int z;
												if(letra69 != 'x')
												{
													printf("Sobre que fuente? Selecciona posicion en la lista de arriba, de 1 a %i:\n", nfuentes);
													scanf(" %i", &z);
													while(z < 1 || z > nfuentes)
													{
														printf("Selecciona una posicion valida\n");
														scanf(" %i", &z);
													}
												}
											
												switch(letra69)
												{//switch de operaciones 2022 y globales BUCLE
													case 'e':
														{
															printf("Maximo 2022: %f\n\n", maximo(z-1, fuente, 2));
															break;
														}
													case 'f':
														{
															printf("Minimo 2022: %f\n\n", minimo(z-1, fuente, 2));
															break;
														}
													case 'g':
														{
															printf("Media 2022: %f\n\n", mediaInd(z-1, fuente, 2));
															break;
														}
													case 'h':
														{
															printf("Total 2022: %f\n\n", total(z-1, fuente, 2));
															break;
														}
													case 'E':
														{
															printf("Maximo 2021-2022: %f\n\n", maximo(z-1, fuente, 0));
															break;
														}
													case 'F':
														{
															printf("Minimo 2021-2022: %f\n\n", minimo(z-1, fuente, 0));
															break;
														}
													case 'G':
														{
															printf("Media 2021-2022: %f\n\n", mediaInd(z-1, fuente, 0));
															break;
														}
													case 'H':
														{
															printf("Total 2021-2022: %f\n\n", total(z-1, fuente, 0));
															break;
														}
													case 'x':
														{
															printf("Elige:\n TOTAL GLOBAL 2021 -1-\nTOTAL GLOBAL 2022 -2-\nTOTAL GLOBAL 2021-2022 -0-\n");
															int q;
															scanf(" %i", &q);
															while(q != 1 && q != 2 && q != 0)
															{
																printf("Elige una opcion valida");
																scanf(" %i", &q);
															}
															
															if(q == 1)
															{
																printf("Total GLOBAL 2021: %f\n\n", totalglobal(fuente, 1, nfuentes));
															}
															else if(q == 2)
															{
																printf("Total GLOBAL 2022: %f\n\n", totalglobal(fuente, 2, nfuentes));
															}
															else if(q == 0)
															{
																printf("Total GLOBAL 2021-2022: %f\n\n", totalglobal(fuente, 0, nfuentes));
															}
															break;
														}
												}//switch de operaciones 2022 y globales BUCLE
												printf("------------------------------\n");
											}while(letra69 != 's');
										}
										else
										{//llave para salir del programa
											printf("--------------------------------\n");
											printf("Gracias por usar nuestro programa!");
											exit(0);
										}//llave para salir del programa
									}
									else if(quehacer == 's')
									{//llave para salir del programa
										printf("--------------------------------\n");
										printf("Gracias por usar nuestro programa!");
										exit(0);
									}//llave para salir del programa
								}//lave para mostrar datos de 2022 (habiendo escogido primero 2021)
							}//llave del case para '2021'
							
						case(2022):
							{//llave del case para '2022'
	    						printf("\n");
	    						for(i=0; i<nfuentes; i++) 
								{//lave del bucle for que muestra los datos de 2022
									//vector meses que vaya avanzando dentro del for
									printf("%i) %s\n", i+1, fuente[i].nombre);
									printf("(Mes): (Gigavatios por hora)\n");
									printf("Enero: %f\nFebrero: %f\nMarzo: %f\nAbril: %f\nMayo: %f\nJunio: %f\nJulio: %f\nAgosto: %f\nSeptiembre: %f\nOctubre: %f\nNoviembre: %f\nDiciembre: %f\n \n", 
									fuente[i].gwh[12], fuente[i].gwh[13], fuente[i].gwh[14], fuente[i].gwh[15], fuente[i].gwh[16], fuente[i].gwh[17],fuente[i].gwh[18], fuente[i].gwh[19], fuente[i].gwh[20],
									fuente[i].gwh[21], fuente[i].gwh[22], fuente[i].gwh[23]);
									printf("------------------------------\n");
								}//lave del bucle for que muestra los datos de 2022
								
								printf("\nQue operacion quieres realizar?\n");
								printf("\t Max -e-\n\t Min -f-\n\tMedia -g-\n\tTotal -h-\n");
								char letra3;
								scanf(" %c",&letra3);
								while(letra3 != 'e' && letra3 != 'f' && letra3 != 'g' && letra3 != 'h')
								{
									printf("Elige una opcion valida:\n");
									scanf(" %c", &letra3);
								}
								
								int x;
								printf("Sobre que fuente? Selecciona posicion en la lista de arriba, de 1 a %i:\n", nfuentes);
								scanf(" %i", &x);
								while(x < 1 || x > nfuentes)
								{
									printf("Selecciona una posicion valida\n");
									scanf(" %i", &x);
								}
								
								switch(letra3)
								{//switch de operaciones 2022
									case 'e':
										{
											printf("Maximo 2022: %f\n", maximo(x-1, fuente, 2));
											break;
										}
									case 'f':
										{
											printf("Minimo 2022: %f\n", minimo(x-1, fuente, 2));
											break;
										}
									case 'g':
										{
											printf("Media 2022: %f\n", mediaInd(x-1, fuente, 2));
											break;
										}
									case 'h':
										{
											printf("Total 2022: %f\n", total(x-1, fuente, 2));
											break;
										}
								}//switch de operaciones 2022
								printf("------------------------------\n");
								
								char otra;
								printf("Quieres hacer otra operacion?\n\tSi -y-\n\tNo -n-\n");
								scanf(" %c", &otra);
								while(otra != 'y' && otra != 'n')
								{
									printf("Selecciona una opcion valida:\n");
									scanf(" %c", &otra);
								}
								if(otra == 'y')
								{//OPCION quiero seguir haciendo operaciones
									char letra4;
									do
									{
										printf("\nQue otra operacion quieres realizar?\n");
										printf("\t Max -e-\n\t Min -f-\n\tMedia -g-\n\tTotal -h-\n\tNo quiero hacer mas operaciones -s-\n");
										scanf(" %c",&letra4);
										
										while(letra4 != 'e' && letra4 != 'f' && letra4 != 'g' && letra4 != 'h' && letra4 != 's')
										{
											printf("Elige una opcion valida:\n");
											scanf(" %c", &letra4);
										}
										if(letra4 == 's')
										{
											break;
										}
										
										int x;
										printf("Sobre que fuente? Selecciona posicion en la lista de arriba, de 1 a %i:\n", nfuentes);
										scanf(" %i", &x);
										while(x < 1 || x > nfuentes)
										{
											printf("Selecciona una posicion valida\n");
											scanf(" %i", &x);
										}
										
										switch(letra4)
										{//switch de operaciones 2022 BUCLE
											case 'e':
												{
													printf("Maximo 2022: %f\n", maximo(x-1, fuente, 2));
													break;
												}
											case 'f':
												{
													printf("Minimo 2022: %f\n", minimo(x-1, fuente, 2));
													break;
												}
											case 'g':
												{
													printf("Media 2022: %f\n", mediaInd(x-1, fuente, 2));
													break;
												}
											case 'h':
												{					
													printf("Total 2022: %f\n", total(x-1, fuente, 2));
													break;
												}
										}//switch de operaciones 2022 BUCLE
										printf("------------------------------\n");
										
									}while(letra4 != 's');
								}//OPCION quiero seguir haciendo operaciones
								
								printf("  \nQue quieres hacer?\n");
								printf("Salir del programa -j-\nMostrar datos de 2021 -k-\n\n");
								char letra5;
								scanf(" %c",&letra5);
								
								while(letra5 != 'j' && letra5 != 'k')
								{
									printf("Selecciona una opcion valida:\n");
									scanf(" %c", &letra5);
								}
								printf("\n");
										
								if(letra5=='j')
								{//llave para salir del programa
									printf("--------------------------------\n");
									printf("Gracias por usar nuestro programa!");
									exit(0);
								}//llave para salir del programa
								else if(letra5=='k')
								{//lave para mostrar datos de 2021 (habiendo escogido primero 2022)
									for(i=0; i<nfuentes; i++)
									{//llave de bucle for que muestra 2021
										printf("%i) %s\n", i+1, fuente[i].nombre);
										printf("(Mes): (Gigavatios por hora)\n");
										printf("Enero: %f\nFebrero: %f\nMarzo: %f\nAbril: %f\nMayo: %f\nJunio: %f\nJulio: %f\nAgosto: %f\nSeptiembre: %f\nOctubre: %f\nNoviembre: %f\nDiciembre: %f\n \n", 
										fuente[i].gwh[0], fuente[i].gwh[1], fuente[i].gwh[2], fuente[i].gwh[3], fuente[i].gwh[4], fuente[i].gwh[5],fuente[i].gwh[6], fuente[i].gwh[7], fuente[i].gwh[8],
										fuente[i].gwh[9], fuente[i].gwh[10], fuente[i].gwh[11]);	
									}//llave de bucle for que muestra 2021
									printf("----------------------------\n");
									printf(" Que quieres hacer?\n");
									printf("Realizar operaciones: -c-\n");
									printf("Salir del programa: -s-\n");
									
									char quehacer;
									scanf(" %c", &quehacer);
									while(quehacer != 'c' && quehacer != 's')
									{
										printf("Elige una opcion valida\n");
										scanf(" %c", &quehacer);
									}
									
									if(quehacer == 'c')
									{
										char letra12;
										printf("  Que quieres hacer?\n");
										printf("\t Max -e-\n\t Min -f-\n\tMedia -g-\n\tTotal -h-\n\t Operaciones globales(los dos anyos incluidos) -Igual pero letras en mayuscula-\n\t TOTAL GLOBAL DE TODAS LAS FUENTES SUMADAS -x-\n");
										scanf(" %c",&letra12);
										while(letra12 != 'e' && letra12 != 'f' && letra12 != 'g' && letra12 != 'h' && letra12 != 'E' && letra12 != 'F' && letra12 != 'G' && letra12 != 'H' && letra12 != 'x')
										{
											printf("Elige una opcion valida:\n");
											scanf(" %c", &letra12);
										}
										
										int y;
										if(letra12 != 'x')
										{
											printf("Sobre que fuente? Selecciona posicion en la lista de arriba, de 1 a %i:\n", nfuentes);
											scanf(" %i", &y);
											while(y < 1 || y > nfuentes)
											{
												printf("Selecciona una posicion valida\n");
												scanf(" %i", &y);
											}
										}
										
										switch(letra12)
										{//switch de operaciones 2021 y globales
											case 'e':
												{
													printf("Maximo 2021: %f\n", maximo(y-1, fuente, 1));
													break;
												}
											case 'f':
												{
													printf("Minimo 2021: %f\n", minimo(y-1, fuente, 1));
													break;
												}
											case 'g':
												{
													printf("Media 2021: %f\n", mediaInd(y-1, fuente, 1));
													break;
												}
											case 'h':
												{
													printf("Total 2021: %f\n", total(y-1, fuente, 1));
													break;
												}
											case 'E':
												{
													printf("Maximo 2021-2022: %f\n", maximo(y-1, fuente, 0));
													break;
												}
											case 'F':
												{
													printf("Minimo 2021-2022: %f\n", minimo(y-1, fuente, 0));
													break;
												}
											case 'G':
												{
													printf("Media 2021-2022: %f\n", mediaInd(y-1, fuente, 0));
													break;
												}
											case 'H':
												{
													printf("Total 2021-2022: %f\n", total(y-1, fuente, 0));
													break;
												}
											case 'x':
												{
													printf("Elige:\n TOTAL GLOBAL 2021 -1-\nTOTAL GLOBAL 2022 -2-\nTOTAL GLOBAL 2021-2022 -0-\n");
													int p;
													scanf(" %i", &p);
													while(p != 1 && p != 2 && p != 0)
													{
														printf("Elige una opcion valida");
														scanf(" %i", &p);
													}
													
													if(p == 1)
													{
														printf("Total GLOBAL 2021: %f\n", totalglobal(fuente, 1, nfuentes));
													}
													else if(p == 2)
													{
														printf("Total GLOBAL 2022: %f\n", totalglobal(fuente, 2, nfuentes));
													}
													else if(p == 0)
													{
														printf("Total GLOBAL 2021-2022: %f\n", totalglobal(fuente, 0, nfuentes));
													}
													break;
												}
										}//switch de operaciones 2021 y globales
										printf("------------------------------\n");
										
										char otra2;
										printf("Quieres hacer otra operacion?\n\tSi -y-\n\tNo -n-\n");
										scanf(" %c", &otra2);
										while(otra2 != 'y' && otra2 != 'n')
										{
											printf("Selecciona una opcion valida:\n");
											scanf(" %c", &otra2);
										}
										if(otra2 == 'y')
										{
											char letra69;
											do
											{
												printf("\nQue otra operacion quieres realizar?\n");
												printf("\t Max -e-\n\t Min -f-\n\tMedia -g-\n\tTotal -h-\n\t Operaciones globales(los dos anyos incluidos) -Igual pero letras en mayuscula-\n\t TOTAL GLOBAL DE TODAS LAS FUENTES SUMADAS -x-\n\t Salir -s-");
										
												scanf(" %c",&letra69);
												
												while(letra69 != 'e' && letra69 != 'f' && letra69 != 'g' && letra69 != 'h' && letra69 != 'E' && letra69 != 'F' && letra69 != 'G' && letra69 != 'H' && letra69 != 's' && letra69 != 'x' )
												{
													printf("Elige una opcion valida:\n");
													scanf(" %c", &letra69);
												}
												if(letra69 == 's')
												{
													printf("--------------------------------\n");
													printf("Gracias por usar nuestro programa!");
													exit(0);
												}
												
												int z;
												if(letra69 != 'x')
												{
													printf("Sobre que fuente? Selecciona posicion en la lista de arriba, de 1 a %i:\n", nfuentes);
													scanf(" %i", &z);
													while(z < 1 || z > nfuentes)
													{
														printf("Selecciona una posicion valida\n");
														scanf(" %i", &z);
													}
												}
											
												switch(letra69)
												{//switch de operaciones 2021 y globales BUCLE
													case 'e':
														{
															printf("Maximo 2021: %f\n", maximo(z-1, fuente, 1));
															break;
														}
													case 'f':
														{
															printf("Minimo 2021: %f\n", minimo(z-1, fuente, 1));
															break;
														}
													case 'g':
														{
															printf("Media 2021: %f\n", mediaInd(z-1, fuente, 1));
															break;
														}
													case 'h':
														{
															printf("Total 2021: %f\n", total(z-1, fuente, 1));
															break;
														}
													case 'E':
														{
															printf("Maximo 2021-2022: %f\n", maximo(z-1, fuente, 0));
															break;
														}
													case 'F':
														{
															printf("Minimo 2021-2022: %f\n", minimo(z-1, fuente, 0));
															break;
														}
													case 'G':
														{
															printf("Media 2021-2022: %f\n", mediaInd(z-1, fuente, 0));
															break;
														}
													case 'H':
														{
															printf("Total 2021-2022: %f\n", total(z-1, fuente, 0));
															break;
														}
													case 'x':
														{
															printf("Elige:\n TOTAL GLOBAL 2021 -1-\nTOTAL GLOBAL 2022 -2-\nTOTAL GLOBAL 2021-2022 -0-\n");
															int q;
															scanf(" %i", &q);
															while(q != 1 && q != 2 && q != 0)
															{
																printf("Elige una opcion valida");
																scanf(" %i", &q);
															}
															
															if(q == 1)
															{
																printf("Total GLOBAL 2021: %f\n", totalglobal(fuente, 1, nfuentes));
															}
															else if(q == 2)
															{
																printf("Total GLOBAL 2022: %f\n", totalglobal(fuente, 2, nfuentes));
															}
															else if(q == 0)
															{
																printf("Total GLOBAL 2021-2022: %f\n", totalglobal(fuente, 0, nfuentes));
															}
															break;
														}
												}//switch de operaciones 2021 y globales BUCLE
												printf("------------------------------\n");
												
											}while(letra69 != 's');
										}
										else
										{//llave para salir del programa
											printf("--------------------------------\n");
											printf("Gracias por usar nuestro programa!");
											exit(0);
										}//llave para salir del programa
									}
									else if(quehacer == 's')
									{//llave para salir del programa
										printf("--------------------------------\n");
										printf("Gracias por usar nuestro programa!");
										exit(0);
									}//llave para salir del programa
								}//lave para mostrar datos de 2021 (habiendo escogido primero 2022)
							}//llave del case para '2022'		
					}
				}//llave para entrar en el programa al inicio
			case ('b'):
				{//llave para salir al principio
					printf("--------------------------------\n");
					printf("Gracias por usar nuestro programa!");
					exit(0);
				}//llave para salir al principio
		}//Switch del principio del programa (entrar o salir del programa) 
	}//llave del else por si se lee bien el fichero
}//llave del main




//numfuente es la posicion que cada fuente ocupa en el vector de estructuras, si numfuente es 2, calculas la media de la fuente 3
//funcion de la media de una fuente (media individual)
float mediaInd(int numfuente, energia vector_fuente[], int x)
{
	int i;
	float suma  = 0, media;
	if(x==1)
	{
		for(i=0; i<12; i++)
		{
			suma = suma + vector_fuente[numfuente].gwh[i];
		}
		media = suma/12;
	}
	else if(x==2)
	{
		for(i=12; i<24; i++)
		{
			suma = suma + vector_fuente[numfuente].gwh[i];
		}
		media = suma/12;
	}
	else if(x=0)
	{
		for(i=0; i<24; i++)
		{
			suma = suma + vector_fuente[numfuente].gwh[i];
		}
		media = suma/24;
	}
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
			if(vector_fuente[numfuente].gwh[i] < min)
			{
				min = vector_fuente[numfuente].gwh[i];
			}
		}
	}
	else if(x==2)
	{
		for(i=12; i<24; i++)
		{
			if(vector_fuente[numfuente].gwh[i] < min)
			{
				min = vector_fuente[numfuente].gwh[i];
			}
		}
	}
	else if(x==0)
	{
		for(i=0; i<24; i++)
		{
			if(vector_fuente[numfuente].gwh[i] < min)
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
