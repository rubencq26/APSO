#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(){
    
    printf("Soy el proceso B con un PID %d\n", getpid());
    srand(getpid());
    int num =  rand() % 10 + 1;

    int vpidC =  fork();

    if(vpidC == 0){
        close(1);
        open("/dev/tty", O_WRONLY);
        char num_str[10];
        snprintf(num_str, sizeof(num_str), "%d", num); // Convierte número a cadena

        execl("C", "C", num_str, NULL);
        perror("Error de execl");

    }else{
        printf("PID B %d, PID de A %d, PID de C %d\n", getpid(), getppid(), vpidC);
        sleep(1);
    }
    

    
    return 0;
}