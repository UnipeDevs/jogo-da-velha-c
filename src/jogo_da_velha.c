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
