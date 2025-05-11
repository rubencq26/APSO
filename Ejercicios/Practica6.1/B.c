#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>

struct mensaje{
    long tipo;
    int dato;
};


int main(){
    srand(getpid());
    struct mensaje msgA;
    int numAlea, tiempoAlea;

    key_t clave = ftok("./Makefile", 68);
    if(clave == (key_t) -1){
        perror("Error de ftok()");
        exit(-1);
    }

    int idcola = msgget(clave, 0600 | IPC_CREAT);
    if(idcola == -1){
        perror("Error de idcola");
        exit(-1);
    }

    for(int i = 0; i< 10; i++){
        numAlea = rand() % 100 + 1;
        tiempoAlea = rand() % 3 + 1;
        sleep(tiempoAlea);
        msgA.tipo = 1;
        msgA.dato = numAlea;
        if(msgsnd(idcola,(struct msgbug *) &msgA, sizeof(msgA) - sizeof(long), IPC_NOWAIT) == -1){
            perror("Error al mandar mensaje");
            exit(-1);
        }
    }
    

    return 0;
}