#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>

int llega10 = 0;
void R10()
{
    llega10 = 1;
}

int llega12 = 0;
void R12()
{
    llega12 = 1;
}

int main()
{
    int dev, tubo[2], lafifo, dato, sumaB = 0, sumaC = 0;
    double mediaB, mediaC;
    signal(10, R10);
    signal(12, R12);
    pipe(tubo);
    int vpidB = fork();

    if (vpidB == 0)
    {
        close(2);
        dup(tubo[1]);
        execl("B", "B", NULL);
        perror("A: Error en execl");
        exit(-1);
    }
    else if (vpidB == -1)
    {
        perror("A: Error de fork");
        exit(-1);
    }

    dev = mkfifo("fifoAC", 0660);
    if (dev == -1)
    {
        perror("Error de creacion de fifoAC");
        exit(-1);
    }

    lafifo = open("fifoAC", O_RDONLY);
    if (lafifo == -1)
    {
        perror("A: Error en la apertuta de la fifo");
        exit(-1);
    }

    for (int i = 0; i < 5; i++)
    {
        dev = kill(vpidB, 10);
        if (dev == -1)
        {
            perror("A: Error en el kill");
            exit(-1);
        }

        if (!llega10)
        {
            pause();
        }
        dev = read(tubo[0], &dato, sizeof(dato));
        if (dev == -1)
        {
            perror("A: Error de lectura de dato");
            exit(-1);
        }
        printf("Dato recibido de B: %d\n", dato);
        sumaB += dato;
        llega10 = 0;

        if (!llega12)
        {
            pause();
        }
        llega12 = 0;
        dev = read(lafifo, &dato, sizeof(dato));
        sumaC += dato;
        if (dev == -1)
        {
            perror("Error de read fifo");
            exit(-1);
        }
        printf("Dato reecibido de C: %d\n", dato);
    }

    mediaB = sumaB/5;
    mediaC = sumaC/5;
    
    if(mediaB >= mediaC){
        dev = kill(vpidB, 10);
        if(dev == -1){
            perror("A: Error de kill");
            exit(-1);
        }
    }else{
        dev = kill(vpidB, 12);
        if(dev == -1){
            perror("A: Error de kill");
            exit(-1);
        }
    }

    wait(NULL);

    dev = unlink("fifoAC");
    if(dev == -1){
        perror("A: Error de unlink");
        exit(-1);
    }

    return 0;
}