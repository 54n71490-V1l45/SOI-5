//
// Ejercicio 6
//

/* Crea un programa con las siguientes características:
• Crea una variable global y una variable local al main() de tipo entero.
• Crea dos hilos que reciben como parámetro la variable local del hilo principal.
• Cada hilo define una nueva variable local y la actualiza con el producto de la variable global
y el parámetro recibido por el hilo.
(a) Muestra en pantalla las direcciones de la variable global y las variables locales en el hilo
principal y, por otro lado, de la variable global, los parámetros recibidos y las variables
locales definidas en cada uno de los dos hilos creados. Haz también una llamada a malloc
en los dos hilos.
(b) Localiza todas estas direcciones en el mapa de direcciones del proceso, e identifica las regiones
en las que se encuentran.
(c) Identifica donde están las pilas y los montículos de memoria dinámica de todos los hilos.*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_HILOS 2

int var_global = 10; // Variable global

void* funcion_hilo(void* arg) {
    int var_local_hilo; // Variable local al hilo
    int parametro = *((int*)arg);

    var_local_hilo = var_global * parametro;

    printf("Dirección de la variable global en el hilo: %p\n", &var_global);
    printf("Dirección del parámetro recibido en el hilo: %p\n", arg);
    printf("Dirección de la variable local en el hilo: %p\n", &var_local_hilo);

    // Llamada a malloc
    int* memoria_dinamica = (int*)malloc(sizeof(int));
    printf("Dirección de la memoria dinámica asignada en el hilo: %p\n", (void*)memoria_dinamica);
    free(memoria_dinamica);

    return NULL;
}


int main() {
    printf("PID: %d\n", getpid());
    pthread_t hilo1[NUM_HILOS];
    int var_local_main = 20; // Variable local al main

    printf("Dirección de la variable global en el hilo principal: %p\n", (void*)&var_global);
    printf("Dirección de la variable local en el hilo principal: %p\n", (void*)&var_local_main);
    scanf("%*c");
    for (int i = 0; i < NUM_HILOS; i++) {
        pthread_create(&hilo1[i], NULL, funcion_hilo, &var_local_main);
    }
    scanf("%*c");
    exit(0);
}