def flip(arr, k):
    start = 0
    while start < k:
        arr[start], arr[k] = arr[k], arr[start]
        start += 1
        k -= 1

def find_max_index(arr, n):
    max_index = 0
    for i in range(1, n):
        if arr[i] > arr[max_index]:
            max_index = i
    return max_index

def pancake_sort(arr):
    n = len(arr)
    for size in range(n, 1, -1):
        max_index = find_max_index(arr, size)

        if max_index != size - 1:
            # Llevar el maximo a la parte superior
            flip(arr, max_index)

            # Llevar el maximo a su posicion final
            flip(arr, size - 1)

# Ejemplo de uso
arr = [3, 6, 2, 7, 4, 5]
print("\nArray original:", arr)
pancake_sort(arr)
print("\nArray ordenado:", arr)