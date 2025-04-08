#include<stdio.h>
#include<math.h>

int menu();

int main(){
    
    int opc = 0;
    float a, b,c;
    float x1, x2;
    while(opc != 4){
       opc = menu();
       switch (opc)
       {
       case 1:
            printf("ax² + bx+ c = 0\n");
            printf("a: \n");
            scanf("%f", &a);
            printf("b: \n");
            scanf("%f", &b);
            printf("c: \n");
            scanf("%f", &c);
        break;
        case 2:
            printf("%fx² + %fx + %f = 0\n",a, b, c);
        break;
        case 3:
            x1 = (-b + sqrt((b*b) - (4*a*c))) /(2 *a);
            x2 = (-b - sqrt((b*b) - (4*a*c))) /(2 *a);
            printf("Las raices son: x1 = %f ; x2 = %f \n",x1, x2);
       break;
       default:
        break;
       }

    }



    return 0;
}

int menu(){
    int opc;
    printf("1. Leer Coeficientes\n");
    printf("2. Visualizar Ecuación\n");
    printf("3. Calcular Raices\n");
    printf("4. Salir\n");
    printf("Elija una opcion: \n");
    scanf("%d", &opc);
    return opc;

}