#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int llega10 = 0;


void R10(){
    llega10 = 1;
}

int main(){
    signal(10, R10);
    srand(getpid());
    if(!llega10){
        pause();
    }
    llega10=0;

    int numAlea = rand() %5 + 2;
    printf("Num aleatorio C: %d\n", numAlea);
    sleep(numAlea);

    if(kill(getppid(), 12) == -1){
        perror("Error de kill");
    }

    return 0;
}