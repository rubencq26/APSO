#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void *f1(void *arg)
{
    int id = *((int *)arg);
    int delay;
    int *suma = malloc(sizeof(int));
    *suma = 0;

    for (int i = 0; i < 5; i++)
    {
        printf("Soy hilo %d, iteración %d\n", id, i);
        delay = rand() % 3 + 1;
        *suma += delay;
        sleep(delay);
    }

    pthread_exit((void *)suma);
}

int main()
{
    pthread_t h1, h2;
    void *retorno1, *retorno2;

    int id1 = 1, id2 = 2;

    srand(getpid());  // Inicializa la semilla de rand

    pthread_create(&h1, NULL, f1, &id1);
    pthread_create(&h2, NULL, f1, &id2);

    pthread_join(h1, &retorno1);
    pthread_join(h2, &retorno2);

    int suma1 = *(int *)retorno1;
    int suma2 = *(int *)retorno2;

    if (suma1 < suma2) {
        printf("Ganador hilo %d\n", id1);
    } else if (suma2 < suma1) {
        printf("Ganador hilo %d\n", id2);
    } else {
        printf("Empate\n");
    }

    free(retorno1);
    free(retorno2);

    return 0;
}
