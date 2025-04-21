#include "funciones.h"

int maximo(int vector[], int size){
    int maxim = vector[0];
    for(int i = 0; i < size; i++){
        if(maxim < vector[i]){
            maxim = vector[i];
        }
    }
    return maxim;
}

double senoMax(int vector[], int size){
    int maxim = maximo(vector, size);
    return sin(maxim);
}

