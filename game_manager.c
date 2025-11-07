#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_JOGOS 50
#define MAX_NOME 100

char nomes[MAX_JOGOS][MAX_NOME];
float notas[MAX_JOGOS];
int horasJogadas[MAX_JOGOS];
int totalJogos = 0;

void clearBuffer() {
    while (getchar() != '\n');
}

void adicionarJogo() {
    if (totalJogos >= MAX_JOGOS) {
        printf(" ! A lista está cheia!");
        return;
    }

    clearBuffer();
    
    // Pede nome, nota, horas
    printf("\n • Nome do jogo: ");
    fgets(nomes[totalJogos], MAX_NOME, stdin);
    nomes[totalJogos][strcspn(nomes[totalJogos], "\n")] = '\0';
    
    printf("\n • Horas jogadas [INT]: ");
    scanf("%d", &horasJogadas[totalJogos]);

    printf("\n • Nota [0/10]: ");
    scanf("%f", &notas[totalJogos]);

    // Adiciona nos arrays
    totalJogos++;

    printf("\n + Jogo adicionado.\n");

}

void listarJogos() {
    // Loop mostrando todos os jogos

    for (int i = 0; i < totalJogos; i++) {
        printf("\n • %d. %s - Nota: %.2f - Horas: %d\n", i + 1, nomes[i], notas[i], horasJogadas[i]);
    }

}

void verEstatisticas() {
    // Calcula média de notas
    float somaNotas = 0, mediaDeNotas = 0;
    
    for (int i = 0; i < totalJogos; i++) {
        somaNotas += notas[i];
    }

    mediaDeNotas = somaNotas / totalJogos;
    printf("\n • A média de notas é: %.2f\n", mediaDeNotas);

    // Soma total de horas

    int somaHoras = 0;
    
    for (int i = 0; i < totalJogos; i++) {
        somaHoras += horasJogadas[i];
    }
    
    printf(" • Total de Horas jogadas: %d", somaHoras);

    // Encontra jogo com maior nota

    float maiorNota;

    for (int i = 0; i < totalJogos; i++) {
        if (notas[0] < notas[i]) {
            maiorNota = notas[0] = notas[i];
        }
    }

    printf("\n • Maior nota: %.2f\n", maiorNota);
}

void sortearJogo() {
    if (totalJogos == 0) {
        printf("Nenhum jogo cadastrado!");
        return;
    }
    int jogoSorteado = rand() % totalJogos;
    printf("\n • Jogo sorteado: %s\n", nomes[jogoSorteado]);
}

void buscarJogo() {
    //strcmp() pra comparar strings
    
    char busca[MAX_NOME];
    
    clearBuffer();
    printf(" • Nome do jogo: ");
    fgets(busca, MAX_NOME, stdin);
    busca[strcspn(busca, "\n")] = '\0';

    for (int i = 0; i < totalJogos; i++) {
        if (strcmp(nomes[i], busca) == 0) {
            printf("\n + Jogo encontrado!\n");
            printf("%s - Nota: %.2f - Horas: %d\n", nomes[i], notas[i], horasJogadas[i]);
            return;
        }
    }

    printf(" - Jogo não encontrado.");
    
}

void removerJogo() {
    listarJogos();
    
    int indice;
    printf("\n • Número do jogo a remover: ");
    scanf("%d", &indice);
    indice--;

    if (indice < 0 || indice >= totalJogos) {
        printf("\n ! Índice inválido");
        return;
    }

    for (int i = indice; i < totalJogos - 1; i++) {
        strcpy(nomes[i], nomes[i + 1]);
        notas[i] = notas[i + 1];
        horasJogadas[i] = horasJogadas[i + 1];
    }

    totalJogos--;
    printf("\n + Jogo removido");

}

int main() {
    srand(time(NULL));
    int opcao;
    
    do {
        // Menu principal
        printf("\n================================");
        printf("\n      GERENCIADOR DE JOGOS      ");
        printf("\n================================");
        printf("\n 1. Adicionar jogo");
        printf("\n 2. Listar jogos");
        printf("\n 3. Ver estatísticas");
        printf("\n 4. Sortear jogo aleatório");
        printf("\n 5. Buscar jogo");
        printf("\n 6. Remover jogo.");
        printf("\n 7. Sair");

        printf("\n\n • Digite a opção: ");
        scanf("%d", &opcao); 

        // switch-case
        switch (opcao) {
            case 1:
                adicionarJogo();
            break;
            case 2:
                listarJogos();
            break;
            case 3:
                verEstatisticas();
            break;
            case 4:
                sortearJogo();
            break;
            case 5:
                buscarJogo();
            break;
            case 6:
                removerJogo();
            break;
        }
    } while (opcao != 7);
}