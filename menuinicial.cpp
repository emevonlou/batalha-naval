#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <time.h>
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
            // cout << " " << tabuleiro[linha][coluna];
            cout << " " << mascara[linha][coluna];
        }
        cout << endl;
    }

    for (linha = 0; linha < 10; linha++)
    {
        for (coluna = 0; coluna < 10; coluna++)
        {
            cout << " " << tabuleiro[linha][coluna];
            // cout << " " << mascara[linha][coluna];
        }
        cout << endl;
    }
}

void posicionaBarcos(char tabuleiro[10][10])
{
    // Coloca dez barcos no tabuleiro.
    int cont, quantidade = 10, quantidadePosicionada = 0;
    // Verifica se ja posicionou todos os barcos.
    while (quantidadePosicionada < quantidade)
    {
        int linhaAleatoria = rand() % 10; // Gera numero aleatorio de zero a nove.
        int colunaAleatoria = rand() % 10;

        if (tabuleiro[linhaAleatoria][colunaAleatoria] == 'E')
        {
            // Posiciona dez barcos aleatorios.
            tabuleiro[linhaAleatoria][colunaAleatoria] = 'B'; // Posicionando quatro barquinhos(manualmente).
            // Aumenta o contador de barcos posicionados.
            quantidadePosicionada++;
        }
    }
}

void verificaTiro(char tabuleiro[10][10], int linhaJogada, int colunaJogada, int *pontos, string *mensagem)
{
    // Verifica quantos pontos adicionar!
    switch (tabuleiro[linhaJogada][colunaJogada])
    {
    case 'B':
        *pontos = *pontos + 10;
        *mensagem = "Voce acertou um barco pequeno!(10 pts)";
        break;
    case 'E':
        *mensagem = "Voce acertou a agua!";
        break;
    }
}

void jogo()
{
    // Variaveis gerais.
    char tabuleiro[10][10], mascara[10][10];
    int linhaJogada, colunaJogada; // Posicao escolhida pelo jogador.
    int estadoDeJogo = 1;          // 1 = jogo acontecendo; 0 = fim de jogo.

    // Navegando em uma matriz- variaveis auxiliares.
    int linha, coluna;
    int pontos = 0; // Pontuacao do jogador.
    string mensagem = "Bem vindo ao Jogo!"; // Mensagem de Feedback para o jogador.
    int tentativas;
    // Inicia o tabuleiro com água.
    iniciaTabuleiro(tabuleiro, mascara);

    // Posiciona barcos aleatoriamente.
    posicionaBarcos(tabuleiro);

    while (estadoDeJogo == 1)
    {
        limpaTela();

        // Exibe tabuleiro.
        exibeTabuleiro(tabuleiro, mascara);

        cout << "\nPontos: " << pontos << endl;
        cout << "\nMensagem: " << mensagem << endl;

        cout << "\nDigite uma linha: ";
        cin >> linhaJogada;
        cout << "\nDigite uma Coluna: ";
        cin >> colunaJogada;

        verificaTiro(tabuleiro, linhaJogada, colunaJogada, &pontos, &mensagem);

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
        // Gerando um numero aleatorio ate 10 com (rand() % 10).
        // cout << "ALEATORIO: " << rand() % 10 << endl << endl;
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