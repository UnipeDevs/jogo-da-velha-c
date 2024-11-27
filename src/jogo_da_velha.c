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