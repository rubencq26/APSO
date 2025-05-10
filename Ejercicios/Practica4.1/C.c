#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int llega12 = 0;
void R12(){
    llega12 = 1;;
}
int llega14 = 0;

void R14(){
    llega14 = 1;
}

int main(int argc, char* argv[]){
    signal(12, R12);
    signal(14, R14);

    if(!llega12){
        pause();
    }
    llega12 = 0;
    printf("Tercer Mensaje\n");

    alarm(3);
    while(!llega14){
        sleep(1);
        printf("Esperar alarma\n");
    }
    
    llega14 = 0;
    printf("Cuarto Mensaje\n");
    if(kill(getppid(),10)== -1){
        perror("Error de kill");
    }

    return 0;
}