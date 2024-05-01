def selectionSort(array):
    size = len(array)
    for ind in range(size):
        min_index = ind
        for j in range(ind + 1, size):
            if array[j] < array[min_index]:
                min_index = j
        (array[ind], array[min_index]) = (array[min_index], array[ind])

# Prompting the user for array input
input_array = input("Enter the elements of the array separated by spaces: ")
arr = list(map(int, input_array.split()))

selectionSort(arr)

print('The array after sorting in Ascending Order by selection sort is:')
print(arr)
