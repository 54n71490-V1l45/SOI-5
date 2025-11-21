/*
Autores:
    Sergio Nuñez
        y
    Santiago Vilas Pampín
*/
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