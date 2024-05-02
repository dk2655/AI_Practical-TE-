#include <iostream>
using namespace std;

// Function to swap the positions of two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to print an array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Function to perform selection sort
void selectionSort(int array[], int size) {
    for (int step = 0; step < size - 1; step++) {
        int min_idx = step;
        // Find the index of the minimum element in each loop
        for (int i = step + 1; i < size; i++) {
            // To sort in descending order, change < to > in this line.
            if (array[i] < array[min_idx])
                min_idx = i;
        }
        // Put the minimum element at the correct position
        swap(&array[min_idx], &array[step]);
    }
}

// Driver code
int main() {
    int data[] = {20, 12, 10, 15, 2};
    int size = sizeof(data) / sizeof(data[0]);
    selectionSort(data, size);
    cout << "Sorted array in Ascending Order:\n";
    printArray(data, size);
    return 0;
}
