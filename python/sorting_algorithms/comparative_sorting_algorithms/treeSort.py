class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

# Insertar un nodo en el arbol
def insert(root, key):
    if root is None:
        return Node(key)
    if key < root.key:
        root.left = insert(root.left, key)
    elif key > root.key:
        root.right = insert(root.right, key)
    return root

# Recorrido in-order del arbol
def inorder(root, sorted_list):
    if root is not None:
        inorder(root.left, sorted_list)
        sorted_list.append(root.key)
        inorder(root.right, sorted_list)

# Tree Sort
def tree_sort(arr):
    if not arr:
        return []

    root = None
    for key in arr:
        root = insert(root, key)

    sorted_list = []
    inorder(root, sorted_list)
    return sorted_list

# Ejemplo de uso
arr = [5, 3, 7, 1, 9, 4, 6]
print(f"\nArray original: {arr}")
sorted_arr = tree_sort(arr)
print(f"\nArray ordenado: {sorted_arr}")