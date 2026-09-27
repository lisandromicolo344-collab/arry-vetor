#include <stdio.h>

#define TAMANHO 20

int main(void) {
    int numeros[TAMANHO];
    int somaMultiplosDe3 = 0;
    int somaPares = 0;
    int quantidadePares = 0;
    int quantidadePositivos = 0;
    int quantidadeNegativos = 0;
    int maior;
    int menor;
    int i;
    double mediaPares;

    printf("=== ANALISE DE 20 NUMEROS INTEIROS ===\n\n");

    /* Preenche o vetor com os valores informados pelo usuario. */
    for (i = 0; i < TAMANHO; i++) {
        printf("Digite o %do numero: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    /*
     * O maior e o menor valor sao inicialmente definidos
     * como o primeiro elemento do vetor.
     */
    maior = numeros[0];
    menor = numeros[0];

    /* Percorre o vetor para realizar todos os calculos. */
    for (i = 0; i < TAMANHO; i++) {
        /* Verifica se o numero e multiplo de 3. */
        if (numeros[i] % 3 == 0) {
            somaMultiplosDe3 += numeros[i];
        }

        /* Verifica se o numero e par. */
        if (numeros[i] % 2 == 0) {
            somaPares += numeros[i];
            quantidadePares++;
        }

        /*
         * Conta positivos e negativos.
         * O zero nao se enquadra em nenhuma das duas categorias.
         */
        if (numeros[i] > 0) {
            quantidadePositivos++;
        } else if (numeros[i] < 0) {
            quantidadeNegativos++;
        }

        /* Atualiza o maior valor encontrado. */
        if (numeros[i] > maior) {
            maior = numeros[i];
        }

        /* Atualiza o menor valor encontrado. */
        if (numeros[i] < menor) {
            menor = numeros[i];
        }
    }

    printf("\n=== RESULTADOS ===\n");
    printf("Soma dos multiplos de 3: %d\n", somaMultiplosDe3);

    /*
     * A media somente e calculada se houver pelo menos
     * um numero par, evitando uma divisao por zero.
     */
    if (quantidadePares > 0) {
        mediaPares = (double) somaPares / quantidadePares;
        printf("Media dos numeros pares: %.2f\n", mediaPares);
    } else {
        printf("Media dos numeros pares: nao existem numeros pares.\n");
    }

    printf("Quantidade de numeros positivos: %d\n", quantidadePositivos);
    printf("Quantidade de numeros negativos: %d\n", quantidadeNegativos);
    printf("Maior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);

    printf("\n=== ELEMENTOS DO VETOR ===\n");

    /* Exibe todos os elementos armazenados no vetor. */
    for (i = 0; i < TAMANHO; i++) {
        printf("%d", numeros[i]);

        if (i < TAMANHO - 1) {
            printf(", ");
        }
    }

    printf("\n");

    return 0;
}
