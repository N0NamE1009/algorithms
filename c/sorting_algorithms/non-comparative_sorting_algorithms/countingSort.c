#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void countingSort(int arr[], int n, int range) {
    int* count = (int*)calloc(range, sizeof(int));
    int* output = (int*)malloc(n * sizeof(int));

    // Contar las ocurrencias
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Acumular las posiciones
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // Construir el array ordenado
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copiar el array ordenado al original
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(count);
    free(output);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int range = 9; // Rango de los valores (0 a 8)

    printf("\nArray original:\n");
    printArray(arr, n);

    countingSort(arr, n, range);

    printf("\nArray ordenado:\n");
    printArray(arr, n);

    return 0;
}