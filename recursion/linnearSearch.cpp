#include<iostream> // Include the iostream library for input and output
using namespace std;

// Recursive function to perform linear search
bool linearSearch(int arr[], int size, int key) {
    // Base case: if the size is 0, the key is not found in the array
    if (size == 0) {
        return false;
    }

    // Check if the first element of the current array segment matches the key
    if (arr[0] == key) {
        return true; // Key found, return true
    } else {
        // Recursive call to search the rest of the array
        return linearSearch(arr + 1, size - 1, key);
    }
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5}; // Define an array of 5 integers
    int size = 5; // Size of the array
    int key = 44; // Key to search for in the array

    // Call the linearSearch function and store the result in 'ans'
    bool ans = linearSearch(arr, size, key);

    // Output the result based on the value of 'ans'
    if (ans) {
        cout << "present" << endl;
    } else {
        cout << "absent" << endl;
    }

    return 0; // End of program
}
