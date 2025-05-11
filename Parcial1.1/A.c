#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>

void *f1(){
    for(int i = 1; i < 5; i++ ){
        
        printf("Iteracion del hilo nº %d\n", i);
        sleep(2);
    }

}

int llega12 = 0;
void R12(){
    llega12 = 1;
}


int main(){
    signal(12, R12);
    int dev;
    pthread_t h1;
    printf("PA: mi pid es %d\n", getpid());

    dev = mkfifo("fifoBC", 0660);
    if(dev == -1){
        perror("Error de mkfifo");
        exit(-1);
    }

    pthread_create(&h1, NULL,(void *) f1, NULL);

    int vpidB  = fork();
    if(vpidB == 0){
        execl("B", "B", NULL);
        perror("Error de execl");
        exit(-1);
    }

    if(!llega12){
        pause();
    }
    llega12=0;
    printf("PA: Comunicacion finalizada\n");

    pthread_join(h1, NULL);
    wait(NULL);
    
    dev = unlink("fifoBC");
    if(dev == -1){
        perror("Error de unlink");
        exit(-1);
    }

    printf("PA: fin\n");
    return 0;
}