# Ordenação de Estoque em C: Bubble Sort e Quick Sort

Trabalho da disciplina de Algoritmos e Pensamento Computacional, da professora Karla Sartin.

Executar o programa em C online: https://onlinegdb.com/9Am1k-Jue

## Objetivo

Aplicar os algoritmos Bubble Sort e Quick Sort em uma situação do dia a dia, ordenando os mesmos dados pelos dois métodos e mostrando os resultados.

## Situação-problema

Uma loja precisa saber quais produtos estão acabando, para repor, e quais estão com muita quantidade, para fazer promoção. Para isso, a lista de produtos é ordenada pela quantidade em estoque, da menor para a maior. Sem a ordenação, seria preciso olhar item por item da lista.

## Arquivos do projeto

- `main.c`: programa principal em C, com os registros, o Bubble Sort, o Quick Sort e a exibição dos dados.
- `index.html`: demonstração extra em JavaScript (parte 2), explicada mais abaixo.
- `README.md`: esta documentação.

## Como executar

Online: abra o link acima e clique em Run.

No computador, com o compilador GCC instalado:

```bash
gcc main.c -o estoque
./estoque
```

No Windows, o segundo comando é `estoque.exe`.

## Como o programa funciona

O programa guarda 10 produtos em uma struct, cada um com código, nome e quantidade. Primeiro ele mostra a lista original. Depois copia os dados para dois vetores, para que os dois algoritmos ordenem exatamente a mesma entrada. Por fim, ordena uma cópia com Bubble Sort e a outra com Quick Sort e mostra o resultado de cada um.

O código está todo no arquivo `main.c`, com comentários explicando cada algoritmo.

## Bubble Sort

Compara cada elemento com o vizinho e troca os dois de lugar se estiverem fora de ordem. A cada passada pelo vetor, o maior elemento vai para o final, como uma bolha subindo. Quando uma passada termina sem nenhuma troca, o vetor está ordenado. A complexidade é O(n²), então é simples de entender, mas fica lento com muitos dados.

## Quick Sort

Escolhe um elemento como pivô e separa os outros em dois grupos, os menores que o pivô e os maiores. O pivô fica na sua posição final, e o mesmo processo é repetido, por recursão, em cada grupo. A complexidade média é O(n log n), por isso é bem mais rápido que o Bubble Sort quando há muitos dados. No pior caso ele também chega a O(n²).

## Parte 2: demonstração em HTML

O arquivo `index.html` é uma página extra que usa os mesmos 10 produtos e reescreve os dois algoritmos em JavaScript. Ela permite escolher ordem crescente ou decrescente e mostra quantas comparações e quantas trocas cada algoritmo fez, para comparar os dois na prática.

Importante: o programa principal do trabalho é o `main.c`, em C. A página em HTML é só uma demonstração visual e não executa o código em C.

## Autor

Pedro Henrique de Lira Tavares (https://github.com/pedrinH1904)
