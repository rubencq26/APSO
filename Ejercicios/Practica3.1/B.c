#include <stdio.h>
#include <unistd.h>

int main(){
    printf("Soy B, mi PID es %d y el PID de mi padre es %d\n",  getpid(), getppid());

    int vpidCopia = fork();

    if(vpidCopia == 0){
        for(int i = 0; i < 3; i++){
            printf("Soy el proceso B Copia, mi pid es %d, y el de mi padre es %d\n", getpid(), getppid());
            sleep(1);
        }
    }else{
        for(int i = 0; i < 3; i++){
            printf("Soy el proceso B, mi pid es %d, y el de mi copia es %d\n", getpid(), vpidCopia);
            sleep(1);
        }
    }   
    
    return 0;
}