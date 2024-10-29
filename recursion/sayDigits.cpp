#include<iostream>
using namespace std;

// Recursive function to say each digit of a number in words
void sayDigit(int n, string arr[]) {
    
    // Base case: if n becomes 0, stop the recursion
    if(n == 0) {
        return;
    }

    // Extract the last digit of the number
    int digit = n % 10;
    n = n / 10;  // Reduce n by removing the last digit

    // Recursive call with the remaining digits
    sayDigit(n, arr);

    // Print the word corresponding to the current digit
    cout << arr[digit] << " ";
}

int main() {
    
    // Array containing words for digits 0 to 9
    string arr[10] = {"zero", "one", "two", "three",
                      "four", "five", "six",
                      "seven", "eight", "nine"};
                      
    int n;
    cout << "Enter a number: ";
    cin >> n;  // Input the number from the user

    cout << endl << "The number in words is: " << endl;

    // Call the function to print each digit in words
    sayDigit(n, arr);

    cout << endl;  // Print new lines for better output formatting

    return 0;  // Indicate that the program ended successfully
}
