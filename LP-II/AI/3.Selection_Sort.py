def selectionSort(arr):
    for i in range(len(arr)):
        min = float('-inf')
        for j in range(i + 1, len(arr)):
            if arr[i] > arr[j]:
                arr[i],arr[j] = arr[j], arr[i]
    return arr
    
print(selectionSort([89,56,45,34,65,76]))