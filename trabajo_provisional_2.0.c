#include<stdio.h>
#include<stdlib.h>

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
		printf("(Fichero abierto correctamente)\n");
		printf("-------------------------------\n\n");
		char c; //declaramos una variable char para contar los saltos de línea
		int nlineas = 0; //iniciamos el contador en 0
		while(fscanf(plectura, "%c", &c) != EOF)
		{
			if(c == '\n')
			{
				nlineas++;
				//cada vez que encuentra un \n suma 1 al número de líneas
			}
			if(nlineas==5)
			{
				break;
				//para al final de la linea 5 para empezar a escanear en la 6
			}
		}
		int linea;
		int i=0; //contador para el bucle for
		int nfuentes = 16; //líneas con los datos con los que se va a trabajar
		energia fuente[40]; //vector donde guardar los valores de las energías
		for(i; i<=nfuentes; i++)
		{
			fscanf(plectura, "%[^,]s", fuente[i].nombre); //fscanf del tipo de energía
			fscanf(plectura, "%c", &c); //fscanf para la coma que separa la fuente y los datos
			fscanf(plectura, "%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f", //fscanf de los datos
			&fuente[i].gwh[0], &fuente[i].gwh[1], &fuente[i].gwh[2], &fuente[i].gwh[3], &fuente[i].gwh[4], &fuente[i].gwh[5], &fuente[i].gwh[6], &fuente[i].gwh[7], &fuente[i].gwh[8],
			&fuente[i].gwh[9], &fuente[i].gwh[10], &fuente[i].gwh[11], &fuente[i].gwh[12], &fuente[i].gwh[13], &fuente[i].gwh[14], &fuente[i].gwh[15], &fuente[i].gwh[16], &fuente[i].gwh[17], &fuente[i].gwh[18],
			&fuente[i].gwh[19], &fuente[i].gwh[20], &fuente[i].gwh[21], &fuente[i].gwh[22], &fuente[i].gwh[23]);
		}
		
		char letra;
		printf("Hola, bienvenido a nuestro programa.\nAqui estan recogidos los datos de la energia electrica generada en Espanya durante 2021 y 2022\n\n");
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
	    			while(anyo != 2021 && anyo != 2022) //bucle por si el usuario introduce un valor incorrecto
	    			{
	    				printf("Selecciona 2021 o 2022\n");
	    				scanf("%i", &anyo);
					}
	    			switch(anyo)
	    			{//llave del case para elegir los datos del año
	    				case(2021):
	    					{//llave del case para '2021'
	    						printf("\n");
	    						for(i=0; i<=nfuentes; i++) 
								{//lave del bucle for que muestra los datos de 2021
									printf("%i) %s\n", i+1, fuente[i].nombre); //determina un número para cada energía y el nombre del tipo de energía
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
								while(letra3 != 'e' && letra3 != 'f' && letra3 != 'g' && letra3 != 'h') //bucle por si el usuario introduce una letra incorrecta
								{
									printf("Elige una opcion valida:\n");
									scanf(" %c", &letra3);
								}
								
								int x;
								printf("Sobre que fuente? Selecciona posicion en la lista de arriba, de 1 a %i:\n", nfuentes);
								scanf(" %i", &x);
								while(x < 1 || x > nfuentes) //bucle por si el usuario introduce un número incorrecto
								{
									printf("Selecciona una posicion valida\n");
									scanf(" %i", &x);
								}
								
								switch(letra3)
								{//switch de operaciones 2021
									case 'e':
										{
											printf("Maximo 2021: %f GWh\n\n", maximo(x-1, fuente, 1)); //imprime el valor máximo de una fuente
											break;
										}
									case 'f':
										{
											printf("Minimo 2021: %f GWh\n\n", minimo(x-1, fuente, 1)); //imprime el valor mínimo de una fuente
											break;
										}
									case 'g':
										{
											printf("Media 2021: %f GWh\n\n", mediaInd(x-1, fuente, 1)); //imprime la media de una fuente
											break;
										}
									case 'h':
										{
											printf("Total 2021: %f GWh\n\n", total(x-1, fuente, 1)); //imprime el total
											break;
										}
								}//switch de operaciones 2021
								printf("------------------------------\n");
								
								char otra;
								printf("Quieres hacer otra operacion?\n\tSi -y-\n\tNo -n-\n");
								scanf(" %c", &otra);
								while(otra != 'y' && otra != 'n') //bucle por si el usuario introduce una letra incorrecta
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
										
										while(letra4 != 'e' && letra4 != 'f' && letra4 != 'g' && letra4 != 'h' && letra4 != 's') //bucle por si el usuario introduce una letra incorrecta
										{
											printf("Elige una opcion valida:\n");
											scanf(" %c", &letra4);
										}
										if(letra4 == 's')
										{
											break; //si el usuario pulsa la letra 's', el programa sale del bucle do-while
										}
										
										int x;
										printf("Sobre que fuente? Selecciona posicion en la lista de arriba, de 1 a %i:\n", nfuentes);
										scanf(" %i", &x);
										while(x < 1 || x > nfuentes) //bucle por si el usuario introduce un número incorrecto
										{
											printf("Selecciona una posicion valida\n");
											scanf(" %i", &x);
										}
										
										switch(letra4)
										{//switch de operaciones 2021 BUCLE
											case 'e':
												{
													printf("Maximo 2021: %f GWh\n\n", maximo(x-1, fuente, 1)); //imprime el máximo de una fuente
													break;
												}
											case 'f':
												{
													printf("Minimo 2021: %f GWh\n\n", minimo(x-1, fuente, 1)); //imprime el mínimo de una fuente
													break;
												}
											case 'g':
												{
													printf("Media 2021: %f GWh\n\n", mediaInd(x-1, fuente, 1)); //imprime la media de una fuente
													break;
												}
											case 'h':
												{					
													printf("Total 2021: %f GWh\n\n", total(x-1, fuente, 1)); //imprime el total de una fuente
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
								
								while(letra5 != 'j' && letra5 != 'k') //bucle por si el usuario se equivoca que de letra
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
									for(i=0; i<=nfuentes; i++)
									{//llave de bucle for que muestra 2022
										printf("%i) %s\n", i+1, fuente[i].nombre); //determina un número para cada energía y el nombre del tipo de energía
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
									while(quehacer != 'c' && quehacer != 's') //bucle por si el usuario no pulsa la tecla correcta
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
											printf("Elige una opcion valida:\n"); //bucle por si el usuario no pulsa la tecla correcta
											scanf(" %c", &letra12);
										}
										
										int y;
										if(letra12 != 'x')
										{
											printf("Sobre que fuente? Selecciona posicion en la lista de arriba, de 1 a %i:\n", nfuentes);
											scanf(" %i", &y);
											while(y < 1 || y > nfuentes) //bucle por si el usuario no introduce el número correcto
											{
												printf("Selecciona una posicion valida\n");
												scanf(" %i", &y);
											}
										}
										
										switch(letra12)
										{//switch de operaciones 2022 y globales
											case 'e':
												{
													printf("Maximo 2022: %f GWh\n\n", maximo(y-1, fuente, 2)); //muestra el máximo de una fuente
													break;
												}
											case 'f':
												{
													printf("Minimo 2022: %f GWh\n\n", minimo(y-1, fuente, 2)); //muestra el mínimo de una fuente
													break;
												}
											case 'g':
												{
													printf("Media 2022: %f GWh\n\n", mediaInd(y-1, fuente, 2)); //muestra la media de una fuente
													break;
												}
											case 'h':
												{
													printf("Total 2022: %f GWh\n\n", total(y-1, fuente, 2)); //muestra el total de una fuente
													break;
												}
											case 'E':
												{
													printf("Maximo 2021-2022: %f GWh\n\n", maximo(y-1, fuente, 0)); //máximo de una fuente (dos años)
													break;
												}
											case 'F':
												{
													printf("Minimo 2021-2022: %f GWh\n\n", minimo(y-1, fuente, 0)); //mínimo de una fuente (dos años)
													break;
												}
											case 'G':
												{
													printf("Media 2021-2022: %f GWh\n\n", mediaInd(y-1, fuente, 0)); //media de una fuente (dos años)
													break;
												}
											case 'H':
												{
													printf("Total 2021-2022: %f GWh\n\n", total(y-1, fuente, 0)); //total de una fuente (dos años)
													break;
												}
											case 'x':
												{
													printf("Elige:\nTOTAL GLOBAL 2021 -1-\nTOTAL GLOBAL 2022 -2-\nTOTAL GLOBAL 2021-2022 -0-\n");
													int p;
													scanf(" %i", &p);
													while(p != 1 && p != 2 && p != 0) //bucle por si el usuario mo introduce el número que es 
													{
														printf("Elige una opcion valida");
														scanf(" %i", &p);
													}
													
													if(p == 1)
													{
														printf("Total GLOBAL 2021: %f GWh\n\n", totalglobal(fuente, 1, nfuentes)); //total global de 2021
													}
													else if(p == 2)
													{
														printf("Total GLOBAL 2022: %f GWh\n\n", totalglobal(fuente, 2, nfuentes)); //total global de 2022
													}
													else if(p == 0)
													{
														printf("Total GLOBAL 2021-2022: %f GWh\n\n", totalglobal(fuente, 0, nfuentes)); //total global de 2021 y 2022
													}
													break;
												}
										}//switch de operaciones 2022 y globales
										printf("------------------------------\n");
											
										char otra2;
										printf("Quieres hacer otra operacion?\n\tSi -y-\n\tNo -n-\n");
										scanf(" %c", &otra2);
										while(otra2 != 'y' && otra2 != 'n') //bucle por si el usuario no pulsa la tecla correcta
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
												printf("\t Max -e-\n\t Min -f-\n\tMedia -g-\n\tTotal -h-\n\t Operaciones globales(los dos anyos incluidos) -Igual pero letras en mayuscula-\n\t TOTAL GLOBAL DE TODAS LAS FUENTES SUMADAS -x-\n\t Salir -s-\n");
										
												scanf(" %c",&letra69);
												
												while(letra69 != 'e' && letra69 != 'f' && letra69 != 'g' && letra69 != 'h' && letra69 != 'E' && letra69 != 'F' && letra69 != 'G' && letra69 != 'H' && letra69 != 's' && letra69 != 'x' )
												{
													printf("Elige una opcion valida:\n"); //bucle por si el usuario no introduce la letra correcta
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
													while(z < 1 || z > nfuentes) //bucle por si el usuario no pulsa el número correcto
													{
														printf("Selecciona una posicion valida\n");
														scanf(" %i", &z);
													}
												}
											
												switch(letra69)
												{//switch de operaciones 2022 y globales BUCLE
													case 'e':
														{
															printf("Maximo 2022: %f GWh\n\n", maximo(z-1, fuente, 2)); //máximo de una fuente
															break;
														}
													case 'f':
														{
															printf("Minimo 2022: %f GWh\n\n", minimo(z-1, fuente, 2)); //mínimo de una fuente
															break;
														}
													case 'g':
														{
															printf("Media 2022: %f GWh\n\n", mediaInd(z-1, fuente, 2)); //media de una fuente
															break;
														}
													case 'h':
														{
															printf("Total 2022: %f GWh\n\n", total(z-1, fuente, 2)); //total de una fuente
															break;
														}
													case 'E':
														{
															printf("Maximo 2021-2022: %f GWh\n\n", maximo(z-1, fuente, 0)); //máximo de una fuente (dos años)
															break;
														}
													case 'F':
														{
															printf("Minimo 2021-2022: %f GWh\n\n", minimo(z-1, fuente, 0)); //mínimo de una fuente (dos años)
															break;
														}
													case 'G':
														{
															printf("Media 2021-2022: %f GWh\n\n", mediaInd(z-1, fuente, 0)); //media de una fuente (dos años)
															break;
														}
													case 'H':
														{
															printf("Total 2021-2022: %f GWh\n\n", total(z-1, fuente, 0)); //total de una fuente (dos años)
															break;
														}
													case 'x':
														{
															printf("Elige:\nTOTAL GLOBAL 2021 -1-\nTOTAL GLOBAL 2022 -2-\nTOTAL GLOBAL 2021-2022 -0-\n");
															int q;
															scanf(" %i", &q);
															while(q != 1 && q != 2 && q != 0) //bucle por si el usuario no introduce bien el número
															{
																printf("Elige una opcion valida");
																scanf(" %i", &q);
															}
															
															if(q == 1)
															{
																printf("Total GLOBAL 2021: %f GWh\n\n", totalglobal(fuente, 1, nfuentes)); //total global de 2021
															}
															else if(q == 2)
															{
																printf("Total GLOBAL 2022: %f GWh\n\n", totalglobal(fuente, 2, nfuentes)); //total global de 2022
															}
															else if(q == 0)
															{
																printf("Total GLOBAL 2021-2022: %f GWh\n\n", totalglobal(fuente, 0, nfuentes)); //total global de 2021 y 2022
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
	    						for(i=0; i<=nfuentes; i++) 
								{//lave del bucle for que muestra los datos de 2022
									//vector meses que vaya avanzando dentro del for
									printf("%i) %s\n", i+1, fuente[i].nombre); //determina un número para cada energía y el nombre del tipo de energía
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
									printf("Elige una opcion valida:\n"); //bucle por si el usuario no introduce bien la letra pedida
									scanf(" %c", &letra3);
								}
								
								int x;
								printf("Sobre que fuente? Selecciona posicion en la lista de arriba, de 1 a %i:\n", nfuentes);
								scanf(" %i", &x);
								while(x < 1 || x > nfuentes) //bucle por si el usuario introduce mal el número pedido
								{
									printf("Selecciona una posicion valida\n");
									scanf(" %i", &x);
								}
								
								switch(letra3)
								{//switch de operaciones 2022
									case 'e':
										{
											printf("Maximo 2022: %f GWh\n", maximo(x-1, fuente, 2)); //máximo de una fuente
											break;
										}
									case 'f':
										{
											printf("Minimo 2022: %f GWh\n", minimo(x-1, fuente, 2)); //mínimo de una fuente
											break;
										}
									case 'g':
										{
											printf("Media 2022: %f GWh\n", mediaInd(x-1, fuente, 2)); //media de una fuente
											break;
										}
									case 'h':
										{
											printf("Total 2022: %f GWh\n", total(x-1, fuente, 2)); //total de una fuente
											break;
										}
								}//switch de operaciones 2022
								printf("------------------------------\n");
								
								char otra;
								printf("Quieres hacer otra operacion?\n\tSi -y-\n\tNo -n-\n");
								scanf(" %c", &otra);
								while(otra != 'y' && otra != 'n') //bucle por si el usuario no pulsa la tecla adecuada
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
											printf("Elige una opcion valida:\n"); //bucle por si el usuario no introduce la letra indicada
											scanf(" %c", &letra4);
										}
										if(letra4 == 's')
										{
											break; //si el usuario elige 's', el programa sale del do-while
										}
										
										int x;
										printf("Sobre que fuente? Selecciona posicion en la lista de arriba, de 1 a %i:\n", nfuentes);
										scanf(" %i", &x);
										while(x < 1 || x > nfuentes) //bucle por si el usuario se equivoca
										{
											printf("Selecciona una posicion valida\n");
											scanf(" %i", &x);
										}
										
										switch(letra4)
										{//switch de operaciones 2022 BUCLE
											case 'e':
												{
													printf("Maximo 2022: %f GWh\n", maximo(x-1, fuente, 2)); //máximo de una fuente
													break;
												}
											case 'f':
												{
													printf("Minimo 2022: %f GWh\n", minimo(x-1, fuente, 2)); //mínimo de una fuente
													break;
												}
											case 'g':
												{
													printf("Media 2022: %f GWh\n", mediaInd(x-1, fuente, 2)); //media de una fuente
													break;
												}
											case 'h':
												{					
													printf("Total 2022: %f GWh\n", total(x-1, fuente, 2)); //total de una fuente
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
								
								while(letra5 != 'j' && letra5 != 'k') //bucle por si no se introduce bien la letra correspondiente
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
									for(i=0; i<=nfuentes; i++)
									{//llave de bucle for que muestra 2021
										printf("%i) %s\n", i+1, fuente[i].nombre); //determina un número para cada energía y el nombre del tipo de energía
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
									while(quehacer != 'c' && quehacer != 's') //bucle por si no se introduce la letra correspondiente
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
											printf("Elige una opcion valida:\n"); //bucle por si no se introduce la letra pedida
											scanf(" %c", &letra12);
										}
										
										int y;
										if(letra12 != 'x')
										{
											printf("Sobre que fuente? Selecciona posicion en la lista de arriba, de 1 a %i:\n", nfuentes);
											scanf(" %i", &y);
											while(y < 1 || y > nfuentes) //bucle por si no se introduce el número pedido
											{
												printf("Selecciona una posicion valida\n");
												scanf(" %i", &y);
											}
										}
										
										switch(letra12)
										{//switch de operaciones 2021 y globales
											case 'e':
												{
													printf("Maximo 2021: %f GWh\n", maximo(y-1, fuente, 1)); //máximo de una fuente 
													break;
												}
											case 'f':
												{
													printf("Minimo 2021: %f GWh\n", minimo(y-1, fuente, 1)); //mínimo de una fuente 
													break;
												}
											case 'g':
												{
													printf("Media 2021: %f GWh\n", mediaInd(y-1, fuente, 1)); //media de una fuente 
													break;
												}
											case 'h':
												{
													printf("Total 2021: %f GWh\n", total(y-1, fuente, 1)); //total de una fuente 
													break;
												}
											case 'E':
												{
													printf("Maximo 2021-2022: %f GWh\n", maximo(y-1, fuente, 0)); //máximo de una fuente (dos años)
													break;
												}
											case 'F':
												{
													printf("Minimo 2021-2022: %f GWh\n", minimo(y-1, fuente, 0)); //mínimo de una fuente (dos años)
													break;
												}
											case 'G':
												{
													printf("Media 2021-2022: %f GWh\n", mediaInd(y-1, fuente, 0)); //media de una fuente (dos años)
													break;
												}
											case 'H':
												{
													printf("Total 2021-2022: %f GWh\n", total(y-1, fuente, 0)); //total de una fuente (dos años)
													break;
												}
											case 'x':
												{
													printf("Elige:\nTOTAL GLOBAL 2021 -1-\nTOTAL GLOBAL 2022 -2-\nTOTAL GLOBAL 2021-2022 -0-\n");
													int p;
													scanf(" %i", &p);
													while(p != 1 && p != 2 && p != 0) //bucle por si el usuario se equivoca al introducir el número
													{
														printf("Elige una opcion valida");
														scanf(" %i", &p);
													}
													
													if(p == 1)
													{
														printf("Total GLOBAL 2021: %f GWh\n", totalglobal(fuente, 1, nfuentes)); //total global de 2021
													}
													else if(p == 2)
													{
														printf("Total GLOBAL 2022: %f GWh\n", totalglobal(fuente, 2, nfuentes)); //total global de 2022
													}
													else if(p == 0)
													{
														printf("Total GLOBAL 2021-2022: %f GWh\n", totalglobal(fuente, 0, nfuentes));  //total global de 2021 y 2022
													}
													break;
												}
										}//switch de operaciones 2021 y globales
										printf("------------------------------\n");
										
										char otra2;
										printf("Quieres hacer otra operacion?\n\tSi -y-\n\tNo -n-\n");
										scanf(" %c", &otra2);
										while(otra2 != 'y' && otra2 != 'n') //bucle por si el usuario se equivoca
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
												printf("\t Max -e-\n\t Min -f-\n\tMedia -g-\n\tTotal -h-\n\t Operaciones globales(los dos anyos incluidos) -Igual pero letras en mayuscula-\n\t TOTAL GLOBAL DE TODAS LAS FUENTES SUMADAS -x-\n\t Salir -s-\n");
										
												scanf(" %c",&letra69);
												
												while(letra69 != 'e' && letra69 != 'f' && letra69 != 'g' && letra69 != 'h' && letra69 != 'E' && letra69 != 'F' && letra69 != 'G' && letra69 != 'H' && letra69 != 's' && letra69 != 'x' )
												{
													printf("Elige una opcion valida:\n"); //bucle por si el usuario se equivoca
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
													while(z < 1 || z > nfuentes) //bucle por si el usuario se equivoca
													{
														printf("Selecciona una posicion valida\n");
														scanf(" %i", &z);
													}
												}
											
												switch(letra69)
												{//switch de operaciones 2021 y globales BUCLE
													case 'e':
														{
															printf("Maximo 2021: %f GWh\n", maximo(z-1, fuente, 1)); //máximo de una fuente
															break;
														}
													case 'f':
														{
															printf("Minimo 2021: %f GWh\n", minimo(z-1, fuente, 1)); //mínimo de una fuente
															break;
														}
													case 'g':
														{
															printf("Media 2021: %f GWh\n", mediaInd(z-1, fuente, 1)); //media de una fuente
															break;
														}
													case 'h':
														{
															printf("Total 2021: %f GWh\n", total(z-1, fuente, 1)); //total de una fuente
															break;
														}
													case 'E':
														{
															printf("Maximo 2021-2022: %f GWh\n", maximo(z-1, fuente, 0)); //máximo de una fuente (dos años)
															break;
														}
													case 'F':
														{
															printf("Minimo 2021-2022: %f GWh\n", minimo(z-1, fuente, 0)); //mínimo de una fuente (dos años)
															break;
														}
													case 'G':
														{
															printf("Media 2021-2022: %f GWh\n", mediaInd(z-1, fuente, 0)); //media de una fuente (dos años)
															break;
														}
													case 'H':
														{
															printf("Total 2021-2022: %f GWh\n", total(z-1, fuente, 0)); //total de una fuente (dos años)
															break;
														}
													case 'x':
														{
															printf("Elige:\nTOTAL GLOBAL 2021 -1-\nTOTAL GLOBAL 2022 -2-\nTOTAL GLOBAL 2021-2022 -0-\n");
															int q;
															scanf(" %i", &q);
															while(q != 1 && q != 2 && q != 0) //bucle por si el usuario se equivoca
															{
																printf("Elige una opcion valida");
																scanf(" %i", &q);
															}
															
															if(q == 1)
															{
																printf("Total GLOBAL 2021: %f GWh\n", totalglobal(fuente, 1, nfuentes)); //total global de 2021
															}
															else if(q == 2)
															{
																printf("Total GLOBAL 2022: %f GWh\n", totalglobal(fuente, 2, nfuentes)); //total global de 2022
															}
															else if(q == 0)
															{
																printf("Total GLOBAL 2021-2022: %f GWh\n", totalglobal(fuente, 0, nfuentes)); //total global de 2021 y 2022
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
	if(x==1) //calcula la media para 2021
	{
		for(i=0; i<12; i++)
		{
			suma = suma + vector_fuente[numfuente].gwh[i];
			//suma los datos de enero a diciembre de 2021
		}
		media = suma/12; //divide la suma obtenida entre los meses de 2021
	}
	else if(x==2) //media para 2022
	{
		for(i=12; i<24; i++)
		{
			suma = suma + vector_fuente[numfuente].gwh[i];
			//suma los datos de enero a diciembre de 2022
		}
		media = suma/12; //divide la suma obtenida entre los meses de 2022
	}
	else if(x=0) //media para los dos años
	{
		for(i=0; i<24; i++)
		{
			suma = suma + vector_fuente[numfuente].gwh[i];
			//suma los datos de 2021 y 2022
		}
		media = suma/24; //divide la suma obtenida entre 2021 y 2022 juntos
	}
	return media; //devuelve el valor "media"
}

//función máximo de una fuente
float maximo(int numfuente, energia vector_fuente[], int x)
{
	int i;
	float max=0; //declara un valor como 0 para determinar el máximo
	if(x==1) //Máximo para 2021
	{
		for(i=0; i<12; i++)
		{
			if(vector_fuente[numfuente].gwh[i] > max)
			{
				max = vector_fuente[numfuente].gwh[i];
				//si max es menor que vector_fuente, max queda declarado como el valor de vector_fuente
			}
			//recorre los 12 meses buscando el valor máximo
		}
	}
	else if(x==2) //máximo para 2022
	{
		for(i=12; i<24; i++)
		{
			if(vector_fuente[numfuente].gwh[i] > max)
			{
				max = vector_fuente[numfuente].gwh[i];
			}
			//recorre los 12 meses buscando el valor máximo
		}
	}
	else if(x==0) //máximo para los dos años
	{
		for(i=0; i<24; i++)
		{
			if(vector_fuente[numfuente].gwh[i] > max)
			{
				max = vector_fuente[numfuente].gwh[i];
			}
			//recorre 24 meses buscando el valor máximo
		}
	}
	return max; //devuelve el valor "máximo"
}

//función mínimo de una fuente
float minimo(int numfuente, energia vector_fuente[], int x)
{
	int i;
	float min=vector_fuente[numfuente].gwh[0]; //declara como mínimo el primer vector
	if(x==1) //mínimo para 2021
	{
		for(i=0; i<12; i++)
		{
			//recorre los 12 meses de 2021 para encontrar el vector más pequeño
			if(vector_fuente[numfuente].gwh[i] < min)
			{
				min = vector_fuente[numfuente].gwh[i];
				//si un vector_fuente es más pequeño que min, este vector queda declarado como min
			}
		}
	}
	else if(x==2) //mínimo para 2022
	{
		for(i=12; i<24; i++)
		{
			//recorre 2022 para encontrar el vector más pequeño
			if(vector_fuente[numfuente].gwh[i] < min)
			{
				min = vector_fuente[numfuente].gwh[i];
				//si un vector_fuente es más pequeño que min, este vector queda declarado como min
			}
		}
	}
	else if(x==0) //mínimo de los dos años
	{
		for(i=0; i<24; i++)
		{
			//recorre 2021 y 2022 para encontrar el vector más pequeño
			if(vector_fuente[numfuente].gwh[i] < min)
			{
				min = vector_fuente[numfuente].gwh[i];
				//si un vector_fuente es más pequeño que min, este vector queda declarado como min
			}
		}
	}
	return min; //devuelve el valor "min"
}

//función total de una determinada fuente
float total(int numfuente, energia vector_fuente[], int x)
{
	int i;
	float suma=0; //inicia el contador de la suma en 0
	if(x==1) //total de 2021
	{
		for(i=0; i<12; i++)
		{
			//recorre los 12 meses del año para sumar todos los vectores
			suma = suma + vector_fuente[numfuente].gwh[i];
		}
	}
	else if(x==2) //total de 2022
	{
		for(i=12; i<24; i++)
		{
			//recorre los 12 meses del año para sumar todos los vectores
			suma = suma + vector_fuente[numfuente].gwh[i];
		}
	}
	else if(x==0) //total de los dos años
	{
		for(i=0; i<24; i++)
		{
			//recorre los dos años para sumar todos los vectores
			suma = suma + vector_fuente[numfuente].gwh[i];
		}
	}
	return suma; //devuelve el valor "suma"
}

//función total global (suma de los datos de todas las fuentes)
float totalglobal(energia vector_fuente[], int x, int nfuentes)
{//tambien se puede hacer esta funcion sumando las columnas de la fila 'Generacion total'
	float totalGlob=0;
	int i;
	if(x==1) //suma de las fuentes de 2021
	{
		for(i=0; i<nfuentes-1; i++)
		{
			//usando la función suma, calcula la suma total recorriendo todos los meses de 2021
			totalGlob = totalGlob + total(i, vector_fuente, 1);
		}
	}
	else if(x==2) //suma de las fuentes de 2022
	{
		for(i=0; i<nfuentes-1; i++)
		{
			//usando la función suma, calcula la suma total recorriendo todos los meses de 2022
			totalGlob = totalGlob + total(i, vector_fuente, 2);
		}
	}
	else if(x==0) //suma de las fuentes de 2021 y 2022
	{
		for(i=0; i<nfuentes-1; i++)
		{
			//usando la función suma, calcula la suma total de los dos años
			totalGlob = totalGlob + total(i, vector_fuente, 0);
		}
	}
	return totalGlob; //devuelve el valor "total global"
}
