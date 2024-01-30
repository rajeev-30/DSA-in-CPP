#include<iostream>
using namespace std;

int partition(int arr[], int low, int high){
    int pivot = high;
    int i = low-1;
    int j = low;
    while (j<pivot)
    {
        if(arr[pivot]>=arr[j])
            swap(arr[++i], arr[j]);
        j++;

    }

    swap(arr[++i], arr[pivot]);
    return i;
}

void quickSort(int arr[], int low, int high){
    if(low>=high) return;

    int p = partition(arr, low, high);
    quickSort(arr,low,p-1);
    quickSort(arr,p+1,high);

}


void sort(int arr[], int low, int high){
    
}
int main(){
    int arr[] = {5,4,3,2,1};
    quickSort(arr,0,4);

    for(int i=0; i<5; i++)
        cout<<arr[i]<<" ";
}