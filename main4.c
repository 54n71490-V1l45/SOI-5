/*
Autores:
    Sergio Núñez
        y
    Santiago Vilas Pampín
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(){
    printf("Proceso padre (PID: %d) antes del fork\n", getpid());
    scanf("%*c");

    pid_t a=fork();
    if(a<0){
        perror("Error en fork");
        exit(1);
    }
    if(a==0){
        printf("Proceso hijo (PID: %d) antes del malloc\n", getpid());
        scanf("%*c");

        //Malloc en el hijo
        int *b=malloc(1024*sizeof(int));
        printf("malloc:%p\n", b); //No es necesario hacer un free() porque execv reemplaza el proceso
        scanf("%*c");

        char *args[] = {"./programa_hijo", NULL};
        //Para que el execv funcione, el ejecutable del hijo debe existir antes de ejecutar el padre
        execv("./programa_hijo", args);

        //Nunca se llega aquí si execv funciona correctamente
        perror("Error, execv ha fallado");
        free(b);
        exit(1);
    }else{
        printf("(PADRE) Esperando a que el hijo termine...\n");
        wait(NULL);
        scanf("%*c"); //Pausa final para ver el mapa del padre
    }
    exit(0);
}