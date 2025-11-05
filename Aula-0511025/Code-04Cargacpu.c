#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

#define NUM_THREADS 50
#define EXEC_TIME 20

//Uso
 //%gcc cpu_stress_20s.c -o cpu_stress_20s -lpthread -lm
//%./cpu_stress_20s
 
  
void* cpu_burn(void* arg) {
    int id = *(int*)arg;
    double x = 0.0001;
    clock_t start = clock();
    printf("Thread %d iniciada.\n", id);

    while ((double)(clock() - start) / CLOCKS_PER_SEC < EXEC_TIME) {
        // Operações matemáticas intensivas para ocupar CPU
        x = sin(x) * tan(x) * sqrt(fabs(x)) + 1.0;
        if (x > 1000) x = 0.0001;
    }

    printf("Thread %d finalizada.\n", id);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int ids[NUM_THREADS];
    int i;

    printf("Gerando %d threads para usar CPU por %d segundos...\n", NUM_THREADS, EXEC_TIME);

    // Criação das threads
    for (i = 0; i < NUM_THREADS; i++) {
        ids[i] = i + 1;
        if (pthread_create(&threads[i], NULL, cpu_burn, &ids[i]) != 0) {
            perror("Erro ao criar thread");
            exit(1);
        }
    }

    // Espera todas as threads terminarem
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Execução completa.\n");
    return 0;
}
