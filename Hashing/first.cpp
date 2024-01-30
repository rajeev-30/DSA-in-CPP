#include<iostream>
#include<string>
#include<queue>
using namespace std;

int main()
{
    int arr[] = {1,2,3,4,5,6,7,1};
    int n = 8;
    int idx = -1;
    for(int i = 0; i < n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]==arr[j]){
                 idx = i;
                 break;
            }
        }
    }

    for(int i=idx; i<n; i++){
        arr[i] = arr[i+1];
    }
    for(int i=0; i<n-1; i++){
        cout<<arr[i];
    }
    
}