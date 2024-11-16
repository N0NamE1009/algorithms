import random

# Funcion para verificar si el array esta ordenado
def is_sorted(arr):
    return all(arr[i] <= arr[i + 1] for i in range(len(arr) - 1))

# Bogo Sort
def bogo_sort(arr):
    while not is_sorted(arr):
        random.shuffle(arr)

# Ejemplo de uso
arr = [3, 2, 5, 1, 4]
print("\nArray original:", arr)
bogo_sort(arr)
print("\nArray ordenado:", arr)