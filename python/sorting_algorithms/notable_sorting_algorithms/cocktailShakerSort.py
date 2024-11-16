def cocktail_shaker_sort(arr):
    start = 0
    end = len(arr) - 1
    swapped = True

    while swapped:
        swapped = False

        # Pasada de izquierda a derecha
        for i in range(start, end):
            if arr[i] > arr[i + 1]:
                arr[i], arr[i + 1] = arr[i + 1], arr[i]
                swapped = True

        if not swapped:
            break

        swapped = False
        end -= 1

        # Pasada de derecha a izquierda
        for i in range(end - 1, start - 1, -1):
            if arr[i] > arr[i + 1]:
                arr[i], arr[i + 1] = arr[i + 1], arr[i]
                swapped = True

        start += 1

# Ejemplo de uso
arr = [5, 3, 8, 6, 2, 7, 4, 1]
print("\nArray original:", arr)
cocktail_shaker_sort(arr)
print("\nArray ordenado:", arr)