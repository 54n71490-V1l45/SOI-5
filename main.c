#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char c = 'A';
int i = 42;
float pi = 3.14;
int arr[200000];
int unused_global;





int main() {
    printf("PID: %d\n", getpid());
    
    int p[10][10][10];
    printf("Matriz p creada\n");
    printf("local_p: %p\n", p);

    scanf("%*c"); //Pausa para poder mirar el mapa

    for (int a = 0; a < 10; a++) {
        for (int b = 0; b < 10; b++) {
            for (int c = 0; c < 10; c++) {
                p[a][b][c] = a + b + c;
                //printf("p[%d][%d][%d] = %d\n", a, b, c, p[a][b][c]); 
            }
            printf("%p\n", &p[a][b][c]);
        }
    }

    printf("local_p inicializada: %p\n", p);
    scanf("%*c");

    scanf("%*c"); //Pausa para poder mirar el mapa
    char local_c;
    printf("local_c: %p\n", &local_c);
    local_c='2';
    printf("local_c inicializada: %p\n", &local_c);

    int local_i;
    printf("local_i: %p\n", &local_i);
    local_i=84;
    printf("local_i inicializada: %p\n", &local_i);

    float local_f;
    printf("local_f creado\n");
    printf("local_f: %p\n", &local_f);
    local_f = 6.28;
    printf("local_f inicializada: %p\n", &local_f);

    scanf("%*c"); //Pausa para poder mirar el mapa


    printf("c: %p\n", &c);
    printf("i: %p\n", &i);
    printf("pi: %p\n", &pi);
    printf("arr: %p\n", arr);
    printf("arr[último]: %p\n", &arr[199999]);
    printf("unused_global: %p\n", &unused_global);
    
    printf("unused_global inicializada: %p\n", &unused_global);

    scanf("%*c");

    return 0;
}
