def comb_sort(arr):
    n = len(arr)
    gap = n
    shrink = 1.3
    swapped = True

    while gap > 1 or swapped:
        gap = int(gap / shrink)
        if gap < 1:
            gap = 1

        swapped = False

        for i in range(n - gap):
            if arr[i] > arr[i + gap]:
                arr[i], arr[i + gap] = arr[i + gap], arr[i]
                swapped = True

# Ejemplo de uso
arr = [8, 4, 1, 56, 3, -44, 23, -6, 28, 0]
print("\nArray original:", arr)
comb_sort(arr)
print("\nArray ordenado:", arr)