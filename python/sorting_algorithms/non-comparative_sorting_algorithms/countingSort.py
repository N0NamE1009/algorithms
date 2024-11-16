def counting_sort(arr, max_val):
    n = len(arr)
    count = [0] * (max_val + 1)
    output = [0] * n

    # Contar las ocurrencias
    for num in arr:
        count[num] += 1

    # Acumular las posiciones
    for i in range(1, len(count)):
        count[i] += count[i - 1]

    # Construir el array ordenado
    for num in reversed(arr):
        output[count[num] - 1] = num
        count[num] -= 1

    return output

# Ejemplo de uso
arr = [4, 2, 2, 8, 3, 3, 1]
print("\nArray original:", arr)
sorted_arr = counting_sort(arr, max(arr))
print("\nArray ordenado:", sorted_arr)
