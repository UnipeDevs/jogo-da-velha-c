#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura de dados para armazenar as informacoes de cada jogador
typedef struct {
    char nome[50];   // Nome do jogador
    int vitorias;    // Numero de vitorias do jogador
} Jogador;

// Funcao que salva o ranking dos jogadores em um arquivo
void salvarRanking(Jogador jogador1, Jogador jogador2) {
    FILE *arquivo = fopen("ranking.txt", "w");  // Abre o arquivo para escrita
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar o ranking.\n");
        return;
    }
    
    // Escreve os dados dos jogadores no arquivo
    fprintf(arquivo, "%s: %d vitorias\n", jogador1.nome, jogador1.vitorias);
    fprintf(arquivo, "%s: %d vitorias\n", jogador2.nome, jogador2.vitorias);

    fclose(arquivo);  // Fecha o arquivo apos escrever
}

// Funcao que carrega o ranking dos jogadores a partir do arquivo
void carregarRanking(Jogador *jogador1, Jogador *jogador2) {
    FILE *arquivo = fopen("ranking.txt", "r");  // Abre o arquivo para leitura
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de ranking.\n");
        return;
    }

    // Le os dados dos jogadores e os armazena nas variaveis passadas por referencia
    fscanf(arquivo, "%s: %d vitorias\n", jogador1->nome, &jogador1->vitorias);
    fscanf(arquivo, "%s: %d vitorias\n", jogador2->nome, &jogador2->vitorias);

    fclose(arquivo);  // Fecha o arquivo apos a leitura
}