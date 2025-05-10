#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int llega10 = 0;
void R10(){
    llega10 = 1;
}

int main(int argc, char* argv[]){
    
    signal(10,R10);
    int vpidB = fork();
    if(vpidB ==  0){
        execl("B", "B", NULL);
        perror("Error de execl");
        exit(-1);
    }

    int vpidC = fork();
    if(vpidC ==  0){
        execl("C", "C", NULL);
        perror("Error de execl");
        exit(-1);
    }

    sleep(1);

    printf("Primer mensaje\n");
    if(kill(vpidB, 12) == -1){
        perror("Error en el kill");
    }
    if(!llega10){
        pause();
    }
    llega10 = 0;
    if(kill(vpidC, 12) == -1){
        perror("Error de kill");
    }
    if(!llega10){
        pause();
    }
    llega10=0;
    if(kill(vpidB,12)==-1){
        perror("Error de kill");
    }
    wait(NULL);
    wait(NULL);
    printf("Ultimo mensaje\n");


    
    return 0;
}