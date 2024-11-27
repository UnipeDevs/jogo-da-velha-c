<<<<<<< HEAD
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
=======
// Funcao principal que controla o menu e chama as outras funcoes
int main() {
    Jogador jogador1 = {"Jogador 1", 0};  // Inicializa o jogador 1
    Jogador jogador2 = {"Jogador 2", 0};  // Inicializa o jogador 2
    int opcao;

    // Carrega o ranking a partir do arquivo
    carregarRanking(&jogador1, &jogador2);

    // Loop do menu principal
    do {
        printf("\nMenu:\n");
        printf("1. Jogar\n");
        printf("2. Ver Ranking\n");
        printf("3. Creditos\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // Solicita os nomes dos jogadores antes de iniciar uma nova partida
                printf("Nome do Jogador 1: ");
                scanf(" %[^\n]", jogador1.nome);

                printf("Nome do Jogador 2: ");
                scanf(" %[^\n]", jogador2.nome);

                jogar(&jogador1, &jogador2);  // Inicia o jogo
                break;
            case 2:
                exibirRanking(jogador1, jogador2);  // Exibe o ranking
                break;
            case 3:
                exibirCreditos();  // Exibe os creditos
                break;
            case 4:
                printf("\nJogo encerrado\n");  // Encerra o jogo
                break;
        }
    } while (opcao != 4);  // Continua exibindo o menu até a opção 4 ser escolhida
    return 0;
}
>>>>>>> c5a71da7aa76f7c7b86cd736df28160f833b6897
// Funcao para criar o tabuleiro de jogo da velha dinamicamente
char** criarTabuleiro() {
    char** tabuleiro = malloc(3 * sizeof(char*));  // Aloca memoria para 3 linhas
    for (int i = 0; i < 3; i++) {
        tabuleiro[i] = malloc(3 * sizeof(char));  // Aloca memoria para 3 colunas em cada linha
        for (int j = 0; j < 3; j++) {
            tabuleiro[i][j] = ' ';  // Inicializa o tabuleiro com espacos vazios
        }
    }
    return tabuleiro;  // Retorna o tabuleiro criado
}

// Funcao para liberar a memoria do tabuleiro dinamico
void liberarTabuleiro(char** tabuleiro) {
    for (int i = 0; i < 3; i++) {
        free(tabuleiro[i]);  // Libera cada linha do tabuleiro
    }
    free(tabuleiro);  // Libera a memoria do proprio tabuleiro
}

// Funcao principal do jogo, onde a logica de execucao acontece
void jogar(Jogador *jogador1, Jogador *jogador2) {
    int l, c, linha, coluna, jogadorAtual = 1, ganhou = 0, jogadas = 0;
    char** tabuleiro = criarTabuleiro();  // Cria o tabuleiro dinamicamente