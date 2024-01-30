
#include<iostream>
using namespace std;

void heap(int arr[],int n, int i){
    int lar = i;
    int left = 2*i+1  ;  
    int right = 2*i+2;  

    if(left<n && arr[left]>arr[lar])
        lar = left;
    if(right<n && arr[right]>arr[lar])
        lar = right;

    if(lar!=i){
        swap(arr[lar],arr[i]);
        heap(arr,n,lar);
    }
}

int main(){
    
    
}