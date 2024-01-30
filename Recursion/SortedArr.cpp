#include <iostream>
using namespace std;

bool rec(int arr[], int n, int j)
{
    if (j == n-1)
        return true;

    if(arr[j] > arr[j+1])
        return false;

    return rec(arr,n,j+1);
}

int main(){
    int arr[] = {0,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<rec(arr,n, 0)<<endl;

    return 0;
}