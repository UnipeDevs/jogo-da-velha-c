<<<<<<< HEAD
// Loop principal do jogo
    do {
        // Exibe o tabuleiro atual
        printf("\n\t 0   1   2\n");
        for (l = 0; l < 3; l++) {
            printf("\t");
            for (c = 0; c < 3; c++) {
                printf(" %c ", tabuleiro[l][c]);
                if (c < 2) printf("|");  // Adiciona as barras verticais entre as colunas
            }
            printf("  %d\n", l);  // Exibe o numero da linha
            if (l < 2) printf("\t---|---|---\n");  // Exibe a separacao entre as linhas
        }

        // Solicita a entrada de dados para a jogada
        printf("\nJOGADOR %s (%c): Digite a linha e depois a coluna que deseja jogar (utilize um espaco entre os numeros): ", 
               jogadorAtual == 1 ? jogador1->nome : jogador2->nome, 
               jogadorAtual == 1 ? 'X' : 'O');
        scanf("%d %d", &linha, &coluna);

        // Valida a jogada (garante que a posicao seja valida e esteja livre)
        while (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || tabuleiro[linha][coluna] != ' ') {
            printf("Jogada invalida. Tente novamente (linha coluna): ");
            scanf("%d %d", &linha, &coluna);
        }

        // Realiza a jogada no tabuleiro
        tabuleiro[linha][coluna] = (jogadorAtual == 1) ? 'X' : 'O';
        jogadas++;

        // Verifica se algum jogador ganhou
        for (l = 0; l < 3; l++) {
            if (tabuleiro[l][0] == tabuleiro[l][1] && tabuleiro[l][1] == tabuleiro[l][2] && tabuleiro[l][0] != ' ') 
                ganhou = jogadorAtual;
            if (tabuleiro[0][l] == tabuleiro[1][l] && tabuleiro[1][l] == tabuleiro[2][l] && tabuleiro[0][l] != ' ') 
                ganhou = jogadorAtual;
        }
        if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ') 
            ganhou = jogadorAtual;
        if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ') 
            ganhou = jogadorAtual;

        // Alterna para o proximo jogador
        if (!ganhou) jogadorAtual = (jogadorAtual == 1) ? 2 : 1;

    } while (!ganhou && jogadas < 9);  // O jogo continua ate alguem ganhar ou o numero de jogadas atingir 9 (empate)

    // Exibe o resultado
    if (ganhou) {
        printf("\nParabens, %s! Voce venceu!\n", ganhou == 1 ? jogador1->nome : jogador2->nome);
        if (ganhou == 1) jogador1->vitorias++;  // Incrementa as vitorias do jogador vencedor
        else jogador2->vitorias++;
    } else {
        printf("\nDeu velha! Ninguem venceu.\n");  // Empate
    }

    // Salva o ranking atual
    salvarRanking(*jogador1, *jogador2);

    // Libera a memoria do tabuleiro
    liberarTabuleiro(tabuleiro);
}
=======
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
>>>>>>> 71561156511083b97cf8e81d69f754089f985190
