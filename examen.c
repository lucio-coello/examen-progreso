#include <stdio.h>
#include <string.h>

char nombres [5] [20];
float tiempos [5] [3];
int i, j, k, mejorTiempo = 0, nadadorGanador = 0, competenciaGanadora = 0, resultado = 0, cantidadNadadores = 0;
int opciones;
int nadadorMejorTiempo = 0;
int main() {
    do {
        printf("Identificador de ganadores\n");
        printf("1. Ingresar datos de los nadadores\n");
        printf("2. Mostrar ganadores\n");
        printf("3. Salir\n");
        printf(">> ");
        scanf("%d", &opciones);
        getchar(); 
        switch (opciones) {
        case 1:
            do {
                printf("Ingrese la cantidad de nadadores (maximo 5): ");
                resultado = scanf("%d", &cantidadNadadores);
                getchar(); 

                if (resultado != 1 || cantidadNadadores < 1 || cantidadNadadores > 5) {
                    printf("Cantidad invalida. Intente nuevamente.\n");
                    cantidadNadadores = 0;
                }
            } while (cantidadNadadores == 0);

            for (i = 0; i < cantidadNadadores; i++) {
                printf("Ingrese el nombre del nadador %d: ", i + 1);
                scanf("%19s", nombres[i]);
                getchar();

                for (j = 0; j < 3; j++) {
                    do {
                        printf("Ingrese el tiempo en competencia %d: ", j + 1);
                        resultado = scanf("%f", &tiempos[i][j]);
                        getchar(); 

                        if (resultado != 1 || tiempos[i][j] < 0) {
                            printf("Tiempo invalido. Intente de nuevo.\n");
                        }
                    } while (resultado != 1 || tiempos[i][j] < 0);
                }
            }
            break;

        case 2:
            if (cantidadNadadores == 0) {
                printf("Primero debe ingresar los datos de los nadadores.\n");
            } else {
                mejorTiempo = tiempos[0][0];
                nadadorGanador = 0;
                competenciaGanadora = 0;

                for (i = 0; i < cantidadNadadores; i++) {
                    for (j = 0; j < 3; j++) {
                        if (tiempos[i][j] < mejorTiempo) {
                            mejorTiempo = tiempos[i][j];
                            nadadorGanador = i;
                            competenciaGanadora = j;
                        }
                    }
                }
                printf("El ganador es %s en la competencia %d con un tiempo de %.2f segundos.\n",
                    nombres[nadadorGanador], competenciaGanadora + 1, mejorTiempo);
            }
            break;

        case 3:
            printf("Saliendo del programa...\n");
            break;

        default:
            printf("Opcion invalida. Intente nuevamente.\n");
        }
    } while (opciones != 3);
    

    return 0;
}
