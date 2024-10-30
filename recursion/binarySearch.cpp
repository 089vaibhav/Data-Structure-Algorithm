#include<iostream> // Include the iostream library for input and output
using namespace std;

// Recursive function to perform binary search on a sorted array
bool binarySearch(int arr[], int s, int e, int k) {
    // Base case: if the start index exceeds the end index, key is not found
    if (s > e) 
        return false;

    // Calculate the middle index
    int mid = s + (e - s) / 2;

    // Check if the middle element is equal to the key
    if (arr[mid] == k)
        return true;

    // If the middle element is less than the key, search the right half
    if (arr[mid] < k) {
        return binarySearch(arr, mid + 1, e, k);
    } else {
        // If the middle element is greater than the key, search the left half
        return binarySearch(arr, s, mid - 1, k);
    }
}

int main() {
    int arr[6] = {1, 3, 5, 6, 12, 18}; // Sorted array
    int size = 6; // Size of the array
    int key = 18; // Key to search for

    // Output the result of binarySearch function
    cout << "Present or not: " << binarySearch(arr, 0, size - 1, key) << endl;

    return 0; // End of program
}
