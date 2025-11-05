#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 5
#define MAX_RAM 2  // capacidade máxima da memória principal (RAM)

// Estrutura de processo
typedef struct {
    int pid;
    char nome[20];
    int estado; // 0 = no disco, 1 = na RAM
} Processo;

// Simula carregamento de um processo na RAM
void swap_in(Processo *p) {
    p->estado = 1;
    printf("Swap IN: Processo %s (PID %d) carregado para a RAM.\n", p->nome, p->pid);
}

// Simula remoção de um processo da RAM (para o disco)
void swap_out(Processo *p) {
    p->estado = 0;
    printf("📤 Swap OUT: Processo %s (PID %d) movido para o disco.\n", p->nome, p->pid);
}

int main() {
    Processo processos[MAX_PROCESSES] = {
        {1, "Editor", 0},
        {2, "Navegador", 0},
        {3, "Compilador", 0},
        {4, "Terminal", 0},
        {5, "Jogador", 0}
    };

    int ram_count = 0;  // quantos processos estão na RAM
    printf("=== Simulação de Swapping de Processos ===\n\n");

    for (int i = 0; i < MAX_PROCESSES; i++) {
        if (ram_count >= MAX_RAM) {
            // RAM cheia → escolher um processo para swap out
            for (int j = 0; j < MAX_PROCESSES; j++) {
                if (processos[j].estado == 1) {
                    swap_out(&processos[j]);
                    ram_count--;
                    break;
                }
            }
        }
        // Carrega o próximo processo
        swap_in(&processos[i]);
        ram_count++;

        printf("\n📊 Estado atual da memória:\n");
        for (int k = 0; k < MAX_PROCESSES; k++) {
            printf(" - Processo %-10s | PID: %d | Estado: %s\n",
                   processos[k].nome,
                   processos[k].pid,
                   processos[k].estado ? "RAM" : "Disco");
        }
        printf("--------------------------------------------\n\n");
    }

    printf("Todos os processos foram processados com swapping.\n");
    return 0;
}
