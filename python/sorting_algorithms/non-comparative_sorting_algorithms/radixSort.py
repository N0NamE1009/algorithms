def counting_sort(arr, exp):
    n = len(arr)
    output = [0] * n
    count = [0] * 10

    # Contar ocurrencias de digitos
    for num in arr:
        index = (num // exp) % 10
        count[index] += 1

    # Acumular posiciones
    for i in range(1, 10):
        count[i] += count[i - 1]

    # Construir el array ordenado
    for num in reversed(arr):
        index = (num // exp) % 10
        output[count[index] - 1] = num
        count[index] -= 1

    return output

def radix_sort(arr):
    if not arr:
        return []

    max_val = max(arr)
    exp = 1
    while max_val // exp > 0:
        arr = counting_sort(arr, exp)
        exp *= 10

    return arr

# Ejemplo de uso
arr = [170, 45, 75, 90, 802, 24, 2, 66]
print("\nArray original:", arr)
sorted_arr = radix_sort(arr)
print("\nArray ordenado:", sorted_arr)