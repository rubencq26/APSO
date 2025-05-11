#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/wait.h>

int llega10 = 0;
void R10(){
    llega10 = 1;
}

struct mensaje{
    long tipo;
    int dato;

};

int main(){
    srand(getpid());
    signal(10, R10);
    struct mensaje msgC;
    printf("PB: mi pid es %d\n",getpid());
    key_t clave = ftok("./Makefile", 68);
    if(clave == -1){
        perror("Error de ftok");
        exit(-1);
    }

    int idcola = msgget(clave, 0600 | IPC_CREAT);
    if(idcola == -1){
        perror("Error en el msgget");
        exit(-1);
    }
    
    int vpidC = fork();
    if(vpidC == 0){
        execl("C", "C", NULL);
        perror("Error de execl");
        exit(-1);
    }

    
    int num = rand() % 2 + 1;

    int lafifo = open("fifoBC", O_WRONLY);
    int dev = write(lafifo, &num, sizeof(num));
    while(!llega10){
        if(msgrcv(idcola, (struct msgbug *) &msgC, sizeof(msgC) -  sizeof(long), 1, 0) == -1){
            perror("Error de msgrcv");
        }
        printf("PB: número leido: %d\n", msgC.dato);
    }
    
    dev = kill(getppid(), 12);
    if(dev == -1){
        perror("Error de kill");
        exit(-1);
    }
    
    wait(NULL);
    
    if(msgctl(idcola, IPC_RMID, (struct msqid_ds *) NULL) == -1){
        perror("Error de msgctl");
        exit(-1);
    }

    printf("PB: Fin\n");
    return 0;
}