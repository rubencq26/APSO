#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int llega14 = 0;

void R14(){
    llega14 = 1;
}

int llega10 = 0;
void R10(){
    llega10  = 1;
}

int main(){
    int dev, pidB;
    signal(14, R14);
    signal(10, R10);

    int lafifo = open("fifoBC", O_RDONLY);
    if(lafifo == -1){
        perror("C: Error de open FIFO");
        exit(-1);
    }
    
    

    if(!llega10){
        pause();
    }

    dev = read(lafifo, &pidB, sizeof(pidB));
    if(dev == -1){
        perror("C: Error de read");
        exit(-1);
    }

    printf("Tercer Mensaje\n");

    alarm(3);
    while(!llega14){
        sleep(1);
        printf("Esperando Alarma...\n");
    }

    printf("Cuarto Mensaje\n");
    
    dev = kill(pidB,12);
    if(dev == -1){
        perror("C: Error de KILL");
        exit(-1);
    }

    close(lafifo);

    return 0;
}