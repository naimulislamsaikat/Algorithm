#include<iostream>
using namespace std;

int linearSearch(int arr[], int n, int s){
    for(int i=0; i<n; i++){
        if(arr[i] == s){
            return i;
        }
    }
    return 0;
}

void bubbleSort(int arr[], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<(n-i-1); j++){
            if(arr[j]> arr[j+1]){
                swap (arr[j], arr[j+1]);

            }
        }
    }
}

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

int binarySearch(int arr[], int n, int s){

    bubbleSort(arr, n);
    countingSort(arr, n);

    int low=0, high=n - 1;

    while(low <= high){
        int mid=low+(high-low)/2;

        if(arr[mid] == s){
            return mid;
        }
        else if(arr[mid] < s){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
return 0;
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i] << " ";
    }
    cout<<endl;
}

int main(){
    int n, s, result;
    cout<<"Enter the number of elements: ";
    cin>>n;

    int arr[n];
    cout<<"Enter the elements: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<"Enter the element to search: ";
    cin>>s;

    int choice;
    cout<<"Enter 1 for linear search, 2 for binary search.\nAnswer: ";
    cin>>choice;

    if(choice == 1){
        result=linearSearch(arr, n, s);
        cout<<"Sorted array: ";
        printArray(arr, n);
        cout<<"Element is present at index: "<<result<<endl;
    }
    else if(choice == 2){
        cout<<"Which sorting do you want to do for the correct solution?\n1. Apply bubble sort\n2. Apply Counting sort\n";
        cout<<"Answer: ";
        cin>>choice;
        if(choice == 1){
            bubbleSort(arr, n);
            result=binarySearch(arr, n, s);
            cout<<"Sorted array: ";
            printArray(arr, n);
            cout<<"Element is present at index: "<<result<<endl;
        }
        else if(choice == 2){
            countingSort(arr, n);
            result=binarySearch(arr, n, s);
            cout<<"Sorted array: ";
            printArray(arr, n);
            cout<<"Element is present at index: "<<result<<endl;
        }
    }
    else{
        cout<<"Invalid choice"<<endl;
        return 0;
    }

return 0;
}
