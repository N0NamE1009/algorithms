#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_RUN 32

void insertionSort(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void merge(int arr[], int left, int mid, int right) {
    int len1 = mid - left + 1, len2 = right - mid;
    int *leftArr = (int *)malloc(len1 * sizeof(int));
    int *rightArr = (int *)malloc(len2 * sizeof(int));

    for (int i = 0; i < len1; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < len2; i++)
        rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < len1 && j < len2) {
        if (leftArr[i] <= rightArr[j])
            arr[k++] = leftArr[i++];
        else
            arr[k++] = rightArr[j++];
    }

    while (i < len1)
        arr[k++] = leftArr[i++];
    while (j < len2)
        arr[k++] = rightArr[j++];

    free(leftArr);
    free(rightArr);
}

void timSort(int arr[], int n) {
    for (int i = 0; i < n; i += MIN_RUN) {
        int end = (i + MIN_RUN - 1 < n) ? i + MIN_RUN - 1 : n - 1;
        insertionSort(arr, i, end);
    }

    for (int size = MIN_RUN; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = (left + size - 1 < n) ? left + size - 1 : n - 1;
            int right = (left + 2 * size - 1 < n) ? left + 2 * size - 1 : n - 1;

            if (mid < right)
                merge(arr, left, mid, right);
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {5, 21, 7, 23, 19, 4, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("\nArray original:\n");
    printArray(arr, n);

    timSort(arr, n);

    printf("\nArray ordenado:\n");
    printArray(arr, n);

    return 0;
}