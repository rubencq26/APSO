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

struct mensaje{
    long tipo;
    int dato;

};

int llega14 = 0;
void R14(){
    llega14 = 1;
}

int main(){
    srand(getpid());
    signal(14, R14);
    printf("PC: mi pid es %d\n", getpid());
    struct mensaje msgA;
    key_t clave = ftok("./Makefile", 68);
    if(clave == -1){
        perror("Error de ftok");
        exit(-1);
    }

    int idcola =  msgget(clave, 0600 | IPC_CREAT);
    if(idcola == -1){
        perror("Error de msgget");
        exit(-1);
    }

    int lafifo = open("fifoBC", O_RDONLY);
    if(lafifo == -1){
        perror("Error de open");
        exit(-1);
    }
    int tiempo, num;
    int dev = read(lafifo, &tiempo, sizeof(tiempo));
    if(dev == -1){
        perror("Error de read");
        exit(-1);
    }
    printf("PC: Intervalo de envío: %d\n", tiempo);
    alarm(5);
    while(!llega14){
        sleep(tiempo);
        num = rand() % 200 + 100;
        msgA.tipo = 1;
        msgA.dato = num;
        if(msgsnd(idcola, (struct msgbug *) &msgA, sizeof(msgA) - sizeof(long), IPC_NOWAIT) == -1){
            perror("Error de msgnd");
            exit(-1);
        }
    }
    dev = kill(getppid(), 10);
    if(dev == -1){
        perror("Error de kill");
        exit(-1);
    }

    close(lafifo);
    printf("PC: Fin\n");

    return 0;
}