def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        # Mover elementos mayores que la clave hacia la derecha
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

# Ejemplo de uso
arr = [12, 11, 13, 5, 6]
print(f"\nArray original: {arr}")
insertion_sort(arr)
print(f"\nArray ordenado: {arr}")