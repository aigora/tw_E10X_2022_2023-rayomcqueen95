#include <stdio.h>
#include <string.h>
#define MAX_LINE_LENGTH 1024

void abrirArchivo();
void mostrarContenidoArchivo(const char* archivo);
void calcularMaximoEnergia(const char* tipoEnergia);
void calcularMaximo();

int main() {
    int opcion;
    char tipoEnergia[50];

    do {
        printf("Menu:\n");
        printf("1. Abrir un archivo\n");
        printf("2. Calcular el dato de generacion maxima del tipo de energia deseado\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                abrirArchivo();
                break;
            case 2:
                printf("\nIngrese el tipo de Energía: ");
                scanf("%s", tipoEnergia);
                calcularMaximoEnergia(tipoEnergia);
                break;
            case 3:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción inválida. Por favor, seleccione una opción válida.\n");
        }

        printf("\n");
    } while (opcion != 3);

    return 0;
}

void abrirArchivo() {
    mostrarContenidoArchivo("datos.csv");
}

void mostrarContenidoArchivo(const char* archivo) {
    FILE* file = fopen(archivo, "r");
    if (file == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    char linea[MAX_LINE_LENGTH];
    while (fgets(linea, MAX_LINE_LENGTH, file) != NULL) {
        printf("%s", linea);
    }

    fclose(file);
}

void calcularMaximoEnergia(const char* tipoEnergia) {
    FILE* archivoEntrada = fopen("datos.csv", "r");
    if (archivoEntrada == NULL) {
        printf("No se pudo abrir el archivo de entrada.\n");
        return;
    }

    FILE* archivoSalida = fopen("resultados.txt", "a");
    if (archivoSalida == NULL) {
        printf("No se pudo abrir el archivo de salida.\n");
        fclose(archivoEntrada);
        return;
    }

    char linea[MAX_LINE_LENGTH];
    while (fgets(linea, MAX_LINE_LENGTH, archivoEntrada) != NULL) {
        char* token = strtok(linea, ",");
        if (strcasecmp(token, tipoEnergia) == 0) {
            int maximo = 0;
            while ((token = strtok(NULL, ",")) != NULL) {
                int valor = atoi(token);
                if (valor > maximo) {
                    maximo = valor;
                }
            }

            fprintf(archivoSalida, "El máximo de generación para %s es: %d\n", tipoEnergia, maximo);
            fclose(archivoEntrada);
            fclose(archivoSalida);
            printf("El resultado se ha guardado en el archivo resultados.txt.\n");
            return;
        }
    }

    printf("Tipo de energía no encontrada.\n");
    fclose(archivoEntrada);
    fclose(archivoSalida);
}

void calcularMaximo() {
    char tipoEnergia[50];
    printf("Ingrese el tipo de Energía: ");
    scanf("%s", tipoEnergia);
    calcularMaximoEnergia(tipoEnergia);
}


