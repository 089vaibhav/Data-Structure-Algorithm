#include<iostream>
using namespace std;

bool isSorted(int arr[],int size){

    if(size==0 || size==1){
        return true; 
    }

    if(arr[0]>arr[1]){
        return false;
    }
    else{
        bool remainingArr = isSorted(arr+1, size-1);
        return remainingArr ;
    }

}

int main(){
    int arr[10] = {2,4,5,6,7,88,9,33,44,55};
    int size = 10;
    bool ans = isSorted(arr, size);

    if(ans){
        cout<<"Array is sorted"<<endl;
    }
    else{
        cout<<"Array is not sorted"<<endl;
    }

    return 0;
}