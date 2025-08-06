//esse é o arquivo com o cabeçalho de todas as funções
#ifndef FORCA_H
#define FORCA_H

void carregarPalavras(char palavra[]);
void registrarResultado(const char* nome,const char* palavra, int resultado);
void desenharForca (int erros, char* letrasDescobertas, int tamanhoPalavra);
int verificarLetra(char letra, int letrasUsadas[26]);
void dica(const char* palavra);


#endif
