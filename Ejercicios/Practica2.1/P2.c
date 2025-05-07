#include <stdio.h>
#include <pthread.h>
#include <unistd.h> 
#include <stdbool.h>

bool continua = true;

void *contador(int *valor){
    while(continua){
        system("clear");
        printf("%d\n", *valor);
        sleep(1);
        *valor = *valor + 1;
    }
}



int main(){
    pthread_t h1, h2;
    int dato = 1;
    int valor = 0;
    
    pthread_create(&h1, NULL,(void *) contador, &valor);

    while(dato != 0){
        scanf("%d", &dato);
        valor = valor + dato;
        
    }

    continua  = false;
    pthread_join(h1, NULL);
    printf("Fin de la funcion\n");
    

    return 0;
}