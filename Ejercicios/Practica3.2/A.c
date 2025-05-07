#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(){
    
    printf("Soy el proceso A con un PID %d\n", getpid());

    int vpidB = fork();

    if(vpidB == 0){
        close(1);
        open("infoB", O_WRONLY | O_CREAT, 0600);
        execl("B", "B", NULL);
        perror("Error de execl");

    }else{
        printf("PID de A %d y PID de B %d\n", getpid(), vpidB);
        sleep(2);
    }

    
    return 0;
}