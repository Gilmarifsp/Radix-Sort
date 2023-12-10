#include <stdio.h>

// Função para imprimir uma lista
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função para encontrar o maior número em uma lista
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Função para executar o Radix Sort
void radixSort(int arr[], int n) {
    int i, j, exp = 1;
    int max = findMax(arr, n);

    // Executa o Radix Sort
    while (max / exp > 0) {
        int bucket[10][n];
        int bucketCount[10] = {0};

        // Coloca os elementos nos baldes
        for (i = 0; i < n; i++) {
            int digit = (arr[i] / exp) % 10;
            bucket[digit][bucketCount[digit]++] = arr[i];
        }

        // Move os elementos de volta para a lista
        int k = 0;
        for (i = 0; i < 10; i++) {
            for (j = 0; j < bucketCount[i]; j++) {
                arr[k++] = bucket[i][j];
            }
        }

        // Imprime os baldes nesta análise
        printf("Baldes na analise de casa decimal: %d\n", exp / 10);
        for (i = 0; i < 10; i++) {
            printf("Balde %d: ", i + 1);
            printArray(bucket[i], bucketCount[i]);
        }

        // Atualiza a posição do dígito
        exp *= 10;
    }
}

int main() {
    int opcao;
    int arrMelhorCaso[] = {123, 456, 789, 321, 654};
    int arrCasoMedio[] = {12, 456, 7890, 321, 6543};
    int arrPiorCaso[] = {123, 456, 789, 321, 654, 1, 234, 567, 890, 4321};

    do {
        printf("\nMenu:\n");
        printf("1. Melhor caso\n");
        printf("2. Caso medio\n");
        printf("3. Pior caso\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nMelhor caso:\n");
                radixSort(arrMelhorCaso, sizeof(arrMelhorCaso) / sizeof(arrMelhorCaso[0]));
                printf("\nLista ordenada: ");
                printArray(arrMelhorCaso, sizeof(arrMelhorCaso) / sizeof(arrMelhorCaso[0]));
                break;

            case 2:
                printf("\nCaso medio:\n");
                radixSort(arrCasoMedio, sizeof(arrCasoMedio) / sizeof(arrCasoMedio[0]));
                printf("\nLista ordenada: ");
                printArray(arrCasoMedio, sizeof(arrCasoMedio) / sizeof(arrCasoMedio[0]));
                break;

            case 3:
                printf("\nPior caso:\n");
                radixSort(arrPiorCaso, sizeof(arrPiorCaso) / sizeof(arrPiorCaso[0]));
                printf("\nLista ordenada: ");
                printArray(arrPiorCaso, sizeof(arrPiorCaso) / sizeof(arrPiorCaso[0]));
                break;

            case 4:
                printf("\nEncerrando o programa.\n");
                break;

            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }

    } while (opcao != 4);

    return 0;
}
