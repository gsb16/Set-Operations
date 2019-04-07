# Operações de conjuntos

## Autores:
Guilherme Bastos de Oliveira
Gabriel de Souza Barreto

## Objetivo:
Trabalho para a disciplina de Algoritmos 2

## Makefile:
- *make:* compila o programa
- *make clean:* deleta arquivos temporários de compilação
- *make purge:* executa clean e remove executavel

## Parte 2
A parte 2 do trabalho está implementada.
Para compilar basta usar o make.

Para realizar a parte 2 foi necessário contruir uma função para verificar se um conjunto é superconjunto de outro.
Essa mesma função permite fazer o teste para subconjuntos.
Com essa parte pronta a listagem de superconjuntos e subconjuntos se tornou simples, bastando comparar todos os conjuntos que são superconjunto ou subconjunto potenciais.  

## Parte 1
A parte 1 do trabalho está implementada.
Para compilar basta usar o make.

Após decidirmos sobre as estruturas de dados a serem utilizadas, tivemos um pouco de dificuldade em usar os ponteiros de forma correta e para manter os conjuntos sempre ordenados após cada inclusão/remoção.
A busca que fazemos e a velocidade da execução dependem diretamente de conservar os conjuntos ordenados.
Também foi necessário pensar na forma de administrar os mallocs e reallocs  durante a execução do código, para não faltar espaço para guardar os conjuntos e não existir o risco de memory leak.
