#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int llega10 = 0;

void R10(){
    llega10 = 1;
}

int llega14 = 0;

void R14(){
    llega14 = 1;
}

int llega12 = 0;
void R12(){
    llega12 = 1;
}

int main(){
    int salida = -1;
    signal(10, R10);
    signal(12, R12);
    signal(14, R14);

    srand(getpid());
    printf("Hola soy el proceso B\n");

    int vpidC = fork();

    if(vpidC == 0){
        execl("C", "C", NULL);
        perror("Error de execl");
        exit(-1);
    }else if(vpidC == -1){
        perror("Error de fork");
        exit(-1);
    }
    sleep(1);

    if(kill(getppid(),12) == -1){
        perror("Error de kill");    
    }

    if(kill(vpidC, 10) == -1){
        perror("Error de kill");
    }

    int numAlea = rand() % 6 + 3;
    printf("Numero generado alarma: %d\n", numAlea);
    alarm(numAlea);

    if(!llega10 && !llega14 && !llega12){
        pause();
    }
    
    if(llega10){
        llega10 = 0;
        return 1;
    }else if(llega12){
        llega12 = 0;
        return 2;
    }else if(llega14){
        llega14 = 0;
        return 0;
    }

    
}