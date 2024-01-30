#include <iostream>
using namespace std;

void merge(int arr[], int s, int m, int e)
{
    int temp[(e - s) + 1];
    int i = s;
    int j = m + 1;
    int k = 0;

    while (i <= m && j <= e)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= m)
        temp[k++] = arr[i++];
    while (j <= e)
        temp[k++] = arr[j++];

    for (k = 0,i = s; k < (e - s) + 1; k++, i++)
        arr[i] = temp[k];
}

void mergeSort(int arr[], int s, int e)
{
    if (s >= e)
        return;

    int m = (s + e) / 2;
    mergeSort(arr, s, m);
    mergeSort(arr, m + 1, e);
    merge(arr, s, m, e);
}

int main()
{
    int arr[] = {5, 3, 7, 8, 1};
    mergeSort(arr, 0, 4);

    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";

    return 0;
}