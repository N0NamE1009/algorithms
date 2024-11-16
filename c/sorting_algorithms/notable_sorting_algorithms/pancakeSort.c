#include <stdio.h>

// Voltear los primeros k elementos del array
void flip(int arr[], int k) {
    int start = 0;
    while (start < k) {
        int temp = arr[start];
        arr[start] = arr[k];
        arr[k] = temp;
        start++;
        k--;
    }
}

// Encontrar el indice del elemento maximo en un rango
int findMaxIndex(int arr[], int n) {
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

// Pancake Sort
void pancakeSort(int arr[], int n) {
    for (int size = n; size > 1; size--) {
        int maxIndex = findMaxIndex(arr, size);

        if (maxIndex != size - 1) {
            // Llevar el maximo a la parte superior
            flip(arr, maxIndex);

            // Llevar el maximo a su posicion final
            flip(arr, size - 1);
        }
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
    int arr[] = {3, 6, 2, 7, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("\nArray original:\n");
    printArray(arr, n);

    pancakeSort(arr, n);

    printf("\nArray ordenado:\n");
    printArray(arr, n);

    return 0;
}