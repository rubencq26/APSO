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
    clave = ftok("./Makefile", 68);
    if(clave == -1){
        perror("Error de frok");
        exit(-1);
    }

    int idcola = msgget(clave, 0600 | IPC_CREAT);
    if(idcola == -1){
        perror("Error de creacion idcola");
        exit(-1);
    }

    int vpidB = fork();
    if(vpidB == 0){
        execl("B", "B", NULL);
        perror("Error de execl");
        exit(-1);
    }else if(vpidB == -1){
        perror("Error de fork");
        exit(-1);
    }


    for(int i = 1; i <= 5; i++){
        numAlea = i;
        tiempoAlea = rand() % 3 + 1;
        sleep(tiempoAlea);
        msgB.tipo = 1;
        msgB.dato = numAlea;
        if(msgsnd(idcola,(struct msgbug *) &msgB, sizeof(msgB) - sizeof(long), IPC_NOWAIT) == -1){
            perror("Error al mandar mensaje de A a B");
            exit(-1);
        }
    }
    wait(NULL);
    if(msgctl(idcola, IPC_RMID, (struct msqid_ds *) NULL) == -1){
        perror("Error de msgctl");
        exit(-1);
    }
    
    return 0;
}