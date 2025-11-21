/*
Autores:
    Sergio Nuñez
        y
    Santiago Vilas Pampín
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void f1(int a){
    int c=3;
    printf("direccion de memoria de fi: %p\n", f1);
    printf("dirección de memoria de a en f1: %p\n", &a);
    printf("dirección de memoria de c (local) en f1: %p\n", &c);
    printf("Valor de a en f1: %d\n", a);
    printf("Valor de c en f1: %d\n", c);
}

void f2(int b){
    int d=4;
    printf("direccion de memoria de fi: %p\n", f2);
    printf("dirección de memoria de b en f2: %p\n", &b);
    printf("dirección de memoria de d (local) en f2: %p\n", &d);
    printf("Valor de b en f2: %d\n", b);
    printf("Valor de d en f2: %d\n", d);
}
int main() {
    int a=1, b=2;
    printf("PID: %d\n", getpid());
    printf("direccion de memoria de main: %p\n", main);
    f1(a);
    f2(b);
    scanf("%*c");
    return 0;
}