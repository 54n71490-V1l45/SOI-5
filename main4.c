//
// Ejercicio 4
//

/*Crea un proceso hijo que incluya un malloc y a continuación cambie su imagen con execv a
un código cualquiera creado por ti. Compara los mapas de memoria del proceso padre y el
proceso hijo antes y después del malloc y comprueba como el cambio de imagen afecta al mapa
de memoria del proceso hijo*/

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