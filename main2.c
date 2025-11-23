/*
Autores:
    Sergio Nuñez
        y
    Santiago Vilas Pampín
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//Función que imprime direcciones y valores de variables locales y parámetros
void f1(int a){
    int c=3;
    printf("direccion de memoria de f1: %p\n", f1);
    printf("dirección de memoria de a en f1: %p\n", &a);
    printf("dirección de memoria de c (local) en f1: %p\n", &c);
    printf("Valor de a en f1: %d\n", a);
    printf("Valor de c en f1: %d\n", c);
    return;
}

//Función que imprime direcciones y valores de variables locales y parámetros
void f2(int b){
    int d=4;
    printf("direccion de memoria de f2: %p\n", f2);
    printf("dirección de memoria de b en f2: %p\n", &b);
    printf("dirección de memoria de d (local) en f2: %p\n", &d);
    printf("Valor de b en f2: %d\n", b);
    printf("Valor de d en f2: %d\n", d);
    return;
}

int main() {
    int a=1, b=2;
    printf("PID: %d\n", getpid());
    printf("direccion de memoria de main: %p\n", main);
    f1(a);
    f2(b);
    printf("dirección de memoria de a en main: %p\n", &a);
    printf("dirección de memoria de b en main: %p\n", &b);

    printf("Pausa para poder mirar el mapa (pulsa enter para seguir)\n");
    scanf("%*c");
    exit(0);
}