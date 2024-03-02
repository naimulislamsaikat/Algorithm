#include<iostream>
using namespace std;

void merge(int arr[], int low, int high, int mid){
    int i=low, j=mid+1, k=0, c[(high-low)+1];
    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            c[k++]=arr[i++];
        }
        else{
            c[k++]=arr[j++];
        }
    }
    while(i<=mid){
        c[k++]=arr[i++];
    }
    while(j<=high){
        c[k++]=arr[j++];
    }
    for(i=low; i<=high; i++){
        arr[i]=c[i-low];
    }
}

void mergesort(int arr[], int low, int high){
    int mid=(low+high)/2;
    if(low<high){
        mergesort(arr, low, mid);
        mergesort(arr, mid+1, high);
        merge(arr, low, high, mid);
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

    mergesort(arr, 0, n-1);
    cout<<"Sorted array: ";
    printArray(arr, n);

    return 0;
}
