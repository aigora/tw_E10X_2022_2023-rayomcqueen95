#include<stdio.h>
int main()
{
    char letra, final, op;
    printf("Que quieres hacer?\n \n");
    printf("\t      Mostrar datos: -a- \n");
    printf("\t  Realizar operaciones: -b- \n");
    printf("\t \t Salir: -c- \n \n");
    printf("Pulsa la tecla (minuscula) correspondiente a la accion que quieres realizar: ");
    scanf(" %c",&letra);
    switch (letra)
    {
        case ('a'):
        {
            printf("\nHas seleccionado 'Mostrar datos'\n");
            printf("\nDe que anyo quieres ver los datos?\n(Introduce el anyo correspondiente)\n");
            printf("\t-2021-\n");
            printf("\t-2022-\n");
            scanf(" %i",&datos);
            switch(datos)
            {
            	case(2021):
            		{
            			printf("(Printf de prueba para ver que funcione el case de 2021)\n");
            			//código para mostrar los datos de 2021
					}break;
				case(2022):
					{
						printf("(Printf de prueba para ver que funcione el case de 2022)\n");
            			//código para mostrar los datos de 2022
					}break;
				default:
					{
						do
		                {
		                    printf("Pulsa el numero correspondiente al anyo del cual quieres ver los datos\n");
		                    scanf(" %i", &datos);
		                } while (datos != 2021 && datos != 2022);
					}	
			}
            // no sé si lo podremos hacer o no pero por si acaso lo dejo
            // me imagino que le puedo preguntar al usuario qué datos quiere ver con los datos almacenados
            printf("Deseas hacer alguna otra operacion?\n");
            printf("\t-s- Si\n");
            printf("\t-n- No\n");
            scanf(" %c", &final);
            switch (final)
            {
                case ('s'):
                {
                    printf("\nPulsa la tecla (minuscula) correspondiente a la accion que quieres realizar\n");
                    printf("\t      Mostrar otro dato: -a- \n");
                    printf("\t     Realizar operaciones: -b- \n");
                    printf("\tMe equivoque de tecla, quiero salir: -c- \n");
                    scanf(" %c",&letra);
                    switch (letra)
                        {
                            case ('a'):
                            {
                                printf("Has seleccionado 'Mostrar otro dato'\n");
                                //
                                printf("\n \tGracias por utilizar nuestro programa!");
                            }break;
                            case ('b'):
                            {
                                printf("Has seleccionado 'Realizar operaciones'\n");
                                printf("\nQue operacion quieres realizar?\n");
                                printf(" \t       Max: -q- \n");
                                printf(" \t       Min: -w- \n");
                                printf(" \t      Media: -e- \n");
                                printf("\t   Media (global): -r- \n");
                                printf("\tComparar energias: -t- \n");
                                printf("\nPulsa la tecla (minuscula) correspondiente a la accion que quieres realizar\n");
                                scanf(" %c",&op);
                                switch (op)
                                {
                                case ('q'):
                                    {
                                        printf("Has seleccionado 'Max'\n");
                                        //calcular el maximo
                                        printf("\n \tGracias por utilizar nuestro programa!");
                                    }break;
                                case ('w'):
                                {
                                    printf("Has seleccionado 'Min'\n");
                                    //calcular el min
                                    printf("\n \tGracias por utilizar nuestro programa!");
                                }break;
                                case ('e'):
                                {
                                    printf("Has seleccionado 'Media'\n");
                                    //calcular la media
                                    printf("\n \tGracias por utilizar nuestro programa!");
                                }break;
                                case ('r'):
                                {
                                    printf("Has seleccionado 'Media (global)'\n");
                                    //calcular la media global
                                    printf("\n \tGracias por utilizar nuestro programa!");
                                }break;
                                case ('t'):
                                {
                                    printf("Has seleccionado 'Comparar energias'\n");
                                    //comparar energías
                                    printf("\n \tGracias por utilizar nuestro programa!");
                                }break;
                                }
                            }break;
                            case ('c'):
                            {
                                printf("\nGracias por utilizar nuestro programa!\n");
                            }break;
                        }
                }break;
                case ('n'):
                {
                    printf("\nGracias por utilizar nuestro programa!");
                }
            }
        }break;
        case ('b'):
        {
        	 printf("\nHas seleccionado 'Realizar operaciones'\n");
            printf(" \t       Max: -q- \n");
            printf(" \t       Min: -w- \n");
            printf(" \t      Media: -e- \n");
            printf("\t   Media (global): -r- \n");
            printf("\tComparar energias: -t- \n");
            printf("\nPulsa la tecla (minuscula) correspondiente a la accion que quieres realizar: ");
            scanf(" %c", &op);
            switch(op)
            {
                case ('q'):
                    {
                        printf("\nHas seleccionado 'Max'\n");
                        // código para el maximo
                        printf("\n \tGracias por usar el programa!\nSi quieres hacer otra operacion reinicia el programa.");
                    }break;
                case ('w'):
                    {
                        printf("\nHas seleccionado 'Min'\n");
                        // código para el minimo
                        printf("\n \tGracias por usar el programa!\nSi quieres hacer otra operacion reinicia el programa.");
                    }break;
                case ('e'):
                    {
                        printf("\nHas seleccionado 'Media'\n");
                        // código para la media
                        printf("\n \tGracias por usar el programa!\nSi quieres hacer otra operacion reinicia el programa.");
                    }break;
                case ('r'):
                    {
                        printf("\nHas seleccionado 'Media(global)'\n");
                        // código para la media (global)
                        printf("\n \tGracias por usar el programa!\nSi quieres hacer otra operacion reinicia el programa.");
                    }break;
                case ('t'):
                    {
                        printf("\nHas seleccionado 'Comparar energias'\n");
                        // código para comparar las energias
                        printf("\n \tGracias por usar el programa!\nSi quieres hacer otra operacion reinicia el programa.");
                    }break;
            }
        }break;
        case ('c'):
        {
            printf("\nGracias por usar el programa!");
        }break;
        default:
        {
            do
                {
                    printf("Pulsa la tecla correspondiente a la accion que quieres realizar \n");
                    scanf(" %c", &letra);
                } while (letra != 'a' && letra != 'b' && letra != 'c');
        }
    }
    return 0;
}
