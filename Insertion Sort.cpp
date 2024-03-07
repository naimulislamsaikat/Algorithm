#include<iostream>
using namespace std;

void insertionSort(int arr[], int n){
    for(int i=1; i<n; i++){
        for (int j=i-1; j>=0; j--){
            if(arr[j+1] < arr[j]){
                swap(arr[j+1], arr[j]);
            }
        }
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i] << " ";
    }
    cout<<endl;
}

int main() {
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;

    int arr[n];
    cout<<"Enter the elements: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    insertionSort(arr, n);
    cout<<"Sorted array: ";
    printArray(arr, n);

    return 0;
}
