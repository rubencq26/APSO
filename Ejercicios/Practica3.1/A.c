#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>




int main(){

    printf("Soy el proceso A, con un PID %d\n", getpid());

    int vpidB = fork();
    if(vpidB == 0){
        execl("B", "B", NULL);
        perror("Error de execl");
    }
    
    int vpidC = fork();
    if(vpidC == 0){
        close(1);
        open("infoc", O_WRONLY | O_CREAT, 0600);
        execl("C", "C", NULL);
        perror("Error de execl");
        exit(-1);
    }

    printf("PID de B %d  PID de C %d\n", vpidB, vpidC);
    sleep(4);
    return 0;
}