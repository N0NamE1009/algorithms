#include <stdio.h>
#include <stdlib.h>

// Funcion para ordenar una cubeta usando Insertion Sort
void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Bucket Sort
void bucketSort(float arr[], int n) {
    // Crear cubetas
    int numBuckets = 10;
    float* buckets[numBuckets];
    int bucketSizes[numBuckets];

    for (int i = 0; i < numBuckets; i++) {
        buckets[i] = (float*)malloc(n * sizeof(float));
        bucketSizes[i] = 0;
    }

    // Distribuir elementos en cubetas
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(arr[i] * numBuckets);
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
    }

    // Ordenar cubetas y concatenar resultados
    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        insertionSort(buckets[i], bucketSizes[i]);
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
        free(buckets[i]);
    }
}

// Imprimir un array
void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

int main() {
    float arr[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("\nArray original:\n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("\nArray ordenado:\n");
    printArray(arr, n);

    return 0;
}