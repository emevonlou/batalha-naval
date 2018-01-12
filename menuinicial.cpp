#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdio.h>
using namespace std;

void limpaTela()
{
    system("clear");
}

void iniciaTabuleiro(char tabuleiro[10][10], char mascara[10][10])
{
    int linha, coluna;

    // Popula o tabuleiro com 'A'
    for (linha = 0; linha < 10; linha++)        // Para linhas
    {                                           // para cada linha, dá zero, até a nove.
        for (coluna = 0; coluna < 10; coluna++) // Para colunas
        {
            tabuleiro[linha][coluna] = 'E';
            mascara[linha][coluna] = '*'; // Adicionando o simbolo de asterisco na masc
        }
    }
}

void exibeTabuleiro(char tabuleiro[10][10], char mascara[10][10])
{
    int linha, coluna;
    // Exibe o tabuleiro.
    for (linha = 0; linha < 10; linha++)
    {
        for (coluna = 0; coluna < 10; coluna++)
        {
            //cout << " " << tabuleiro[linha][coluna];
            cout << " " << mascara[linha][coluna];
        }
        cout << endl;
    }
}

void posicionaBarcos(char tabuleiro[10][10])
{
    tabuleiro[0][0] = 'B'; // Posicionando quatro barquinhos(manualmente).
    tabuleiro[2][0] = 'B';
    tabuleiro[5][5] = 'B';
    tabuleiro[6][7] = 'B';
}

void jogo()
{
    // Variaveis gerais.
    char tabuleiro[10][10], mascara[10][10];
    int linhaJogada, colunaJogada; // Posicao escolhida pelo jogador.
    int estadoDeJogo = 1;          // 1 = jogo acontecendo; 0= fim de jogo.

    // Navegando em uma matriz- variaveis auxiliares.
    int linha, coluna;

    // Inicia o tabuleiro com água.
    iniciaTabuleiro(tabuleiro, mascara);

    // Posiciona barcos aleatoriamente.
    posicionaBarcos(tabuleiro);

    while (estadoDeJogo == 1)
    {
        limpaTela();

        // Exibe tabuleiro.
        exibeTabuleiro(tabuleiro, mascara);
        cout << "\nDigite uma linha: ";
        cin >> linhaJogada;
        cout << "\nDigite uma Coluna: ";
        cin >> colunaJogada;

        // Revela o que esta no tabuleiro.
        mascara[linhaJogada][colunaJogada] = tabuleiro[linhaJogada][colunaJogada];
    }
}

void menuInicial()
{
    // Opção escolhida pelo usuário.
    int opcao = 0;

    // Enquanto o jogador não digita uma opção válida, mostra o menu novamente.
    while (opcao < 1 || opcao > 3)
    {
        limpaTela();
        cout << "Bem vindo ao Jogo Batalha Naval!" << endl;
        cout << "1 - Jogar" << endl;
        cout << "2 - Sobre" << endl;
        cout << "3 - sair" << endl;
        cout << "Escolha uma opcao e tecle enter: ";

        // Faz a leitura da opção.
        cin >> opcao;

        // Faz algo de acordo com a opção escolhida.
        switch (opcao)
        {
        case 1:
            // Inicia o jogo.
            // cout << "Jogo iniciado" << endl;
            jogo();
            break;
        case 2:
            cout << "Informacoes do jogo" << endl;
            break;
        case 3:
            cout << "See you, buddy!" << endl;
            break;
        }
    }
}

int main()
{
    srand((unsigned)time(NULL)); // Codigo/função para gerar numeros aleatorios
    menuInicial();

    return 0;
}