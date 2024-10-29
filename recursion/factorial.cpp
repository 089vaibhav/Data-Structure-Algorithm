#include<iostream>
using namespace std;

int factorial(int n){
    //base case
    if(n == 0){
        return 1;
    }

    //recursive case
    return n * factorial(n - 1);  

}

int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;

    int ans = factorial(n);
    cout<<"Factorial of " << n << " is: " << ans << endl;
}
