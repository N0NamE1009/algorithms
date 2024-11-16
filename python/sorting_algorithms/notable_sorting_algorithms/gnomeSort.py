def gnome_sort(arr):
    i = 0
    while i < len(arr):
        if i == 0 or arr[i - 1] <= arr[i]:
            i += 1
        else:
            arr[i], arr[i - 1] = arr[i - 1], arr[i]
            i -= 1

# Ejemplo de uso
arr = [34, 2, 10, -9, 7]
print("\nArray original:", arr)
gnome_sort(arr)
print("\nArray ordenado:", arr)