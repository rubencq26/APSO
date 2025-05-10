#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int llega12 = 0;

void R12(){
    llega12 = 1;
}

int main(int argc, char* argv[]){
    signal(12, R12);
    if(!llega12){
        pause();
    }
    llega12 = 0;
    printf("Segundo Mensaje\n");
    if(kill(getppid(), 10) == -1){
        perror("Error en el kill");
    }

    if(!llega12){
        pause();
    }
    llega12=1;
    printf("Quinto Mensaje\n");


    return 0;
}