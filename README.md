# JOGO-DA-FORCA-EM-LINGUAGEM-C
## DESENVOLVEDORAS:

Nome: Aline Sayuri Hamawaki Kawamura || Maria Paula Barbosa Vartuli.
Curso: Engenharia de Sistemas | UFMG. 
Disciplina: Programação e Desenvolvimento de Software I | PDS I.
Data de entrega: 02/07/2025. 
-------------------------------------------------------------------------------------------------------------------------------------------------------------  
## DESCRIÇÃO: 

Este projeto de trabalho prático implementa o clássico jogo da forca, desenvolvido para a disciplina de Programação e Desenvolvimento de Software I (PDS I) da Universidade Federal de Minas Gerais (UFMG). 
O jogo sorteia aleatoriamente uma palavra de um banco de palavras, com a temática de comidas/pratos, e o jogador deve adivinhá-la letra por letra. 
O jogo possui um número limitado de tentativas, até que o boneco seja completado e "enforcado".
-------------------------------------------------------------------------------------------------------------------------------------------------------------  
## ESTRUTURA DO PROJETO: 

- "main.c" - contém a função principal (main) e a lógica principal do programa. 
- "forca.c" - implementação das funções (carregar palavras, registrar resultado, desenhar forca e verificar letra). 
- "forca.h" - arquivo de cabeçalho com as declarações das funções usadas. 
- "palavras.txt" - lista de palavras que podem ser sorteadas durante o jogo. 
- "resultados.txt" - registro das partidas. 
- "README.txt" - este arquivo de instruções para compilação e execução. 
------------------------------------------------------------------------------------------------------------------------------------------------------------- 
## INSTRUÇÕES PARA COMPILAÇÃO NO PROMPT DE COMANDO DO WINDOWS: 

Pré requisitos: 1. Ter o GCC instalado no Windows;
                2. Estar com todos os arquivos na mesma pasta.

1. Navegue até a pasta onde estão os arquivos com o comando 'cd' e endereço da pasta, exemplo: 
    cd C:\Users\aline\Área de Trabalho\UFMG\PDS 1\TP_Forca_AlineSayuri_MariaPaula

2. Compile o programa usando o GCC: 
    gcc main.c forca.c -o forca

3. Execute o jogo digitando: 
    forca ou forca.exe
-------------------------------------------------------------------------------------------------------------------------------------------------------------
## INSTRUÇÕES DE USO / JOGO:

1. O jogo escolhe uma palavra aleatória do arquivo "palavras.txt". 
2. O jogador digita letras, uma de cada vez, para tentar adivinhar. 
3. A cada erro, as partes do boneco são desenhadas.
4. O jogo termina com vitória ou derrota. 
-------------------------------------------------------------------------------------------------------------------------------------------------------------
## OBSERVAÇÕES: 

- O jogo utiliza o total de 30 palavras, sorteadas aleatoriamente. 
- Letras maiúsculas e minúsculas são tratadas como iguais. 
- Palavras com acentos não são suportadas. 
- Para adicionar novas palavras no jogo, edite o arquivo "palavras.txt", escreva uma palavra em cada linha, sem acentos ou caracteres especiais.
- O tema pré definido das palavras possíveis de serem sorteadas é o de "comidas/pratos". 

-------------------------------------------------------------------------------------------------------------------------------------------------------------
## TESTES E EXEMPLOS DE EXECUÇÃO: 

| Nº  | Tipo de Teste                  | Palavra Sorteada | Entradas                 | Resultado Esperado                                                | Status |
| :-: | :----------------------------- | :--------------- | :----------------------- | :---------------------------------------------------------------- | :----: |
| 1   | Vitória                        | `arroz`          | `a, r, o, z`             | Palavra completada sem erros.                                     | OK     |
| 2   | Vitória com erros              | `canjica`        | `e, a, d, s, i, c, n, j` | Palavra completada com 3 erros (3 partes do boneco).              | OK     |
| 3   | Derrota                        | `feijoada`       | `t, r, q, w, j, k, f`    | Derrota por excesso de tentativas e exibe a palavra correta.      | OK     |
| 4   | Derrota                        | `panqueca`       | `t, d, f, g, s, q, j`    | Derrota por excesso de tentativas e exibe a palavra correta.      | OK     |
| 5   | Letra com mais de uma ocorrência | `panqueca`       | `a, n, p, q, u, e, c`    | As duas letras 'a' são reveladas na posição correta.              | OK     |
| 6   | Letra repetida                 | (qualquer)       | `a, a`                   | Exibe a mensagem "Voce ja tentou a letra A" e continua o jogo.     | OK     |
| 7   | Registro de resultados         | `pudim`          | `p, u, d, i, m`          | Ao final da partida, o resultado é salvo no arquivo `resultados.txt`. | OK     |
| 8   | Entrada inválida               | (qualquer)       | `ab` ou `1` ou `.`       | Entrada é ignorada e/ou uma mensagem de erro é exibida.           | OK     |
