#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>

struct mensaje
{
    long tipo;
    int dato;
};

int main()
{

    struct mensaje msgB;
    struct mensaje msgC;

    key_t clave;
    clave = ftok("./Makefile", 68);

    if (clave == (key_t)-1)
    {
        perror("Error de ftok()");
        exit(-1);
    }

    int idcola = msgget(clave, 0600 | IPC_CREAT);
    if (idcola == -1)
    {
        perror("Error de idcola");
        exit(-1);
    }

    int vpidB = fork();
    if (vpidB == 0)
    {
        execl("B", "B", NULL);
        perror("Error de execl");
        exit(-1);
    }
    else if (vpidB == -1)
    {
        perror("Error de fork");
        exit(-1);
    }

    int vpidC = fork();

    if (vpidC == 0)
    {
        execl("C", "C", NULL);
        perror("Error de execl");
        exit(-1);
    }
    else if (vpidC == -1)
    {
        perror("Error de fork");
        exit(-1);
    }

    for(int i = 0; i < 10; i++){
        if(msgrcv(idcola,(struct msgbug *) &msgB, sizeof(msgB) - sizeof(long), 1, 0) == -1){
            perror("Error de msgrcv");
            exit(-1);
        }
        printf("Numero de B: %d\n", msgB.dato);

        if(msgrcv(idcola,(struct msgbug *) &msgC, sizeof(msgC) - sizeof(long), 2, 0) == -1){
            perror("Error de msgrcv");
            exit(-1);
        }
        printf("Numero de C: %d\n", msgC.dato);
    }

    if(msgctl(idcola, IPC_RMID,(struct msqid_ds *) NULL) == -1){
        perror("Error de msgctl");
        exit(-1);
    }

    return 0;
}