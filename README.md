# Ordenação de Estoque em C — Bubble Sort e Quick Sort

Atividade de **Algoritmos e Pensamento Computacional** (Profª Karla Sartin).

## Objetivo
Aplicar os algoritmos de ordenação **Bubble Sort** e **Quick Sort** em uma situação do cotidiano, comparando os resultados de ambos sobre os mesmos dados.

## Situação-problema
Uma loja precisa saber quais produtos estão com **pouco estoque** (para repor) e quais têm **muito** (para fazer promoção). Para isso, a lista de produtos é ordenada pela quantidade disponível, do menor para o maior. Sem ordenação, seria necessário procurar item por item na lista.

## Como executar
Pré-requisito: compilador GCC.

```bash
gcc main.c -o estoque
./estoque        # no Windows: estoque.exe
```

## O que o programa faz
1. Possui 10 produtos (código, nome, quantidade) fora de ordem.
2. Exibe os dados **antes** da ordenação.
3. Ordena uma cópia com **Bubble Sort** e exibe o resultado.
4. Ordena outra cópia com **Quick Sort** e exibe o resultado.

## Os algoritmos

### Bubble Sort
Compara pares de elementos vizinhos e troca de lugar se estiverem na ordem errada. A cada passada, o maior elemento "flutua" até o final do vetor. Para quando uma passada não faz nenhuma troca.
- Complexidade: **O(n²)**
- Simples, mas lento para muitos dados.

### Quick Sort
Escolhe um **pivô**, separa os elementos menores à esquerda e os maiores à direita (partição) e repete o processo recursivamente em cada lado.
- Complexidade média: **O(n log n)**; pior caso: O(n²)
- Muito mais rápido para grandes volumes de dados.

## Autor
Pedro Henrique de Lira Tavares — [@pedrinH1904](https://github.com/pedrinH1904)
