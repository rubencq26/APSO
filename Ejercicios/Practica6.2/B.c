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

    struct mensaje msgA;
    struct mensaje msgC;
    key_t claveA;
    claveA = ftok("./Makefile", 68);
    if(claveA == -1){
        perror("Error de ftok");
        exit(-1);
    }

    int idcolaA = msgget(claveA, 0600 | IPC_CREAT);
    if(idcolaA == -1){
        perror("Error de idcolaA");
        exit(-1);
    }

    key_t claveC;
    claveC = ftok("./Makefile", 86);

    int idcolaC = msgget(claveC, 0600 | IPC_CREAT);
    if(idcolaC == -1){
        perror("Error de idcolaC");
        exit(-1);
    }

    int vpidC = fork();
    if(vpidC == 0){
        execl("C", "C", NULL);
        perror("Error de execl");
        exit(-1);
    }else if(vpidC == -1){
        perror("Error de fork");
        exit(-1);
    }

    int dev;

    for(int i = 1; i < 6; i++){
        sleep(2);
        if(msgrcv(idcolaA, (struct msgbug *) &msgA, sizeof(msgA) - sizeof(long), 1, IPC_NOWAIT) == -1){
            printf("A no pone a tiempo el %d  %d\n", i, msgA.dato);
        
            dev = -1;
        }

        if(msgA.dato == i){
            printf("A pone a tiempo el %d\n", i);
        }else if(dev != -1){
            printf("A no pone a tiempo el %d  %d\n", i, msgA.dato); 
        }
            dev = 0;
        

        

        if(msgrcv(idcolaC, (struct msgbug *) &msgC, sizeof(msgC) - sizeof(long), 2, IPC_NOWAIT)== -1 ){
           printf("C no pone a tiempo el %d\n", i);
           dev = -1;
        }

        if(msgC.dato == i){
            printf("C pone a tiempo el %d\n", i);
        }else if(dev != -1){
            printf("C no pone a tiempo el %d\n", i);  
        }
            dev = 0;
    }
    
    
    
    wait(NULL);

    if(msgctl(idcolaC, IPC_RMID, (struct msqid_ds *) NULL) == -1){
        perror("Error de msgctl");
        exit(-1);
    }

    return 0;
}