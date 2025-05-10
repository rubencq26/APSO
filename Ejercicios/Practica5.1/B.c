#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int llega12 = 0;
void R12(){
    llega12 = 1;
}


int main(){

    int dev, lafifo, pidc, mipid;
    signal(12, R12);
    
    int lapipe = dup(2);
    close(2);
    dev = open("/dev/tty", O_WRONLY);
    if(dev == -1){
        perror("B: Error de open de /dev/tty\n");
    }

    lafifo = open("fifoBC", O_WRONLY);
    if(lafifo == -1){
        perror("B: Erro de open FIFO");
        exit(-1);
    }

    dev = read(lapipe, &pidc, sizeof(pidc));
    if(dev == -1){
        perror("B: Error de read");
        exit(-1);
    }

    mipid = getpid();
    dev = write(lafifo, &mipid, sizeof(mipid));
    if(dev ==  -1){
        perror("C: Error de escritura");
        exit(-1);
    }
    printf("Segundo mensaje\n");

    dev = kill(pidc,10);
    if(dev == -1){
        perror("Error en el kill");
        exit(-1);
    }

    if(!llega12){
        pause();
    }
    llega12 = 0;
    printf("Quinto Mensaje\n");

    close(lafifo);
    return 0;
}