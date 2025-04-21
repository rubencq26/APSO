#include <stdio.h>
#include "funciones.h"

int main(){
    int opc = 0;
    double a = 0, b = 0, c = 0;
    while(opc != 4 ){
        printf("1. Leer Coeficientes\n2. Visualizar Raices\n 3. Calcular Raíces\n4. Salir\nElija una opcion: ");
        scanf("%d", &opc);
        switch(opc){
            case 1: 
            printf("ax² + bx + c = 0\n");
            printf("Ingrese a: ");
            scanf("%f", &a);
            printf("\nIngrese b: ");
            scanf("%f", &b);
            printf("\nIngrese c: ");
            scanf("%f", c);
            printf("\n");
                break;
            case 2:
                visualizarEcuacion(a,b,c);
                break;
            case 3:
                calcularRaices(a,b,c);
                break;
        }
    }

    return 0;
}