#include<iostream>
using namespace std;
void deletion(int arr[], int pos,int n){
    for(int i=pos; i<n-1; i++){
        arr[i]=arr[i+1];
    }
    for(int i=0; i<n-1; i++){
        cout<<arr[i]<<" ";
    }
}
void insertion(int arr[],int pos,int val, int n){
    for(int i=n-1; pos<=i; i--){
        arr[i+1]=arr[i];
    }
    arr[pos] = val;
    for(int i=0; i<=n; i++){
        cout<<arr[i]<<" ";
    }
}
void bs(int arr[],int val, int n){
    int start = 0;
    int end = n-1;
    while(start<=end){
        int m = (start+end)/2;
        if(arr[m]==val){
            cout<<"Found"<<endl;
            return;
        }
        else if(val>arr[m])    start = m+1;
        else end = m-1;
    }
    cout<<" Not Found"<<endl;
}

void merge(int arr1[],int arr2[],int n1,int n2){
    int a=0,b=0,c=0;
    int arr3[n1+n2];
    while(a<n1 && b<n2){
        if(arr1[a]>arr2[b]){
            arr3[c] = arr2[b]; 
            b++;
        }else{
            arr3[c] = arr1[a];
            a++;
        }
        c++;
    }
    while(a<n1){
        arr3[c++] = arr1[a++];
    }
    while(b<n1){
        arr3[c++] = arr2[b++];
    }

    for(int i=0; i<n1+n2; i++){
        cout<<arr3[i]<<" ";
    }
}
int main() {
    // your code goes here
    // int arr[10];
    // int n = 5;
    // for(int i=0; i<n; i++){
    //     cin>>arr[i];
    // } 
    int arr[] ={1,2,3,4,5};
    int arr2[] ={0,6,7,9};

    // deletion(arr, 5,6);
    // insertion(arr,0,22, 5);
    bs(arr, 57, 5);
    merge(arr,arr2,5,4);
}