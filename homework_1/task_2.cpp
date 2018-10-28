#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    int n, k;
    cin >> n >> k;
    int* prices = new int[n];
    for (size_t i = 0; i < n; ++i) 
    {
        cin >> prices[i];
    }
    sort(prices, prices + n);
    
    int bestBuySoFar = 0;
    
    for (size_t i = 0; i < n; ++i) 
    {
        bestBuySoFar += prices[i];
    }
    
    for (size_t i = n-k; i >= 0; i-=k) 
    {
        bestBuySoFar -= prices[i];
    }
    delete[] prices;
    
    cout << bestBuySoFar << endl;
    return 0;
}
