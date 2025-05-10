#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{

    // Muestra Primer mensaje
    printf("Primer Mensaje\n");

    int tubo[2];
    pipe(tubo);

    int dev = mkfifo("fifoBC", 0660);
    if (dev == -1)
    {
        perror("A: Error de creacion de la FIFO");
        exit(-1);
    }

    // crear B
    int vpidB = fork();
    if (vpidB == 0)
    {
        close(2);
        dup(tubo[0]);
        execl("B", "B", NULL);
        perror("Error de execl");
        exit(-1);
    }
    else if (vpidB == -1)
    {
        perror("Error de fork");
        exit(-1);
    }

    // crear C
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

    dev = write(tubo[1], &vpidC, sizeof(vpidC));
    if (dev == -1)
    {
        perror("A: Error de escritura");
        exit(-1);
    }

    // espera 1 segundo
    sleep(1);

    wait(NULL);
    wait(NULL);

    // Muestra ultimo mensaje
    printf("Último mensaje\n");

    dev = unlink("fifoBC");
    if(dev == -1){
        perror("A: Error Unlink");
        exit(-1);
    }

    return 0;
}