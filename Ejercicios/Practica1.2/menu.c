#include <stdio.h>
#include "funciones.h"


int main(){
    int opc = 0;
    int vector[10];
    int size = 0;
    int num = 0;
    for(int i = 0; i <10; i++){
        vector[i] = -1;
    }

    while(opc != 4){
        printf("1. Leer datos\n2. Visualizar máximo\n3. Calcular el seno del máximo\n4. Salir\nElija una opcion: ");
        scanf("%d", &opc);
        printf("\n");
        switch(opc){
            case 1:
                while (size < 10 && num != -1)
                {
                    printf("Introduzca un numero: ");
                    scanf("%d", &num);
                    printf("\n");
                    if(num != -1){
                        vector[size] = num;
                        size = size + 1;
                    }
                }
                break;
            case 2:
                int maxi = maximo(vector, size);
                printf("El numero maximo del array es: %d\n", maxi);
                break;
            case 3:
                double sen = senoMax(vector, size);
                printf("El seno del numero maximo es: %f\n", sen);
                break;
        }

    }
    

    return 0;
}

