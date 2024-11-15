#include <stdio.h>
#include <stdlib.h>

// Definicion del nodo del arbol binario
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Crear un nuevo nodo
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Insertar un nodo en el arbol
struct Node* insert(struct Node* node, int data) {
    if (node == NULL)
        return newNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    return node;
}

// Recorrido in-order del arbol
void inorder(struct Node* root, int arr[], int* index) {
    if (root != NULL) {
        inorder(root->left, arr, index);
        arr[(*index)++] = root->data;
        inorder(root->right, arr, index);
    }
}

// Tree Sort
void treeSort(int arr[], int n) {
    struct Node* root = NULL;

    // Insertar elementos en el arbol
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }

    // Recorrido in-order para ordenar
    int index = 0;
    inorder(root, arr, &index);
}

// Imprimir un array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {5, 3, 7, 1, 9, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("\nArray original:\n");
    printArray(arr, n);

    treeSort(arr, n);

    printf("\nArray ordenado:\n");
    printArray(arr, n);

    return 0;
}