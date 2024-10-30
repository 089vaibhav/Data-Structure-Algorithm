#include<iostream> // Include the iostream library for input and output
using namespace std;

// Function to check if an array is sorted in ascending order
bool isSorted(int arr[], int size) {
    // Base case: if the array has 0 or 1 element, it's considered sorted
    if (size == 0 || size == 1) {
        return true; 
    }

    // Check if the first element is greater than the second; if so, array is not sorted
    if (arr[0] > arr[1]) {
        return false;
    } else {
        // Recursively check the rest of the array
        bool remainingArr = isSorted(arr + 1, size - 1);
        return remainingArr;
    }
}

int main() {
    int arr[10] = {2, 4, 5, 6, 7, 88, 9, 33, 44, 55}; // Define an array of 10 integers
    int size = 10; // Size of the array

    // Check if the array is sorted and store the result in 'ans'
    bool ans = isSorted(arr, size);

    // Output the result based on the value of 'ans'
    if (ans) {
        cout << "Array is sorted" << endl;
    } else {
        cout << "Array is not sorted" << endl;
    }

    return 0; // End of program
}
