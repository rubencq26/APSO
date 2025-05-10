#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>

int llega12 = 0;

void R12(){
    llega12 = 1;
}

int main(){
    srand(getpid());
    printf("Hola soy el proceso A\n");
    signal(12, R12);
    int vpidB = fork();

    if(vpidB == 0){
        execl("B", "B", NULL);
        perror("Error de execl");
        exit(-1);
    }else if(vpidB == -1){
        perror("Error de fork");
        exit(-1);
    }
    
    if(!llega12){
        pause();
    }
    llega12 = 0;

    int numAlea = rand() % 5 + 2;
    printf("Num aleatorio A: %d\n", numAlea);
    sleep(numAlea);

    if(kill(vpidB, 10) == -1){
        perror("Error de kill");
    }
    int status;
wait(&status);

if (WIFEXITED(status)) {
    int retorno = WEXITSTATUS(status);
    if (retorno == 0) {
        printf("Juego abortado\n");
    } else if (retorno == 1) {
        printf("Gana A\n");
    } else if (retorno == 2) {
        printf("Gana C\n");
    } else {
        printf("Código de salida no esperado: %d\n", retorno);
    }
} else {
    printf("El proceso terminó anormalmente\n");
}
    



    return 0;
}