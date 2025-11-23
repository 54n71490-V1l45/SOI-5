/*
Autores:
    Sergio Núñez
        y
    Santiago Vilas Pampín
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//Variables globales
//Inicializadas
char c = 'A';
int i = 42;
float pi = 3.14;

//No inicializadas
int arr[200000];
int unused_global;

int main() {
    printf("PID: %d\n", getpid());
    printf("Dirección de la función main: %p\n", &main); //dirección de la función main
    
    //Variable local no inicializada
    int p[10][10][10];
    printf("Matriz p creada\n");
    printf("Dirección base del array p: %p\n", p);

    printf("Pausa para poder mirar el mapa (pulsa enter para seguir)\n");
    scanf("%*c"); //Pausa para poder mirar el mapa

    //Se imprimen algunas direcciones de elementos del array p para observar el orden
    printf("p[0][0][0]: %p\n", &p[0][0][0]);
    printf("p[0][0][1]: %p\n", &p[0][0][1]); //Debería ser +4 bytes
    printf("p[0][0][9]: %p\n", &p[0][0][9]);
    printf("p[0][1][0]: %p\n", &p[0][1][0]); //El salto de fila
    printf("p[1][0][0]: %p\n", &p[1][0][0]); //El salto de plano
    printf("p[9][9][9]: %p\n", &p[9][9][9]); //Último elemento

    //Variables locales inicializadas
    char local_c = '2';
    int local_i = 84;
    float local_f = 6.28;

    printf("local_c: %p\n", &local_c);
    printf("local_i: %p\n", &local_i);
    printf("local_f: %p\n", &local_f);

    printf("Pausa para poder mirar el mapa (pulsa enter para seguir)\n");
    scanf("%*c"); //Pausa para poder mirar el mapa

    printf("Variables Globales (DATA/BSS)\n");
    printf("c: %p\n", &c);
    printf("i: %p\n", &i);
    printf("pi: %p\n", &pi);
    printf("arr: %p\n", arr);
    printf("arr[último]: %p\n", &arr[199999]);
    printf("unused_global: %p\n", &unused_global);

    printf("Pausa para poder mirar el mapa (pulsa enter para seguir)\n");
    scanf("%*c");

    exit(0);
}
