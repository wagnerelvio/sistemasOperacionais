#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char buffer[128];

    // Executa o comando ps -e | wc -l e lê a saída
    fp = popen("ps -e | wc -l", "r");
    if (fp == NULL) {
        printf("Erro ao executar comando.\n");
        return 1;
    }

    // Lê o número de processos
    fgets(buffer, sizeof(buffer), fp);
    printf("Número total de processos em execução: %s", buffer);

    pclose(fp);
    return 0;
}
