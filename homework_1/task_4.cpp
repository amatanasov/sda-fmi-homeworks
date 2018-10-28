#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Pair
{
    int shortSock;
    int longSock;

    bool operator<(const Pair& p) const
    {
        int diferenceA = longSock - shortSock;
        int diferenceB = p.longSock - p.shortSock;
        if (diferenceA != diferenceB)
        {
            return diferenceA < diferenceB;
        }

        return shortSock < p.shortSock;
    }
};

int main() 
{
    int n, k;
    cin >> n >> k;

    vector<int> socks;

    for (size_t i = 0; i < n; i++)
    {
        int sock;
        cin >> sock;
        socks.push_back(sock);
    }

    vector<Pair> pairs;
    
    for (size_t i = 0; i < n - 1; i++)
    {
        for (size_t j = i + 1; j < n; j++)
        {
            Pair pairOfSocks;
            
            pairOfSocks.shortSock = socks[i];
            pairOfSocks.longSock = socks[j];

            pairs.push_back(pairOfSocks);
        }
    }

    sort(pairs.begin(), pairs.end());

    cout << pairs[k - 1].shortSock << " " << pairs[k - 1].longSock << endl;

    return 0;
}
