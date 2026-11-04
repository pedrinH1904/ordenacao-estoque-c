/*
 * Aplicação prática: Bubble Sort e Quick Sort
 * Situação do cotidiano: organizar o estoque de uma loja pela quantidade
 * de cada produto, para saber rapidamente o que está acabando
 * (reposição) e o que está sobrando.
 *
 * Os MESMOS dados são ordenados pelos dois algoritmos, e os resultados
 * são exibidos antes e depois da ordenação.
 */

#include <stdio.h>
#include <string.h>

#define TOTAL 10

/* Registro de um produto do estoque */
typedef struct {
    int codigo;
    char nome[30];
    int quantidade;
} Produto;

/* Mostra a tabela de produtos na tela */
void exibir(Produto v[], int n) {
    printf("%-8s %-25s %s\n", "Codigo", "Produto", "Quantidade");
    printf("---------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-8d %-25s %d\n", v[i].codigo, v[i].nome, v[i].quantidade);
    }
    printf("\n");
}

/*
 * BUBBLE SORT
 * Percorre o vetor comparando pares de elementos vizinhos. Se o da
 * esquerda for maior que o da direita, eles trocam de lugar. A cada
 * passada completa, o maior elemento "flutua" (como uma bolha) até o
 * final, então a parte final do vetor já fica ordenada. Repete-se até
 * não haver mais trocas. Complexidade: O(n²).
 */
void bubbleSort(Produto v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int trocou = 0; /* controla se houve troca nesta passada */
        for (int j = 0; j < n - 1 - i; j++) {
            if (v[j].quantidade > v[j + 1].quantidade) {
                Produto aux = v[j];   /* troca os dois produtos */
                v[j] = v[j + 1];
                v[j + 1] = aux;
                trocou = 1;
            }
        }
        if (!trocou) break; /* nenhuma troca: vetor já está ordenado */
    }
}

/*
 * QUICK SORT
 * Usa a estratégia "dividir para conquistar":
 * 1) Escolhe um elemento como pivô (aqui, o último do trecho).
 * 2) Particiona: move os menores que o pivô para a esquerda e os
 *    maiores para a direita, deixando o pivô na posição final correta.
 * 3) Repete o processo recursivamente para a parte esquerda e a direita.
 * Complexidade média: O(n log n); pior caso: O(n²).
 */
int particionar(Produto v[], int inicio, int fim) {
    int pivo = v[fim].quantidade;
    int i = inicio - 1; /* fronteira dos elementos menores que o pivô */

    for (int j = inicio; j < fim; j++) {
        if (v[j].quantidade <= pivo) {
            i++;
            Produto aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        }
    }
    /* coloca o pivô na posição correta */
    Produto aux = v[i + 1];
    v[i + 1] = v[fim];
    v[fim] = aux;
    return i + 1;
}

void quickSort(Produto v[], int inicio, int fim) {
    if (inicio < fim) {
        int p = particionar(v, inicio, fim);
        quickSort(v, inicio, p - 1); /* lado esquerdo do pivô */
        quickSort(v, p + 1, fim);    /* lado direito do pivô */
    }
}

int main(void) {
    /* Dados originais do estoque (10 registros, fora de ordem) */
    Produto estoque[TOTAL] = {
        {101, "Arroz 5kg",          42},
        {102, "Feijao 1kg",         15},
        {103, "Macarrao 500g",      68},
        {104, "Oleo de soja",        7},
        {105, "Acucar 1kg",         33},
        {106, "Cafe 500g",          21},
        {107, "Leite integral 1L",  90},
        {108, "Sal 1kg",             4},
        {109, "Farinha de trigo",   27},
        {110, "Biscoito recheado",  55}
    };

    Produto copiaBubble[TOTAL], copiaQuick[TOTAL];
    memcpy(copiaBubble, estoque, sizeof(estoque)); /* mesmos dados */
    memcpy(copiaQuick,  estoque, sizeof(estoque)); /* para os 2 algoritmos */

    printf("=== ESTOQUE ORIGINAL (antes da ordenacao) ===\n");
    exibir(estoque, TOTAL);

    bubbleSort(copiaBubble, TOTAL);
    printf("=== ORDENADO COM BUBBLE SORT (menor -> maior quantidade) ===\n");
    exibir(copiaBubble, TOTAL);

    quickSort(copiaQuick, 0, TOTAL - 1);
    printf("=== ORDENADO COM QUICK SORT (menor -> maior quantidade) ===\n");
    exibir(copiaQuick, TOTAL);

    return 0;
}
