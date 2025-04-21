#include "funciones.h"

void calcularRaices(double a, double b, double c){
    double x1 = (-b + sqrt(pow(b,2) - 4*a*c))/(2*a);
    double x2 = (-b - sqrt(pow(b,2) - 4*a*c))/(2*a);
    printf("x1 = %f\nx2 = %f\n",x1, x2);
}



void visualizarEcuacion(double a, double b, double c){
    printf("%fx² + %fx + %f = 0\n", a,b,c);
}


