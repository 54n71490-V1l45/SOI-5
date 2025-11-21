#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    printf("PID: %d\n", getpid());
    scanf("%*c");
    int *a = malloc(100 * sizeof(int));
    if (!a){
        printf("Error en la reserva de memoria\n");
        exit(1);
    }
    printf("Direccion de memoria del bloque reservado con malloc: %p\n", a);
    printf("Últioma direccion de memoria del bloque reservado con malloc: %p\n", &a[99]);
    scanf("%*c");

    int *c = malloc(1000 * sizeof(int));
    if (!c){
        printf("Error en la reserva de memoria\n");
        exit(1);
    }
    printf("Direccion de memoria del bloque reservado con malloc: %p\n", c);
    printf("Última direccion de memoria del bloque reservado con malloc: %p\n", &c[999]);
    scanf("%*c");

    free(a);
    free(c);
    scanf("%*c");

    int *e = alloca(20000 * sizeof(int));
    if (!e){
        printf("Error en la reserva de memoria\n");
        exit(1);
    }
    printf("Direccion de memoria del bloque reservado con alloca: %p\n", e);
    printf("Última Direccion de memoria del bloque reservado con alloca: %p\n", &e[19999]);
    

    scanf("%*c");
    int *f = malloc(20000 * sizeof(int));
    if(!f){
        printf("Error en la reserva de memoria\n");
        exit(1);
    }
    
    printf("Direccion de memoria del bloque reservado con malloc: %p\n", f);
    printf("Última direccion de memoria del bloque reservado con malloc: %p\n", &f[19999]);
    scanf("%*c");

    f = realloc(c, 40000 * sizeof(int));
    if(!f){
        printf("Error en la reserva de memoria\n");
        exit(1);
    }
    printf("Direccion de memoria del bloque reservado con realloc: %p\n", f);
    printf("Última direccion de memoria del bloque reservado con realloc: %p\n", &f[39999]);
    scanf("%*c");
    free(f);

    scanf("%*c");
    int *b = malloc(1000 * sizeof(double));
    if(!b){
        printf("Error en la reserva de memoria\n");
        exit(1);
    }
    printf("Tamaño del puntero de malloc para double: %lu bytes\n", sizeof(*b));
    printf("Direccion de memoria del bloque reservado con malloc: %p\n", b);
    printf("ultioma Direccion de memoria del bloque reservado con malloc: %p\n", &b[999]);
    scanf("%*c");
    free(b);
    scanf("%*c");
    return 0;
    
}