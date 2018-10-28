#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int partition(int arr[], int low, int high) 
{
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

// Naive variation, Weak Tests for Applying Basic Knowledge of QuickSort
void quickSort(int arr[], int low, int high) 
{

    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main() 
{
    
    int n, k;
    cin >> n >> k;

    int* prices = new int[n];

    int toys = 0;
    int moneySpent = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    quickSort(prices, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        if( moneySpent + prices[i] <= k)
        {
            toys++;
        }
        moneySpent += prices[i];
    }

    cout << toys << endl;
    
    return 0;
}
