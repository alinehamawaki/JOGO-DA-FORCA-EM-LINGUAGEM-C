//esse é o arquivo que contém todas as estrturas das funções que serão usadas no codigo
#include<stdio.h>
#include"forca.h"
#include<time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//A função carregarPalavras() – seleciona uma palavra aleatória do arquivo palavras.txt 
void carregarPalavras(char palavra[]) {
    FILE *arquivo = fopen("palavras.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    
    char palavras[30][100]; 
    int total = 0;
    char linha[100];
  

    while (fgets(linha, sizeof(linha), arquivo)) {
        int i = 0;
        while (linha[i] != '\0') {
            if (linha[i] == '\n') {
                linha[i] = '\0';
                break;
            }
            i++;
        }

        strcpy(palavras[total], linha);
        total++; 
    }

    fclose(arquivo);


    srand(time(NULL)); 
    int sorteada= rand()%total;
    strcpy(palavra, palavras[sorteada]);
}




//A função registrarResultado() vai passar para o arquivo resultados.txt o nome do jogador, a palavra da jogada e o resultado da partida
void registrarResultado(const char* nome,const char* palavra, int resultado){

    FILE *arquivo = fopen("resultados.txt", "a");

     if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    const char* resultadopalavra;
    if(resultado == 0){
       (resultadopalavra= "Derrota");
    }else{
       (resultadopalavra= "Vitoria");
    }

    fprintf(arquivo, "Nome do jogador: %s\nPalavra sorteada: %s\nResultado: %s\n\n", nome, palavra, resultadopalavra);

    fclose(arquivo);
}

// Função desenharForca vai imprimir a representação atual do boneco e da forca de acordo com o numero de erros do jogador e imprie o estado da palavra.
void desenharForca (int erros, char* letrasDescobertas, int tamanhoPalavra) {
    if(erros == 0) {
        printf("\n-------------"); 
        printf("\n|           |"); 
        printf("\n|"); 
        printf("\n|"); 
        printf("\n|");
        printf("\n|"); 
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n--");
    }
    else if(erros == 1) {
        printf("\n-------------"); 
        printf("\n|           |"); 
        printf("\n|           0"); 
        printf("\n|"); 
        printf("\n|"); 
        printf("\n|"); 
        printf("\n|"); 
        printf("\n|"); 
        printf("\n|"); 
        printf("\n--");
    }
    else if(erros == 2) {
        printf("\n-------------"); 
        printf("\n|           |"); 
        printf("\n|           0"); 
        printf("\n|           |"); 
        printf("\n|"); 
        printf("\n|"); 
        printf("\n|"); 
        printf("\n|"); 
        printf("\n|"); 
        printf("\n--");
    }
    else if(erros == 3) {
        printf("\n-------------"); 
        printf("\n|           |"); 
        printf("\n|           0"); 
        printf("\n|         --|"); 
        printf("\n|"); 
        printf("\n|"); 
        printf("\n|"); 
        printf("\n|"); 
        printf("\n|"); 
        printf("\n--");
    }
    else if(erros == 4) {
        printf("\n-------------"); 
        printf("\n|           |"); 
        printf("\n|           0"); 
        printf("\n|         --|--"); 
        printf("\n|"); 
        printf("\n|"); 
        printf("\n|"); 
        printf("\n|"); 
        printf("\n|"); 
        printf("\n--");
    }
 
    else if(erros == 5) {
        printf("\n-------------"); 
        printf("\n|           |"); 
        printf("\n|           0"); 
        printf("\n|         --|--"); 
        printf("\n|          /"); 
        printf("\n|"); 
        printf("\n|"); 
        printf("\n|"); 
        printf("\n|"); 
        printf("\n--");
    }
    else if(erros == 6) {
        printf("\n-------------"); 
        printf("\n|           |"); 
        printf("\n|           0"); 
        printf("\n|         --|--"); 
        printf("\n|          / \\");
        printf("\n|"); 
        printf("\n|"); 
        printf("\n|    Fim de jogo!"); 
        printf("\n|"); 
        printf("\n--");
    }
     printf("\n\nPalavra: "); 

    for ( int i = 0; i < tamanhoPalavra; i++) {
        printf("%c ", letrasDescobertas[i]); 
    }
    printf("\n");
}

// Verifica se a letra já foi utilizada, se foi pede para o usuário digitar novamente e se não, já marca como "utilizada" para as tentativas futuras.
int verificarLetra(char letra, int letrasUsadas[26]) {
    letra = toupper(letra); 
    int index = letra - 'A';  
    
    if (letra < 'A' || letra > 'Z') {
        printf("Caractere invalido! Digite apenas letras de A a Z.\n");
        return 1;
    }

    if (letrasUsadas[index] == 1) {
        printf("Voce ja tentou a letra '%c'.\n", letra); 
        return 1;
    }
    else {
        letrasUsadas[index] = 1;
        return 0;
    }

}

//A função que retorna o tema da forca
void dica(const char* palavra) {
    printf("\nDICA:O tema da forca eh comida!Boa sorte!\n");
}
