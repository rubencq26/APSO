#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include "comun.h"

int llega10=0;
void R10(){
    llega10 = 1;
}

int llega12=0;
void R12(){
    printf("No es posible arrancar el servidor grafico\n");
    exit(-1);
    
}


int main(){

    int pservidorgraf;
    int NUMPARADAS = 6;

    char paradas[10];

    signal(10,R10);
    signal(12,R12);
    snprintf(paradas, 10, "%d", NUMPARADAS);

    pservidorgraf = fork();

    if(pservidorgraf == 0){
        execl("servidor_ncurses","servidor_ncurses", paradas, NULL);
        perror("Error al arrancar servidor gráfico");
        exit(-1);
    }else if(pservidorgraf == -1){
        perror("Error de fork");
        exit(-1);
    }
    if(!llega10){
        pause();
    }
    llega10=0;

    //crear cola
    int colagraf = crea_cola(fotk("./fichcola.txt", 18));

    struct tipo_elemento dato;
    dato.tipo = 1;
    dato.pid = getpid();
    dato.parada = 3;
    dato.inout=IN;
    dato.pintaborra = PINTAR;
    dato.destino = 1;


    msgsnd(colagraf, &dato, sizeof(dato)- sizeof(long), 0);
    if(!llega10){
        pause();
    }
    llega10 = 0;

    sleep(10);
    kill(pservidorgraf, 12);

    system("reset");

    printf("fin de la practica\n");

    return 0;
}
