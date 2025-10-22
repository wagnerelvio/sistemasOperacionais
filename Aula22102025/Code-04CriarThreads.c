#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>   // para sleep()

#define N 10  // número de threads
#define TEMPO 120  // tempo em segundos (2 minutos)

void* tarefa(void* arg) {
    int id = *(int*)arg;

    printf("Thread %d iniciada.\n", id);

    // Simula trabalho por 2 minutos
    for (int i = 0; i < TEMPO; i++) {
        sleep(1); // espera 1 segundo
        if (i % 30 == 0 && i > 0)  // mensagem a cada 30 segundos
            printf("Thread %d ainda rodando (%d segundos)...\n", id, i);
    }

    printf("Thread %d finalizada após %d segundos.\n", id, TEMPO);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[N];
    int ids[N];

    printf("Iniciando %d threads por %d segundos...\n\n", N, TEMPO);

    // Criação das threads
    for (int i = 0; i < N; i++) {
        ids[i] = i + 1;
        pthread_create(&threads[i], NULL, tarefa, &ids[i]);
    }

    // Espera todas terminarem
    for (int i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\nTodas as threads encerradas.\n");
    return 0;
}
