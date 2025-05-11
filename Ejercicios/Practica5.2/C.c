#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>

int llega10 = 0;
void R10(){
    llega10 = 1;
}

int llega12 = 0;
void R12(){
    llega12 = 1;
}

int main(){
    int dev, lafifo, num;
    signal(10, R10);
    signal(12, R12);
    srand(getpid());
    lafifo = open("fifoAC", O_WRONLY);
    if(lafifo == -1){
        perror("C: Error apartura de FIFO");
        exit(-1);
    }

    for(int i = 0; i < 5; i++){
        if(!llega10){
            pause();
        }
        llega10 = 0;
        num =  rand() % 5 + 1;
        dev = write(lafifo, &num, sizeof(num));
        if(dev ==  -1){
            perror("C: Error de escritura");
            exit(-1);
        }
        
        dev = kill(getppid(), 12);
        if(dev ==  -1){
            perror("C: Error de kill");
            exit(-1);
        }
    }

    if(!llega10 && !llega12){
        pause();
    }

    if(llega10){
        printf("C Gana\n");
    }else{
        printf("C pierde\n");
    }

    close(lafifo);
    printf("Fin de C\n");


    return 0;
}