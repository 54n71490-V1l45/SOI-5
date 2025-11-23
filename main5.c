/*
Autores:
    Sergio Núñez
        y
    Santiago Vilas Pampín
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

/*
Usado para la compilación estática:
gcc -Wall -o main5static main5.c -static -lm

Usado para la compilación dinámica:
gcc -Wall -o main5 main5.c -lm
*/


//Pasamos un argumento (argc) para que el compilador no pueda predecir el valor
int main(int argc, char *argv[]) {
    double valor = 1.0;
    
    //Si pasamos un número al ejecutar, lo usamos. Si no, usamos 1.0
    if (argc > 1) {
        valor = atof(argv[1]);
    }

    printf("PID: %d\n", getpid());
    
    //Usamos pow además de sin para asegurar dependencia de libm
    double resultado = sin(valor) + pow(valor, 2.0);
    
    printf("Operación con math.h (sin + pow) sobre %.2f = %f\n", valor, resultado);
    
    printf("Pulsa ENTER para terminar...\n");
    scanf("%*c"); 
    
    exit(0);
}