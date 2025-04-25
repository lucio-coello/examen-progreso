// Examen 1 - Programación 1
#include <stdio.h>
#include <string.h>

char nombres [5] [20];
float tiempos [5] [3];
int i, j, k, mejorTiempo = 0, nadadorGanador = 0, competenciaGanadora = 0, resultado = 0, cantidadNadadores = 0;
int opciones;
int nadadorMejorTiempo = 0;

int main(){
 do {
    printf("Identificador de ganadores \n");
    printf("1. Ingresar datos de los nadadores \n");
    printf("2. Mostrar ganadores \n");
    printf("3. Salir \n");
    printf(">> ");
    scanf("%d", &opciones);
    switch (opciones){
    case 1:
    do
    {
        printf("ingrese la cantidad de nadadores: \n");
        cantidadNadadores = scanf("%d", &i);
     if (cantidadNadadores != 1 || i > 5 || i < 0)
     {
        printf("la cantidad permitida de nadadores es 5, porfavor ingrese nuevamente los datos. \n");
        while(getchar() != '\n');
        cantidadNadadores = 0;
     }else{
        for (i = 0; i < 5; i++) 
        {
            printf("ingrese el nombre del nadador %d: ", i + 1);
            scanf("%s", nombres[i]);
            while (getchar() != '\n');
            for (j = 0; j < 3; j++)
            {
                do
                {
                    printf("ingrese el tiempo de la competencia %d: ", j + 1);
                    resultado = scanf("%f", &tiempos[i][j]);
                    if ( resultado !=1 || tiempos[i][j] < 0)
                    {
                        printf("el tiempo no es valido\n");
                        while(getchar() != '\n');
                    }else{
                        printf("tiempo guardado exitosamente\n");
                        while(getchar() != '\n');
                    }
                } while (resultado != 1 || tiempos[i][j] < 0);
            }
        }
     }

     case 2:
        printf("los ganadores son: \n");
        for (i = 0; i < 5; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (tiempos[i][j] < mejorTiempo || mejorTiempo == 0)
                {
                    mejorTiempo = tiempos[i][j];
                    nadadorGanador = i + 1;
                    competenciaGanadora = j + 1;
                }
            }
        }
        printf("el ganador es el nadador %d en la competencia %d con un tiempo de %e segundos\n", nadadorGanador, competenciaGanadora, mejorTiempo);
        break;
      
    
    } while (i > 5 || i < 0);
    
    }
 } while (opciones !=3);
 
 return 0;
}
