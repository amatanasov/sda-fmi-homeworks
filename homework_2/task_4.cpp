#include <iostream>
using namespace std;
// A classical implementation of MergeSort for counting inversions

long int merge(int arr[], int temp[], int left, int mid, int right)
{
    int i, j, k;
    long int count = 0;

    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            count = count + (mid - i);
        }
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return count;
}

long int mergesort(int arr[], int temp[], int left, int right)
{
    long int inversionsCount = 0;
    if (right > left) {
        int mid = (right + left) / 2;
        inversionsCount = mergesort(arr, temp, left, mid);
        
        inversionsCount += mergesort(arr, temp, mid + 1, right);

        inversionsCount += merge(arr, temp, left, mid + 1, right);
    }
    return inversionsCount;
}

int main()
{
    int q;
    cin >> q;
    long int* inversions = new long int[q];
    for (size_t p = 0; p < q; p++) 
    {
        int n;
        cin >> n;
        int* arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            
            cin >> arr[i];
            
        }
        int* temp = (int*)malloc(sizeof(int) * n);
        inversions[p] = mergesort(arr, temp, 0, n - 1);
        
        delete[] arr;
    }

    for (size_t i = 0; i < q; i++)
    {
        cout << inversions[i] << endl;
    }
    
    delete[] inversions;
    return 0;
}