// Fibonacci sequence is a sequence in which each number is the sum of the two preceding ones

#include<iostream>  // include the iostream library for input and output
using namespace std;

// Recursive function to calculate the nth Fibonacci number
int fib(int n) {
    // Base case: if n is 0, the Fibonacci number is 0
    if(n == 0)
        return 0;

    // Base case: if n is 1, the Fibonacci number is 1
    if(n == 1)
        return 1;

    // Recursive case: the nth Fibonacci number is the sum of the two preceding numbers
    int ans = fib(n - 1) + fib(n - 2);

    return ans;  // return the calculated Fibonacci number
}

int main() {
    int n;
    cout << "Enter the position of the Fibonacci sequence: "; // prompt the user to enter a number
    cin >> n;  // take input for the nth position in the Fibonacci sequence

    cout << "The Fibonacci number at position " << n << " is " << fib(n) << endl; // output the result

    return 0;  // indicate that the program ended successfully
}
