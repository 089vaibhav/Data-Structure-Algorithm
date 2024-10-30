#include <iostream>
using namespace std;

int arraySum(int arr[], int size) {
    // Base case: If the array is empty, return 0
    if (size == 0) {
        return 0;
    }

    // Recursive case: Sum of the first element and the sum of the rest of the array
    return arr[0] + arraySum(arr + 1, size - 1);
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5}; // Example array
    int size = 5; // Size of the array

    int sum = arraySum(arr, size); // Calculate the sum
    cout << "Sum of array elements: " << sum << endl; // Output the sum

    return 0;
}
