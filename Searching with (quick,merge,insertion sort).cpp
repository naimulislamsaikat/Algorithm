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

int partition(int arr[], int low, int high){
    int pivot=arr[low];
    int i=low;
    for(int j=low+1; j<=high; j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i], arr[low]);
    return i;
}

void quick(int arr[], int low, int high){
    if(low<high){
        int pi=partition(arr, low, high);
        quick(arr, low, pi-1);
        quick(arr, pi+1, high);
    }
}

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

void insertionSort(int arr[], int n){
    for(int i=1; i<n; i++){
        for (int j=i-1; j>=0; j--){
            if(arr[j+1] < arr[j]){
                swap(arr[j+1], arr[j]);
            }
        }
    }
}

int binarySearch(int arr[], int n, int s){

    insertionSort(arr, n);
    quick(arr, 0, n-1);
    mergesort(arr, 0, n-1);

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
    cout<<"Enter 1 for linear search 2 for binary search  "<<endl;
    cout<<"Enter: ";
    cin>>choice;

    if(choice == 1){
        result=linearSearch(arr, n, s);
    }
    else if(choice == 2){
        int option;
        cout<<"For binary searching which sorting you want to try?\n1. Quick sort\n2. Merge sort\n3. Insertion sort"<<endl;
        cout<<"Enter: ";
        cin>>option;
        if(option ==1){
            cout<<"Sorted array: ";
            printArray(arr, n);
            cout<<"Element is present at index: "<<result<<endl;
            result=binarySearch(arr, n, s);
        }
        else if(option ==2){
            cout<<"Sorted array: ";
            printArray(arr, n);
            cout<<"Element is present at index: "<<result<<endl;
            result=binarySearch(arr, n, s);
        }
        else if(option ==3){
            cout<<"Sorted array: ";
            printArray(arr, n);
            cout<<"Element is present at index: "<<result<<endl;
            result=binarySearch(arr, n, s);
        }
        else{
            cout<<"Entered a wrong option!";
        }
    }
    else{
        cout<<"Invalid choice"<<endl;
        return 0;
    }

return 0;
}
