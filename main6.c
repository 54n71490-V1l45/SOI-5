/*
Autores:
    Sergio Núñez
        y
    Santiago Vilas Pampín
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_HILOS 2

/*
Compilar con -pthread:
gcc -Wall -o main6 main6.c -lpthread
*/

int var_global = 10; //Variable global
int seguir_ejecutando = 1; //Variable para controlar la ejecución de los hilos

// Función que ejecuta cada hilo
void* funcion_hilo(void* arg) {
    int var_local_hilo; //Variable local al hilo
    int id_hilo = *((int*)arg);

    var_local_hilo = var_global * id_hilo; //Operación del enunciado

    printf("Hilo %d - Dirección de la variable global en el hilo: %p\n", id_hilo-20, &var_global);
    printf("Hilo %d - Dirección del parámetro recibido en el hilo: %p\n", id_hilo-20, arg);
    printf("Hilo %d - Dirección de la variable local en el hilo: %p\n", id_hilo-20, &var_local_hilo);

    // Llamada a malloc
    int* memoria_dinamica = (int*)malloc(sizeof(int));
    if (!memoria_dinamica ) {
        perror("Error al asignar memoria");
        pthread_exit(NULL);
    }
    printf("Dirección de la memoria dinámica asignada en el hilo: %p\n", (void*)memoria_dinamica);
    sleep(2); //Esperamos un poco para que puedas ver la dirección en el mapa de memoria

    free(memoria_dinamica);

    //Mantenemos el hilo vivo para que puedas ver su pila en el mapa
    printf("Hilo %d - Esperando a que el usuario pulse ENTER en el main...\n", id_hilo-20);
    while(seguir_ejecutando) {
        sleep(1);
    }

    pthread_exit(NULL);
}


// Función principal que crea y gestiona los hilos
int main() {
    printf("PID: %d\n", getpid());
    pthread_t hilos[NUM_HILOS];
    int ids[NUM_HILOS];
    int var_local_main = 20; //Variable local al main

    printf("Dirección de la variable global en el hilo principal: %p\n", &var_global);
    printf("Dirección de la variable local en el hilo principal: %p\n", &var_local_main);
    scanf("%*c");

    // Crear hilos
    for (int i = 0; i < NUM_HILOS; i++) {
        ids[i] = var_local_main + i; //Les damos un ID: 1 y 2
        //Pasamos la dirección de ids[i] para que sea seguro
        if (pthread_create(&hilos[i], NULL, funcion_hilo, &ids[i]) != 0) {
            perror("Error creando hilo");
            exit(1);
        }
    }

    sleep(2); //Esperamos un poco para que los hilos impriman sus direcciones
    scanf("%*c");

    seguir_ejecutando = 0; //Indicamos a los hilos que terminen

    for (int i = 0; i < NUM_HILOS; i++) {
        pthread_join(hilos[i], NULL);
    }

    printf("Todos los hilos han terminado. ENTER para fin del programa.\n");
    scanf("%*c");
    exit(0);
}