#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 3

void* tarefa(void* arg) {
    int id = *(int*)arg;
    printf("Thread %d executando\n", id);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[N];
    int ids[N];

    for (int i = 0; i < N; i++) {
        ids[i] = i + 1;
        pthread_create(&threads[i], NULL, tarefa, &ids[i]);
    }

    for (int i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Todas as threads encerradas.\n");
    return 0;
}
