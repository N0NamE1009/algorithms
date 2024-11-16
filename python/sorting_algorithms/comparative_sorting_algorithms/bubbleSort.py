def bubble_sort(arr):
    n = len(arr)
    for i in range(n-1):
        swapped = False
        for j in range(n-i-1):
            if arr[j] > arr[j+1]:
                # Intercambiar
                arr[j], arr[j+1] = arr[j+1], arr[j]
                swapped = True
        if not swapped:
            break

# Ejemplo de uso
arr = [64, 34, 25, 12, 22, 11, 90]
print(f"Array original: {arr}")
bubble_sort(arr)
print(f"Array ordenado: {arr}")