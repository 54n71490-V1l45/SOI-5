/*
Autores:
    Sergio Nuñez
        y
    Santiago Vilas Pampín
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(){
    printf("proceso padre (PID: %d) antes del fork:\n", getpid());

    pid_t a=fork();
    if(a<0){
        perror("Error en fork");
        exit(EXIT_FAILURE);
    }
    if(a==0){
        printf("proceso hijo (PID: %d) antes del malloc:\n", getpid());
        scanf("%*c");
        int *b=malloc(1024*sizeof(int));
        printf("malloc:%p\n", b);
        scanf("%*c");
        char *args[] = {"./progrma_hijo", NULL};
        execv("./progrma_hijo", args);
    }else{
        wait(NULL);
    }
    exit(0);
}