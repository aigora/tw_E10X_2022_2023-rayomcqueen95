int main()
{
    char letra, final;
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
            //código para leer los datos
        }break;
        case ('b'):
        {
            printf("Has seleccionado 'Realizar operaciones'");
            //código para las operaciones
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
			            //código para leer los datos
			        }break;
			        case ('b'):
			        {
			            printf("Has seleccionado 'Realizar operaciones'\n");
			            //código para las operaciones
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
                 printf("Deseas hacer alguna otra operacion?\n");
                printf("-s- Si\n");
                printf("-n- No\n");
                scanf(" %c",&final);
                if(final='n')
                {
                	printf("Gracias por usar el programa!");
				}
            } while (final != 'n' && letra != 'a' && letra != 'b');
        }break;
        case ('n'):
        {
            printf("Gracias por utilizar el programa!");
        }break;
    }
    return 0;
}
