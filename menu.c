#include<stdio.h>
int main()
{
    char letra, final, op;
    printf("¿Que quieres hacer?\n Pulsa la tecla correspondiente a la accion que quieres realizar\n");
    printf("Mostrar datos: -a- \n");
    printf("Realizar operaciones: -b- \n");
    printf("Salir: -c- \n");
    scanf(" %c",&letra);

    switch (letra)
    {
        case ('a'):
        {
            printf("Has seleccionado 'Mostrar datos'\n");
            //
            printf("Deseas hacer alguna otra operacion?\n");
            //
            printf("-s- Si\n");
            printf("-n- No\n");
            scanf(" %c",&final);
            switch (final)
            {
                case ('s'):
                {
                    {
                    printf("Pulsa la tecla correspondiente a la accion que quieres realizar\n");
                    printf("Mostrar datos: -a- \n");
                    printf("Realizar operaciones: -b- \n");
                    printf("Salir: -c- \n");
                    scanf(" %c",&letra);
                    switch (letra)
                        {
                            case ('a'):
                            {
                                printf("Has seleccionado 'Mostrar datos'\n");
                                //
                            }break;
                            case ('b'):
                            {
                                printf("Has seleccionado 'Realizar operaciones'\n");
                                printf("Que operacion quieres realizar?\n");
                                printf("Max: -q- \n");
                                printf("Min: -w- \n");
                                printf("Media: -e- \n");
                                printf("Media (global): -r- \n");
                                printf("Comparar energias: -t- \n");
                                scanf(" %c",&op);
                                switch (op)
                                {
                                case ('q'):
                                    {
                                        printf("Has seleccionado 'Max'\n");
                                        //
                                    }
                                    break;
                                case ('w'):
                                {
                                    printf("Has seleccionado 'Min'\n");
                                    //calcular el min
                                }
                                    break;
                                case ('e'):
                                {
                                    printf("Has seleccionado 'Media'\n");
                                    //calcular la media
                                }
                                    break;
                                case ('r'):
                                {
                                    printf("Has seleccionado 'Media (global)'\n");
                                    //calcular la media global
                                }
                                    break;
                                case ('t'):
                                {
                                    printf("Has seleccionado 'Comparar energias'\n");
                                    //comparar energías
                                }
                                    break;
                                }
                            }break;
                            case ('c'):
                            {
                                printf("¡Gracias por utilizar nuestro programa!\n");
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
                }break;
                case ('n'):
                {
                    printf("Gracias por utilizar el programa!");
                }break;
            }
        }break;
        case ('b'):
        {
            printf("Has seleccionado 'Realizar operaciones'\n");
            printf("Que operacion quieres realizar?\n");
            printf("Max: -q- \n");
            printf("Min: -w- \n");
            printf("Media: -e- \n");
            printf("Media (global): -r- \n");
            printf("Comparar energias: -t- \n");
            scanf(" %c",&op);
            switch (op)
            {
            case ('q'):
            {
                printf("Has seleccionado 'Max'\n");
                //calcular el maximo
            }
                break;
            case ('w'):
            {
                printf("Has seleccionado 'Min'\n");
                //calcular el min
            }
                break;
            case ('e'):
            {
                printf("Has seleccionado 'Media'\n");
                //calcular la media
            }
                break;
            case ('r'):
            {
                printf("Has seleccionado 'Media (global)'\n");
                //calcular la media global
            }
                break;
            case ('t'):
            {
                printf("Has seleccionado 'Comparar energias'\n");
                //comparar energías
            }
                break;
            }
            printf("Deseas hacer alguna otra operacion?\n");
            printf("-s- Sí\n");
            printf("-n- No\n");
            scanf(" %c",&final);
            switch (final)
            {
                case ('s'):
                {
                    do
                    {
                    printf("Pulsa la tecla correspondiente a la accion que quieres realizar\n");
                    printf("Mostrar datos: -a- \n");
                    printf("Realizar operaciones: -b- \n");
                    printf("Salir: -c- \n");
                    scanf(" %c",&letra);
                    switch (letra)
                        {
                            case ('a'):
                            {
                                printf("Has seleccionado 'Mostrar datos'\n");
                                //
                            }
                            break;
                            case ('b'):
                            {
                                printf("Has seleccionado 'Realizar operaciones'\n");
                                printf("Que operacion quieres realizar?\n");
                                printf("Max: -q- \n");
                                printf("Min: -w- \n");
                                printf("Media: -e- \n");
                                printf("Media (global): -r- \n");
                                printf("Comparar energias: -t- \n");
                                scanf(" %c",&op);
                                switch (op)
                                {
                                case ('q'):
                                {
                                    printf("Has seleccionado 'Max'\n");
                                    //calcular el maximo
                                }
                                    break;
                                case ('w'):
                                {
                                    printf("Has seleccionado 'Min'\n");
                                    //calcular el min
                                }
                                    break;
                                case ('e'):
                                {
                                    printf("Has seleccionado 'Media'\n");
                                    //calcular la media
                                }
                                    break;
                                case ('r'):
                                {
                                    printf("Has seleccionado 'Media (global)'\n");
                                    //calcular la media global
                                }
                                    break;
                                case ('t'):
                                {
                                    printf("Has seleccionado 'Comparar energias'\n");
                                    //comparar energías
                                }
                                    break;
                                }
                            }break;
                            case ('c'):
                            {
                                printf("¡Gracias por utilizar nuestro programa!\n");
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
                    } while (final != 'n' && letra != 'a' && letra != 'b');
                    if(letra = 's')
                    {
                        printf("Si quieres realizar otra operacion, reinicia el programa");
                    }
                }break;
                case ('n'):
                {
                    printf("Gracias por utilizar el programa!");
                }break;
            }
        }break;
        case ('c'):
        {
            printf("¡Gracias por utilizar nuestro programa!");
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
    
}
    return 0;
}
            printf("Gracias por utilizar el programa!");
        }break;
    }
    return 0;
}
