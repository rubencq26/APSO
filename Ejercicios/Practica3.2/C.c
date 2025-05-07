#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int num = atoi(argv[1]);

    printf("Soy C con PID %d, B tiene PID %d, y el numero aleatorio es %d\n", getpid(), getppid(), num);
    return 0;

}