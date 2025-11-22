/*
Autores:
    Sergio Nuñez
        y
    Santiago Vilas Pampín
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    printf("Programa hijo ejecutando\n");
    printf("Mi PID sigue siendo: %d (mismo que antes)\n", getpid());
    printf("Pulsa ENTER para terminar el hijo...\n");
    scanf("%*c");
    exit(0);
}