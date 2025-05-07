#include <stdio.h>
#include <unistd.h>

int main(){

    
    printf("Soy C, mi PID es %d y el PID de mi padre es %d\n",  getpid(), getppid());


}