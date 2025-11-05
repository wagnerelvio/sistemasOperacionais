#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 50
#define EXEC_TIME 20

void* thread_function(void* arg) {
    int id = *(int*)arg;
    printf("Thread %d iniciada.\n", id);
    sleep(EXEC_TIME);
    printf("Thread %d finalizada.\n", id);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int ids[NUM_THREADS];
    int i;

    printf("Criando %d threads por %d segundos...\n", NUM_THREADS, EXEC_TIME);

    // Criação das threads
    for (i = 0; i < NUM_THREADS; i++) {
        ids[i] = i + 1;
        if (pthread_create(&threads[i], NULL, thread_function, &ids[i]) != 0) {
            perror("Erro ao criar thread");
            exit(1);
        }
    }

    // Espera todas as threads terminarem
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Todas as threads finalizaram.\n");
    return 0;
}
