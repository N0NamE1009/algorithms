def bucket_sort(arr):
    n = len(arr)
    if n <= 0:
        return arr

    # Crear cubetas vacias
    num_buckets = 10
    buckets = [[] for _ in range(num_buckets)]

    # Distribuir elementos en cubetas
    for num in arr:
        index = int(num * num_buckets)
        buckets[index].append(num)

    # Ordenar cada cubeta y concatenar resultados
    sorted_arr = []
    for bucket in buckets:
        sorted_arr.extend(sorted(bucket))

    return sorted_arr

# Ejemplo de uso
arr = [0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68]
print("\nArray original:", arr)
sorted_arr = bucket_sort(arr)
print("\nArray ordenado:", sorted_arr)