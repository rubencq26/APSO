#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>

struct mensaje{
    long tipo;
    int dato;
};

int main(){
    srand(getpid());
    struct mensaje msgB;
    key_t clave;
    int numAlea, tiempoAlea;
    clave = ftok("./Makefile", 86);
    if(clave == -1){
        perror("Error de frok");
        exit(-1);
    }

    int idcola = msgget(clave, 0600 | IPC_CREAT);
    if(idcola == -1){
        perror("Error de creacion idcola");
        exit(-1);
    }



    for(int i = 1; i <= 5; i++){
        numAlea = i;
        tiempoAlea = rand() % 3 + 1;
        sleep(tiempoAlea);
        msgB.tipo = 2;
        msgB.dato = numAlea;
        if(msgsnd(idcola,(struct msgbug *) &msgB, sizeof(msgB) - sizeof(long), IPC_NOWAIT) == -1){
            perror("Error al mandar mensaje de A a B");
            exit(-1);
        }
    }
    wait(NULL);

    
    return 0;
}