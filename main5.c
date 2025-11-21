//
// Ejercicio 5
//

/*Comprueba lo que ocurre cuando un proceso, con una función matemática como sin, se compila
para que enlace la librería matemática de forma estática y cuando lo hace de forma dinámica.
Consulta el manual del compilador para ver qué significa esto y cómo hacerlo. Compara los
mapas de memoria.*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
int main() {
    printf("PID: %d\n", getpid());
    printf("sin(0) = %f\n", sin(0.0));
    scanf("%*c");
    exit(0);
}