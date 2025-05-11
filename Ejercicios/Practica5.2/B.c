#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>

int llega10 = 0;
void R10() {
    llega10  = 1;
}

int llega12 = 0;
void R12(){
    llega12 = 1;
}

int main(){
    signal(10, R10);
    signal(12, R12);
    srand(getpid());
    int dev, numAlea;
    int lapipe = dup(2);
    close(2);
    dev =  open("/dev/tty", O_WRONLY);
    if(dev == -1){
        perror("B: Error apertura /dev/tty ");
        exit(-1);
    }

    int vpidC =  fork();
    if(vpidC == 0){
        execl("C","C", NULL);
        perror("B: Error de execl");
        exit(-1);
    }else if(vpidC == -1){
        perror("B: Error de fork");
        exit(-1);
    }
    for(int i = 0; i<5;i++){
        if(!llega10){
            pause();
        }
        llega10 = 0;
        kill(vpidC, 10);
        numAlea = rand() % 5 + 1;
        
        dev = write(lapipe, &numAlea, sizeof(numAlea));
        if(dev ==  -1){
            perror("B: Error de write en la pipe");
            exit(-1);
        }
        kill(getppid(), 10);
        if(!llega12){
            pause();
        }
        llega12 = 0;
        kill(getppid(), 12);
    }
    if(!llega10 && !llega12){
        pause();
    }

    if(llega10){
        printf("Gana B\n");
        dev = kill(vpidC, 12);
        if(dev == -1){
            perror("B: Error de kill");
            exit(-1);
        }
    }else if(llega12){
        printf("Gana C\n");
        dev = kill(vpidC,10);
        if(dev == -1){
            perror("B: Error de kill");
            exit(-1);
        }
    }

    wait(NULL);

    printf("Fin de B\n");
    return 0;

}