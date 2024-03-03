#include<iostream>
using namespace std;

int count(int arr[], int n) {
    int large = 0;
    for(int i = 0; i < n; i++) {
        if(large < arr[i]){
            large = arr[i];
        }
    }
    return large;
}

void countingSort(int arr[], int n) {
    int c=count(arr, n);
    int arr1[c + 1];
    int arr2[n];
    for(int i=0; i<=c; i++) {
        arr1[i]=0;
    }
    for(int i=0; i<n; i++) {
        arr1[arr[i]]++;
    }
    for(int i=1; i<=c; i++) {
        arr1[i]+=arr1[i-1];
    }
    for(int i=n-1; i>=0; i--) {
        arr1[arr[i]]--;
        arr2[arr1[arr[i]]] = arr[i];
    }
    for(int i=0; i<n; i++) {
        arr[i]=arr2[i];
    }
}

void print(int arr[], int n){
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

    countingSort(arr, n);
    cout<<"Sorted array: ";
    print(arr, n);

    return 0;
}
