#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 3  // número de threads

// Função executada por cada thread
void* tarefa(void* arg) {
    int id = *(int*)arg;

    switch (id) {
        case 1:
            printf("\n[Thread %d] Mostrando data e hora:\n", id);
            system("date");
            break;

        case 2:
            printf("\n[Thread %d] Listando arquivos do diretório atual:\n", id);
            system("ls -l");
            break;

        case 3:
            printf("\n[Thread %d] Mostrando tempo de máquina ligada (uptime):\n", id);
            system("uptime");
            break;

        default:
            printf("\n[Thread %d] Nenhuma tarefa atribuída.\n", id);
            break;
    }

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

    printf("\nTodas as threads foram encerradas.\n");
    return 0;
}
