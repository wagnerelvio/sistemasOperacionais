#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();  // Cria um novo processo

    if (pid < 0) {
        perror("Erro ao criar processo");
        return 1;
    }

    if (pid == 0) {
        // Processo filho: executa o programa /usr/games/sl
        execl("/usr/games/sl", "sl", NULL);

        // Se execl retornar, houve erro
        perror("Erro ao executar /usr/games/sl");
        exit(1);
    } 
    else {
        // Processo pai: aguarda 30 segundos
        printf("Executando /usr/games/sl (PID = %d) por 30 segundos...\n", pid);
        sleep(30);

        // Encerra o processo filho
        if (kill(pid, SIGTERM) == 0)
            printf("Processo %d encerrado com sucesso.\n", pid);
        else
            perror("Erro ao encerrar o processo");

        return 0;
    }
}
