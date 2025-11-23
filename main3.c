/*
Autores:
    Sergio Nuñez
        y
    Santiago Vilas Pampín
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <alloca.h> 

int main(){
    printf("PID: %d\n", getpid());
    scanf("%*c");

    //1. MALLOC PEQUEÑO
    int *a = malloc(100 * sizeof(int));
    if (!a){
        printf("Error en la reserva de memoria\n");
        exit(1);
    }
    printf("Direccion de memoria del bloque reservado con malloc (pequeño): %p\n", a);
    printf("Última direccion de memoria del bloque reservado con malloc: %p\n", &a[99]);
    scanf("%*c");

    //2. MALLOC MEDIANO
    int *c = malloc(1000 * sizeof(int));
    if (!c){
        printf("Error en la reserva de memoria\n");
        exit(1);
    }
    printf("Direccion de memoria del bloque reservado con malloc (mediano): %p\n", c);
    printf("Última direccion de memoria del bloque reservado con malloc: %p\n", &c[999]);
    scanf("%*c");

    //3. FREE
    free(a);
    free(c);
    scanf("%*c");

    //4. ALLOCA (STACK)
    int *e = alloca(20000 * sizeof(int));
    if (!e){
        printf("Error en la reserva de memoria\n");
        exit(1);
    }
    printf("Direccion de memoria del bloque reservado con alloca: %p\n", e);
    printf("Última Direccion de memoria del bloque reservado con alloca: %p\n", &e[19999]);
    
    scanf("%*c");

    //5. MALLOC GRANDE Y REALLOC
    int *f = malloc(20000 * sizeof(int));
    if(!f){
        printf("Error en la reserva de memoria\n");
        exit(1);
    }
    
    printf("Direccion de memoria del bloque reservado con malloc (antes del realloc): %p\n", f);
    printf("Última direccion de memoria del bloque reservado con malloc: %p\n", &f[19999]);
    scanf("%*c");

    int *temp = realloc(f, 40000 * sizeof(int)); 
    if(!temp){
        printf("Error en la reserva de memoria\n");
        exit(1);
    }
    f = temp; //Actualizamos el puntero f

    printf("Direccion de memoria del bloque reservado con realloc: %p\n", f);
    printf("Última direccion de memoria del bloque reservado con realloc: %p\n", &f[39999]);
    scanf("%*c");
    free(f);

    scanf("%*c");

    //6. PRUEBA DESTRUCTIVA (BAD FREE)
    double *b = malloc(1000 * sizeof(double));
    if(!b){
        printf("Error en la reserva de memoria\n");
        exit(1);
    }
    printf("Tamaño del puntero de malloc para double: %lu bytes\n", sizeof(b)); //Tamaño del puntero (8 bytes)
    printf("Direccion de memoria del bloque reservado con malloc: %p\n", b);
    printf("Última Direccion de memoria del bloque reservado con malloc: %p\n", &b[999]);
    scanf("%*c");

    //CAMBIO IMPORTANTE: Modificamos el puntero para probar el error que pide el enunciado
    //printf("Intentando liberar una dirección incorrecta (b + 1)...\n");
    //free(b + 1); //Esto provocará un "free(): invalid pointer" y abortará el programa
    
    free(b); //Para evitar el warning y el aborto, liberamos correctamente

    //Esta línea probablemente no se ejecute porque el programa aborta antes
    scanf("%*c");
    exit(0);
}