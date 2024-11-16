#include <stdio.h>
#include <stdlib.h>

// Obtener el digito mas significativo en la posicion exp
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Counting Sort modificado para Radix Sort
void countingSort(int arr[], int n, int exp) {
    int* output = (int*)malloc(n * sizeof(int));
    int count[10] = {0};

    // Contar ocurrencias de digitos
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Acumular posiciones
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Construir el array ordenado
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copiar el array ordenado al original
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(output);
}

// Radix Sort
void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    // Ordenar para cada digito
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

// Imprimir un array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("\nArray original:\n");
    printArray(arr, n);

    radixSort(arr, n);

    printf("\nArray ordenado:\n");
    printArray(arr, n);

    return 0;
}